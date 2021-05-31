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
	float _pixelPerUnit = 32;
	int _width;
	int _height;
	Uint32 _texFormat;
	int _texAccess;
	Vector2F _pp_unit_size;
public:
	explicit Sprite(const std::shared_ptr<Texture>& a_tex);
	~Sprite() override;
	std::shared_ptr<Texture> get_texture() const;

	float get_pixel_per_unit() const;

	void set_pixel_per_unit(float a_pixelPerUnit);

	int width() const
	{
		return _width;
	}

	int height() const
	{
		return _height;
	}

	Uint32 tex_format() const
	{
		return _texFormat;
	}

	int tex_access() const
	{
		return _texAccess;
	}

	Vector2F pp_unit_size() const
	{
		return _pp_unit_size;
	}
};
