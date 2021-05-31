#include "Texture.h"

Texture::Texture(SDL_Texture* a_tex)
{
	_texture = a_tex;
}

Texture::~Texture()
{
	SDL_DestroyTexture(_texture);
}

SDL_Texture* Texture::getSdlTexture() const
{
	return _texture;
}