#pragma once

#include "Pulio/Core.h"
#include "Event.h"

#include <sstream>

namespace Pulio {

	// event raised whenever the window gets resized
	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(const float& w, const float& h) 
			: m_width(w), m_height(h) { }

		virtual EventType GetEventType() const override { return EventType::WindowResized; }
		static EventType GetEventTypeStatic() { return EventType::WindowResized; }
		virtual EventClass GetClassType() const override { return EventClass::WindowEvent; }
		virtual const char* GetEventName() const override { return "WindowResizedEvent"; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetEventName() << ": (" << m_width << ", " << m_height << ")" << std::endl;
			return ss.str();
		}

		float GetWidth() const { return m_width; }
		float GetHeight() const { return m_height; }

	private:
		float m_width, m_height;
	};

	// event raised whenever the window is closed
	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() {}

		virtual EventType GetEventType() const override { return EventType::WindowClosed; }
		static EventType GetEventTypeStatic() { return EventType::WindowClosed; }
		virtual EventClass GetClassType() const override { return EventClass::WindowEvent; }
		virtual const char* GetEventName() const override { return "WindowClosedEvent"; }
	};

	// event raised whenever the window is closed
	class WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(const float& xOffset, const float& yOffset) 
			: m_xOffset(xOffset), m_yOffset(yOffset) { }

		virtual EventType GetEventType() const override { return EventType::WindowMoved; }
		static EventType GetEventTypeStatic() { return EventType::WindowMoved; }
		virtual EventClass GetClassType() const override { return EventClass::WindowEvent; }
		virtual const char* GetEventName() const override { return "WindowMovedEvent"; }

		float GetXOffset() const { return m_xOffset; }
		float GetYOffset() const { return m_yOffset; }

	private:
		float m_xOffset, m_yOffset;
	};
}