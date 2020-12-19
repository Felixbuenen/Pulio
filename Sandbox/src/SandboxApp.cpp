#include <Pulio.h>

class Sandbox : public Pulio::Application
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Pulio::Application* Pulio::CreateApplication()
{
	return new Sandbox();
}