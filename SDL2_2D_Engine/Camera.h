﻿#pragma once

class Camera
{
private:
	float _size = 1.0f;
public:
	float get_size() const;
	void set_size(float a_size);
};