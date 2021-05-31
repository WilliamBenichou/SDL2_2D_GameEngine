#pragma once
#include <memory>
#include <string>
#include <SDL_image.h>
#include <iostream>

#include "GameEnv.h"
#include "RenderingManager.h"
#include "Resource.h"
#include "Texture.h"

class Sprite : public Resource
{
private:
	std::shared_ptr<Texture> _tex = nullptr;
public:
	explicit Sprite(const std::shared_ptr<Texture>& a_tex);
	~Sprite() override;
	std::shared_ptr<Texture> get_texture() const;
};
