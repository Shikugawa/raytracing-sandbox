#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <random>
#include <utility>
#include <limits>
#include "ray.h"
#include "sphere.h"
#include "vec3.h"
#include "camera.h"

Vec3 color(const Ray& r, const HitableList& hl)
{
	hit_record rec;
	if (hl.hit(r, 0.0, std::numeric_limits<float>::max(), rec))
	{
		return 0.5 * Vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
	}
	else
	{
		Vec3 u = unit_vector(r.direction());
		float t = 0.5 * (u.y() + 1.0);
		return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
	}
}

int main()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand(0, 1);

	std::fstream ofs("ppm.txt");
	ofs.clear();

	int nx = 200;
	int ny = 100;
	
	Camera camera;

	HitableList objects;
	objects.emplace_back(std::make_unique<Sphere>(Vec3(0, 0, -1), 0.5));
	objects.emplace_back(std::make_unique<Sphere>(Vec3(0, -100.5, -1), 100));
	
	ofs << "P3\n" << nx << " " << ny << "\n255\n";
	
	for (int j = ny - 1; j >= 0; --j)
	{
		for (int i = 0; i < nx; ++i)
		{
			float u = float(rand(mt) * i) / float(nx);
			float v = float(rand(mt) * j) / float(ny);
		
			auto c = color(camera.GetRay(u, v), objects);
			
			int ir = int(255.99 * c.r());
			int ig = int(255.99 * c.g());
			int ib = int(255.99 * c.b());
			
			ofs << ir << " " << ig << " " << ib << "\n";
		}
	}
}
