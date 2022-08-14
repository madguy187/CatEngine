#include "precompiled/pch.hpp"
#include "Application/Application.h"

std::unique_ptr<CEngine::Application> app;

int main()
{
	app = std::make_unique<CEngine::Application>();

	app->Init();
	app->MainLoop();
	app->Terminate();
}