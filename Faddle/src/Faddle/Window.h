#pragma once

#include "fmpch.h"

#include "Faddle/Core.h"
#include "Faddle/Event/Event.h"

namespace Faddle {
	struct WindowProps {
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& title = "Faddle Game", unsigned int width = 1280, unsigned int height = 720) : title(title), width(width), height(height) {}
	};

	class FADDLE_API Window {
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

	public:
		virtual ~Window() {}

	public:
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& propes = WindowProps());
	};
}