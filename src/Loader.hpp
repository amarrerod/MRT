
/**
 * Clase para desarollada para cargar los ficheros de datos en el programa
 *
 **/

#ifndef MRT_LOADER_HPP
#define MRT_LOADER_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Tourist.hpp"
#include "Location.hpp"

using namespace std;
const int TOURIST_ARGS = 5;
const char DELIMITER = ',';

vector<int> loadDistances(string &str) {
  ifstream inputFile(str);
  vector<int> distances;
  if (inputFile.good()) {
    int value;
#ifdef DEBUG
    cout << "Matrix: " << endl;
#endif
    while (inputFile >> value) {
#ifdef DEBUG
      cout << value;
#endif
      distances.push_back(value);
    }
    return distances;
  } else {
    cerr << "Error trying to open file: " << str << endl;
    exit(-1);
  }
}

Tourist loadTourist(string &str) {
  ifstream inputFile(str);
  if (inputFile) {
    string line;
    inputFile >> line;
    istringstream iss(line);
    int i = 0;
    vector<int> touristArgs;
    while (iss.good() && i < TOURIST_ARGS) {
      iss >> touristArgs[i];
      ++i;
    }
    Tourist tourist(touristArgs[0], touristArgs[1], touristArgs[2], touristArgs[3], touristArgs[4]);
    return tourist;
  } else {
    cerr << "Error trying to open file: " << str;
    exit(-1);
  }
}

vector<Location> loadLocations(string &str) {
  ifstream inputFile(str);
  if (inputFile) {
    string line;
    inputFile >> line; // Nos saltamos la primera linea de comentarios
    while (inputFile >> line) {
      istringstream iss(line);
      string token;
      while (getline(iss, token, DELIMITER)) {
        cout << token << endl;
      }
    }
  } else {
    cerr << "Error trying to open file: " << str;
    exit(-1);
  }
}

#endif // MRT_LOADER_HPP