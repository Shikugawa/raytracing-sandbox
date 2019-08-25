#pragma once
#include "vec3.h"

class Ray
{
public:
	Ray() = default;
	Ray(const Vec3& _A, const Vec3& _B) : A(_A), B(_B) {}

	Vec3 origin() const { return A; }
	Vec3 direction() const { return B; }
	Vec3 point_at_parameter(const float t) const {
		return A + B * t;
	}
private:
	Vec3 A;
	Vec3 B;
};
