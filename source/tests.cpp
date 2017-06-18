#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"
#include "shape.hpp"
#include "ray.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

TEST_CASE("test spheres", "[Sphere]")
	{
		SECTION("constructor and getter")
		{
			REQUIRE(Sphere().getMid().x == 0.0);
			REQUIRE(Sphere().getMid().y == 0.0);
			REQUIRE(Sphere().getMid().z == 0.0);
			REQUIRE(Sphere().getRad() == 0.0);
			REQUIRE(Sphere().getName() == "no name");
			REQUIRE(Sphere().getColor().r == 0.0);
			REQUIRE(Sphere().getColor().g == 0.0);
			REQUIRE(Sphere().getColor().b == 0.0);

			Color color1{0.2, 0.7, 0.2};
			Sphere sphere1(glm::vec3(2.0, 5.0, 3.0), 1.0, "sphere 1", color1);
			REQUIRE(sphere1.getMid().x == 2.0);
			REQUIRE(sphere1.getMid().y == 5.0);
			REQUIRE(sphere1.getMid().z == 3.0);
			REQUIRE(sphere1.getRad() == 1.0);
			REQUIRE(sphere1.getName() == "sphere 1");
			REQUIRE(sphere1.getColor().r == Approx(0.2));
			REQUIRE(sphere1.getColor().g == Approx(0.7));
			REQUIRE(sphere1.getColor().b == Approx(0.2));

			Color color2{1.0, 0.5, 0.0};
			Sphere sphere2(glm::vec3(45.2, 12.0, 0.0), 5.62, "sphere 2", color2);
			REQUIRE(sphere2.getMid().x == Approx(45.2));
			REQUIRE(sphere2.getMid().y == 12.0);
			REQUIRE(sphere2.getMid().z == 0.0);
			REQUIRE(sphere2.getRad() == Approx(5.62));
			REQUIRE(sphere2.getName() == "sphere 2");
			REQUIRE(sphere2.getColor().r == 1.0);
			REQUIRE(sphere2.getColor().g == Approx(0.5));
			REQUIRE(sphere2.getColor().b == 0.0);
		}

		SECTION("area and volume")
		{
			REQUIRE(Sphere().area() == 0.0);
			REQUIRE(Sphere().volume() == 0.0);

			Color color1{0.2, 0.7, 0.2};
			Sphere sphere1(glm::vec3(2.0, 5.0, 3.0), 1.0, "sphere 1", color1);
			REQUIRE(sphere1.area() == Approx(12.56637));
			REQUIRE(sphere1.volume() == Approx(4.18879));

			Color color2{1.0, 0.5, 0.0};
			Sphere sphere2(glm::vec3(45.2, 12.0, 0.0), 5.62, "sphere 2", color2);
			REQUIRE(sphere2.area() == 396.90128f);
			REQUIRE(sphere2.volume() == 743.52838f); 
		}

		SECTION("print")
		{
			Color color1{0.2, 0.7, 0.2};
			Sphere sphere1(glm::vec3(2.0, 5.0, 3.0), 1.0, "sphere 1", color1);
			std::cout << sphere1;

			Color color2{1.0, 0.5, 0.0};
			Sphere sphere2(glm::vec3(45.2, 12.0, 0.0), 5.62, "sphere 2", color2);
			std::cout <<sphere2;
		}

		SECTION("instersect")
		{
			Ray ray1(glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0));
			Color color1{1.0, 0.0, 0.0};
			Sphere sphere1(glm::vec3(0.0, 0.0, 5.0), 1.0, "sphere 1", color1);
			float dis = 0.0;
			sphere1.intersect(ray1, dis);
			REQUIRE(dis == Approx(4.0f));
		}
	}

