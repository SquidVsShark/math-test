#include <catch/catch.hpp>
#include <math/vec/vec3.hpp>
#include <array>


TEST_CASE("Vector 3")
{
  // Initialize test data that we will use
  const math::vec3 one_two_three = math::vec3_init(1.f, 2.f, 3.f);
  REQUIRE(math::vec3_get_x(one_two_three) == 1.f);
  REQUIRE(math::vec3_get_y(one_two_three) == 2.f);
  REQUIRE(math::vec3_get_z(one_two_three) == 3.f);

  const math::vec3 three = math::vec3_init(3.f);
  REQUIRE(math::vec3_get_x(three) == 3.f);
  REQUIRE(math::vec3_get_y(three) == 3.f);
  REQUIRE(math::vec3_get_z(three) == 3.f);

  const std::array<float, 3> arr_data = {4.f, 5.f, 6.f};
  const math::vec3 four_five_six = math::vec3_init_with_array(&arr_data[0]);
  REQUIRE(math::vec3_get_x(four_five_six) == 4.f);
  REQUIRE(math::vec3_get_y(four_five_six) == 5.f);
  REQUIRE(math::vec3_get_z(four_five_six) == 6.f);
  
  const float error = 0.0001f; // Error for near tests

  SECTION("Export Data")
  {
    std::array<float, 3> arr_export = {0.f, 0.f, 0.f};
    const math::vec3 to_export = math::vec3_one();
    math::vec3_to_array(to_export, arr_export.data());
    
    REQUIRE(arr_export.at(0) == 1.f);
    REQUIRE(arr_export.at(1) == 1.f);
    REQUIRE(arr_export.at(2) == 1.f);
  }

	SECTION("Constants")
	{
		const math::vec3 zero = math::vec3_zero();
    REQUIRE(math::vec3_get_x(zero) == 0.f);
    REQUIRE(math::vec3_get_y(zero) == 0.f);
    REQUIRE(math::vec3_get_z(zero) == 0.f);
    
    const math::vec3 one = math::vec3_one();
    REQUIRE(math::vec3_get_x(one) == 1.f);
    REQUIRE(math::vec3_get_y(one) == 1.f);
    REQUIRE(math::vec3_get_z(one) == 1.f);
    
    const math::vec3 zero_zero_one = math::vec3_zero_zero_one();
    REQUIRE(math::vec3_get_x(zero_zero_one) == 0.f);
    REQUIRE(math::vec3_get_y(zero_zero_one) == 0.f);
    REQUIRE(math::vec3_get_z(zero_zero_one) == 1.f);
	}
  
  SECTION("Equality")
  {
  }
}