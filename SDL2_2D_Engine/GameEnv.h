#pragma once
#include <SDL.h>
#include <cstdio>

#include "Scene.h"
#include "Time.h"

class ResourceManager;
class RenderingManager;

class GameEnv
{
private:

	//The image we will load and show on the screen
	SDL_Surface* gHelloWorld = NULL;

	RenderingManager* _renderingMgr;
	ResourceManager* _resMgr;

	std::list<Scene* > _scenes;
	Scene* _activeScene = nullptr;
	Time _timer;

	bool _capFps = true;
	float _targetFps = 60.0f;

	void close();
	void init_modules();
	void clean_modules() const;
	void update_main_thread() const;
public:

	GameEnv();

	static GameEnv* get_instance();
	Scene* get_active_scene() const;
	RenderingManager* get_rendering_manager() const;
	ResourceManager* get_res_manager() const;
	bool init();
	void run();
	void create_empty_scene();
};
