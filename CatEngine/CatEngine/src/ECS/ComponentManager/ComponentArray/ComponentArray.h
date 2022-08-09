#pragma once
#include "Utilities/SparseSet/SparseSet.hpp"

namespace CEngine
{
	class IComponentArray
	{
	public:
		virtual ~IComponentArray() {};
	};

	template <typename Component>
	class ComponentArray : public IComponentArray
	{
		std::array<Component, MAX_SIZE> m_cArray;
		SparseSet m_Sset;
	public:
		void Insert(const Entity ent, Component comp) {
			size_t index = m_Sset.Insert(ent);
			assert(index != MAX_SIZE && "Array is full");

			m_cArray[index] = comp;
		}

		void Delete(const Entity ent) {
			size_t index = m_Sset.Delete(ent);
			assert(index != MAX_SIZE && "Entity does not exist");

			std::swap(m_cArray[ent], m_cArray[index]);
		}

		Component& GetComponent(const Entity ent) {
			size_t index = m_Sset.Search(ent);
			assert(index != MAX_SIZE && "Getting component of an non-existant entity");

			return m_cArray[index];
		}

		void Clear() {
			m_Sset.Clear();
		}

		void Dump() {
			m_Sset.Dump();
		}
	};
}