#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer()
{
	SpriteRenderer::_sprite = nullptr;
	SpriteRenderer::_depth = 0;
}

void SpriteRenderer::on_enable()
{
	Renderer::on_enable();
	GameEnv::getInstance()->get_rendering_manager()->registerRenderer(this);
}

void SpriteRenderer::on_disable()
{
	Renderer::on_disable();
	GameEnv::getInstance()->get_rendering_manager()->unregisterRenderer(this);
}

void SpriteRenderer::render(SDL_Renderer* a_renderer, Camera* a_camera)
{
	if (_sprite != nullptr)
	{
		auto pos = _parentGo->getPosition();

		auto cameraPos = a_camera->getParent()->getPosition();
		auto cameraSize = Vector2F(a_camera->get_horizontal_size(), a_camera->get_size());
		Vector2F cameraFrustrumOrigin = Vector2F(cameraPos.x - cameraSize.x / 2, cameraPos.y - cameraSize.y / 2);
		
		Vector2F viewportPos;
		viewportPos.x = MathUtils::inverse_lerp(cameraFrustrumOrigin.x, cameraFrustrumOrigin.x + cameraSize.x, pos.x);
		viewportPos.y = MathUtils::inverse_lerp(cameraFrustrumOrigin.y, cameraFrustrumOrigin.y + cameraSize.y, pos.y);
		
		viewportPos.y = 1 - viewportPos.y; //SDL y origin is on top, we want the opposite for our game world

		//if in-screen
		if (viewportPos.x >= 0 && viewportPos.y <= 1 && viewportPos.y >= 0 && viewportPos.y <= 1)
		{
			const Vector2F sizeRelative = _sprite->pp_unit_size() / a_camera->get_size();
			const Vector2F pixelSize = sizeRelative * static_cast<float>(_renderingMgr->SCREEN_HEIGHT);


			const Vector2F pixelPos = viewportPos * Vector2F(static_cast<float>(_renderingMgr->SCREEN_WIDTH),
			                                                 static_cast<float>(_renderingMgr->SCREEN_HEIGHT));

			SDL_Rect rect;
			rect.x = static_cast<int>(pixelPos.x - pixelSize.x / 2);
			rect.y = static_cast<int>(pixelPos.y - pixelSize.y / 2);
			rect.w = static_cast<int>(pixelSize.x);
			rect.h = static_cast<int>(pixelSize.y);

			SDL_RenderCopy(a_renderer, _sprite->get_texture()->getSdlTexture(), nullptr, &rect);
		}
	}
}

void SpriteRenderer::setSprite(std::shared_ptr<Sprite> sprite)
{
	_sprite = sprite;
}
