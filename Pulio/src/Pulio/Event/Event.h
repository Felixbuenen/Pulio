#pragma once

#include "Pulio/Core.h"

#include <functional>
#include <iostream>

namespace Pulio {

	enum class EventType
	{
		None = 0,
		MouseMoved, MouseButtonClicked, MouseButtonReleased, MouseScrolled,
		KeyPressed, KeyReleased,
		WindowResized, WindowClosed, WindowMoved
	};

	enum class EventClass
	{
		None             = 0,
		ApplicationEvent = BIT(0), 
		WindowEvent      = BIT(1),
		InputEvent       = BIT(2),
		MouseEvent       = BIT(3),
		KeyEvent         = BIT(4)
	};

	class Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		static EventType GetEventTypeStatic() { return EventType::None; }
		virtual EventClass GetClassType() const = 0;
		virtual const char* GetEventName() const = 0;

		virtual std::string ToString() const { return GetEventName(); }
	};

	class EventDispatcher
	{
		template<typename T>
		using EventHandler = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event) 
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(EventHandler<T>& eventHandler)
		{
			// check if event handler type is same type as m_Event
			if (m_Event.GetEventType() == T::GetEventTypeStatic())
			{
				// cast Event to specific event type and execute function
				return eventHandler(static_cast<T>(m_event)); // static cast may not work. if not, replace with (*(T*)&m_event)
			}
		}

	private:
		Event& m_Event;
	};

	// todo: create a global function that can print Events in a << stream
	std::ostream& operator<<(std::ostream& output, const Event& e) {
		output << e.ToString();
		return output;
	}
}