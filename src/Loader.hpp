
/**
 * Clase para desarollada para cargar los ficheros de datos en el programa
 *
 **/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tourist.hpp"
#include "Location.hpp"

using namespace std;
class Loader {
 public:
  int loadDistances(string &, vector<int> &distances);
  int loadTourist(string &, Tourist &tourist);
  int loadLocations(string &, vector<Location> &locations);
};