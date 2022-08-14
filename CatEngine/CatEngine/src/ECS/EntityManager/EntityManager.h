#pragma once

namespace CEngine
{
	class EntityManager
	{
		std::stack<Entity> m_stack;
		std::array<Signature, MAX_SIZE> m_entitySignatures;
		size_t m_count = 0;
	public:
		inline size_t GetCount() { return m_count; }
		inline Signature GetSignature(Entity ent) { return m_entitySignatures[ent]; }

		void Init();

		Entity CreateEntity();
		void DeleteEntity(Entity ent);
		void ChangeSignature(Entity ent, unsigned index, bool value);
		void Clear();
	};
}