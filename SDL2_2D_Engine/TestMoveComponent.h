#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Time.h"
#include <SDL.h>

class TestMoveComponent :
	public Component
{
	const Uint8* _keyStates;
public:
	void on_manage() override;
	void on_added() override;
};
