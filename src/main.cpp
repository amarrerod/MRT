
#include <iostream>
#include <vector>
#include "Loader.hpp"

using namespace std;
const int NUM_PARAMS = 3;
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
#ifdef DEBUG
    cout << "Params " << endl;
    cout << "Tourist: " << argv[0] << endl;
    cout << "Locations: " << argv[1] << endl;
    cout << "Distances: " << argv[2] << endl;
#endif
    string tourist(argv[0]);
    string locations(argv[1]);
    string distances(argv[2]);
    vector<int> distanceMatrix = loadDistances(distances);
    vector<Location> locationsVector = loadLocations(locations);
    Tourist touristInfo = loadTourist(tourist);

  }
}