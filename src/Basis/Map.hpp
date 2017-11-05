//
// Created by Marrero on 11/10/2017.
//

#ifndef MRT_MAP_HPP
#define MRT_MAP_HPP
#include <vector>
#include <string>
#include "Location.hpp"

class Map {
 public:
  Map() {};
  static void setParams(const int num, vector<Location> &locations, vector<int> &distances);
  virtual ~Map() {};
 private:
  static int numberOfLocations;
  static vector<int> distances;
  static vector<Location> locations;
 public:
  static void setLocations(vector<Location> &locations);
  static vector<vector<int>> &getDistances();
  static vector<Location> &getLocations();
  static int getDistanceFromTo(const int start, const int end);
  static int getNumberOfLocations();
  static Location getLocation(const int i);
  static void sortBy(const int type, vector<Location>& sorted);
 private:
  static int computeGetDistance(const int start, const int end, const int size);
 public:
  static string &toString();
 public:
  static const int RATIO;
  static const int STARS;
  static const int PONDERATION;
};
#endif //MRT_MAP_HPP
