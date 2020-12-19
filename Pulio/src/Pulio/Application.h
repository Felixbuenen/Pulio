#pragma once

#include "Core.h"

namespace Pulio {
	
	class PULIO_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	Application* CreateApplication();

}