#pragma once

#include "plpch.h"

#include "Event/Event.h"

namespace Pulio {

	class Layer
	{
	public:
		Layer(std::string name = "Layer") 
			: m_name(name) { }
		~Layer() { }

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;

		virtual void OnEvent(Event& event) = 0;
		virtual void OnUpdate() = 0;

		std::string GetName() const { return m_name; }

	private:
		std::string m_name;
	};

}