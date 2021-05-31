#include "Sprite.h"

Sprite::Sprite(SDL_Texture* tex)
{
	_tex = tex;
}

Sprite::~Sprite()
{
	if (_tex != nullptr)
	{
		SDL_DestroyTexture(_tex);
		_tex = nullptr;
	}
}

std::shared_ptr<Sprite> Sprite::load(const std::string& path)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface != nullptr)
	{
		SDL_Renderer* renderer = GameEnv::getInstance()->getRenderingManager()->get_renderer();
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		if (texture != nullptr)
		{
			return std::make_shared<Sprite>(texture);
		}
		else
		{
			std::cerr << "Unable to load Sprite (step: SDL_Texture creation)" << std::endl << "ERR: " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(surface);
	}
	else
	{
		std::cerr << "Unable to load Sprite (step: SDL_Surface loading) at path: " << path << std::endl << "ERR: " << IMG_GetError() << std::endl;
	}
	return nullptr;
}

SDL_Texture* Sprite::get_texture() const
{
	return _tex;
}