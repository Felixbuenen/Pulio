#include <Pulio.h>

class Sandbox : public Pulio::Application
{
public:
	Sandbox() {
		PULIO_LOG_INFO("Created the sandbox application.");
	}

	~Sandbox() {

	}
};

Pulio::Application* Pulio::CreateApplication()
{
	return new Sandbox();
}