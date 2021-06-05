#pragma once
#include <list>
#include <memory>

#include "box2d/box2d.h"

class PhysicsActor;

class PhysicsManager
{
private:
	std::list<PhysicsActor*> _actors;
	std::unique_ptr<b2World> _world;
public:

	PhysicsManager();
	void register_actor(PhysicsActor* a_actor);
	void unregister_actor(PhysicsActor* a_actor);
	void update_physics();
	b2World* physics_world() const;
	
};

