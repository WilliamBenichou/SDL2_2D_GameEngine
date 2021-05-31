#pragma once
#include "GameEnv.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include <SDL.h>
#include <SDL_image.h>

class Root
{
public:
	static void initContext(GameEnv* gameEnv);
};
