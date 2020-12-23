//#include <Pulio.h>
//
//#include "TestLayer.h"
//
//void TestLayer::OnAttach()
//{
//	//PULIO_LOG_INFO("Attached layer: {0}", GetName());
//}
//
//void TestLayer::OnDetach()
//{
//
//}
//
//void TestLayer::OnEvent(Pulio::Event& event)
//{
//	//Pulio::EventDispatcher dispatcher(event);
//	//dispatcher.Dispatch<Pulio::MouseButtonClickedEvent>(std::bind(&TestLayer::TestClickHandler, this, std::placeholders::_1));
//	//dispatcher.Dispatch<Pulio::MouseButtonClickedEvent>(FN_BIND_1_ARG(TestLayer, TestClickHandler));
//}
//
//void TestLayer::OnUpdate()
//{
//
//}
//
//bool TestLayer::TestClickHandler(Pulio::MouseButtonClickedEvent& mbcEvent)
//{
//	//PULIO_LOG_INFO("Mouse button was clicked");
//	return true;
//}