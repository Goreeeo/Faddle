#pragma once

#include "Faddle/Window.h"

struct GLFWwindow;

namespace Faddle {
	class Win64Window : public Window {
	public:
		Win64Window(const WindowProps& props);
		virtual ~Win64Window();

	public:
		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.width; }
		inline unsigned int GetHeight() const override { return m_Data.height; }

		inline void SetEventCallback(const EventCallbackFunc& callback) override { m_Data.eventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline void* GetNativeWindow() const { return m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData {
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFunc eventCallback;
		};

		WindowData m_Data;
	};
}