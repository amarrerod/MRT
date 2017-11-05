//
// Created by Marrero on 17/10/2017.
//

#include "Greedy.hpp"
#include "../Basis/Tourist.hpp"
#include "../Utils/Compare.hpp"
#include <iostream>
#include <algorithm>

using namespace std;
const string Greedy::NAME = "GREEDY";

Greedy::Greedy() :
    Metaheuristic(NAME) {
  initParams();
}

Greedy::~Greedy() {}

void Greedy::initParams() {
  Map::sortBy(STARS, sorted); // Ordenamos las localizaciones por estrellas
}

void Greedy::run() {
  for (int i = 0; i < Tourist::days; i++) {
    solutions[i].addPoint(Tourist::start);
    solutions[i].increaseDuration(0);
    solutions[i].increaseRate(Map::getLocation(Tourist::start).getStars());
    int routeDuration = 0, waybackDuration = 0, index = 0;
    while ((routeDuration + waybackDuration < Tourist::time) && (index < sorted.size())) {
      if (sorted[index].getCategory() == Location::HOTEL)
        index++; // Pasamos al siguiente objeto
      else {
        int point = sorted[index].getId();
        int duration = sorted[index].getDuration();
        int pathDistance = Map::getDistanceFromTo(solutions[i].getRoute().back(), point);
        int wayback = Map::getDistanceFromTo(point, solutions[i].getRoute().front());
        if ((duration + pathDistance + wayback) + routeDuration < Tourist::time) {
          waybackDuration = wayback;
          routeDuration += duration + pathDistance;
          solutions[i].addPoint(point);
          solutions[i].increaseRate(sorted[index].getStars());
          visited.insert(point);
          nonVisited.erase(point);
        }
        index++;
      }
    }
    solutions[i].addPoint(Tourist::start);
    solutions[i].increaseDuration(waybackDuration + routeDuration);
    restartSorted();
  }
}

void Greedy::restartSorted() {
  sorted.clear();
  set<int>::iterator it;
  for (it = nonVisited.begin(); it != nonVisited.end(); ++it) {
    int point = *it;
    sorted.push_back(Map::getLocation(point));
  }
  sort(sorted.begin(), sorted.end(), compareStars);
}
