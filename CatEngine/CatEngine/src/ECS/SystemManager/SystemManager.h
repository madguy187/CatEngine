#pragma once
#include "System/System.hpp"

namespace CEngine
{
	unsigned TypeID<System>::_counter = 0;

	class SystemManager
	{
		std::vector<Signature> m_SystemSignature;
		std::vector<std::shared_ptr<System>> m_System;
		TypeID<System> m_typeID;
	public:
		inline unsigned GetSize() { return m_typeID.GetSize(); }

		template<typename T>
		inline unsigned GetIndex() { return m_typeID.GetID<T>(); }

		template <typename T>
		void RegisterSystem(Signature signature)
		{
			unsigned index = m_typeID.RegisterID<T>();
			
			while (m_System.size() <= index)
			{
				// technically shuld never happen
				m_System.push_back(nullptr);
				m_SystemSignature.push_back(Signature{});
			}

			m_System[index] = std::make_shared<T>();
			m_SystemSignature[index] = signature;
		}

		template <typename T>
		void ClearSystem()
		{
			unsigned index = GetIndex<T>();
			m_System[index]->entArray.clear();
		}

		void ClearAllSystem();
		void RemoveEntity(Entity ent);
		void EntitySignatureChange(Entity ent, Signature signature);
	};
}