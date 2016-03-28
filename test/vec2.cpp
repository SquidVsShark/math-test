#include <catch/catch.hpp>
#include <math/vec/vec2.hpp>
#include <array>

TEST_CASE("Vector 2")
{
  // Initialize test data that we will use
  const math::vec2 one_two = math::vec2_init(1, 2);
  REQUIRE(math::vec2_get_x(one_two) == 1);
  REQUIRE(math::vec2_get_y(one_two) == 2);

  const math::vec2 three = math::vec2_init(3);
  REQUIRE(math::vec2_get_x(three) == 3);
  REQUIRE(math::vec2_get_y(three) == 3);

  std::array<float, 2> arr_data = {4.f, 5.f};
  const math::vec2 four_five = math::vec2_init_with_array(&arr_data[0]);
  REQUIRE(math::vec2_get_x(four_five) == 4);
  REQUIRE(math::vec2_get_y(four_five) == 5);
  
  SECTION("Export data")
  {
    
  }

	SECTION("Constants")
	{
		const math::vec2 zero = math::vec2_zero();
    REQUIRE(math::vec2_get_x(zero) == 0);
    REQUIRE(math::vec2_get_y(zero) == 0);
    
    const math::vec2 one = math::vec2_one();
    REQUIRE(math::vec2_get_x(one) == 1);
    REQUIRE(math::vec2_get_y(one) == 1);
    
    const math::vec2 zero_one = math::vec2_zero_one();
    REQUIRE(math::vec2_get_x(zero_one) == 0);
    REQUIRE(math::vec2_get_y(zero_one) == 1);
	}
  
  
  SECTION("Addition")
  {
  }
  
  
  SECTION("Subtraction")
  {
  }
  
  
  SECTION("Division")
  {
  }
  
  
  SECTION("Multiply")
  {
  }
  
  SECTION("Scale")
  {
  }
  
  
  SECTION("Lerp")
  {
  }
  
  
  SECTION("Normalize")
  {
  }
  
  SECTION("Dot Product")
  {
  }
}