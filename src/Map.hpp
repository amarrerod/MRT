//
// Created by Marrero on 11/10/2017.
//

#ifndef MRT_MAP_HPP
#define MRT_MAP_HPP
#include <vector>
#include "Location.hpp"

class Map {
 public:
  Map();
  Map(const int &num, vector<Location> &locations);
  virtual ~Map();
 private:
  int numberOfLocations;
  vector<Location> locations;
  vector<int> distances;
 public:
  void setLocations(vector<Location> &locations);
  vector<vector<int>> &getDistances();
  vector<Location> &getLocations();
  int getDistanceFromTo(const int start, const int end);
 private:
  int computeGetDistance(const int start, const int end, const int size);
};
#endif //MRT_MAP_HPP
