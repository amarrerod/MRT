
#include "Metaheuristic.hpp"
#include "../Basis/Tourist.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <numeric>
#include <algorithm>
#include "../Utils/Compare.hpp"
#include "../Utils/Randomize.hpp"

using namespace std;
using namespace std::chrono;
const string EXTENSION = ".rs";
const string PATH = "D:\\Proyectos\\MRT\\results\\";

const int Metaheuristic::FACTOR = 0;
const int Metaheuristic::STARS = 1;
const int Metaheuristic::PONDERATE = 2;
int Metaheuristic::selectionMode = 1; // Por defecto nos quedamos con las estrellas
int Metaheuristic::evaluations = 0;

void Metaheuristic::printResults(bool verbose) {
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
      outputFile << solutions[i].toString(verbose);
    }
    outputFile.close();
  } else {
    cerr << "Error trying to write results in: " + fileName << endl;
    exit(-1);
  }
}

int Metaheuristic::getOppositePoint(const int point) {
  return (Location::NUM_HOTELS + Map::getNumberOfLocations() - point);
}

/**
 * @brief Generamos la ruta iRoute de forma aleatoria para iniciar los algoritmos
 */
Route Metaheuristic::generateRandomSolution() {
  Route randomRoute;
  randomRoute.addPoint(Tourist::start);
  randomRoute.increaseDuration(0);
  randomRoute.increaseRate(Map::getLocation(Tourist::start).getStars());
  int wayBackDuration = 0;
  int routeDuration = 0;
  // Puntos comprobados en esta iteracion
  set<int> checked(visited);
  // Mientras podamos incluir más lugares y no hayamos comprobado todos los restantes
  while (routeDuration + wayBackDuration < Tourist::time
      && checked.size() != Map::getNumberOfLocations() - Location::NUM_HOTELS) {
    int index = getRandomElementBetween(0, nonVisited.size() - 1);
    std::set<int>::iterator it = nonVisited.begin();
    std::advance(it, index);
    int point = *it;
    int duration = Map::getLocation(point).getDuration();
    int pathDistance = Map::getDistanceFromTo(randomRoute.getRoute().back(), point);
    int wayback = Map::getDistanceFromTo(point, randomRoute.getRoute().front());
    if ((duration + pathDistance + wayback) + routeDuration < Tourist::time) {
      visited.insert(point);
      nonVisited.erase(point);
      checked.insert(point);
      wayBackDuration = wayback;
      routeDuration += duration + pathDistance;
      randomRoute.addPoint(point);
      randomRoute.increaseRate(Map::getLocation(point).getStars());
    } else {
      checked.insert(point); // Ha sido comprobado pero aún puede ser visitado en otra ruta
      nonVisited.erase(point);
    }
  }
  randomRoute.addPoint(Tourist::start);
  randomRoute.increaseDuration(wayBackDuration + routeDuration);
  nonVisited.insert(checked.begin(), checked.end());
  restartSets();
  return randomRoute;
}

/**
 * @brief Aplicamos la estrategia de OBL para crear una solucion inicial
 */
Route Metaheuristic::generateRandomSolutionWithOBL() {
  // FIXME ME CAGO EN TU PUTA MADRE
  Route randomRoute;
  randomRoute.addPoint(Tourist::start);
  randomRoute.increaseDuration(0);
  randomRoute.increaseRate(Map::getLocation(Tourist::start).getStars());
  int wayBackDuration = 0;
  int routeDuration = 0;
  // Puntos comprobados en esta iteracion
  set<int> checked(visited);
  // Mientras podamos incluir más lugares y no hayamos comprobado todos los restantes
  while (routeDuration + wayBackDuration < Tourist::time
      && checked.size() != Map::getNumberOfLocations() - Location::NUM_HOTELS) {
    int index = getRandomElementBetween(0, nonVisited.size() - 1);
    std::set<int>::iterator it = nonVisited.begin();
    std::advance(it, index);
    int point = *it;
    int secondPoint = getOppositePoint(point);
    int duration, pathDistance, wayback;
    if (nonVisited.find(secondPoint) != nonVisited.end()) { // No ha sido visitado
      Location firstLocation = Map::getLocation(point);
      Location secondLocation = Map::getLocation(secondPoint);
      if (comparePonderation(firstLocation, secondLocation)) {
        duration = firstLocation.getDuration();
        pathDistance = Map::getDistanceFromTo(randomRoute.getRoute().back(), point);
        wayback = Map::getDistanceFromTo(point, randomRoute.getRoute().front());
      } else {
        duration = secondLocation.getDuration();
        pathDistance = Map::getDistanceFromTo(randomRoute.getRoute().back(), secondPoint);
        wayback = Map::getDistanceFromTo(secondPoint, randomRoute.getRoute().front());
        point = secondPoint; // Para insertarlo en el conjunto de visitados
      }
    }
    if ((duration + pathDistance + wayback) + routeDuration < Tourist::time) {
      visited.insert(point);
      nonVisited.erase(point);
      checked.insert(point);
      wayBackDuration = wayback;
      routeDuration += duration + pathDistance;
      randomRoute.addPoint(point);
      randomRoute.increaseRate(Map::getLocation(point).getStars());
    } else {
      checked.insert(point); // Ha sido comprobado pero aún puede ser visitado en otra ruta
    }
  }
  randomRoute.addPoint(Tourist::start);
  randomRoute.increaseDuration(wayBackDuration + routeDuration);
  return randomRoute;
}

/**
 * @brief La funcion de evaluacion es la suma de las estrellas de las localizaciones
 * @param route
 * @return
 */
double Metaheuristic::evaluate(Route &route) {
  double evaluation = 0.0;
  for (int i = 0; i < route.getNumberOfLocations() - 1; i++) {
    evaluation += Map::getLocation(route.getLocationInRoute(i)).getStars();
  }
  return evaluation;
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
  // Rellenamos el vector de no comprobados con los id desde el ultimo hotel
  for (int i = Location::NUM_HOTELS; i < Map::getNumberOfLocations(); i++)
    nonVisited.insert(i);
  for (int i = 0; i < Location::NUM_HOTELS; i++)
    visited.insert(i);
  solutions.resize(Tourist::days);
}

Metaheuristic::~Metaheuristic() {}

string Metaheuristic::toString() {
  return "Metaheuristic: " + name + "\n";
}

Route Metaheuristic::getSolution(const int index) {
  if (index < 0 || index > solutions.size())
    return {};
  else
    return solutions[index];
}

bool Metaheuristic::recalculateRoute(Route &route, int &distance) {
  bool feasible = true;
  distance = 0;
  for (int i = 0; i < (route.getRoute().size() - 1) && feasible; i++) {
    distance += Map::getDistanceFromTo(route.getLocationInRoute(i), route.getLocationInRoute(i + 1))
        + Map::getLocation(route.getLocationInRoute(i)).getDuration();
    if (distance > Tourist::time)
      feasible = false;
  }
  return feasible;
}

void Metaheuristic::restartSets() {
  for (int i : visited)
    nonVisited.erase(nonVisited.find(i));
}




