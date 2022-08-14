#include "precompiled/pch.hpp"
#include "Global.h"
#include "GraphicsSystem.h"

namespace CEngine
{
	void GraphicsSystem::Update(float dt)
	{
		for (auto const& ent : entArray) {
			TransformComponent& trans = app->m_world.GetComponent<TransformComponent>(ent);
			trans.x += 0.1f;
			std::cout << trans.x << std::endl;
		}
	}
}