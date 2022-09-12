#pragma once

#include "Application.h"

#ifdef FM_PLATFORM_WINDOWS

extern Faddle::Application* Faddle::CreateApplication();

int main(int argc, char** argv) {
	auto app = Faddle::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error Get some Windows running.
#endif