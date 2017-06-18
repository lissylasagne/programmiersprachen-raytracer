#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>

class Box: public Shape{
public:
	Box();
	Box(glm::vec3 const& mini, glm::vec3 const& maxi, std::string const& name, Color const& color);
	~Box();
	glm::vec3 const& getMin() const;
	glm::vec3 const& getMax() const;
	float area() const override;
	float volume() const override;
	float const getSideLengthX() const;
	float const getSideLengthY() const;
	float const getSideLengthZ() const;
	std::string const& getName() const;
	Color const& getColor() const;
	std::ostream& print(std::ostream& os) const override;

private:
	glm::vec3 min_;
	glm::vec3 max_;
	std::string name_;
	Color color_;
};

#endif