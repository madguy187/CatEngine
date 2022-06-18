#pragma once
#include "spdlog/logger.h"

namespace CEngine
{
	class Logger
	{
	public:
		void Info(const char* message);
		void Trace(const char* message);
		void Error(const char* message);
	};
}

