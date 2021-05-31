#include "GameObject.h"

GameObject::GameObject(std::string name)
{
	_name = name;
	_components = component_list_t();
	_parentScene = nullptr;
}

GameObject::~GameObject()
{
	for (auto&& component : _components) {
		component->on_removed();
	}
	_components.clear();
}

void GameObject::removeComponent(Component* componentRef)
{
	component_list_t::iterator resultIterator = std::find_if(
		_components.begin(),
		_components.end(),
		[&](std::unique_ptr<Component>& p) {
			return p.get() == componentRef;
		});

	if (resultIterator != _components.end()) {
		(*resultIterator)->on_removed();
		_components.erase(resultIterator);
	}
}

std::string GameObject::get_name() const
{
	return _name;
}

void GameObject::set_name(std::string name)
{
	_name = name;
}

Vector3F GameObject::getPosition() const
{
	return _position;
}

void GameObject::setPosition(Vector3F pos)
{
	_position = pos;
}

void GameObject::update()
{
	for (auto const& cp : _components)
	{
		cp->on_manage();
	}
}