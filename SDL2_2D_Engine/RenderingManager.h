#pragma once
#include "Renderer.h"
#include <memory>
#include <list>
#include <algorithm>

using RenderersList_t = std::list<Renderer*>;

class RenderingManager
{
private:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	const int ERR_INITIALIZATION = 1;

	RenderersList_t _renderers;
	SDL_Renderer* _renderer;
	SDL_Window* _gWindow;
public:
	void registerRenderer(Renderer* renderer);
	void unregisterRenderer(Renderer* renderer);
	void update();
	SDL_Renderer* get_renderer();

	RenderingManager();
	~RenderingManager();
};
