//
// Created by Marrero on 31/10/2017.
//

#include <iostream>
#include <cmath>
#include "VNS.hpp"
#include "../Basis/Tourist.hpp"
#include "Greedy.hpp"

using namespace std;
const string VNS::NAME = "Variable Neighborhood Search";
const int VNS::MAX_K = 3;

VNS::VNS() : Metaheuristic(NAME) {}

VNS::~VNS() {
  // Nothing Really
}

void VNS::run() {
  Greedy greedy;
  greedy.run(); // Obtenemos las soluciones de partida
  for (int iRoute = 0; iRoute < Tourist::days; iRoute++) {
    solutions[iRoute] = greedy.getSolution(iRoute);
    Route child = solutions[iRoute];
    int k = 1;
    while (k < MAX_K) {
      neighborhoodSearch(k, child);
      double childEvaluation = evaluate(child);
      if (isgreater(childEvaluation, solutions[iRoute].getRate())) {
        solutions[iRoute] = child;
        k = 1;
      } else {
        k++;
      }
    }
  }
}

void VNS::initParams() {
  // Nothing Really
}

string VNS::toString() {
  return Metaheuristic::toString();
}

void VNS::neighborhoodSearch(const int k, Route &child) {
  if (k > MAX_K || k < 1) {
    cerr << "Error in neighboorhoodSearch. K = " << k << endl;
  } else {
    switch (k) {
      default: break;
      case 1: insert(child);
        break;
      case 2: remove(child);
        break;
      case 3: swap(child);
        break;
    }
  }
}

void VNS::insert(Route &copy) {
  Route inserted(copy);
  int indexToInsert = rand() % nonVisited.size();
  set<int>::iterator it = nonVisited.begin();
  advance(it, indexToInsert);
  int pointToInsert = *it;
  inserted.setRate(inserted.getRate() + Map::getLocation(pointToInsert).getStars());
  vector<int> newRoute(copy.getRoute());
  newRoute.push_back(Tourist::start);
  newRoute[newRoute.size() - 2] = pointToInsert;
  inserted.setRoute(newRoute);
  int routeDistance = 0;
  if (recalculateRoute(inserted, routeDistance)) {
    nonVisited.erase(pointToInsert);
    visited.insert(pointToInsert);
    copy = inserted;
    copy.setDuration(routeDistance);
  }
}

void VNS::remove(Route &copy) {
  Route removed(copy);
  int indexToRemove = 0;
  while (indexToRemove == 0 || indexToRemove == removed.getNumberOfLocations() - 1) {
    indexToRemove = rand() % removed.getNumberOfLocations();
  }
  int pointToRemove = removed.getLocationInRoute(indexToRemove);
  removed.setRate(removed.getRate() - Map::getLocation(pointToRemove).getStars());
  vector<int> newRoute;
  for (int location : removed.getRoute())
    if (location != pointToRemove)
      newRoute.push_back(location);
  removed.setRoute(newRoute);
  int routeDistance = 0;
  if (recalculateRoute(removed, routeDistance)) {
    nonVisited.insert(pointToRemove);
    visited.erase(pointToRemove);
    copy = removed;
    copy.setDuration(routeDistance);
  }
}

void VNS::swap(Route &copy) {
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
