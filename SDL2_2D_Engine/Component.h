#pragma once
#include <iostream>
#include "PtrExtensions.h"

class GameObject;

class Component
{
protected:
	GameObject* _parentGo = nullptr;

public:
	virtual ~Component() = default;

	virtual void on_added();
	virtual void on_enable() {};
	virtual void on_disable() {};
	virtual void on_removed();
	virtual void on_manage() {};

	GameObject* getParent();

	void setParentGo(GameObject* parent);
};
