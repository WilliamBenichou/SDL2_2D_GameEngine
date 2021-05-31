#pragma once
#include <SDL.h>
#include <cstdlib>
#include <stdio.h>
#include "GameEnv.h"
#include <SDL_image.h>
#include "GameObject.h"
#include "SpriteRenderer.h"
#include <iostream>
#include <memory>
#include "TestMoveComponent.h"

int main(int argc, char* args[])
{
	GameEnv gameEnv = GameEnv();

	gameEnv.create_empty_scene();

	{
		const std::shared_ptr<Sprite> testSprite = Sprite::load("Res/test_sprite.png");

		for (int i = 0; i < 10; ++i)
		{
			GameObject* testGo = gameEnv.get_active_scene()->create_game_object();

			Vector3F pos = Vector3F();
			pos.y = i * 32;

			testGo->setPosition(pos);
			auto spriteRdr = testGo->addComponent<SpriteRenderer>();
			testGo->addComponent<TestMoveComponent>();

			spriteRdr->setSprite(testSprite);
		}
	}

	gameEnv.run();

	return 0;
}