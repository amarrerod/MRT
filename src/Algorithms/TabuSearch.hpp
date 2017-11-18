//
// Created by Marrero on 31/10/2017.
//

#ifndef MRT_TABUSEARCH_HPP
#define MRT_TABUSEARCH_HPP
#include "Metaheuristic.hpp"
#include <queue>

class TabuSearch : public Metaheuristic {
 public:
  TabuSearch(const int size, const int tweaks);
  TabuSearch();
  virtual ~TabuSearch();
  virtual void run();
  virtual void initParams();
  string toString();
 private:
  void tweak(Route& children);
  bool inList(const int point);
 public:
  static const string NAME;
 private:
  queue<int> tabuList;
  int listSize;
  int tweaks;
};
#endif //MRT_TABUSEARCH_HPP
