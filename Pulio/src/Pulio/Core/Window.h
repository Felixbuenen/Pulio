#pragma once

#include "plpch.h"

#include "Core.h"
#include "Pulio/Event/event.h"

namespace Pulio {

	struct WindowProperties
	{
		std::string Title;
		int Width, Height;

		WindowProperties() = default;
		WindowProperties(const std::string& title, const int& width, const int& height)
			: Title(title), Width(width), Height(height) { }
	};

	class Window 
	{
	public:
		// function definition for handling window events
		using WindowEventCallback = std::function<void(Event&)>;

		// properties
		virtual std::string GetTitle() const = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual bool GetVSync() const = 0;

		// attribute setters
		virtual void Init(const WindowProperties& props) = 0;
		virtual void OnClose() = 0;
		virtual void SetCallbackMethod(const WindowEventCallback& callbackMethod) = 0;
		virtual void SetVSync(bool setVSync = true) = 0;

		virtual void OnUpdate() = 0;

		// creates a platform-specific window based on build configurations
		static Window* CreateNewWindow(const WindowProperties& props);
	};

}