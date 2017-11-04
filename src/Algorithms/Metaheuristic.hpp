
#ifndef MRT_METAHEURISTIC_HPP
#define MRT_METAHEURISTIC_HPP
#include "Metaheuristic.hpp"
#include <string>
#include <set>
#include "../Basis/Route.hpp"
#include "../Basis/Map.hpp"

using namespace std;
class Metaheuristic {
 public:
  Metaheuristic();
  Metaheuristic(const string name);
  virtual ~Metaheuristic();
 public:
  virtual void run() = 0; // Obtenemos una ruta para cada dia de estancia
  virtual void initParams() = 0;
  string toString();
  virtual void printResults();
 protected:
  double evaluate(Route &route);
 protected:
  void generateRandomSolution(const int);
 public:
  static int evaluations;
  static int selectionMode;
 protected:
  string name;
  vector<Route> solutions;
  // Vectores para almacenar los ID de las localizaciones comprobadas
  set<int> visited;
  set<int> nonVisited;
 public:
  static const int FACTOR;
  static const int STARS;
  static const int PONDERATE;
};
#endif //MRT_METAHEURISTIC_HPP
