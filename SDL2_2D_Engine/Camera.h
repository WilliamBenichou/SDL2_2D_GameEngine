#pragma once
#include "Component.h"
#include <SDL.h>

#include "Renderer.h"

class RenderingManager;

class Camera : public Component
{
private:
	float _size = 5.0f;
	RenderingManager* _renderingMgr = nullptr;
	SDL_Renderer* _renderer = nullptr;

public:
	void on_added() override;
	void on_enable() override;
	void on_disable() override;
	void render(const std::list<Renderer*>& a_renderers);
	float get_size() const;
	float get_horizontal_size() const;
	void set_size(float a_size);
	float getAspectRatio() const;
};
