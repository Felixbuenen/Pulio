#pragma once

#include "Pulio/Core/Window.h"

struct GLFWwindow;

namespace Pulio {

	class WindowsWindow : public Window
	{
		struct WindowsWindowCallbackData
		{
			WindowsWindowCallbackData(WindowsWindow* w, const WindowEventCallback& c)
				: activeWindow(w), callback(c) { }

			WindowsWindow* activeWindow;
			WindowEventCallback callback;
		};

	public:
		WindowsWindow(const WindowProperties& props);
		~WindowsWindow();

		// properties
		virtual std::string GetTitle() const override { return m_WindowProps.Title; }
		virtual int GetWidth() const override { return m_WindowProps.Width; }
		virtual int GetHeight() const override { return m_WindowProps.Height; }
		virtual bool GetVSync() const override { return m_vSync; }

		// attribute setters
		virtual void Init(const WindowProperties& props) override;
		virtual void OnClose() override;

		virtual void SetCallbackMethod(const WindowEventCallback& callbackMethod) override;
		virtual void SetVSync(bool setVSync = true) override { m_vSync = setVSync; }

		virtual void OnUpdate() override;

	private:
		GLFWwindow* m_Window;
		WindowProperties m_WindowProps;
		bool m_vSync;

		// event handlers
		static void WindowClosedHandler(GLFWwindow* window);
		static void WindowResizedHandler(GLFWwindow* window, int width, int height);
		static void WindowPositionHandler(GLFWwindow* window, int xpos, int ypos);

		static void KeyInputHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void MouseButtonHandler(GLFWwindow*, int, int, int);
		static void CursorMovedHandler(GLFWwindow* window, double xpos, double ypos);
		static void MouseScrolledHandler(GLFWwindow* window, double xoffset, double yoffset);
	};

}
