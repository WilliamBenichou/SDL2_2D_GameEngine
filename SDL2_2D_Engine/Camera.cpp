#include "Camera.h"
#include "GameEnv.h"
#include "RenderingManager.h"

void Camera::on_added()
{
	
	_renderingMgr = GameEnv::getInstance()->get_rendering_manager();
	_renderTex = SDL_CreateTexture(_renderingMgr->get_renderer(), SDL_PIXELFORMAT_ARGB32, SDL_TEXTUREACCESS_TARGET,
		_renderingMgr->SCREEN_WIDTH, _renderingMgr->SCREEN_HEIGHT);

	_renderer = _renderingMgr->get_renderer();
	Component::on_added();
}

void Camera::on_enable()
{
	Component::on_enable();
	_renderingMgr->register_active_camera(this);
}

void Camera::on_removed()
{
	Component::on_removed();
	SDL_DestroyTexture(_renderTex);
}

void Camera::on_disable()
{
	Component::on_disable();
	_renderingMgr->unregister_active_camera(this);
}

void Camera::render(const std::list<Renderer*>& a_renderers)
{
	SDL_SetRenderTarget(_renderer, _renderTex);
	SDL_RenderClear(_renderer);
	
	for (auto& renderer : a_renderers)
	{
		renderer->render(_renderer, this);
	}
	SDL_RenderPresent(_renderer);
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