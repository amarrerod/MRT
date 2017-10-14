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
 public:
  vector<int> getRoute();
  int getLocationInRoute(const int point);
  double getRate();
  void setPointInRoute(const int point);
  void setRate(const double r);
 public:
  string toString();
};
#endif //MRT_SOLUTIONS_HPP
