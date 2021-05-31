#include "Component.h"

void Component::on_added()
{
	//std::cout << "Component created" << std::endl;
	on_enable();
}

void Component::on_removed()
{
	on_disable();
	//std::cout << "Component destroyed" << std::endl;
}

GameObject* Component::getParent()
{
	return _parentGo;
}

void Component::setParentGo(GameObject* parent)
{
	_parentGo = parent;
}