TEST_CASE("test boxes", "[Box]")
	{
		SECTION("constructor and getter")
		{
			REQUIRE(Box().getMin().x == 0.0);
			REQUIRE(Box().getMin().y == 0.0);
			REQUIRE(Box().getMin().z == 0.0);
			REQUIRE(Box().getMax().x == 0.0);
			REQUIRE(Box().getMax().y == 0.0);
			REQUIRE(Box().getMax().z == 0.0);
			REQUIRE(Box().getSideLengthX() == 0.0);
			REQUIRE(Box().getSideLengthY() == 0.0);
			REQUIRE(Box().getSideLengthZ() == 0.0);
			REQUIRE(Box().getName() == "no name");
			REQUIRE(Box().getColor().r == 0.0);
			REQUIRE(Box().getColor().g == 0.0);
			REQUIRE(Box().getColor().b == 0.0);

			Color color1{0.2, 0.7, 0.2};
			Box box1(glm::vec3(3.0, 9.0, 0.0), glm::vec3(1.0, 4.0, 3.0), "box 1", color1);
			REQUIRE(box1.getMin().x == 3.0);
			REQUIRE(box1.getMin().y == 9.0);
			REQUIRE(box1.getMin().z == 0.0);
			REQUIRE(box1.getMax().x == 1.0);
			REQUIRE(box1.getMax().y == 4.0);
			REQUIRE(box1.getMax().z == 3.0);
			REQUIRE(box1.getSideLengthX() == 2.0);
			REQUIRE(box1.getSideLengthY() == 5.0);
			REQUIRE(box1.getSideLengthZ() == 3.0);
			REQUIRE(box1.getName() == "box 1");
			REQUIRE(box1.getColor().r == Approx(0.2));
			REQUIRE(box1.getColor().g == Approx(0.7));
			REQUIRE(box1.getColor().b == Approx(0.2));

			Color color2{1.0, 0.5, 0.0};
			Box box2(glm::vec3(7.332, 0.2, 3.12), glm::vec3(27.0, 2.12, 3.54), "box 2", color2);
			REQUIRE(box2.getMin().x == Approx(7.332));
			REQUIRE(box2.getMin().y == Approx(0.2));
			REQUIRE(box2.getMin().z == Approx(3.12));
			REQUIRE(box2.getMax().x == 27.0);
			REQUIRE(box2.getMax().y == Approx(2.12));
			REQUIRE(box2.getMax().z == Approx(3.54));
			REQUIRE(box2.getSideLengthX() == Approx(19.668));
			REQUIRE(box2.getSideLengthY() == Approx(1.92));
			REQUIRE(box2.getSideLengthZ() == Approx(0.42));
			REQUIRE(box2.getName() == "box 2");
			REQUIRE(box2.getColor().r == 1.0);
			REQUIRE(box2.getColor().g == Approx(0.5));
			REQUIRE(box2.getColor().b == 0.0);
		}

		SECTION("area and volume")
		{
			REQUIRE(Box().area() == 0.0);
			REQUIRE(Box().volume() == 0.0);

			Color color1{0.2, 0.7, 0.2};
			Box box1(glm::vec3(3.0, 9.0, 0.0), glm::vec3(1.0, 4.0, 3.0), "box 1", color1);
			REQUIRE(box1.area() == 62.0);
			REQUIRE(box1.volume() == 30.0);

			Color color2{1.0, 0.5, 0.0};
			Box box2(glm::vec3(7.332, 0.2, 3.12), glm::vec3(27.0, 2.12, 3.54), "box 2", color2);
			REQUIRE(box2.area() == Approx(93.65904));
			REQUIRE(box2.volume() == Approx(15.86027));
		}

		SECTION("print")
		{
			Color color1{0.2, 0.7, 0.2};
			Box box1(glm::vec3(3.0, 9.0, 0.0), glm::vec3(1.0, 4.0, 3.0), "box 1", color1);
			std::cout << box1;

			Color color2{1.0, 0.5, 0.0};
			Box box2(glm::vec3(7.332, 0.2, 3.12), glm::vec3(27.0, 2.12, 3.54), "box 2", color2);
			std::cout << box2;
		}
	}

TEST_CASE("intersectRaySphere", "[intersect]")
{
	// Ray
	glm::vec3 ray_origin{0.0, 0.0, 0.0};
	// ray direction has to be normalized!
	// you can use:
	// v = glm::normalize(some_vector)
	glm::vec3 ray_direction{0.0, 0.0, 1.0};
	
	// Sphere
	glm::vec3 sphere_center{0.0, 0.0, 5.0};
	float sphere_radius{1.0};
	
	float distance{0.0};
	auto result = glm::intersectRaySphere(
		ray_origin, ray_direction,
		sphere_center,
		sphere_radius * sphere_radius, // squared radius !!!
		distance);
	REQUIRE(distance == Approx(4.0));
}

TEST_CASE("destructor", "[destructor]")
{
	Color red (255, 0, 0);
	glm::vec3 position (0, 0, 0);
	Sphere* s1 = new Sphere(position, 1.2, "sphere0", red);
	Shape* s2 = new Sphere(position, 1.2, "sphere1", red);
	s1 -> print(std::cout);
	s2 -> print(std::cout);
	delete s1;
	delete s2;
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
