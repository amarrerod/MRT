//
// Created by Marrero on 14/10/2017.
//

#ifndef MRT_SIMULATEDANNEALING_HPP
#define MRT_SIMULATEDANNEALING_HPP
#include "Metaheuristic.hpp"

class SimulatedAnnealing : public Metaheuristic {
 public:
  SimulatedAnnealing(const double initial, const double decre);
  SimulatedAnnealing();
  virtual ~SimulatedAnnealing();
 public:
  virtual void run();
  virtual void initParams();
  string toString();
 private:
  void perturbateSolution(Route &child);
  void updateTemperature();
 private:
  double initialTemperature;
  double temperature;
  double decrement;
 protected:
  static const string NAME;
};
#endif //MRT_SIMULATEDANNEALING_HPP

