#pragma once

#include "Core.h"

#include "Window.h"

namespace Pulio {
	
	class Event;
	class WindowClosedEvent;

	class PULIO_API Application
	{
	public:
		Application();
		~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_running;

		void OnEvent(Event& e);
		bool OnWindowCloseEvent(WindowClosedEvent& e);
	};

	Application* CreateApplication();

}