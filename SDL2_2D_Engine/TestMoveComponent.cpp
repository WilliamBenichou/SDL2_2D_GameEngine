#include "TestMoveComponent.h"

const float moveSpeed = 200.0f;

void TestMoveComponent::on_added()
{
	_keyStates = SDL_GetKeyboardState(nullptr);
}

void TestMoveComponent::on_manage()
{
	auto pos = _parentGo->getPosition();

	Vector2F input = Vector2F();
	if (_keyStates[SDL_SCANCODE_RIGHT])
	{
		input.x += 1;
	}
	if (_keyStates[SDL_SCANCODE_LEFT])
	{
		input.x -= 1;
	}
	if (_keyStates[SDL_SCANCODE_UP])
	{
		input.y += 1;
	}
	if (_keyStates[SDL_SCANCODE_DOWN])
	{
		input.y -= 1;
	}

	pos.x += moveSpeed * Time::delta_time() * input.x;
	pos.y += moveSpeed * Time::delta_time() * -input.y;
	_parentGo->setPosition(pos);
}