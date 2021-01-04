#include <Pulio.h>

#include "TestLayer.h"

class Sandbox : public Pulio::Application
{
public:
	Sandbox() {
		PULIO_LOG_INFO("Created the sandbox application.");

		//PL_ASSERT(2 < 1, "test message {0}", 1);

		PushLayer(new TestLayer("Test Layer"));
	}

	~Sandbox() {

	}
};

Pulio::Application* Pulio::CreateApplication()
{
	return new Sandbox();
}