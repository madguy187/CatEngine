#pragma once
#include "precompiled/pch.hpp"
#include "../ComponentArray/ComponentArray.h"

namespace CEngine
{
	struct ComponentBase
	{
		std::unique_ptr<IComponentArray> _container;
		void (*Delete)(IComponentArray&, const Entity);
		void (*GetComponent)(IComponentArray&, const Entity);
		void (*Clear)(IComponentArray&);
	};
}