//
// Created by Marrero on 31/10/2017.
//

#include "TabuSearch.hpp"

const string TabuSearch::NAME = "Tabu Search";

TabuSearch::TabuSearch(const int size) : Metaheuristic(NAME), tabuListSize(size) {
  tabuList.resize(size);
}

TabuSearch::TabuSearch() : Metaheuristic(NAME), tabuListSize(-1) {
  tabuList.resize(0);
}

TabuSearch::~TabuSearch() {

}

void TabuSearch::run() {

}

void TabuSearch::initParams() {

}

string TabuSearch::toString() {
  return Metaheuristic::toString();
}

void TabuSearch::setTabuListSize(const int size) {
  tabuListSize = size;
  tabuList.clear();
  tabuList.resize(size);
}

int TabuSearch::getTabuListSize() {
  return tabuListSize;
}

vector<int> TabuSearch::getTabuList() {
  return tabuList;
}

void TabuSearch::setTabuList(vector<int> &newList) {
  tabuList.clear();
  tabuList = newList;
}
