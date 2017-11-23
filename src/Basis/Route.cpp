//
// Created by Marrero on 11/10/2017.
//

#include "Route.hpp"
#include <iostream>
#include "Map.hpp"
#include <iomanip>
#include <sstream>

using namespace std;

string Route::toString(bool verbose) {
  string resultStr = " ";
  if (!verbose) {
    for (int i = 0; i < route.size(); ++i) {
      resultStr += to_string(route[i]) + ",";
    }
  } else {
    for (int i = 0; i < route.size(); ++i) {
      resultStr += Map::getLocation(route[i]).toString();
    }
  }
  stringstream rateStr, durationStr;
  rateStr << fixed << setprecision(1) << rate;
  int minutes = duration % 60;
  int hours = (duration - minutes) / 60;
  durationStr << hours << " horas " << minutes << " minutos";
  resultStr += "Estrellas: " + rateStr.str() + " Duración: " + durationStr.str() + " En minutos solos: " + to_string(duration)
      + "\n --- \n";
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

void Route::addPointViaId(const int id) {
  route.push_back(id);
  locationsInRoute++;
}

void Route::addPoint(const int point) {
  route.push_back(Map::getLocation(point).getId());
  locationsInRoute++;
}

void Route::increaseDuration(const int distance) {
  duration += distance;
}

void Route::increaseRate(const double r) {
  rate += r;
}

vector<int> Route::getRoute() const {
  return route;
}

void Route::setDuration(const int d) {
  duration = d;
}

void Route::setPointInRoute(const int index, const int point) {
  route[index] = point;
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

void Route::setRoute(vector<int> &newRoute) {
  route = newRoute;
}
