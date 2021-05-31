#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	_resources = std::map<std::string, std::weak_ptr<Resource>>();
}

std::shared_ptr<Texture> ResourceManager::load_texture(const std::string& a_path)
{
	const std::string path = TEXTURE_KEY + a_path;

	auto preloaded_tex = get_res_if_loaded<Texture>(path);
	if (preloaded_tex != nullptr)
	{
		return preloaded_tex;
	}

	SDL_Surface* surface = IMG_Load(a_path.c_str());
	if (surface != nullptr)
	{
		SDL_Renderer* renderer = GameEnv::getInstance()->get_rendering_manager()->get_renderer();
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		if (texture != nullptr)
		{
			auto shrd_tex = std::make_shared<Texture>(texture);
			_resources.emplace(path, shrd_tex);
			return shrd_tex;
		}
		else
		{
			std::cerr << "Unable to load Sprite (step: SDL_Texture creation)" << std::endl << "ERR: " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(surface);
	}
	else
	{
		std::cerr << "Unable to load Sprite (step: SDL_Surface loading) at path: " << a_path << std::endl << "ERR: " << IMG_GetError() << std::endl;
	}
	return nullptr;
}

std::shared_ptr<Sprite> ResourceManager::load_sprite(const std::string& a_path)
{
	const std::string path = SPRITE_KEY + a_path;

	auto preloaded_sprite = get_res_if_loaded<Sprite>(path);
	if (preloaded_sprite != nullptr)
	{
		return preloaded_sprite;
	}

	std::shared_ptr<Texture> texPtr = load_texture(a_path);
	if (texPtr != nullptr)
	{
		auto sprite = std::make_shared<Sprite>(texPtr);
		_resources.emplace(SPRITE_KEY + a_path, sprite);
		return sprite;
	}
	else
	{
		std::cerr << "Unable to load Sprite" << std::endl;
	}

	return nullptr;
}