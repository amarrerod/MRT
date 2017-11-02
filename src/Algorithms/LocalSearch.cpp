//
// Created by Marrero on 31/10/2017.
//

#include <cmath>
#include "LocalSearch.hpp"
#include "Greedy.hpp"
#include "../Basis/Tourist.hpp"
#include "../Utils/RandomNumber.hpp"

const string LocalSearch::NAME = "LocalSearch";

LocalSearch::LocalSearch(const int test) : Metaheuristic(NAME), maxTest(test) {}

LocalSearch::LocalSearch() : Metaheuristic(NAME) {
// NR
}

LocalSearch::~LocalSearch() {
// NR
}

void LocalSearch::run() {

}

void LocalSearch::initParams() {

}

string LocalSearch::toString() {
  return Metaheuristic::toString();
}

/**
 * @brief A partir de la solucion actual, intercambiamos un punto de la ruta por otro punto no seleccionado
 * @param copy
 */
void LocalSearch::swap(Route &copy) {

}

