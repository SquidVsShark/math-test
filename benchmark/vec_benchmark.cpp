// Benchmarks for vectors.

#define MATH_USE_SIMD

#include <math/vec/vec3.hpp>
#include <math/vec/vec4.hpp>
#include <chrono>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


constexpr uint32_t bench_iterations = 1000000;

std::chrono::high_resolution_clock::time_point start;
std::chrono::high_resolution_clock::time_point end;


inline void
start_benchmark()
{
  start = std::chrono::high_resolution_clock::now();  
}


inline uint32_t
end_benchmark()
{
  end = std::chrono::high_resolution_clock::now();

  auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  return milli.count();
}


int
main()
{
  printf("Vector Iterations\n");

  srand(time(NULL));

  const float x = static_cast<float>(rand() % 100);
  const float y = static_cast<float>(rand() % 100);
  const float z = static_cast<float>(rand() % 100);
  const float w = static_cast<float>(rand() % 100);
  const float a = static_cast<float>(rand() % 100);
  const float b = static_cast<float>(rand() % 100);
  const float c = static_cast<float>(rand() % 100);
  const float d = static_cast<float>(rand() % 100);
  
  // Additions
  {
    const math::vec4 vec_a = math::vec4_init(x,y,z,w);
    const math::vec4 vec_b = math::vec4_init(a,b,c,d);
    
    math::vec4 vec_c = math::vec4_zero();

    start_benchmark();

    for(uint32_t i = 0; i < bench_iterations; ++i)
    {
      vec_c = math::vec4_add(vec_c, vec_a);
      vec_c = math::vec4_add(vec_c, vec_b);  
    } 

    auto result = end_benchmark(); 

    printf("Addition: %d\n", result);
  }


  // Subtractions
  {
    const math::vec4 vec_a = math::vec4_init(x,y,z,w);
    const math::vec4 vec_b = math::vec4_init(a,b,c,d);
    
    math::vec4 vec_c = math::vec4_zero();

    start_benchmark();

    for(uint32_t i = 0; i < bench_iterations; ++i)
    {
      vec_c = math::vec4_subtract(vec_c, vec_a);
      vec_c = math::vec4_subtract(vec_c, vec_b);  
    } 

    auto result = end_benchmark(); 

    printf("Subtract: %d\n", result);
  }

  // Multiplication
  {
    const math::vec4 vec_a = math::vec4_init(x,y,z,w);
    const math::vec4 vec_b = math::vec4_init(a,b,c,d);
    
    math::vec4 vec_c = math::vec4_zero();

    start_benchmark();

    for(uint32_t i = 0; i < bench_iterations; ++i)
    {
      vec_c = math::vec4_multiply(vec_c, vec_a);
      vec_c = math::vec4_multiply(vec_c, vec_b);  
    } 

    auto result = end_benchmark(); 

    printf("Multiply: %d\n", result);
  }
  
  // Dot product
  {
    const math::vec4 vec_a = math::vec4_init(x,y,z,w);
    const math::vec4 vec_b = math::vec4_init(a,b,c,d);
    
    float dot_accum = 0.f;

    start_benchmark();

    for(uint32_t i = 0; i < bench_iterations; ++i)
    {
      dot_accum += math::vec4_dot(vec_b, vec_a);
    } 

    auto result = end_benchmark(); 

    printf("Dot Prodcut: %d\n", result);
  }

  // Cross product
  {
    const math::vec3 vec_a = math::vec3_init(x,y,z);
    const math::vec3 vec_b = math::vec3_init(a,b,c);
    
    math::vec3 cross_accum = math::vec3_zero();

    start_benchmark();

    for(uint32_t i = 0; i < bench_iterations; ++i)
    {
      cross_accum = math::vec3_cross(vec_b, vec_a);
    } 

    auto result = end_benchmark(); 

    printf("Cross Prodcut: %d\n", result);
  }


  return 0;
}
