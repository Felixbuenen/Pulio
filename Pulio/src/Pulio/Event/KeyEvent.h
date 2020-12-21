#pragma once

#include "Pulio/Core.h"
#include "Event.h"

namespace Pulio {

	// abstract key event
	class KeyEvent : public Event
	{
	public:
		int GetKeyCode() const { return m_keyCode; }
		virtual EventClass GetClassType() const override { return EventClass::KeyEvent; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetEventName() << ": (" << m_keyCode << ")" << std::endl;
			return ss.str();
		}

	protected:
		KeyEvent(const int& keyCode)
			: m_keyCode(keyCode) { }

	protected:
		int m_keyCode;
	};

	// event raised whenever a key is pressed
	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const int& keyCode)
			:KeyEvent(keyCode) { }

		virtual EventType GetEventType() const override { return EventType::KeyPressed; }
		static EventType GetEventTypeStatic() { return EventType::KeyPressed; }
		virtual const char* GetEventName() const override { return "KeyPressedEvent"; }
	};

	// event raised whenever a pressed key is released
	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const int& keyCode)
			: KeyEvent(keyCode) { }

		virtual EventType GetEventType() const override { return EventType::KeyReleased; }
		static EventType GetEventTypeStatic() { return EventType::KeyReleased; }
		virtual const char* GetEventName() const override { return "KeyReleasedEvent"; }
	};

}