
#include "Metaheuristic.hpp"
#include "../Basis/Tourist.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <numeric>

using namespace std;
using namespace std::chrono;
const string EXTENSION = ".rs";
const string PATH = "D:\\Proyectos\\MRT\\results\\";
const int Metaheuristic::NOT_VALID = -1;

void Metaheuristic::printResults() {
  milliseconds milliseconds1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  string milisecondsString = to_string(milliseconds1.count());
  string fileName = PATH + name + milisecondsString + EXTENSION;
  ofstream outputFile(fileName, ifstream::out);
  if (outputFile.is_open()) {
    auto end = chrono::system_clock::now();
    time_t timeStamp = chrono::system_clock::to_time_t(end);
    outputFile << ctime(&timeStamp);
    // Meter los resultados en el fichero
    for (int i = 0; i < solutions.size(); ++i) {
      outputFile << solutions[i].toString();
    }
    outputFile.close();
  } else {
    cerr << "Error trying to write results in: " + fileName << endl;
    exit(-1);
  }
}

void Metaheuristic::restartChecks() {
  unchecked.resize(Map::getNumberOfLocations() - Location::NUM_HOTELS);
  iota(unchecked.begin(), unchecked.end(), Location::NUM_HOTELS - 1);
  checked.resize(0);
}

/**
 * @brief Generamos una solucion aleatoria para iniciar los algoritmos
 */
void Metaheuristic::generateRandomSolution() {
  Route randomRoute;
  randomRoute.setPointInRoute(Tourist::start);
  while (randomRoute.getDuration() < Tourist::time
      && checked.size() != Map::getNumberOfLocations() - Location::NUM_HOTELS) {
    // TODO: TRACATÁ
    int index = NOT_VALID;
    while (index == NOT_VALID) // OBTENEMOS UN VALOR ALEATORIO
      index = rand() % unchecked.size(); // Random dentro del rango del vector
    if (Map::getLocation(index).getDuration()
        + Map::getDistanceFromTo(randomRoute.getLocationInRoute(randomRoute.getNumberOfLocations() - 1), index)
        < Tourist::time) {
      unchecked[index] = NOT_VALID;
      checked.push_back(index);
      randomRoute.setPointInRoute(index);
    }
  }
}

/**
 * @brief Sumamos las valoraciones de cada localizacion de una ruta para obtener su evaluacion
 */
void Metaheuristic::evaluateRoute(Route &route) {
  double evaluation = 0;
  for (int i : route.getRoute()) {
    evaluation += Map::getLocation(i).getStars();
  }
  route.setRate(evaluation);
}

Metaheuristic::Metaheuristic() {
  // Rellenamos el vector de no comprobados con los id desde el ultimo hotel
  unchecked.resize(Map::getNumberOfLocations() - Location::NUM_HOTELS);
  iota(unchecked.begin(), unchecked.end(), Location::NUM_HOTELS - 1);
  checked.resize(0);
  solutions.resize(Tourist::days);
}

Metaheuristic::Metaheuristic(const string name) {
  this->name = name;
}

Metaheuristic::~Metaheuristic() {}

string Metaheuristic::toString() {
  return "Metaheuristic: " + name + "\n";
}