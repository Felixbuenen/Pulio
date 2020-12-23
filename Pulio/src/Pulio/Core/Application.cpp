#include "plpch.h"
#include "Application.h"

#include "Log.h"
#include "Pulio/Event/Event.h"
#include "Pulio/Event/WindowEvent.h"
#include "Window.h"
#include "Pulio/Layer.h"

#include "GLFW/glfw3.h"

namespace Pulio {

	Application::Application()
	{
		PULIO_LOG_WARNING("Starting the application...");

		m_running = true;
		m_layerStack = std::unique_ptr<LayerStack>(new LayerStack());

		// initialize window and bind event handling
		WindowProperties props("Pulio Game Engine", 1280, 720);
		m_Window = std::unique_ptr<Window>(Window::CreateNewWindow(props));
		m_Window->SetCallbackMethod(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}
	Application::~Application()
	{
		PULIO_LOG_CRITICAL("DESTRUCTION");
	}

	void Application::Run()
	{
		while (m_running)
		{
			glClearColor(.6, .1, .1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();

			// update layers
			for (auto rIt = m_layerStack->Begin(); rIt != m_layerStack->End(); ++rIt)
			{
				(*rIt)->OnUpdate();
			}
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_layerStack->PushLayer(layer);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(std::bind(&Application::OnWindowCloseEvent, this, std::placeholders::_1));

		// inform layers about events
		for (auto rIt = m_layerStack->RBegin(); rIt != m_layerStack->REnd(); ++rIt)
		{
			(*rIt)->OnEvent(e);
		}
	}

	bool Application::OnWindowCloseEvent(WindowClosedEvent& e)
	{
		m_running = false;
		return true;
	}
}