#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>

class Sphere: public Shape{
public:
	Sphere();
	Sphere(glm::vec3 const& middle, float a, std::string const& name, Color const& color);
	glm::vec3 const& getMid() const;
	float const getRad() const;
	float area() const override;
	float volume() const override;
	std::string const& getName() const;
	Color const& getColor() const;
	std::ostream& print(std::ostream& os) const override;

private:
	glm::vec3 mid_;
	float rad_;
	std::string name_;
	Color color_;
};

#endif