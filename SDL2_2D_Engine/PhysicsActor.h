#pragma once
#include <list>

#include "Component.h"

class Collider;

class PhysicsActor : public Component
{

	std::list<Collider*> _colliders;
	
public:
	void on_enable() override;
	void on_disable() override;
	
	void update_physics();
};

