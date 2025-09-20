#include <Siphon.h>

class Sandbox : public Siphon::Application {
public:
	Sandbox() {
	}
	~Sandbox() {
	}
};

Siphon::Application* Siphon::CreateApplication()
{
	return new Sandbox();
}