#include <iostream>
#include "shape.hpp"

	Shape::Shape():
		name_{"No name"}, color_{0.0, 0.0, 0.0}{}

	Shape::Shape(std::string const& name, Color const& color):
		name_{name}, color_{color}{}

	std::string Shape::getName() const
	{
		return name_;
	}

	Color const& Shape::getColor() const
	{
		return color_;
	}

	std::ostream& Shape::print(std::ostream& os) const
	{
		os << "Name: " << name_ << " Color: " << color_;
		return os;
	}

	std::ostream& operator<<(std::ostream& os, Shape const& s)
	{
		return s.print(os);
	}