#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <cmath>

class Shape {
public:
	Shape();
	virtual float area() const = 0;
	virtual float volume() const = 0;
};

#endif