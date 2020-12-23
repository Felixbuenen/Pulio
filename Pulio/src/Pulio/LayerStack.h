#pragma once

#include "Layer.h"

namespace Pulio {
	
	class LayerStack
	{
	public:
		typedef std::vector<Layer*>::const_iterator LayerStackIterator;
		typedef std::vector<Layer*>::reverse_iterator LayerStackReverseIterator;

		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer();

		inline LayerStackIterator Begin()			{ return m_layers.begin(); }
		inline LayerStackIterator End()				{ return m_layers.end();  }
		inline LayerStackReverseIterator RBegin()	{ return m_layers.rbegin(); }
		inline LayerStackReverseIterator REnd()		{ return m_layers.rend(); }

	private:
		std::vector<Layer*> m_layers;
	};

}
