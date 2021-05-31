#include "Scene.h"

Scene::Scene()
{
	_gameObjects = std::list<std::unique_ptr<GameObject>>();
}

void Scene::main_thread_update()
{
	for (auto const& go_element : _gameObjects)
	{
		go_element->update();
	}
}

GameObject* Scene::create_game_object(const std::string& name)
{
	auto go = std::make_unique<GameObject>(name);
	const auto raw_ptr = go.get();
	_gameObjects.push_back(std::move(go));
	return raw_ptr;
}

void Scene::add_game_object_to_scene(std::unique_ptr<GameObject>& go_ref)
{
	//todo Should check if already in another scene
	_gameObjects.push_back(std::move(go_ref));
}

void Scene::moveGameObjectToScene(GameObject* goRef, Scene& targetScene)
{
	if (goRef->_parentScene != nullptr)
	{
		//todo Move logic
	}
}