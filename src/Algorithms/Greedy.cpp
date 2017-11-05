//
// Created by Marrero on 17/10/2017.
//

#include "Greedy.hpp"
#include "../Basis/Tourist.hpp"
#include <iostream>

using namespace std;
const string Greedy::NAME = "GREEDY";

Greedy::Greedy() :
    Metaheuristic(NAME) {}

Greedy::~Greedy() {}

void Greedy::initParams() {
}

void Greedy::run() {
  vector<Location> sorted;
  Map::sortBy(STARS, sorted); // Ordenamos las localizaciones por estrellas
  initialRoute.addPoint(Tourist::start);
  initialRoute.increaseDuration(0);
  initialRoute.increaseRate(Map::getLocation(Tourist::start).getStars());
  int routeDuration = 0, waybackDuration = 0, index = 0;
  while ((routeDuration + waybackDuration < Tourist::time) && (index < sorted.size())) {
    if (sorted[index].getCategory() == Location::HOTEL)
      index++; // Pasamos al siguiente objeto
    else {
      int point = sorted[index].getId();
      int duration = sorted[index].getDuration();
      int pathDistance = Map::getDistanceFromTo(initialRoute.getRoute().back(), point);
      int wayback = Map::getDistanceFromTo(point, initialRoute.getRoute().front());
      if ((duration + pathDistance + wayback) + routeDuration < Tourist::time) {
        waybackDuration = wayback;
        routeDuration += duration + pathDistance;
        initialRoute.addPoint(point);
        initialRoute.increaseRate(sorted[index].getStars());
      }
      index++;
    }
  }
  initialRoute.addPoint(Tourist::start);
  initialRoute.increaseDuration(waybackDuration + routeDuration);
}

string Greedy::toString() {
  return initialRoute.toString();
}