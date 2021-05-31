#include "Sprite.h"

Sprite::Sprite(const std::shared_ptr<Texture>& a_tex) {
	_tex = a_tex;

	Uint32 format;
	int w, h, access;

	const auto res = SDL_QueryTexture(_tex->getSdlTexture(), &format, &access, &w, &h);
	if (res >= 0)
	{
		_width = w;
		_height = h;
		_texFormat = format;
		_texAccess = access;

		Vector2F pp_unit_size;
		pp_unit_size.x = static_cast<float>(_width) / _pixelPerUnit;
		pp_unit_size.y = static_cast<float>(_height) / _pixelPerUnit;
		_pp_unit_size = pp_unit_size;
	}
	else
	{
		std::cerr << "There was an error loading texture info" << std::endl << SDL_GetError() << std::endl;
		
	}
}

Sprite::~Sprite()
= default;

std::shared_ptr<Texture> Sprite::get_texture() const
{
	return _tex;
}

float Sprite::get_pixel_per_unit() const
{
	return _pixelPerUnit;
}

void Sprite::set_pixel_per_unit(float a_pixelPerUnit)
{
	_pixelPerUnit = a_pixelPerUnit;
}