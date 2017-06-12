#include <iostream>
#include "box.hpp"

	Box::Box():
		min{0.0, 0.0, 0.0}, max{0.0, 0.0, 0.0}{}

	glm::vec3 const getMin() const
	{
		return min;
	}

	glm::vec3 const getMax() const
	{
		return max;
	}

	float const getSideLengthX() const
	{
		return (max.x - min.x);
	}

	float const getSideLengthY() const
	{
		return (max.y - min.y);
	}

	float const getSideLengthZ() const
	{
		return (max.z - min.z);
	}

	float area() const override
	{
		return((2 * getSideLengthX * getSideLengthY) 
			 + (2 * getSideLengthY * getSideLengthZ) 
			 + (2 * getSideLengthZ * getSideLengthX));
	}

	float volume() const override
	{
		return(getSideLengthX * getSideLengthY * getSideLengthZ);
	}