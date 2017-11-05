//
// Created by Marrero on 17/10/2017.
//

#ifndef MRT_GREEDY_HPP
#define MRT_GREEDY_HPP
#include <stack>
#include "Metaheuristic.hpp"

class Greedy : public Metaheuristic {
 public:
  Greedy();
  virtual ~Greedy();
  virtual void run();
  virtual void initParams();
  string toString();
 private:
  void restartSorted();
 public:
  vector<Location> sorted;
 public:
  static const string NAME;
};
#endif //MRT_GREEDY_HPP
