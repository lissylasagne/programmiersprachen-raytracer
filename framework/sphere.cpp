#include <iostream>
#include "sphere.hpp"

	Sphere::Sphere():
		mid{0.0, 0.0, 0.0}, rad{0.0}{}

	glm::vec3 const getMid() const
	{
		return mid;
	}

	float const getRad() const
	{
		return rad;
	}

	float area() const override
	{
		float pi = M_PI;
		return (4 * pi * pow(rad, 2));
	}

	float volume() const override
	{
		float pi = M_PI;
		return ((4/3) * pi * pow(rad, 3));
	}