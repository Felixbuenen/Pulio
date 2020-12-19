#pragma once

#ifdef PL_PLATFORM_WINDOWS
extern Pulio::Application* Pulio::CreateApplication();

int main()
{
	auto app = Pulio::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Pulio only supports windows!
#endif