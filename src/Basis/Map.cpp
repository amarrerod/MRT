//
// Created by Marrero on 11/10/2017.
//

#include "Map.hpp"

int Map::numberOfLocations = 0;
vector<Location> Map::locations;
vector<int> Map::distances;

void Map::setParams(const int num, vector<Location> &locationsAux, vector<int> &distancesAux) {
  numberOfLocations = num;
  locations = locationsAux;
  distances = distancesAux;
}

int Map::getNumberOfLocations() {
  return numberOfLocations;
}

Location Map::getLocation(const int i) {
  return locations[i];
}

void Map::setLocations(vector<Location> &locationsaux) {
  locations = locationsaux;
}

int Map::getDistanceFromTo(const int start, const int end) {
  return computeGetDistance(start, end, numberOfLocations);
}

int Map::computeGetDistance(const int start, const int end, const int size) {
  // TODO CALCULAR LA DISTANCIA
  return -1;
}