#include "plpch.h"
#include "WindowsWindow.h"

#include "GLFW/glfw3.h"

#include "Pulio/Log.h"
#include "Pulio/Event/KeyEvent.h"
#include "Pulio/Event/MouseEvent.h"
#include "Pulio/Event/WindowEvent.h"

namespace Pulio {

	Window* Window::CreateNewWindow(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props) 
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		OnClose();
	}

	void WindowsWindow::Init(const WindowProperties& props) 
	{
		PULIO_LOG_INFO("Initializing WindowsWindow...");

		// set properties
		m_WindowProps.Title = props.Title;
		m_WindowProps.Width = props.Width;
		m_WindowProps.Height = props.Height;

		// by default, set vsync to be true
		SetVSync();

		// TODO: create windows window
		if (!glfwInit())
		{
			// TODO: error handling
			return;
		}

		// TODO: set error handler (?)

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), NULL, NULL);
		if (!m_Window)
		{
			// Window or OpenGL context creation failed
			PULIO_LOG_ERROR("Failed to initialize GLFW window.");
			// TODO: error handling
		}

		glfwMakeContextCurrent(m_Window);

		// TODO: initialize glad

		PULIO_LOG_INFO("Succesfully opened GLFW window!");
	}

	void WindowsWindow::OnClose()
	{
		delete glfwGetWindowUserPointer(m_Window);
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void WindowsWindow::SetCallbackMethod(const WindowEventCallback& callbackMethod)
	{
		// TODO: assert there is a window

		WindowsWindowCallbackData* data = new WindowsWindowCallbackData(this, callbackMethod);
		glfwSetWindowUserPointer(m_Window, reinterpret_cast<void*>(data));

		// window events
		glfwSetWindowCloseCallback(m_Window, WindowsWindow::WindowClosedHandler);
		glfwSetWindowSizeCallback(m_Window, WindowsWindow::WindowResizedHandler);
		//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		glfwSetWindowPosCallback(m_Window, WindowsWindow::WindowPositionHandler);

		// key event
		glfwSetKeyCallback(m_Window, WindowsWindow::KeyInputHandler);

		// mouse events
		glfwSetMouseButtonCallback(m_Window, WindowsWindow::MouseButtonHandler);
		glfwSetCursorPosCallback(m_Window, WindowsWindow::CursorMovedHandler);
		glfwSetScrollCallback(m_Window, WindowsWindow::MouseScrolledHandler);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	// ----------------- event handlers ----------------------------------------------------------------------------------------
	void WindowsWindow::WindowClosedHandler(GLFWwindow* window)
	{
		WindowsWindowCallbackData* clbData = reinterpret_cast<WindowsWindowCallbackData*>(glfwGetWindowUserPointer(window));

		// call user callback method with window closed event
		WindowClosedEvent e;
		clbData->callback(e);
	}

	void WindowsWindow::WindowResizedHandler(GLFWwindow* window, int width, int height)
	{
		WindowsWindowCallbackData* clbData = reinterpret_cast<WindowsWindowCallbackData*>(glfwGetWindowUserPointer(window));

		// call user callback method with window resized event	
		WindowResizedEvent e(width, height);
		clbData->callback(e);
	}

	void WindowsWindow::WindowPositionHandler(GLFWwindow* window, int xpos, int ypos)
	{
		WindowsWindowCallbackData* clbData = reinterpret_cast<WindowsWindowCallbackData*>(glfwGetWindowUserPointer(window));

		// call user callback method with window moved event
		WindowMovedEvent e(xpos, ypos);
		clbData->callback(e);
	}

	void WindowsWindow::KeyInputHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		WindowsWindowCallbackData* clbData = reinterpret_cast<WindowsWindowCallbackData*>(glfwGetWindowUserPointer(window));

		// call user callback method with key pressed/released event
		if (action == GLFW_PRESS)
		{
			KeyPressedEvent e(key);
			clbData->callback(e);
		}
		else if (action == GLFW_RELEASE)
		{
			KeyReleasedEvent e(key);
			clbData->callback(e);
		}

		// TODO: add some modifier handling
	}


	void WindowsWindow::MouseButtonHandler(GLFWwindow* window, int button, int action, int mods)
	{
		WindowsWindowCallbackData* clbData = reinterpret_cast<WindowsWindowCallbackData*>(glfwGetWindowUserPointer(window));

		// call user callback method with mouse button pressed/released event
		if (action == GLFW_PRESS)
		{
			MouseButtonClickedEvent e(button);
			clbData->callback(e);
		}
		else if (action == GLFW_RELEASE)
		{
			MouseButtonReleasedEvent e(button);
			clbData->callback(e);
		}

		// TODO: add some modifier handling
	}

	void WindowsWindow::CursorMovedHandler(GLFWwindow* window, double xpos, double ypos)
	{
		WindowsWindowCallbackData* clbData = reinterpret_cast<WindowsWindowCallbackData*>(glfwGetWindowUserPointer(window));
		
		// call user callback method with mouse moved event
		MouseMovedEvent e(xpos, ypos);
		clbData->callback(e);
	}

	void WindowsWindow::MouseScrolledHandler(GLFWwindow* window, double xoffset, double yoffset)
	{
		WindowsWindowCallbackData* clbData = reinterpret_cast<WindowsWindowCallbackData*>(glfwGetWindowUserPointer(window));
		
		// call user callback method with mouse scrolled event
		MouseScrolledEvent e(yoffset); // for now only support yoffset
		clbData->callback(e);
	}

}