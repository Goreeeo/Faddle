#pragma once

#include "Core.h"

namespace Faddle {
	class FADDLE_API Application
	{
	public:
		Application();
		virtual ~Application();

	public:
		void Run();
	};

	Application* CreateApplication();
}
