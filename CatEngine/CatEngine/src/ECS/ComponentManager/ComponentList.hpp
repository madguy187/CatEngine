#pragma once
#include "precompiled/pch.hpp"
#include "Global.h"

namespace CEngine
{
	template <typename ...T>
	struct TypeList
	{

	};

	template <typename ...T>
	struct ComponentTypeList : TypeList<T...>
	{

	};

	using ComponentList = ComponentTypeList <

	>;
}