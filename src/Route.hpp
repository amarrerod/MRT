//
// Created by Marrero on 11/10/2017.
//

#ifndef MRT_SOLUTIONS_HPP
#define MRT_SOLUTIONS_HPP
#include <vector>

using namespace std;
class Route {
 public:
  Route();
  Route(int locations);
  virtual ~Route();
 private:
  vector<int> route;
 public:
  vector<int> &getRoute();
  int getLocationInRoute(const int point);
  void setPointInRoute(const int point);
};
#endif //MRT_SOLUTIONS_HPP
