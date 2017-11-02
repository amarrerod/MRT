//
// Created by Marrero on 14/10/2017.
//

#ifndef MRT_SIMULATEDANNEALING_HPP
#define MRT_SIMULATEDANNEALING_HPP
#include "Metaheuristic.hpp"

class SimulatedAnnealing : public Metaheuristic {
 public:
  SimulatedAnnealing(const double initial, const double decre, const int tries);
  SimulatedAnnealing();
  virtual ~SimulatedAnnealing();
 public:
  virtual void run();
  virtual void initParams();
  string toString();
 private:
  void perturbateSolution(Route &initial, Route &child);
  int evaluateDifference(Route &initial, Route &child);
 private:
  double initialTemperature;
  double temperature;
  double decrement;
  int chances;
 protected:
  static const string NAME;
};
#endif //MRT_SIMULATEDANNEALING_HPP

