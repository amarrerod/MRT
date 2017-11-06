//
// Created by Marrero on 31/10/2017.
//

#ifndef MRT_VNS_HPP
#define MRT_VNS_HPP
#include "Metaheuristic.hpp"
#include <string>

class VNS : public Metaheuristic {
 public:
  VNS();
  virtual ~VNS();
  virtual void run();
  virtual void initParams();
  string toString();
 private:
  void neighborhoodSearch(const int, Route &);
  void insert(Route &);
  void remove(Route &);
  void swap(Route &);
 protected:
  static const string NAME;
  static const int MAX_K;
};
#endif //MRT_VNS_HPP
