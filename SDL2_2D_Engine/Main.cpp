#pragma once

#include <cstdlib>
#include "EngineCore.h"

#include "TestMoveComponent.h"
#include "ResourceManager.h"

int main(int argc, char* args[])
{
	GameEnv gameEnv = GameEnv();

	gameEnv.create_empty_scene();

	{
		const std::shared_ptr<Sprite> testSprite = gameEnv.get_res_manager()->load_sprite("Res/test_sprite.png");

		GameObject* cameraGo = gameEnv.get_active_scene()->create_game_object();
		cameraGo->addComponent<Camera>();

		
		GameObject* testGo = gameEnv.get_active_scene()->create_game_object();

		auto spriteRdr = testGo->addComponent<SpriteRenderer>();
		testGo->addComponent<TestMoveComponent>();

		spriteRdr->setSprite(testSprite);

	}

	gameEnv.run();

	return 0;
}