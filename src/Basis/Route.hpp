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
  Route(const Route &copy);
  virtual ~Route();
 private:
  vector<int> route;
  double rate;
  int duration;
  int locationsInRoute;
 public:
  vector<int> getRoute() const;
  int getLocationInRoute(const int point) const;
  int getNumberOfLocations() const;
  double getRate() const;
  int getDuration() const;
  void addPointViaId(const int id);
  void addPoint(const int point);
  void increaseDuration(const int distance);
  void increaseRate(const double rate);
  void setRate(const double r);
  void setDuration(const int);
  void setPointInRoute(const int index, const int point);
  void setRoute(vector<int>& newRoute);
 public:
  void initRoute();
  void finishRoute();
 public:
  string toString(bool verbose);
};
#endif //MRT_SOLUTIONS_HPP
