#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>

class Sphere: public Shape{
public:
	Sphere();

private:
	glm::vec3 mid;
	float r;

};

#endif