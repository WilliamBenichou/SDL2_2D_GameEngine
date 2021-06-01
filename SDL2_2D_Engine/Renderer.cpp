#include "Renderer.h"

#include "GameEnv.h"

void Renderer::on_added()
{
	Component::on_added();
	_renderingMgr = GameEnv::get_instance()->get_rendering_manager();
}

void Renderer::on_enable()
{
	Component::on_enable();
}