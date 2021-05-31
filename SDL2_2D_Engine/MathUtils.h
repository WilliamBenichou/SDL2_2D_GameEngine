#pragma once

class MathUtils
{
	static float lerp(const float a, const float b, const float t);
};

inline float MathUtils::lerp(const float a, const float b, const float t)
{
	return (b - a) * t + a;
}

typedef struct {
	float x;
	float y;
} Vector2F;

typedef struct {
	float x;
	float y;
	float z;
} Vector3F;
