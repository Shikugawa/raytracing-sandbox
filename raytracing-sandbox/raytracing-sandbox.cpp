#include <iostream>
#include <fstream>
#include <cmath>
#include "ray.h"
#include "vec3.h"

float hit_sphere(const Vec3& center, float radius, const Ray& r)
{
	Vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		return -1.0;
	}
	else
	{
		return (-b - std::sqrt(discriminant)) / (2.0 * a);
	}
}

Vec3 color(const Ray& r)
{
	float t = hit_sphere(Vec3(0, 0, -1), 0.5, r);
	if (t > 0.0)
	{
		Vec3 N = unit_vector(r.point_at_parameter(t) - Vec3(0, 0, -1));
		return 0.5 * Vec3(N.x() + 1, N.y() + 1, N.z() + 1);
	}
	Vec3 u = unit_vector(r.direction());
	t = 0.5 * (u.y() + 1.0);
	return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
}

int main()
{
	std::fstream ofs("ppm.txt");
	ofs.clear();

	int nx = 200;
	int ny = 100;
	
	Vec3 ll_corner(-2.0, -1.0, -1.0);
	Vec3 origin(0, 0, 0);
	Vec3 vertical(0.0, 2.0, 0.0);
	Vec3 horizontal(4.0, 0.0, 0.0);

	ofs << "P3\n" << nx << " " << ny << "\n255\n";
	
	for (int j = ny - 1; j >= 0; --j)
	{
		for (int i = 0; i < nx; ++i)
		{
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);
			Ray r(origin, ll_corner + v*vertical + u*horizontal);
			auto c = color(r);
			int ir = int(255.99 * c.r());
			int ig = int(255.99 * c.g());
			int ib = int(255.99 * c.b());
			ofs << ir << " " << ig << " " << ib << "\n";
		}
	}
}
