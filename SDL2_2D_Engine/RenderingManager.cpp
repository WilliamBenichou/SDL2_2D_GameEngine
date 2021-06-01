#include "RenderingManager.h"

void RenderingManager::registerRenderer(Renderer* renderer)
{
	_renderers.push_back(renderer);
}

void RenderingManager::unregisterRenderer(Renderer* renderer)
{
	const auto iterator = std::find(_renderers.begin(), _renderers.end(), renderer);
	if (iterator != _renderers.end()) {
		_renderers.erase(iterator);
	}
}

void RenderingManager::update() const
{
	SDL_RenderClear(_renderer);
	for each (Camera* cam in _cameras)
	{
		cam->render(_renderers);
	}
	SDL_RenderPresent(_renderer);

}

SDL_Renderer* RenderingManager::get_renderer() const
{
	return _renderer;
}

void RenderingManager::register_active_camera(Camera* a_camera)
{
	_cameras.push_back(a_camera);
}

void RenderingManager::unregister_active_camera(Camera* a_camera)
{
	const auto it = std::find(_cameras.begin(), _cameras.end(), a_camera);
	if (it != _cameras.end())
	{
		_cameras.erase(it);
	}
}

RenderingManager::RenderingManager()
{
	_cameras = std::list<Camera*>();
	_renderers = RenderersList_t();
	_gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (_gWindow == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		throw std::exception("Initialization error");
	}
	else
	{
		//Get window surface
		_renderer = SDL_CreateRenderer(_gWindow, -1, SDL_RENDERER_ACCELERATED);
	}
}

RenderingManager::~RenderingManager()
{
	SDL_DestroyRenderer(_renderer);

	//Destroy window
	SDL_DestroyWindow(_gWindow);
	_gWindow = nullptr;
}