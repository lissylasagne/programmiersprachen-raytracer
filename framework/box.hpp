#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>

class Box: public Shape{
public:
	Box();
	glm::vec3 const getMin() const;
	glm::vec3 const getMax() const;
	float area() const override;
	float volume() const override;
	float const getSideLengthX() const;
	float const getSideLengthY() const;
	float const getSideLengthZ() const;

private:
	glm::vec3 min;
	glm::vec3 max;
};

#endif