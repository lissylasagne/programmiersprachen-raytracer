#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>

class Sphere: public Shape{
public:
	Sphere();
	Sphere(gml::vec3 const& middle; float a);
	glm::vec3 const getMid() const;
	float const getRad() const;
	float area() const override;
	float volume() const override;

private:
	glm::vec3 mid;
	float rad;

};

#endif