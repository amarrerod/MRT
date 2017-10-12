
#include <iostream>
#include <vector>
#include "Loader.hpp"

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
    cerr << "Error in params: " << argc << endl;
    for (int i = 0; i < argc; i++) {
      cerr << "\t" << argv[i] << endl;
    }
    cerr << "Usage: ./MRT tourist.conf location.conf distances.conf" << endl;
    exit(-1);
  } else {
#ifdef DEBUG
    cout << "Params " << endl;
    cout << "Tourist: " << argv[1] << endl;
    cout << "Locations: " << argv[2] << endl;
    cout << "Distances: " << argv[3] << endl;
#endif
    string tourist(argv[1]);
    string locations(argv[2]);
    string distances(argv[3]);
    vector<int> distanceMatrix = loadDistances(distances);
    vector<Location> locationsVector = loadLocations(locations);
    Tourist touristInfo = loadTourist(tourist);
  }
}