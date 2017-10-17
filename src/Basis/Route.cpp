//
// Created by Marrero on 11/10/2017.
//

#include "Route.hpp"
#include <iostream>
#include "Map.hpp"

using namespace std;

string Route::toString() {
  string resultStr = "";
  for (int i = 0; i < route.size(); ++i) {
    resultStr += route[i] + " ";
  }
  resultStr += "| " + to_string(rate) + "\n";
  return resultStr;
}

Route::Route() : rate(0.0), duration(0), locationsInRoute(0) {
}

Route::Route(int locations) : rate(0.0), duration(0), locationsInRoute(0) {
  route.resize(locations);
}

Route::~Route() {}

int Route::getLocationInRoute(const int point) {
  if (!route.empty())
    return route[point];
  else {
    cerr << "Route is empty" << endl;
    exit(-1);
  }
}

void Route::setPointInRoute(const int point) {
  route.push_back(point);
  locationsInRoute++;
  rate += Map::getLocation(point).getStars();
}

vector<int> Route::getRoute() {
  return route;
}

void Route::setDuration(const int d) {
  duration = d;
}

int Route::getDuration() {
  return duration;
}

int Route::getNumberOfLocations() {
  return locationsInRoute;
}

void Route::setRate(const double r) {
  rate = r;
}