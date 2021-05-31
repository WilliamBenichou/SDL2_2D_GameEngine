#pragma once
#include <chrono>
#include <iostream>
class Time
{
public:
	Time();
	void refresh() const;
	float curr_frame_duration() const;
	static float delta_time();
};
