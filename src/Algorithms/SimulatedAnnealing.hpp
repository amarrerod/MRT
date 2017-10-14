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
 public:
  static const string NAME;
 private:
  double initialTemperature;
  double temperature;
  double decrement;
};
#endif //MRT_SIMULATEDANNEALING_HPP
