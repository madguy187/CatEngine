#pragma once
#include "precompiled/pch.hpp"
#include "Global.h"
#include "ComponentBase/ComponentBase.hpp"
#include "ComponentArray/ComponentArray.h"

namespace CEngine
{
	unsigned TypeID<IComponentArray>::_counter = 0;

	class ComponentManager
	{
		std::vector<ComponentBase> m_componentArray;
		TypeID<IComponentArray> typeID;
	public:
		template<typename T>
		void RegisterComponent()
		{
			m_componentArray.push_back({
				std::make_unique<ComponentArray<T>>(),

				[](IComponentArray& _container, Entity ent) {
					static_cast<ComponentArray<T>&>(_container).Delete(ent);
				},

				[](IComponentArray& _container, Entity ent) {
					static_cast<ComponentArray<T>&>(_container).GetComponent(ent);
				},

				[](IComponentArray& _container) {
					static_cast<ComponentArray<T>&>(_container).Clear();
				}
			});

			typeID.RegisterID<T>();
		}

		template <typename T>
		void AddComponent(Entity ent, T comp) {
			static_cast<ComponentArray<T>&>(*(m_componentArray[typeID.GetID<T>()]._container)).Insert(ent, comp);
		}

		template <typename T>
		T& GetComponentRef(Entity ent) {
			auto& base = static_cast<ComponentArray<T>&>(*(m_componentArray[typeID.GetID<T>()]._container));
			return base.GetComponent(ent);
		}

		template <typename T>
		T* GetComponentPtr(Entity ent) {
			auto& base = static_cast<ComponentArray<T>&>(*(m_componentArray[typeID.GetID<T>()]._container));
			return &(base.GetComponent(ent));
		}

		template <typename T>
		void DeleteComponent(Entity ent) {
			auto& base = m_componentArray[typeID.GetID<T>()];
			base.Delete(*base._container, ent);
			std::cout << "deleted: 5" << std::endl;
			static_cast<ComponentArray<T>&>(*base._container).Dump();
		}
	};
}