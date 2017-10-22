//
// Created by Marrero on 11/10/2017.
//

#include "Route.hpp"
#include <iostream>
#include "Map.hpp"
#include <iomanip>

using namespace std;

string Route::toString() {
  string resultStr = " ";
  for (int i = 0; i < route.size(); ++i) {
    resultStr += to_string(route[i]) + "-";
  }
  resultStr += " | " + to_string(rate) + "  |  " + to_string(duration) + "\n";
  return resultStr;
}

Route::Route() : rate(0.0), duration(0), locationsInRoute(0) {
}

Route::Route(int locations) : rate(0.0), duration(0), locationsInRoute(0) {
  route.resize(locations);
}

Route::Route(const Route &copy) {
  duration = copy.duration;
  rate = copy.rate;
  locationsInRoute = 0;
  locationsInRoute = copy.locationsInRoute;
  route = copy.route;
}

Route::~Route() {}

int Route::getLocationInRoute(const int point) const {
  if (!route.empty())
    return route[point];
  else {
    cerr << "Route is empty" << endl;
    exit(-1);
  }
}

/**
 * @brief Incluimos una localizacion en la ruta
 * @param point
 * @param d
 */
void Route::addPointToRoute(const int point, const int d, bool rated) {
  route.push_back(Map::getLocation(point).getId());
  locationsInRoute++;
  if (rated)
    rate += Map::getLocation(point).getStars();
  duration += d;
}

void Route::setPointInRouteById(const int id, const int d) {
  route.push_back(id);
  locationsInRoute++;
  // TODO
  duration += d;
}

vector<int> Route::getRoute() const {
  return route;
}

void Route::setDuration(const int d) {
  duration = d;
}

int Route::getDuration() const {
  return duration;
}

int Route::getNumberOfLocations() const {
  return locationsInRoute;
}

double Route::getRate() const {
  return rate;
}

void Route::setRate(const double r) {
  rate = r;
}