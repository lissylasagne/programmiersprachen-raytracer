#include <iostream>
#include "sphere.hpp"

	Sphere::Sphere():
		mid_{0.0, 0.0, 0.0}, rad_{0.0}, name_{"no name"}, color_{0.0, 0.0, 0.0}
		{
			//std::cout << "Standard sphere constructor." << std::endl;
		}

	Sphere::Sphere(glm::vec3 const& middle, float r, std::string const& name, Color const& color):
		mid_{middle}, rad_{r}, name_{name}, color_{color}
		{
			//std::cout << "Customized sphere constructor." << std::endl;
		}

	Sphere::~Sphere()
	{
		//std::cout << "Sphere destructor." << std::endl;
	}

	glm::vec3 const& Sphere::getMid() const
	{
		return mid_;
	}

	float const Sphere::getRad() const
	{
		return rad_;
	}

	float Sphere::area() const
	{
		float pi = M_PI;
		return (4 * pi * pow(rad_, 2));
	}

	float Sphere::volume() const
	{
		float pi = M_PI;
		return (4 * pi * pow(rad_, 3) / 3);
	}

	std::string const& Sphere::getName() const
	{
		return(name_);
	}

	Color const& Sphere::getColor() const
	{
		return(color_);
	}

	std::ostream& Sphere::print(std::ostream& os) const
	{
		Shape::print(os);
		os << "Center: " << mid_.x << ", " << mid_.y << ", " << mid_.z << "\nRadius: " << rad_ << "\n";
		return os;
	}

	bool Sphere::intersect(Ray const& ray, float& distance) const
	{
		return glm::intersectRaySphere(
			ray.origin, ray.direction,
			mid_, rad_ * rad_, distance);
	}	

