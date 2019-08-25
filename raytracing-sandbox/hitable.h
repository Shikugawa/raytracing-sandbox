#pragma once

#include <vector>
#include "ray.h"

struct hit_record
{
	float t;
	Vec3 p;
	Vec3 normal;
};

class Hitable
{
public:
	virtual bool hit(const Ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

class HitableList : public Hitable
{
public:
	HitableList() = default;
	explicit HitableList(std::vector<Hitable> _list) : list(_list)
	{}

	bool hit(const Ray& r, float t_min, float t_max, hit_record& rec)
	{
		hit_record tmp;
		bool hit_anything = false;
		double closest_so_far = t_max;
		for (const auto& hitable : list)
		{
			if (hitable.hit(r, t_min, closest_so_far, tmp))
			{
				hit_anything = true;
				closest_so_far = tmp.t;
				rec = tmp;
			}
		}
		return hit_anything;
	}
private:
	std::vector<Hitable> list;
};