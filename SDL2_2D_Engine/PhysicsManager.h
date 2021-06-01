#pragma once
#include <list>

#include "PhysicsActor.h"

class PhysicsManager
{
private:
	std::list<PhysicsActor*> _actors;
public:
	void register_actor(PhysicsActor* a_actor);
	void unregister_actor(PhysicsActor* a_actor);
	void update_physics();
	
};

