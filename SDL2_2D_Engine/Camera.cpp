#include "Camera.h"
#include "GameEnv.h"
#include "RenderingManager.h"

void Camera::on_added()
{
	
	_renderingMgr = GameEnv::get_instance()->get_rendering_manager();

	_renderer = _renderingMgr->get_renderer();
	Component::on_added();
}

void Camera::on_enable()
{
	Component::on_enable();
	_renderingMgr->register_active_camera(this);
}

void Camera::on_disable()
{
	Component::on_disable();
	_renderingMgr->unregister_active_camera(this);
}

void Camera::render(const std::list<Renderer*>& a_renderers)
{
	
	for (auto& renderer : a_renderers)
	{
		renderer->render(_renderer, this);
	}
}

float Camera::get_size() const
{
	return _size;
}

float Camera::get_horizontal_size() const
{
	return getAspectRatio() * _size;
}

void Camera::set_size(const float a_size)
{
	_size = a_size;
}

float Camera::getAspectRatio() const
{
	return static_cast<float>(_renderingMgr->SCREEN_WIDTH) / static_cast<float>(_renderingMgr->SCREEN_HEIGHT);
}