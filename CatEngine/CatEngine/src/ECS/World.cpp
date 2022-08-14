#include "precompiled/pch.hpp"
#include "Global.h"
#include "World.h"

namespace CEngine
{
	World::World()
	{
		m_entityManager = std::make_unique<EntityManager>();
		m_componentManager = std::make_unique<ComponentManager>();
		m_systemManager = std::make_unique<SystemManager>();
	}

	void World::Init()
	{
		m_entityManager->Init();
	}
}