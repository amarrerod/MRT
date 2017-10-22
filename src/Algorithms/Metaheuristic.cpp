
#include "Metaheuristic.hpp"
#include "../Basis/Tourist.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <numeric>
#include <algorithm>

using namespace std;
using namespace std::chrono;
const string EXTENSION = ".rs";
const string PATH = "D:\\Proyectos\\MRT\\results\\";

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
  // Rellenamos el vector de no comprobados con los id desde el ultimo hotel
  for (int i = Location::NUM_HOTELS - 1; i < Map::getNumberOfLocations(); i++)
    nonVisited.insert(i);
}

/**
 * @brief Generamos una solucion aleatoria para iniciar los algoritmos
 */
void Metaheuristic::generateRandomSolution(const int iRoute) {
  Route randomRoute;
  randomRoute.addPointToRoute(Tourist::start, 0, true);
  int wayBackDuration = 0;
  while (randomRoute.getDuration() < Tourist::time
      && visited.size() != Map::getNumberOfLocations() - Location::NUM_HOTELS) {
    int index = 0;
    int count = 0;
    // OBTENEMOS UN VALOR ALEATORIO
    index = rand() % nonVisited.size(); // Random dentro del rango del vector
    // Distancia del camino más la actividad
    int pathDistance = Map::getLocation(index).getDuration()
        + Map::getDistanceFromTo(randomRoute.getRoute().back(), index);
    wayBackDuration = Map::getDistanceFromTo(Map::getLocation(index).getId(), randomRoute.getRoute().front());
    if (pathDistance + wayBackDuration < Tourist::time) {
      visited.insert(index);
      nonVisited.erase(index);
      randomRoute.addPointToRoute(index, pathDistance, true);
    }
  }
  randomRoute.addPointToRoute(Tourist::start, wayBackDuration, false);
  solutions[iRoute] = randomRoute;
}

/**
 * @brief Sumamos las valoraciones de cada localizacion de una ruta para obtener su evaluacion
 */
bool Metaheuristic::feasibleRoute(Route &route) {
  double evaluation = 0;
  int duration = 0;
  for (int i = 0; i < route.getRoute().size() - 1; i++) {
    evaluation += Map::getLocation(i).getStars();
    duration += Map::getDistanceFromTo(route.getLocationInRoute(i), route.getLocationInRoute(i + 1))
        + Map::getLocation(i).getDuration();
    if (duration > Tourist::time) {
      return false;
    }
  }
  route.setRate(evaluation);
  route.setDuration(duration);
}

int Metaheuristic::evaluate(Route &route) {
  int evaluation = 0;
  for (int i : route.getRoute()) {
    evaluation += Map::getLocation(i).getStars();
  }
  return evaluation / route.getDuration();
}

Metaheuristic::Metaheuristic() {
  // Rellenamos el vector de no comprobados con los id desde el ultimo hotel
  for (int i = Location::NUM_HOTELS; i < Map::getNumberOfLocations(); i++)
    nonVisited.insert(i);
  for (int i = 0; i < Location::NUM_HOTELS; i++)
    visited.insert(i);
  solutions.resize(Tourist::days);
  name = "NOT_NAMED";
}

Metaheuristic::Metaheuristic(const string name) {
  this->name = name;
}

Metaheuristic::~Metaheuristic() {}

string Metaheuristic::toString() {
  return "Metaheuristic: " + name + "\n";
}


