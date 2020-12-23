#include <Pulio.h>

#include "TestLayer.h"

class Sandbox : public Pulio::Application
{
public:
	Sandbox() {
		PULIO_LOG_INFO("Created the sandbox application.");

		PushLayer(new TestLayer("Test Layer"));
	}

	~Sandbox() {

	}
};

Pulio::Application* Pulio::CreateApplication()
{
	return new Sandbox();
}