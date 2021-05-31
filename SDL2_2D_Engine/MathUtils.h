#pragma once

struct Vector3F;

struct Vector2F {
	float x;
	float y;

	Vector2F()
		: x(0),
		y(0)
	{
	}
	
	Vector2F(float a_x, float a_y)
		: x(a_x),
		y(a_y)
	{
	}

	Vector2F operator+(Vector2F a) const
	{
		return { a.x + x,a.y + y };
	}

	Vector2F operator-(Vector2F a) const
	{
		return { x - a.x,y - a.y };
	}

	Vector2F operator*(Vector2F a) const
	{
		return { x * a.x,y * a.y };
	}

	Vector2F operator*(float a_scale) const
	{
		return { x * a_scale, y * a_scale };
	}

	Vector2F operator/(float a_scale) const
	{
		return { x / a_scale, y / a_scale };
	}
	operator Vector3F() const; // conversion function
};

struct Vector3F {
	float x;
	float y;
	float z;

	Vector3F()
		: x(0),
		y(0),
		z(0)
	{
	}
	
	Vector3F(float a_x, float a_y, float a_z)
		: x(a_x),
		y(a_y),
		z(a_z)
	{
	}

	Vector3F(float a_x, float a_y)
		: x(a_x),
		y(a_y),
		z(0)
	{
	}

	Vector3F operator+(Vector3F a) const
	{
		return { a.x + x,a.y + y , a.z + z };
	}

	Vector3F operator-(Vector3F a) const
	{
		return { x - a.x,y - a.y , z - a.z };
	}

	Vector3F operator*(Vector3F a) const
	{
		return { x * a.x,y * a.y , z * a.z };
	}

	operator Vector2F() const; // conversion function
};

class MathUtils
{
public:
	static float lerp(const float a, const float b, const float t);
	static Vector2F scaleVector2(const Vector2F& a_vec, const float& a_scale);
	static Vector2F scaleVector2(const Vector2F& a_vec_1, const Vector2F& a_vec_2);
	static float inverse_lerp(const float& a_min, const float& a_max, const float& a_value);
};

inline Vector2F::operator Vector3F() const
{
	return { x, y, 0 };
}

inline Vector3F::operator Vector2F() const
{
	return { x, y };
}

inline float MathUtils::lerp(const float a, const float b, const float t)
{
	return (b - a) * t + a;
}

inline Vector2F MathUtils::scaleVector2(const Vector2F& a_vec, const float& a_scale)
{
	return a_vec * a_scale;
}

inline Vector2F MathUtils::scaleVector2(const Vector2F& a_vec_1, const Vector2F& a_vec_2)
{
	return a_vec_1 * a_vec_2;
}

inline float MathUtils::inverse_lerp(const float& a_min, const float& a_max, const float& a_value)
{
	return (a_value - a_min) / (a_max - a_min);
}
