#include "plpch.h"
#include "Application.h"

#include "Log.h"
#include "Event/Event.h"
#include "Event/WindowEvent.h"
#include "Window.h"

#include "GLFW/glfw3.h"

namespace Pulio {

	Application::Application()
	{
		PULIO_LOG_WARNING("Starting the application...");

		m_running = true;

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
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(std::bind(&Application::OnWindowCloseEvent, this, std::placeholders::_1));
	}

	bool Application::OnWindowCloseEvent(WindowClosedEvent& e)
	{
		m_running = false;
		return true;
	}
}