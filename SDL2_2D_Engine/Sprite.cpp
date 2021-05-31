#include "Sprite.h"

Sprite::Sprite(const std::shared_ptr<Texture>& a_tex) {
	_tex = a_tex;
}

Sprite::~Sprite()
= default;

std::shared_ptr<Texture> Sprite::get_texture() const
{
	return _tex;
}