#include "fmpch.h"
#include "Win64Window.h"

#include <Faddle/Event/ApplicationEvent.h>
#include <Faddle/Event/KeyEvent.h>
#include <Faddle/Event/MouseEvent.h>
#include <Faddle/Log.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Faddle {
	static bool s_GLFWInitialized = false;

	static void ErrorCallback(int error, const char* desc) {
		FM_ERROR("GLFW Error ({0}): {1}", error, desc);
	}

	Window* Window::Create(const WindowProps& props) {
		return new Win64Window(props);
	}

	Win64Window::Win64Window(const WindowProps& props) {
		Init(props);
	}

	Win64Window::~Win64Window() {
		Shutdown();
	}

	void Win64Window::Init(const WindowProps& props) {
		m_Data.title = props.title;
		m_Data.width = props.width;
		m_Data.height = props.height;

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			FM_ASSERT(success, "Could not initialize GLFW!");

			glfwSetErrorCallback(ErrorCallback);

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.width, (int)props.height, m_Data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		FM_ASSERT(status, "Failed to initialize glad.");
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowResizeEvent event(width, height);
			data.eventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.eventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0);
				data.eventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);
				data.eventCallback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, 1);
				data.eventCallback(event);
				break;
			}
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int character) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			KeyTypedEvent event(character);
			data.eventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.eventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.eventCallback(event);
				break;
			}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double x, double y) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)x, (float)y);
			data.eventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((float)x, (float)y);
			data.eventCallback(event);
		});
	}

	void Win64Window::Shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void Win64Window::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Win64Window::SetVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}

		m_Data.vSync = enabled;
	}

	bool Win64Window::IsVSync() const {
		return m_Data.vSync;
	}
}