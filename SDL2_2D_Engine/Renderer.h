#pragma once
#include "Component.h"
#include <SDL.h>

#include "GameEnv.h"

class Camera;

class Renderer :
	public Component
{
protected:
	RenderingManager* _renderingMgr = nullptr;
public:

	void on_added() override;
	void on_enable() override;

	virtual void render(SDL_Renderer* renderTex, Camera* camera) = 0;
};
