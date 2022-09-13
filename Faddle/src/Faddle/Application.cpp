#include "fmpch.h"

#include "Application.h"
#include "Event/ApplicationEvent.h"
#include "Log.h"

namespace Faddle {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		FM_TRACE(e);

		while (true);
	}
}