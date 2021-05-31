#pragma once
#include "Component.h"
#include <concepts>
#include <cstddef>
#include "MathUtils.h"
#include <algorithm>
#include <concepts>
#include <list>
#include <memory>
#include "PtrExtensions.h"
#include <string>

class Scene;
using component_list_t = std::list<std::unique_ptr<Component>>;

class GameObject
{
	friend Scene;

private:
#pragma region Members
	component_list_t _components;
	std::string _name;
	Vector3F _position;
	Scene* _parentScene;
#pragma endregion
	GameObject() = delete;
public:

#pragma region Constructors and destructors
	GameObject(std::string name = "New GameObject");

	~GameObject();
#pragma endregion

#pragma region Methods
	void removeComponent(Component* componentRef);
#pragma endregion

#pragma region Getters - Setters
	std::string get_name() const;
	void set_name(std::string name);

	Vector3F getPosition() const;
	void setPosition(Vector3F pos);
#pragma endregion

#pragma region Templates defs
	template<class T>
	T* addComponent()
	{
		std::unique_ptr<T> componentInstance = std::make_unique<T>();
		componentInstance->setParentGo(this);
		T* rawPtr = componentInstance.get();

		static_cast<Component*>(rawPtr)->on_added();

		_components.push_back(std::move(componentInstance));
		return rawPtr;
	}

	template<class T>
	T* getComponent()
	{
		component_list_t::iterator resultIterator = std::find_if(
			_components.begin(),
			_components.end(),
			[](std::unique_ptr<Component>& c) {
				Component* base = c.get();
				T* derived = dynamic_cast<T*>(base);
				return derived != nullptr;
			});

		if (resultIterator == _components.end()) {
			return nullptr;
		}
		else {
			return *resultIterator;
		}
	}

	void update();
#pragma endregion
};
