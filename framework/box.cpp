#include <iostream>
#include "box.hpp"

	Box::Box():
		min_{0.0, 0.0, 0.0}, max_{0.0, 0.0, 0.0}, name_{"no name"}, color_{0.0, 0.0, 0.0}
		{
			std::cout << "Standard box constructor." << std::endl;
		}

	Box::Box(glm::vec3 const& mini, glm::vec3 const& maxi, std::string const& name, Color const& color):
		min_{mini}, max_{maxi}, name_{name}, color_{color}
		{
			std::cout << "Customized box constructor." << std::endl;
		}

	Box::~Box()
	{
		std::cout << "Box destructor." << std::endl;
	}

	glm::vec3 const& Box::getMin() const
	{
		return min_;
	}

	glm::vec3 const& Box::getMax() const
	{
		return max_;
	}

	float const Box::getSideLengthX() const
	{
		if(max_.x >= min_.x)
		{
			return (max_.x - min_.x);
		}
		else
		{
			return (min_.x - max_.x);
		}
	}

	float const Box::getSideLengthY() const
	{
		if(max_.y >= min_.y)
		{
			return (max_.y - min_.y);
		}
		else
		{
			return (min_.y - max_.y);
		}
	}

	float const Box::getSideLengthZ() const
	{
		if(max_.z >= min_.z)
		{
			return (max_.z - min_.z);
		}
		else
		{
			return (min_.z - max_.z);
		}
	}

	float Box::area() const
	{
		return((2 * getSideLengthX() * getSideLengthY()) 
			 + (2 * getSideLengthY() * getSideLengthZ()) 
			 + (2 * getSideLengthZ() * getSideLengthX()));
	}

	float Box::volume() const
	{
		return(getSideLengthX() * getSideLengthY() * getSideLengthZ());
	}

	std::string const& Box::getName() const
	{
		return(name_);
	}

	Color const& Box::getColor() const
	{
		return(color_);
	}

	std::ostream& Box::print(std::ostream& os) const
	{
		Shape::print(os);
		os << "Min: " << min_.x << ", " << min_.y << ", " << min_.z 
			<< " Max: " << max_.x << " ," << max_.y << " ," << max_.z << " ,";
		return os;
	}


