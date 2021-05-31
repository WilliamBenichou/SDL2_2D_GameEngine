#include "GameEnv.h"

#include "Time.h"

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
		GameEnv::initModules();
	}

	std::cout << "Initialization: " << success << std::endl;
	return success;
}

GameEnv::~GameEnv()
{
	for (Scene* scene : _scenes)
	{
		delete scene;
	}
	_activeScene = nullptr;
	_scenes.clear();
}

void GameEnv::close()
{
	std::cout << "Quitting GameEnv..." << std::endl;

	std::cout << "Exiting all scenes..." << std::endl;

	for (Scene* scene : _scenes)
	{
		delete scene;
	}

	std::cout << "Cleaning..." << std::endl;

	GameEnv::clean_modules();

	//Quit SDL subsystems
	SDL_Quit();
}

void GameEnv::initModules()
{
	_timer = Time();
	_renderingMgr = new RenderingManager();
}

void GameEnv::clean_modules() const
{
	delete _renderingMgr;
}

void GameEnv::update_main_thread() const
{
	_timer.refresh();

	for (Scene* scene : _scenes)
	{
		scene->main_thread_update();
	}

	_renderingMgr->update();
}

GameEnv::GameEnv()
{
	init();
}

GameEnv* GameEnv::getInstance()
{
	return s_instance;
}

Scene* GameEnv::get_active_scene() const
{
	return _activeScene;
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