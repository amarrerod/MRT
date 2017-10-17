
#include <string>
#include "../Basis/Route.hpp"
#include "../Basis/Map.hpp"

using namespace std;
class Metaheuristic {
 public:
  Metaheuristic();
  Metaheuristic(const string name);
  virtual ~Metaheuristic();
 public:
  virtual void run() = 0;
  virtual void initParams() = 0;
  string toString();
  virtual void printResults();
 private:
  void generateRandomSolution();
  void restartChecks(); // Tras completar una ruta reiniciamos los vectores auxiliares
  void evaluateRoute(Route& route);
 private:
  string name;
  vector<Route> solutions;
 private:
  // Vectores para almacenar los ID de las localizaciones comprobadas
  vector<int> checked;
  vector<int> unchecked;

 private:
  static const int NOT_VALID;
};