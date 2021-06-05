#pragma once
#include <list>

#include "Component.h"
#include "GameEnv.h"
#include "PhysicsManager.h"

class Collider;

class PhysicsActor : public Component
{

	std::list<Collider*> _colliders;
	PhysicsManager* _physicsMgr = nullptr;

public:
	void on_added() override;
	void on_enable() override;
	void on_disable() override;
	
	void update_physics();
};

