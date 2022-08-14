#pragma once
#include "precompiled/pch.hpp"
#include "Global.h"

namespace CEngine
{
	class System
	{
	public:
		std::set<Entity> entArray;
		virtual void Update(float dt) = 0;
	};
}