#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer()
{
	SpriteRenderer::_sprite = nullptr;
	SpriteRenderer::_depth = 0;
}

void SpriteRenderer::on_enable()
{
	Renderer::on_enable();
	GameEnv::getInstance()->getRenderingManager()->registerRenderer(this);
}

void SpriteRenderer::on_disable()
{
	Renderer::on_disable();
	GameEnv::getInstance()->getRenderingManager()->unregisterRenderer(this);
}

void SpriteRenderer::render(SDL_Renderer* target)
{
	if (_sprite != nullptr) {
		auto pos = _parentGo->getPosition();
		SDL_Rect rect = SDL_Rect();
		rect.x = pos.x;
		rect.y = pos.y;
		rect.w = 32;
		rect.h = 32;

		SDL_RenderCopy(target, _sprite->get_texture(), nullptr, &rect);
	}
}

void SpriteRenderer::setSprite(std::shared_ptr<Sprite> sprite)
{
	_sprite = sprite;
}