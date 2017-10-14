
#include <iostream>
#include <vector>
#include "Handlers/Loader.hpp"
#include "Basis/Map.hpp"
#include "Algorithms/SimulatedAnnealing.hpp"

using namespace std;
const int NUM_PARAMS = 4;
#define DEBUG

int main(int argc, char **argv) {
  /**
   * @brief 1. Cargar todos los datos (Turista, Localizaciones, Distancias)
   *        2. Inicializar la Metaheuristica (Numero de rutas, preferencias)
   *        3. Ejecutar algoritmo.
   *        4. Mostrar resultados.
   **/
  if (argc != NUM_PARAMS) {
    cerr << "Error in params" << endl;
    cerr << "Usage: ./MRT tourist.conf location.conf distances.conf" << endl;
    exit(-1);
  } else {
    string touristStr(argv[1]);
    string locations(argv[2]);
    string distances(argv[3]);
#ifdef DEBUG
    cout << "Params " << endl;
    cout << "Tourist: " << touristStr << endl;
    cout << "Locations: " << locations << endl;
    cout << "Distances: " << distances << endl;
#endif
    vector<int> distanceMatrix = loadDistances(distances);
    vector<Location> locationsVector = loadLocations(locations);
    Tourist tourist = loadTourist(touristStr);
    Map map(distanceMatrix.size(), locationsVector, distanceMatrix);
    SimulatedAnnealing simulatedAnnealing;
    simulatedAnnealing.printResults();
  }
}