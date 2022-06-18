#pragma once

#define CENGINE_INFO(x) spdlog::info(x);
#define CENGINE_DEBUG(x) spdlog::debug(x);

#include <iostream>
#include <vector>
#include <string>

#include "Utilities/MemoryHandler/MemoryHandler.h"
#include "spdlog/spdlog.h"