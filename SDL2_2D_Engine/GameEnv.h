#pragma once
#include <SDL.h>
#include <stdio.h>
#include "RenderingManager.h"
#include "Scene.h"
#include "Time.h"

class GameEnv
{
private:

	//The image we will load and show on the screen
	SDL_Surface* gHelloWorld = NULL;

	RenderingManager* _renderingMgr;

	std::list<Scene* > _scenes;
	Scene* _activeScene = nullptr;
	Time _timer;

	bool loadMedia();
	void close();
	void initModules();
	void clean_modules() const;
	void update_main_thread() const;
public:

	GameEnv();
	~GameEnv();

	static GameEnv* getInstance();
	Scene* get_active_scene() const;
	RenderingManager* getRenderingManager() const { return _renderingMgr; }
	bool init();
	void run();
	void create_empty_scene();
};
