//
// Created by Marrero on 11/10/2017.
//

#ifndef MRT_SOLUTIONS_HPP
#define MRT_SOLUTIONS_HPP
#include <vector>
#include <string>

using namespace std;
class Route {
 public:
  Route();
  Route(int locations);
  virtual ~Route();
 private:
  vector<int> route;
  double rate;
  int duration;
  int locationsInRoute;
 public:
  vector<int> getRoute();
  int getLocationInRoute(const int point);
  int getNumberOfLocations();
  double getRate();
  int getDuration();
  void setPointInRoute(const int point);
  void setRate(const double r);
  void setDuration(const int);
 public:
  string toString();
};
#endif //MRT_SOLUTIONS_HPP
