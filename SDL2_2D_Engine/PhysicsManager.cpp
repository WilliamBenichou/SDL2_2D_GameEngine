#include "PhysicsManager.h"

#include "PhysicsActor.h"

PhysicsManager::PhysicsManager()
{
	_world = std::make_unique<b2World>(b2Vec2(0.0f, -9.81f));
}

void PhysicsManager::register_actor(PhysicsActor* a_actor)
{
	_actors.push_back(a_actor);
}

void PhysicsManager::unregister_actor(PhysicsActor* a_actor)
{
	const auto it = std::find(_actors.begin(), _actors.end(), a_actor);
	if (it != _actors.end())
	{
		_actors.erase(it);
	}
}

void PhysicsManager::update_physics()
{
	for (PhysicsActor* actor : _actors)
	{
		actor->update_physics();
	}
}

b2World* PhysicsManager::physics_world() const
{
	return _world.get();
}

