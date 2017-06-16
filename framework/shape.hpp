#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <cmath>
#include "color.hpp"

class Shape {
public:
	Shape();
	Shape(std::string const& name, Color const& color);
	virtual float area() const = 0;
	virtual float volume() const = 0;
	std::string getName() const;
	Color const& getColor() const;
	virtual std::ostream& print(std::ostream& os) const;

private:
	std::string name_;
	Color color_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif