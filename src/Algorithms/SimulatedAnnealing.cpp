//
// Created by Marrero on 14/10/2017.
//

#include "SimulatedAnnealing.hpp"
#include "../Basis/Tourist.hpp"
#include "Greedy.hpp"
#include <iostream>
#include <cmath>
#include <random>

#define DEBUG
using namespace std;
const string SimulatedAnnealing::NAME = "Simulated Annealing";

SimulatedAnnealing::SimulatedAnnealing()
    : Metaheuristic(NAME), initialTemperature(-1.0), temperature(-1.0), decrement(0.0) {
}

SimulatedAnnealing::SimulatedAnnealing(const double initial, const double decre)
    : initialTemperature(initial), temperature(initial), decrement(decre) {
  name = NAME;
}

SimulatedAnnealing::~SimulatedAnnealing() {}

void SimulatedAnnealing::initParams() {
  // TODO
}

/**
 * @brief Ejecutamos el algoritmo para generar la i-ésima ruta
 * @param iRoute
 */
void SimulatedAnnealing::run() {
  Greedy greedy;
  greedy.run();
  for (int iRoute = 0; iRoute < Tourist::days; ++iRoute) {
    solutions[iRoute] = greedy.getSolution(iRoute);
    temperature = initialTemperature;
    while (isgreater(temperature, 1.0)) {
      Route child = solutions[iRoute];
      perturbateSolution(child);
      double childEvaluation = evaluate(child);
      double evaluation = evaluate(solutions[iRoute]);
      if (isgreater(childEvaluation, evaluation)) {
        solutions[iRoute] = child;
      } else {
        std::random_device rd;
        mt19937 generation(rd());
        uniform_real_distribution<double> distribution(0.0, 1.0);
        double randomProbability = distribution(generation);
        double probability = -(childEvaluation - evaluation);
        probability = exp(probability / temperature);
        if (isgreater(randomProbability, probability)) {
          solutions[iRoute] = child;
        }
      }
      updateTemperature();
    }
  }
}

/**
 * @brief Generamos una perturbacion cambiando un punto de la ruta
 * @return
 */
void SimulatedAnnealing::perturbateSolution(Route &copy) {
  Route swaped(copy);
  int indexInSolution = 0;
  while (indexInSolution == 0 || indexInSolution == swaped.getNumberOfLocations() - 1)
    indexInSolution = rand() % swaped.getNumberOfLocations();
  int index = rand() % nonVisited.size();
  std::set<int>::iterator it = nonVisited.begin();
  std::advance(it, index);
  int pointToInsert = *it;
  int pointToErase = copy.getLocationInRoute(indexInSolution);
  // Intercambiamos el punto
  swaped.setPointInRoute(indexInSolution, pointToInsert);
  int routeDistance = 0;
  if (recalculateRoute(swaped, routeDistance)) {
    nonVisited.insert(pointToErase);
    nonVisited.erase(pointToInsert);
    visited.insert(pointToInsert);
    copy = swaped;
    copy.setDuration(routeDistance);
  }
}

void SimulatedAnnealing::updateTemperature() {
  temperature *= decrement;
}

