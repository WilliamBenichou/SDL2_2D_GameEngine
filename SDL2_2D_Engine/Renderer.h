#pragma once
#include "Component.h"
#include <SDL.h>
class Renderer :
	public Component
{
public:

	void on_added() override;
	void on_enable() override;

	virtual void render(SDL_Renderer* target) = 0;
};
