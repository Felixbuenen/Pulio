#pragma once

#include "Core.h"

#include "Window.h"
#include "Pulio/LayerStack.h"
#include "Pulio/Event/WindowEvent.h"
#include "Pulio/Event/Event.h"
#include "Pulio/Layer.h"

namespace Pulio {

	class PULIO_API Application
	{
	public:
		Application();
		~Application();

		void Run();
		void PushLayer(Layer* layer);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_running;
		std::unique_ptr<LayerStack> m_layerStack;

		void OnEvent(Event& e);
		bool OnWindowCloseEvent(WindowClosedEvent& e);
	};

	Application* CreateApplication();

}