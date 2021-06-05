#include "GameEnv.h"

#include "Time.h"
#include "RenderingManager.h"
#include "ResourceManager.h"
#include "PhysicsManager.h"

//Main loop flag
bool quit = false;
static GameEnv* s_instance;

//Event handler
SDL_Event e;

bool GameEnv::init()
{
	std::cout << "Initializing GameEnv..." << std::endl;
	s_instance = this;
	_scenes = std::list<Scene*>();

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		GameEnv::init_modules();
	}

	std::cout << "Initialization: " << success << std::endl;
	return success;
}


void GameEnv::close()
{
	std::cout << "Quitting GameEnv..." << std::endl;

	std::cout << "Exiting all scenes..." << std::endl;

	for (Scene* scene : _scenes)
	{
		delete scene;
	}
	_activeScene = nullptr;
	_scenes.clear();

	std::cout << "Cleaning..." << std::endl;

	GameEnv::clean_modules();

	//Quit SDL subsystems
	SDL_Quit();
}

void GameEnv::init_modules()
{
	_timer = Time();
	_resMgr = new ResourceManager();
	_renderingMgr = new RenderingManager();
	_physicsMgr = new PhysicsManager();
}

void GameEnv::clean_modules() const
{
	delete _renderingMgr;
	delete _resMgr;
	delete _physicsMgr;
}

void GameEnv::update_main_thread() const
{
	_timer.refresh();

	for (Scene* scene : _scenes)
	{
		scene->main_thread_update();
	}

	_renderingMgr->update();
	_physicsMgr->update_physics();

	if (_capFps)
	{
		const float frame_delay = (1.0f / _targetFps) - _timer.curr_frame_duration();
		if (frame_delay > 0)
		{
			SDL_Delay(static_cast<Uint32>(frame_delay * 1000.0f));
		}
	}
}

GameEnv::GameEnv()
{
	init();
}

GameEnv* GameEnv::get_instance()
{
	return s_instance;
}

Scene* GameEnv::get_active_scene() const
{
	return _activeScene;
}

RenderingManager* GameEnv::get_rendering_manager() const
{
	return _renderingMgr;
}

ResourceManager* GameEnv::get_res_manager() const
{
	return _resMgr;
}

PhysicsManager* GameEnv::get_physics_manager() const
{
	return _physicsMgr;
}

void GameEnv::run() {
	std::cout << "Running GameEnv..." << std::endl;
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			////Apply the image
			//SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

			////Update the surface
			//SDL_UpdateWindowSurface(gWindow);
		}
		update_main_thread();
	}
	//Free resources and close SDL
	close();
}

void GameEnv::create_empty_scene()
{
	auto scene = new Scene();
	if (_scenes.empty())
	{
		_activeScene = scene;
	}
	_scenes.push_back(scene);
}