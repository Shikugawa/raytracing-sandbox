#pragma once

#include "ray.h"

class Camera
{
public:
	Camera()
	{
		lower_left_corner = Vec3(-2.0, -1.0, -1.0);
		origin = Vec3(0, 0, 0);
		vertical = Vec3(0.0, 2.0, 0.0);
		horizontal = Vec3(4.0, 0.0, 0.0);
	}

	Ray GetRay(float u, float v) 
	{
		return Ray(origin, lower_left_corner + v * vertical + u * horizontal - origin);
	}

private:
	Vec3 origin, lower_left_corner, horizontal, vertical;
};
