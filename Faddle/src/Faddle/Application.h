#pragma once

#include "Core.h"
#include "Window.h"
#include <Faddle/LayerStack.h>
#include <Faddle/Event/ApplicationEvent.h>

namespace Faddle {
	class FADDLE_API Application
	{
	public:
		Application();
		virtual ~Application();
	public:
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}
