#include "precompiled/pch.hpp"
#include "Application.h"

namespace CEngine
{
	void Application::Init()
	{
		m_world.Init();

		m_world.RegisterComponent<TransformComponent>();

		Entity ent = m_world.CreateEntity(TransformComponent{});
		TransformComponent& trans = m_world.GetComponent<TransformComponent>(ent);
		std::cout << trans.x << std::endl;
	}

	void Application::MainLoop()
	{
		
	}

	void Application::Terminate()
	{

	}
}
