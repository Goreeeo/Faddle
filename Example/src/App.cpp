#include <Faddle.h>

class Test : public Faddle::Application {
public:
	Test() {

	}
	~Test() {

	}
};

Faddle::Application* Faddle::CreateApplication() {
	return new Test();
}