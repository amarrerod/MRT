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
  vector<vector<int>> routes;
 public:
  vector<vector<int>> &getRoutes();
  int getLocationInRoute(const int route, const int point);
  vector<int> &getRouteNumber(const const int route);

  void setPointInRoute(const int route, const int point);

};
#endif //MRT_SOLUTIONS_HPP
