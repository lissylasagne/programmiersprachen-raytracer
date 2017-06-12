#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere: public Shape{
public:

private:
	glm::vec3 mid;
	float r;
};

#endif