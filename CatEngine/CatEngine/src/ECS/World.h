#pragma once
#include "ComponentManager/ComponentManager.hpp"
#include "EntityManager/EntityManager.h"
#include "SystemManager/SystemManager.h"

namespace CEngine
{
	class World
	{
		std::unique_ptr<EntityManager> m_entityManager;
		std::unique_ptr<ComponentManager> m_componentManager;
		std::unique_ptr<SystemManager> m_systemManager;
	public:
		World();

		void Init();

		template <typename ...T>
		Entity CreateEntity(T... args)
		{
			Entity ent = m_entityManager->CreateEntity();

			if (sizeof...(args)) {
				((RecursiveAddComponent(ent, args)), ...);
			}

			return ent;
		}

		void Destroy(Entity ent)
		{
			m_componentManager->DestroyBySignature(ent, m_entityManager->GetSignature(ent));
			m_systemManager->RemoveEntity(ent);
			m_entityManager->DeleteEntity(ent);
		}

		template <typename T>
		void RegisterComponent()
		{
			m_componentManager->RegisterComponent<T>();
		}

		template <typename T>
		T& GetComponent(Entity ent)
		{
			return m_componentManager->GetComponentRef<T>(ent);
		}

		template <typename T>
		void AddComponent(Entity ent, T component = T{})
		{
			unsigned const index = m_componentManager->GetComponentIndex<T>();
			m_entityManager->ChangeSignature(ent, index, true);
			m_componentManager->AddComponent(ent, component);
			m_systemManager->EntitySignatureChange(ent, m_entityManager->GetSignature(ent));
		}

		template <typename T>
		void DestroyComponent(Entity ent)
		{
			m_entityManager->ChangeSignature(ent, index, false);
			m_componentManager->DeleteComponent(ent);
			m_systemManager->EntitySignatureChange(ent, m_entityManager->GetSignature(ent));
		}

		template <typename ...T>
		void RegisterSystem(T... args)
		{
			Signature systemSignature = Signature{};
			if (sizeof...(args)) {
				((RecursiveGetSignature(systemSignature, args)), ...);
			}

			m_systemManager->RegisterSystem(systemSignature);
			std::cout << "system signature: " << systemSignature << std::endl;
		}

	private:
		template <typename T>
		void RecursiveAddComponent(const Entity& ent, T component)
		{
			AddComponent(ent, component);
		}

		template <typename T>
		void RecursiveGetSignature(Signature& signature)
		{
			signature.set(m_componentManager->GetComponentIndex<T>(), true);
		}
	};
}