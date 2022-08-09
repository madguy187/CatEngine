#pragma once

namespace CEngine
{
	class EntityManager
	{
		std::stack<Entity> m_stack;
		size_t count = 0;
	public:
		void Init();
		Entity CreateEntity();
		void DeleteEntity(Entity ent);
		void Clear();
	};
}