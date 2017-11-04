
#include <iostream>
#include <vector>
#include "Handlers/Loader.hpp"
#include "Basis/Map.hpp"
#include "Algorithms/SimulatedAnnealing.hpp"
#include "Utils/RandomNumber.hpp"
#include "Algorithms/Greedy.hpp"
#include "Algorithms/LocalSearch.hpp"

using namespace std;
const int NUM_PARAMS = 7;
//#define DEBUG

int main(int argc, char **argv) {
  /**
   * @brief 1. Cargar todos los datos (Turista, Localizaciones, Distancias)
   *        2. Inicializar la Metaheuristica (Numero de rutas, preferencias)
   *        3. Ejecutar algoritmo.
   *        4. Mostrar resultados.
   **/
  if (argc != NUM_PARAMS) {
    cerr << "Error in params" << endl;
    cerr << "Usage: ./MRT tourist.conf location.conf distances.conf <seed> <evaluations> <selection mode>" << endl;
    exit(-1);
  } else {
    string touristStr(argv[1]);
    string locations(argv[2]);
    string distances(argv[3]);
    srand(atoi(argv[3]));
    int evaluation = atoi(argv[4]);
    int selection = atoi(argv[5]);
    if (selection != Metaheuristic::FACTOR && selection != Metaheuristic::STARS
        && selection != Metaheuristic::PONDERATE) {
      cerr << "Error in selection mode" << endl;
      cerr << "Set Ponderate by default" << endl;
      selection = Metaheuristic::PONDERATE;
    }
    Metaheuristic::evaluations = evaluation;
    Metaheuristic::selectionMode = selection;
#ifdef DEBUG
    cout << "Params " << endl;
    cout << "Tourist: " << touristStr << endl;
    cout << "Locations: " << locations << endl;
    cout << "Distances: " << distances << endl;
#endif
    vector<int> distanceMatrix = loadDistances(distances);
    vector<Location> locationsVector = loadLocations(locations);
    loadTourist(touristStr);
    Map::setParams(locationsVector.size(), locationsVector, distanceMatrix);
    SimulatedAnnealing simulatedAnnealing(250, 0.9, 10);
    simulatedAnnealing.run();
    simulatedAnnealing.printResults();

  }
}