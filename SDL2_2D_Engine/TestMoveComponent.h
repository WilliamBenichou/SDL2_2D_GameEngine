#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Time.h"

class TestMoveComponent :
	public Component
{
public:
	void on_manage() override;
};
