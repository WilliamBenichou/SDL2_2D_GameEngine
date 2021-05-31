#include "RenderingManager.h"

void RenderingManager::registerRenderer(Renderer* renderer)
{
	_renderers.push_back(renderer);
}

void RenderingManager::unregisterRenderer(Renderer* renderer)
{
	auto iterator = std::find(_renderers.begin(), _renderers.end(), renderer);
	if (iterator != _renderers.end()) {
		_renderers.erase(iterator);
	}
}

void RenderingManager::update()
{
	SDL_RenderClear(_renderer);
	for each (Renderer * renderer in _renderers)
	{
		renderer->render(_renderer);
	}
	SDL_RenderPresent(_renderer);
}

SDL_Renderer* RenderingManager::get_renderer()
{
	return _renderer;
}

RenderingManager::RenderingManager()
{
	_renderers = RenderersList_t();
	_gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (_gWindow == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		throw ERR_INITIALIZATION;
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