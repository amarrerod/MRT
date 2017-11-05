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
  int pointInSolution = 0;
  while (pointInSolution == 0 || pointInSolution == swaped.getNumberOfLocations() - 1)
    pointInSolution = rand() % swaped.getNumberOfLocations();
  int pointUnselected = rand() % nonVisited.size();
  int point = swaped.getRoute()[pointInSolution];
  bool feasible = true;
  // Intercambiamos el punto
  swaped.setPointInRoute(pointInSolution, pointUnselected);
  int routeDistance = 0;
  for (int i = 0; i < (swaped.getRoute().size() - 1) && feasible; i++) {
    routeDistance += Map::getDistanceFromTo(swaped.getLocationInRoute(i), swaped.getLocationInRoute(i + 1));
    if (routeDistance > Tourist::time)
      feasible = false;
  }
  if (feasible) {
    nonVisited.insert(point);
    nonVisited.erase(pointUnselected);
    visited.insert(pointUnselected);
    copy = swaped;
    copy.setDuration(routeDistance);
  }
}

