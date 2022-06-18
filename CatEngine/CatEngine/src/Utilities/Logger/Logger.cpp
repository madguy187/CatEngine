#include "precompiled/pch.hpp"
#include "Logger.h"

namespace CEngine
{
	void Logger::Info(const char* message)
	{
		spdlog::info(message);
	}

	void Logger::Trace(const char* message)
	{
		spdlog::trace(message);
	}

	void Logger::Error(const char* message)
	{
		spdlog::error(message);
	}
}
