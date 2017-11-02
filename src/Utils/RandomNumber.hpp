//
// Created by Marrero on 31/10/2017.
//

#ifndef MRT_RANDOMNUMBER_HPP
#define MRT_RANDOMNUMBER_HPP
#include <random>

namespace {
class RandomNumber {
 public:
  static double seed;
 public:
  static int getRandomIntBetween(const int initial, const int final) {
    std::mt19937_64 engine(seed);
    std::uniform_int_distribution<> distribution(initial, final);
    return distribution(engine);
  }

  static double getRandomDoubleBetween(const int inital, const int final) {
    std::mt19937_64 engine(seed);
    std::uniform_real_distribution<> distribution(inital, final);
    return distribution(engine);
  }
};
double RandomNumber::seed = 0.0;
}
#endif //MRT_RANDOMNUMBER_HPP
