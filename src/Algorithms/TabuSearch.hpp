//
// Created by Marrero on 31/10/2017.
//

#ifndef MRT_TABUSEARCH_HPP
#define MRT_TABUSEARCH_HPP
#include "Metaheuristic.hpp"

class TabuSearch : public Metaheuristic {
 public:
  TabuSearch(const int size);
  TabuSearch();
  virtual ~TabuSearch();
  virtual void run();
  virtual void initParams();
  string toString();
 public:
  void setTabuListSize(const int );
  int getTabuListSize();
  vector<int> getTabuList();
  void setTabuList(vector<int>&);
 public:
  const string NAME;
 private:
  vector<int> tabuList;
  int tabuListSize;
};
#endif //MRT_TABUSEARCH_HPP
