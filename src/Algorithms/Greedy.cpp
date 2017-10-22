//
// Created by Marrero on 17/10/2017.
//

#include "Greedy.hpp"
#include "../Basis/Tourist.hpp"
#include <iostream>

using namespace std;
const string Greedy::NAME = "GREEDY";

Greedy::Greedy() :
    Metaheuristic(NAME) {
  initialRoute.addPointToRoute(Tourist::start, 0, true);
  initParams();
}

Greedy::~Greedy() {}

void Greedy::initParams() {
  Map::sortByRatio();
}

void Greedy::run() {
  int index = 0;
  int wayBackDuration = 0;
  while ((initialRoute.getDuration() < Tourist::time)
      && (index - (Map::getNumberOfLocations() - Location::NUM_HOTELS))) {
    int pathDuration =
        Map::getLocation(index).getDuration() + Map::getDistanceFromTo(initialRoute.getRoute().back(), Map::getLocation(index).getId());
     wayBackDuration = Map::getDistanceFromTo(Map::getLocation(index).getId(), initialRoute.getRoute().front());
    if (pathDuration + initialRoute.getDuration() + wayBackDuration < Tourist::time) {
      initialRoute.addPointToRoute(index, pathDuration, true);
    }
    index++;
  }
  initialRoute.addPointToRoute(Tourist::start, wayBackDuration, false);
  printResults();
}