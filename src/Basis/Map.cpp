//
// Created by Marrero on 11/10/2017.
//

#include "Map.hpp"
#include <algorithm>

int Map::numberOfLocations = 0;
vector<Location> Map::locations;
vector<int> Map::distances;

bool compareRatio(Location &a, Location &b) {
  return ((a.getDuration() / a.getStars()) > (b.getDuration() / b.getStars()));
}

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
  return distances[computeGetDistance(start, end, numberOfLocations)];
}

int Map::computeGetDistance(const int i, const int j, const int size) {
 if(i <= j)
   return i * size - (i - 1) * i / 2 + j - i;
 else
   return j * size - (j - 1) * j / 2 + i - j;
}

/**
 * @brief Ordenamos las localizaciones por el ratio DURACION/ESTRELLAS
 */
void Map::sortByRatio() {
  sort(locations.begin(), locations.end(), compareRatio);
}

