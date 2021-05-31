#pragma once
#include <memory>
#include <string>
#include <SDL_image.h>
#include <iostream>

#include "GameEnv.h"
#include "RenderingManager.h"

class Sprite
{
private:
	SDL_Texture* _tex = nullptr;

public:
	Sprite(SDL_Texture* tex);
	~Sprite();
	static std::shared_ptr<Sprite> load(const std::string& path);
	SDL_Texture* get_texture() const;
};
