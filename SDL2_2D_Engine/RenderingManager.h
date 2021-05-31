#pragma once
#include "Renderer.h"
#include <memory>
#include <list>
#include <algorithm>

#include "Camera.h"

using RenderersList_t = std::list<Renderer*>;

class RenderingManager
{
private:

	RenderersList_t _renderers;
	SDL_Renderer* _renderer;
	SDL_Window* _gWindow;

	std::list<Camera*> _cameras;

public:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	void registerRenderer(Renderer* renderer);
	void unregisterRenderer(Renderer* renderer);
	void update() const;
	SDL_Renderer* get_renderer() const;
	void register_active_camera(Camera* a_camera);
	void unregister_active_camera(Camera* a_camera);

	RenderingManager();
	~RenderingManager();
};
