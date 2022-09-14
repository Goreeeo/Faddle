#include <Faddle.h>

class Test : public Faddle::Application {
public:
	Test() {
		PushOverlay(new Faddle::ImGuiLayer());
	}
	~Test() {

	}
};

Faddle::Application* Faddle::CreateApplication() {
	return new Test();
}