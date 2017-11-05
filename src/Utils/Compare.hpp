//
// Created by Marrero on 05/11/2017.
//

#ifndef MRT_COMPARE_HPP_HPP
#define MRT_COMPARE_HPP_HPP
#include <cmath>

namespace {
/**
 * @brief Comparamos los lugares por el ratio Duracion/Estrellas de cada lugar
 * @param a
 * @param b
 * @return
 */
bool compareRatio(Location &a, Location &b) {
  return ((a.getDuration() / a.getStars()) > (b.getDuration() / b.getStars()));
}

/**
 * @brief Comparamos los lugares por la cantidad de estrellas que tiene cada uno de los lugares
 * @param a
 * @param b
 * @return
 */
bool compareStars(Location &a, Location &b) {
  return (a.getStars() > b.getStars());
}

/**
 * @brief Realizamos una ponderacion para comparar los lugares
 * @param a
 * @param b
 * @return
 */
bool comparePonderation(Location &a, Location &b) {
  double ponderationA = (0.3 * a.getDuration() + 0.7 * a.getStars()) / pow(a.getStars(), 2);
  double ponderationB = (0.3 * b.getDuration() + 0.7 * b.getStars() / (pow(b.getStars(), 2)));
  return (ponderationA > ponderationB);
}
}
#endif //MRT_COMPARE_HPP_HPP
