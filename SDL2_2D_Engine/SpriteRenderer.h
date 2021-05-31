#pragma once
#include "Renderer.h"
#include "GameEnv.h"
#include "RenderingManager.h"
#include "GameObject.h"
#include <memory>
#include "Camera.h"

#include "Sprite.h"

class SpriteRenderer :
	public Renderer
{
private:
	float _depth;
	std::shared_ptr<Sprite> _sprite;

public:
	SpriteRenderer();

	void on_enable() override;
	void on_disable() override;
	void render(SDL_Renderer* a_target, Camera* a_camera) override;

	void setSprite(std::shared_ptr<Sprite> sprite);
};
