#pragma once
#include <ODVM.h>

class VulkanLayer : public ODVM::Layer
{
public:

	VulkanLayer();

	virtual void OnAttach();
	virtual void OnDetach();
	virtual void OnUpdate(ODVM::Timestep ts);
	virtual void OnImGuiRender();
	virtual void OnEvent(ODVM::Event& event);


};