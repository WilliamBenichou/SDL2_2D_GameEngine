#pragma once
#include "Resource.h"
#include "SDL.h"

class Texture : public Resource
{
	SDL_Texture* _texture;
public:
	explicit Texture(SDL_Texture* a_tex);
	~Texture() override;

	SDL_Texture* getSdlTexture() const;
};
