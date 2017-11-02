//
// Created by Marrero on 14/10/2017.
//

#include "SimulatedAnnealing.hpp"
#include "../Basis/Tourist.hpp"
#include <cmath>
#include <iostream>

#define DEBUG
using namespace std;
const string SimulatedAnnealing::NAME = "Simulated Annealing";

SimulatedAnnealing::SimulatedAnnealing()
    : Metaheuristic(NAME), initialTemperature(-1.0), temperature(-1.0), decrement(0.0), chances(0) {

}

SimulatedAnnealing::SimulatedAnnealing(const double initial, const double decre, const int tries)
    : initialTemperature(initial), temperature(initial), decrement(decre), chances(tries) {
  name = NAME;
}

SimulatedAnnealing::~SimulatedAnnealing() {}

/**
 * @brief Ejecutamos el algoritmo para generar la i-ésima ruta
 * @param iRoute
 */
void SimulatedAnnealing::run() {
  for (int iRoute = 0; iRoute < Tourist::days; ++iRoute) {
    generateRandomSolution(iRoute);
#ifdef DEBUG
    cout << "Ruta: " << iRoute << " terminada" << endl;
#endif
  }
}

/**
 * @brief Generamos una perturbacion cambiando un punto de la ruta
 * @return
 */
void SimulatedAnnealing::perturbateSolution(Route &initial, Route &child) {

}

int SimulatedAnnealing::evaluateDifference(Route &initial, Route &child) {
}

void SimulatedAnnealing::initParams() {
  // TODO
}

