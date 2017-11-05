//
// Created by Marrero on 11/10/2017.
//

#include "Map.hpp"
#include <algorithm>

int Map::numberOfLocations = 0;
vector<Location> Map::locations;
vector<int> Map::distances;

const int Map::RATIO = 0;
const int Map::STARS = 1;
const int Map::PONDERATION = 2;

/**
 * @brief Comparamos los lugares por el ratio Duracion/Estrellas de cada lugar
 * @param a
 * @param b
 * @return
 */
bool compareRatio(Location &a, Location &b) {
  return ((a.getDuration() / a.getStars()) > (b.getDuration() / b.getStars()));
}

/**
 * @brief Comparamos los lugares por la cantidad de estrellas que tiene cada uno de los lugares
 * @param a
 * @param b
 * @return
 */
bool compareStars(Location &a, Location &b) {
  return (a.getStars() > b.getStars());
}

/**
 * @brief Realizamos una ponderacion para comparar los lugares
 * @param a
 * @param b
 * @return
 */
bool comparePonderation(Location &a, Location &b) {
  double ponderationA = (0.3 * a.getDuration() + 0.7 * a.getStars()) / pow(a.getStars(), 2);
  double ponderationB = (0.3 * b.getDuration() + 0.7 * b.getStars() / (pow(b.getStars(), 2)));
  return (ponderationA > ponderationB);
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
  if (i <= j)
    return i * size - (i - 1) * i / 2 + j - i;
  else
    return j * size - (j - 1) * j / 2 + i - j;
}

/**
 * @brief Ordenamos las localizaciones por diferentes factores
 */
void Map::sortBy(const int type, vector<Location> &sorted) {
  sorted = locations;
  if (type != RATIO && type != PONDERATION && type != STARS)
    return;
  else {
    switch (type) {
      case RATIO: sort(sorted.begin(), sorted.end(), compareRatio);
        break;
      case PONDERATION: sort(sorted.begin(), sorted.end(), comparePonderation);
        break;
      case STARS: sort(sorted.begin(), sorted.end(), compareStars);
      default: break;
    }
  }
}

