//
// Created by Marrero on 11/10/2017.
//

#ifndef MRT_SOLUTIONS_HPP
#define MRT_SOLUTIONS_HPP
#include <vector>

using namespace std;
class Solutions {
 public:
  Solutions();
  Solutions(int locations);
  virtual ~Solutions();
 private:
  int numberOfLocations;
  vector<int> distance;
  vector<vector<int>> routes;
 public:
  vector<vector<int>> &getRoutes();
  vector<vector<int>> &getDistances();
  int getLocationInRoute(const int route, const int point);
  vector<int> &getRouteNumber(const const int route);
  int getDistanceFromTo(const int start, const int end);
  void setPointInRoute(const int route, const int point);
 private:
  int computeGetDistance(const int start, const int end, const int size);

};
#endif //MRT_SOLUTIONS_HPP
