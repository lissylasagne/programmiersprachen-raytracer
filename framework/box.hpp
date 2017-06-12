#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>

class Box: public Shape{
public:
	Box();

private:
	glm::vec3 min;
	glm::vec3 max;
};

#endif