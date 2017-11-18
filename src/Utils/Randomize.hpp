//
// Created by Marrero on 15/11/2017.
//


#ifndef MRT_RANDOMIZE_HPP
#include <gmon.h>
#include <random>

namespace {
u_int seed;

/**
 * @brief Devuelve un entero aleatorio en el rango [begin, end]
 * @param begin
 * @param end
 * @return
 */
int getRandomElementBetween(const int begin, const int end) {
  std::random_device randomDevice;
  std::mt19937 engine{randomDevice()};
  std::uniform_int_distribution<int> distribution(begin, end);
  return distribution(engine);
}

/**
 * @brief Devuelve un número aleatorio en el rango [begin, end]
 * @param begin
 * @param end
 * @return
 */
double getRandomElementBetween(const double begin, const int end) {
  std::mt19937 engine(seed);
  std::uniform_real_distribution<double> distribution(begin, end);
  return distribution(engine);
}
}
#define MRT_RANDOMIZE_HPP
#endif //MRT_RANDOMIZE_HPP
