#pragma once

#include "Application.h"
#include "Log.h"

#ifdef FM_PLATFORM_WINDOWS

extern Faddle::Application* Faddle::CreateApplication();

int main(int argc, char** argv) {
	Faddle::Log::Init();
	FM_INFO("Engine Initialized.");

	auto app = Faddle::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Get some Windows running.
#endif