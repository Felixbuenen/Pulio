#include "plpch.h"

#include "LayerStack.h"
#include "Core/Log.h"

namespace Pulio {

	LayerStack::LayerStack() { }

	LayerStack::~LayerStack()
	{
		PULIO_LOG_WARNING("Deleting layerstack...");
		// delete all layers
		for (auto l : m_layers)
		{
			delete l;
		}
		m_layers.clear();
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_layers.emplace_back(layer);

		layer->OnAttach();
	}

	void LayerStack::PopLayer()
	{
		Layer* layer = m_layers.back();
		layer->OnDetach();

		m_layers.pop_back();
	}

}

