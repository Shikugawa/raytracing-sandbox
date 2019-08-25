#pragma once
#include "hitable.h"
#include <cmath>

class Sphere : public Hitable
{
public:
	Sphere() = default;
	explicit Sphere(Vec3 cen, float r) : center(cen), radius(r)
	{
	}

	bool hit(const Ray& r, float t_min, float t_max, hit_record& rec) 
	{
		Vec3 oc = r.origin() - center;
		float a = dot(r.direction(), r.direction());
		float b = 2.0 * dot(oc, r.direction());
		float c = dot(oc, oc) - radius * radius;
		float discriminant = b * b - 4 * a * c;
		if (discriminant > 0)
		{
			float temp = (-b - std::sqrt(b * b - a * c) / a);
			if (temp < t_max && temp > t_min)
			{
				rec.t = temp;
				rec.p = r.point_at_parameter(rec.t);
				rec.normal = (rec.p - center) / radius;
				return true;
			}

			temp = (-b + std::sqrt(b * b - a * c)) / a;
			if (temp < t_max && temp > t_min) 
			{
				rec.t = temp;
				rec.p = r.point_at_parameter(rec.t);
				rec.normal = (rec.p - center) / radius;
				return true;
			}
		}
		return false;
	}
private:
	Vec3 center;
	float radius;
};