#pragma once
#include <chrono>
#include <iostream>
class Time
{
public:
	Time();
	void refresh() const;
	static float delta_time();
};
