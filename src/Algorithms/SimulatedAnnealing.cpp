//
// Created by Marrero on 14/10/2017.
//

#include "SimulatedAnnealing.hpp"
#include "../Basis/Tourist.hpp"
#include <cmath>

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
    double loopTemperature = initialTemperature;
    int tries = 0;
    while (isgreater(loopTemperature, 0.0) && tries < chances) {
      // ALTERAR SOLUCION
      // EVALUAR DIFERENCIA
      // ACTUALIZAR LA TEMPERATURA
      Route child(solutions.at(iRoute));
      perturbateSolution(solutions[iRoute], child);
      if (feasibleRoute(child)) { // Si el nuevo hijo es factible
        int difference = evaluateDifference(solutions[iRoute], child);
        if (difference > 0) { // La nueva solucion tiene más estrellas
          solutions[iRoute] = child;
        } else {
          const double randomProbability = (double) rand() / (RAND_MAX);
          const double probability = exp(-(child.getRate() - solutions[iRoute].getRate()) / temperature);
          if (isgreater(randomProbability, probability)) {
            solutions[iRoute] = child;
          }
        }
      } else {
        tries++;
      }
      loopTemperature *= decrement;
    }
  }
}

/**
 * @brief Generamos una perturbacion intercambiando de orden dos puntos
 * @return
 */
void SimulatedAnnealing::perturbateSolution(Route &initial, Route &child) {
  int first = 0, second = 0;
  while (first == 0 && second == 0 && first == second) {
    first = rand() % initial.getRoute().size(); // Random dentro del rango del vector
    second = rand() % initial.getRoute().size();
  }
  int swapVar = first;
  child.getRoute()[first] = second;
  child.getRoute()[second] = swapVar;
}

int SimulatedAnnealing::evaluateDifference(Route &initial, Route &child) {
  return evaluate(child) - evaluate(initial);
}

void SimulatedAnnealing::initParams() {
  // TODO
}

