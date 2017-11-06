//
// Created by Marrero on 31/10/2017.
//

#include <cmath>
#include <iostream>
#include "LocalSearch.hpp"
#include "Greedy.hpp"
#include "../Basis/Tourist.hpp"

const string LocalSearch::NAME = "LocalSearch";

LocalSearch::LocalSearch(const int test) : Metaheuristic(NAME), maxTest(test) {}

LocalSearch::LocalSearch() : Metaheuristic(NAME) {
// NR
}

LocalSearch::~LocalSearch() {
// NR
}

void LocalSearch::initParams() {

}

string LocalSearch::toString() {
  return Metaheuristic::toString();
}

void LocalSearch::run() {
  Greedy greedy;
  greedy.run();
  for (int iRoute = 0; iRoute < Tourist::days; iRoute++) {
    solutions[iRoute] = greedy.getSolution(iRoute); // Partimos de la solucion obtenida por el greedy
    bool improve = true;
    int tries = 0;
    while (improve) {
      Route child = solutions[iRoute];
      swap(child);
      double evaluation = evaluate(child);
      child.setRate(evaluation);
      if (isgreater(evaluation, solutions[iRoute].getRate())) {
        improve = true;
        solutions[iRoute] = child;
      } else {
        tries++;
        improve = true; // Permitimos un cierto empeoramiento
        if (tries >= maxTest) {
          improve = false;
        }
      }
    }
  }
}

/**
 * @brief A partir de la solucion actual, intercambiamos un punto de la ruta por otro punto no seleccionado
 * @param copy
 */
void LocalSearch::swap(Route &copy) {
  Route swaped(copy);
  int indexInSolution = 0;
  while (indexInSolution == 0 || indexInSolution == swaped.getNumberOfLocations() - 1)
    indexInSolution = rand() % swaped.getNumberOfLocations();
  int index = rand() % nonVisited.size();
  std::set<int>::iterator it = nonVisited.begin();
  std::advance(it, index);
  int pointToInsert = *it;
  int pointToErase = copy.getLocationInRoute(indexInSolution);
  // Intercambiamos el punto
  swaped.setPointInRoute(indexInSolution, pointToInsert);
  int routeDistance = 0;
  if (recalculateRoute(swaped, routeDistance)) {
    nonVisited.insert(pointToErase);
    nonVisited.erase(pointToInsert);
    visited.insert(pointToInsert);
    copy = swaped;
    copy.setDuration(routeDistance);
  }
}

