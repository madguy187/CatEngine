#pragma once
#include "precompiled/pch.hpp"

#define MAX_SIZE 1000
#define MAX_COMPONENT 32

using Entity = size_t;
using Signature = std::bitset<MAX_COMPONENT>;

#include "ECS/SystemManager/System/System.hpp"
#include "ECS/UserDefinedComponents/_ComponentList.hpp"
#include "Utilities/TypeID/TypeID.hpp"