#include "PhysicsActor.h"
#include "RenderingManager.h"

void PhysicsActor::on_added()
{
	Component::on_added();
	_physicsMgr = GameEnv::get_instance()->get_physics_manager();
}

void PhysicsActor::on_enable()
{
	Component::on_enable();
	_physicsMgr->register_actor(this);
}

void PhysicsActor::on_disable()
{
	_physicsMgr->unregister_actor(this);
	Component::on_disable();
}

void PhysicsActor::update_physics()
{
	
}
