#pragma once
#include <cmath>
#include <cstdlib>
#include <iostream>

class Vec3
{
public:
	Vec3() = default;
	Vec3(float e0, float e1, float e2)
	{
		e[0] = e0;
		e[1] = e1;
		e[2] = e2;
	}

	inline float x() const { return e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }
	inline float r() const { return e[0]; }
	inline float g() const { return e[1]; }
	inline float b() const { return e[2]; }

	inline const Vec3& operator+() const { return *this;  }
	inline Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; }

	inline Vec3& operator+=(const Vec3& v2);
	inline Vec3& operator-=(const Vec3& v2);
	inline Vec3& operator*=(const Vec3& v2);
	inline Vec3& operator/=(const Vec3& v2);
	inline Vec3& operator*=(const float t);
	inline Vec3& operator/=(const float t);

	inline float length() const 
	{
		return std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	}

	inline float squared_length() const 
	{
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	inline void make_unit_vector();

private:
	float e[3];
};

void Vec3::make_unit_vector() 
{
	float k = 1.0 / std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}

inline std::ostream& operator<<(std::ostream& os, const Vec3& t)
{
	os << t.x() << " " << t.y() << " " << t.z();
	return os;
}

inline Vec3 operator+(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}

inline Vec3 operator-(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}

inline Vec3 operator*(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.x() * v2.x(), v1.y() * v2.y(), v1.z() * v2.z());
}

inline Vec3 operator/(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.x() / v2.x(), v1.y() / v2.y(), v1.z() / v2.z());
}

inline Vec3 operator*(const Vec3& v1, const float t)
{
	return Vec3(v1.x() * t, v1.y() * t, v1.z() * t);
}

inline Vec3 operator/(const Vec3& v1, const float t)
{
	return Vec3(v1.x() / t, v1.y() / t, v1.z() / t);
}

inline Vec3 operator*(const float t, const Vec3& v1)
{
	return Vec3(v1.x() * t, v1.y() * t, v1.z() * t);
}

inline float dot(const Vec3& v1, const Vec3& v2)
{
	return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}

inline Vec3 cross(const Vec3& v1, const Vec3& v2)
{
	return Vec3();
}

inline Vec3& Vec3::operator+=(const Vec3& v)
{
	e[0] += v.x();
	e[1] += v.y();
	e[2] += v.z();
	return *this;
}

inline Vec3& Vec3::operator-=(const Vec3& v)
{
	e[0] -= v.x();
	e[1] -= v.y();
	e[2] -= v.z();
	return *this;
}

inline Vec3& Vec3::operator*=(const Vec3& v)
{
	e[0] *= v.x();
	e[1] *= v.y();
	e[2] *= v.z();
	return *this;
}

inline Vec3& Vec3::operator/=(const Vec3& v)
{
	e[0] /= v.x();
	e[1] /= v.y();
	e[2] /= v.z();
	return *this;
}

inline Vec3& Vec3::operator*=(const float v)
{
	e[0] *= v;
	e[1] *= v;
	e[2] *= v;
	return *this;
}

inline Vec3& Vec3::operator/=(const float v)
{
	e[0] /= v;
	e[1] /= v;
	e[2] /= v;
	return *this;
}

inline Vec3 unit_vector(Vec3 v)
{
	return v / v.length();
}
