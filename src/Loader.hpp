
/**
 * Clase para desarollada para cargar los ficheros de datos en el programa
 *
 **/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Loader {

 public:
  int loadDistances(string &);
  int loadTourist(string &);
  int loadCategories(string &);
  int loadLocations(string &);
};