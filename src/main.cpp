
#include <iostream>
#include <vector>
#include "Handlers/Loader.hpp"
#include "Basis/Map.hpp"
#include "Algorithms/SimulatedAnnealing.hpp"
#include "Algorithms/Greedy.hpp"
#include "Algorithms/LocalSearch.hpp"
#include "Algorithms/VNS.hpp"
#include "Utils/Randomize.hpp"
#include "Algorithms/TabuSearch.hpp"

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
    return (EXIT_FAILURE);
  } else {
    string touristStr(argv[1]);
    string locations(argv[2]);
    string distances(argv[3]);
    seed = static_cast<unsigned int>(atoi(argv[3]));
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
   /* LocalSearch localSearch(2);
    localSearch.run();
    localSearch.printResults(false);
    VNS vns;
    vns.run();
    vns.printResults(false);*/
    SimulatedAnnealing simulatedAnnealing(50, 0.9);
    simulatedAnnealing.run();
    simulatedAnnealing.printResults(false);
    /*TabuSearch tabuSearch(4, 3);
    tabuSearch.run();
    tabuSearch.printResults(false);*/
    return (EXIT_SUCCESS);
  }
}