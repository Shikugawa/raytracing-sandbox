#pragma once

#include <vector>
#include <memory>
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

using HitablePtr = std::unique_ptr<Hitable>;

class HitableList : public std::vector<HitablePtr>
{
public:
	using Base = std::vector<HitablePtr>;
	
	HitableList() = default;
	explicit HitableList(std::vector<HitablePtr> _list) : Base(std::move(_list))
	{}

	bool hit(const Ray& r, float t_min, float t_max, hit_record& rec) const
	{
		hit_record tmp;
		bool hit_anything = false;
		double closest_so_far = t_max;
		for (auto it = Base::begin(); it != Base::end(); ++it)
		{
			if (it->get()->hit(r, t_min, closest_so_far, tmp))
			{
				hit_anything = true;
				closest_so_far = tmp.t;
				rec = tmp;
			}
		}
		return hit_anything;
	}
};