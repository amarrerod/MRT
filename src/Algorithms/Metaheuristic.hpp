
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
  void restartChecks(); // Tras completar una ruta reiniciamos los vectores auxiliares
  bool feasibleRoute(Route &route);
  int evaluate(Route& route);
 protected:
  void generateRandomSolution(const int);
 protected:
  string name;
  vector<Route> solutions;
  // Vectores para almacenar los ID de las localizaciones comprobadas
  set<int> visited;
  set<int> nonVisited;
};

#endif //MRT_METAHEURISTIC_HPP
