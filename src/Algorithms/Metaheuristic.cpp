
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

const int Metaheuristic::FACTOR = 0;
const int Metaheuristic::STARS = 1;
const int Metaheuristic::PONDERATE = 2;
int Metaheuristic::selectionMode = 1; // Por defecto nos quedamos con las estrellas
int Metaheuristic::evaluations = 0;

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

/**
 * @brief Generamos la ruta iRoute de forma aleatoria para iniciar los algoritmos
 */
void Metaheuristic::generateRandomSolution(const int iRoute) {
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
    int index = rand() % nonVisited.size(); // Cogemos un punto no visitado aún
    std::set<int>::iterator it = nonVisited.begin();
    std::advance(it, index);
    int point = *it;
    int duration = Map::getLocation(point).getDuration();
    int pathDistance = Map::getDistanceFromTo(randomRoute.getRoute().back(), point);
    int wayback = Map::getDistanceFromTo(point, randomRoute.getRoute().front());
    /**
     * @brief Si puede incluirse en la solucion
     *          1. Lo incluimos en visitados y lo eliminamos de los no-visitados
     *          2. Realizamos los calculos
     */
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
  solutions[iRoute] = randomRoute;
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
  if(index < 0 || index > solutions.size())
    return {};
  else
    return solutions[index];
}


