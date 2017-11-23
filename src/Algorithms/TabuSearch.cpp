//
// Created by Marrero on 31/10/2017.
//

#include <cmath>
#include "TabuSearch.hpp"
#include "Greedy.hpp"
#include "../Basis/Tourist.hpp"
#include <algorithm>

const string TabuSearch::NAME = "Tabu Search";

TabuSearch::TabuSearch(const int size, const int tweaks) : Metaheuristic(NAME), listSize(size), tweaks(tweaks) {
}

TabuSearch::TabuSearch() : Metaheuristic(NAME), listSize(-1), tweaks(-1) {
}

TabuSearch::~TabuSearch() {
  // Nothing Really
}

void TabuSearch::initParams() {

}

string TabuSearch::toString() {
  return Metaheuristic::toString();
}

void TabuSearch::run() {
  //Greedy greedy;
  //greedy.run();
  for (int iRoute = 0; iRoute < Tourist::days; iRoute++) {
    Route bestFound = generateRandomSolution(); //greedy.getSolution(iRoute);
    Route actualSolution = bestFound;
    tabuList.push(bestFound.getLocationInRoute(bestFound.getRoute().size() - 1));
    bool improve = true;
    while (improve) {
      if (tabuList.size() > listSize)
        tabuList.pop();
      Route children = actualSolution;
      tweak(children);
      for (int i = 0; i < tweaks; i++) {
        Route secondChild = actualSolution;
        tweak(secondChild);
        evaluate(secondChild);
        evaluate(children);
        if (isgreater(secondChild.getRate(), children.getRate())) {
          children = secondChild;
        }
      }
      actualSolution = children;
      if (isgreater(actualSolution.getRate(), bestFound.getRate())) {
        bestFound = actualSolution;
        improve = true;
      } else {
        improve = false;
      }
    }
    // Una vez salimos del bucle en bestFound esta la mejor solucion
    solutions[iRoute] = bestFound;
  }
}

void TabuSearch::tweak(Route &children) {
  Route swaped(children);
  int indexInSolution = 0;
  int pointToErase = -1;
  while ((indexInSolution == 0 || indexInSolution == swaped.getNumberOfLocations() - 1)
      && (pointToErase == -1 && !inList(pointToErase))) {
    indexInSolution = rand() % swaped.getNumberOfLocations();
    pointToErase = children.getLocationInRoute(indexInSolution);
  }
  int pointToInsert = -1;
  while (pointToInsert == -1 && !inList(pointToInsert)) {
    int index = rand() % nonVisited.size();
    std::set<int>::iterator it = nonVisited.begin();
    std::advance(it, index);
    pointToInsert = *it;
  }
  // Actualizamos la lista tabu
  tabuList.push(pointToErase);
  tabuList.push(pointToInsert);
  // Intercambiamos el punto
  swaped.setPointInRoute(indexInSolution, pointToInsert);
  int routeDistance = 0;
  if (recalculateRoute(swaped, routeDistance)) {
    nonVisited.insert(pointToErase);
    nonVisited.erase(pointToInsert);
    visited.insert(pointToInsert);
    children = swaped;
    children.setDuration(routeDistance);
  }
}

bool TabuSearch::inList(const int point) {
  queue<int> copy = tabuList;
  while (!copy.empty()) {
    int front = copy.front();
    if (front == point)
      return true;
    else {
      copy.pop();
    }
  }
  return false;
}



