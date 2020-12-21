#pragma once

#include "Pulio/Core.h"
#include "Event.h"

namespace Pulio {

	// event raised whenever the mouse has moved
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const float& xPos, const float& yPos)
			: m_xPos(xPos), m_yPos(yPos) { }

		virtual EventType GetEventType() const override { return EventType::MouseMoved; }
		static EventType GetEventTypeStatic() { return EventType::MouseMoved; }
		virtual EventClass GetClassType() const override { return EventClass::MouseEvent; }
		virtual const char* GetEventName() const override { return "MouseMovedEvent"; }

		float GetXPosition() const { return m_xPos; }
		float GetYPosition() const { return m_yPos; }

		virtual std::string ToString() const override
		{ 
			std::stringstream ss;
			ss << GetEventName() << ": (" << m_xPos << ", " << m_yPos << ")" << std::endl;
			return ss.str(); 
		}

	private:
		float m_xPos, m_yPos;
	};

	// event raised whenever the mouse scrolled
	class MouseScrolledEvent: public Event
	{
	public:
		MouseScrolledEvent(const float& scrollOffset)
			: m_scrollOffset(scrollOffset) { }

		virtual EventType GetEventType() const override { return EventType::MouseScrolled; }
		static EventType GetEventTypeStatic() { return EventType::MouseScrolled; }
		virtual EventClass GetClassType() const override { return EventClass::MouseEvent; }
		virtual const char* GetEventName() const override { return "MouseScrolledEvent"; }

		float GetOffset() const { return m_scrollOffset; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetEventName() << ": (" << m_scrollOffset << ")" << std::endl;
			return ss.str();
		}

	private:
		float m_scrollOffset;
	};

	// event raised whenever a mouse button was clicked
	class MouseButtonClickedEvent : public Event
	{
	public:
		MouseButtonClickedEvent(const int& buttonCode)
			: m_btnCode(buttonCode) { }

		virtual EventType GetEventType() const override { return EventType::MouseButtonClicked; }
		static EventType GetEventTypeStatic() { return EventType::MouseButtonClicked; }
		virtual EventClass GetClassType() const override { return EventClass::MouseEvent; }
		virtual const char* GetEventName() const override { return "MouseButtonClickedEvent"; }

		int GetButtonCode() const { return m_btnCode; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetEventName() << ": (" << m_btnCode << ")" << std::endl;
			return ss.str();
		}

	private:
		float m_btnCode;
	};

	// event raised whenever a clicked mouse button was released
	class MouseButtonReleasedEvent : public Event
	{
	public:
		MouseButtonReleasedEvent(const int& buttonCode)
			: m_btnCode(buttonCode) { }

		virtual EventType GetEventType() const override { return EventType::MouseButtonReleased; }
		static EventType GetEventTypeStatic() { return EventType::MouseButtonReleased; }
		virtual EventClass GetClassType() const override { return EventClass::MouseEvent; }
		virtual const char* GetEventName() const override { return "MouseButtonReleasedEvent"; }

		int GetButtonCode() const { return m_btnCode; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetEventName() << ": (" << m_btnCode << ")" << std::endl;
			return ss.str();
		}

	private:
		float m_btnCode;
	};
}