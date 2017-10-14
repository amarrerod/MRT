//
// Created by Marrero on 14/10/2017.
//

#include "SimulatedAnnealing.hpp"

const string SimulatedAnnealing::NAME = "Simulated Annealing";

SimulatedAnnealing::SimulatedAnnealing()
    : Metaheuristic(SimulatedAnnealing::NAME), initialTemperature(-1.0), temperature (- 1.0) {

}

SimulatedAnnealing::SimulatedAnnealing(const double initial, const double decre)
    : initialTemperature(initial), decrement(decre) {
}

SimulatedAnnealing::~SimulatedAnnealing() {}

void SimulatedAnnealing::run() {

}

void SimulatedAnnealing::initParams() {

}

