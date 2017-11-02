//
// Created by Marrero on 31/10/2017.
//

#ifndef MRT_LOCALSEARCH_HPP
#define MRT_LOCALSEARCH_HPP
#include "Metaheuristic.hpp"

class LocalSearch : public Metaheuristic {
 public:
  LocalSearch(const int test);
  LocalSearch();
  virtual ~LocalSearch();
  virtual void run();
  virtual void initParams();
  string toString();
 public:
  int maxTest;
 protected:
  static const string NAME;
 private:
  void swap(Route& copy);
};
#endif //MRT_LOCALSEARCH_HPP
