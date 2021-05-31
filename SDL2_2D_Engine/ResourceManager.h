#pragma once
#include <memory>
#include <map>
#include <string>
#include "Resource.h"
#include "Sprite.h"
#include "Texture.h"

class ResourceManager
{
	const std::string TEXTURE_KEY = "TEX_";
	const std::string SPRITE_KEY = "SPR_";

	std::map<std::string, std::weak_ptr<Resource>> _resources;

	template <class T>
	std::shared_ptr<T> get_res_if_loaded(const std::string& a_fullKey);

public:
	ResourceManager();
	std::shared_ptr<Texture> load_texture(const std::string& a_path);
	std::shared_ptr<Sprite> load_sprite(const std::string& a_path);
};

template <class T>
std::shared_ptr<T> ResourceManager::get_res_if_loaded(const std::string& a_fullKey)
{
	const auto it = _resources.find(a_fullKey);
	if (it != _resources.end())
	{
		const auto wk_ptr = _resources[a_fullKey];
		const std::shared_ptr<Resource> shared_ptr = wk_ptr.lock();
		if (shared_ptr != nullptr)
		{
			return std::dynamic_pointer_cast<T>(shared_ptr);
		}
		else
		{
			_resources.erase(it);
		}
	}
	return nullptr;
}
