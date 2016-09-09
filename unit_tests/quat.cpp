#include <catch/catch.hpp>
#include <math/quat/quat.hpp>
#include <array>


TEST_CASE("Quat rotations")
{

  SECTION("Initialize")
  {
    const math::quat empty = math::quat_init();
    REQUIRE(math::get_x(empty) == 0.f);
    REQUIRE(math::get_y(empty) == 0.f);
    REQUIRE(math::get_z(empty) == 0.f);
    REQUIRE(math::get_w(empty) == 1.f);
    
    const math::quat one_two_three_four = math::quat_init(10, 0, 0, 0);
//    REQUIRE(math::get_x(one_two_three_four) == 1.f);
    REQUIRE(math::get_y(one_two_three_four) == 0.f);
    REQUIRE(math::get_z(one_two_three_four) == 0.f);
    REQUIRE(math::get_w(one_two_three_four) == 0.f);
    
    const math::quat angle_axis = math::quat_init_with_axis_angle(1, 0, 0, math::tau());
    REQUIRE(math::get_x(angle_axis) == 1.f);
    REQUIRE(math::get_y(angle_axis) == 0.f);
    REQUIRE(math::get_z(angle_axis) == 0.f);
    REQUIRE(math::get_w(angle_axis) == 0.f);
    
  }

}