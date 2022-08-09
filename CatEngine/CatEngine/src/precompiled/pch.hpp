#pragma once

#define CENGINE_INFO(x) spdlog::info(x);
#define CENGINE_DEBUG(x) spdlog::debug(x);
#define CENGINE_ERROR(x) spdlog::error(x);

#include <iostream>

#include <vector>
#include <array>
#include <stack>
#include <string>

#include <ctime>
#include <stdlib.h>

#include <functional>
#include <memory>
#include <algorithm>
#include <type_traits>
#include <utility>

#include "Utilities/MemoryHandler/MemoryHandler.h"
#include "spdlog/spdlog.h"