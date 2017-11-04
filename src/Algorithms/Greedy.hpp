//
// Created by Marrero on 17/10/2017.
//

#ifndef MRT_GREEDY_HPP
#define MRT_GREEDY_HPP
#include "Metaheuristic.hpp"

class Greedy : public Metaheuristic {
 public:
  Greedy();
  virtual ~Greedy();
  virtual void run();
  virtual void initParams();
  string toString();
 public:
  Route initialRoute;
 public:
  static const string NAME;
};
#endif //MRT_GREEDY_HPP
