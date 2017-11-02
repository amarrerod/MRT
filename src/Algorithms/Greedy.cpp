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
  initialRoute.addPoint(Tourist::start);
  initialRoute.increaseRate(Map::getLocation(Tourist::start).getStars());
  initParams();
}

Greedy::~Greedy() {}

void Greedy::initParams() {
  Map::sortByRatio();
}

void Greedy::run() {
  initParams();
  int index = 0;
  int wayBackDuration = 0;
  while (((initialRoute.getDuration() + wayBackDuration) <= Tourist::time)
      && (index - (Map::getNumberOfLocations() - Location::NUM_HOTELS))) {
    int pathDuration =
        Map::getLocation(index).getDuration() + Map::getDistanceFromTo(initialRoute.getRoute().back(), Map::getLocation(index).getId());
     wayBackDuration = Map::getDistanceFromTo(Map::getLocation(index).getId(), initialRoute.getRoute().front());
    if (pathDuration + initialRoute.getDuration() + wayBackDuration <= Tourist::time) {
      initialRoute.addPoint(index);
      initialRoute.increaseDuration(pathDuration);
      initialRoute.increaseRate(Map::getLocation(index).getStars());
    }
    index++;
  }
  initialRoute.addPointViaId(Tourist::start);
  initialRoute.increaseDuration(Map::getDistanceFromTo(initialRoute.getRoute().back(), Tourist::start));
}

string Greedy::toString() {
  return initialRoute.toString();
}