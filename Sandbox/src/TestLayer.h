#pragma once

#include <Pulio.h>

class TestLayer : public Pulio::Layer
{
public:
	TestLayer(std::string name) : Pulio::Layer(name) { }
	~TestLayer() { PULIO_LOG_WARNING("trying to delete test layer..."); }

	virtual void OnAttach() override { PULIO_LOG_INFO("Added layer: {0}", GetName()); }
	virtual void OnDetach() override {}

	virtual void OnEvent(Pulio::Event& event) override 
	{
		Pulio::EventDispatcher dispatcher(event);
		dispatcher.Dispatch<Pulio::MouseButtonClickedEvent>(FN_BIND_1_ARG(TestLayer, TestClickHandler));
		dispatcher.Dispatch<Pulio::WindowClosedEvent>(FN_BIND_1_ARG(TestLayer, WindowCloseHandler));
	}
	virtual void OnUpdate() override{}

private:
	bool TestClickHandler(Pulio::MouseButtonClickedEvent& mbcEvent) { PULIO_LOG_INFO("CLICK"); return true; }
	bool WindowCloseHandler(Pulio::WindowClosedEvent& mbcEvent) { PULIO_LOG_INFO("window closed"); return true; }
};