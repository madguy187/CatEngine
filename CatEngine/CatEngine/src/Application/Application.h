#pragma once
#include "ECS/World.h"

namespace CEngine
{
	class Application
	{
	public:
		World m_world;

		void Init();
		void MainLoop();
		void Terminate();
	};
}