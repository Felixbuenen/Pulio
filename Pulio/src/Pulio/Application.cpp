#include "plpch.h"
#include "Application.h"

#include "Log.h"
#include "Event/Event.h"
#include "Event/WindowEvent.h"

namespace Pulio {

	Application::Application(){}
	Application::~Application(){}

	void Application::Run()
	{
		PULIO_LOG_WARNING("Starting the application...");

		WindowResizedEvent wre(1280, 720);
		if (wre.GetClassType() == EventClass::WindowEvent)
		{
			PULIO_LOG_INFO(wre);
		}

		while (true);
	}

}