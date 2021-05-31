#pragma once
#include "GameObject.h"

class Scene
{
private:
	std::list<std::unique_ptr<GameObject>> _gameObjects;
public:
	Scene();
	void main_thread_update();
	GameObject* create_game_object(const std::string& name = "New GameObject");
	void add_game_object_to_scene(std::unique_ptr<GameObject>& go_ref);
	static void moveGameObjectToScene(GameObject* goRef, Scene& targetScene);
};
