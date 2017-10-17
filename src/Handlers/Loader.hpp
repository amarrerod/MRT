
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
#include <algorithm>
#include "../Basis/Tourist.hpp"
#include "../Basis/Location.hpp"

using namespace std;
const int TOURIST_ARGS = 5;
const char DELIMITER = ',';

vector<int> loadDistances(string &str) {
  ifstream inputFile(str);
  vector<int> distances;
  if (inputFile.good()) {
    int value;
    while (inputFile >> value) {
      distances.push_back(value);
    }
    return distances;
  } else {
    cerr << "Error trying to open file: " << str << endl;
    exit(-1);
  }
}

void loadTourist(string &str) {
  ifstream inputFile(str, ifstream::in);
  if (inputFile.is_open()) {
    string line;
    getline(inputFile, line);
#ifdef DEBUG
    cout << "Comentario: " << line << endl;
#endif
    istringstream iss(line);
    int i = 0;
    vector<int> touristArgs(5);
    while (iss.good() && i < TOURIST_ARGS) {
      iss >> touristArgs[i];
      ++i;
    }
    Tourist::setParams(touristArgs[0], touristArgs[1], touristArgs[2], touristArgs[3], touristArgs[4]);
  } else {
    cerr << "Error trying to open file: " << str;
    exit(-1);
  }
}

vector<Location> loadLocations(string &str) {
  ifstream inputFile(str);
  if (inputFile) {
    string line;
    vector<Location> locations;
    getline(inputFile, line); // Nos saltamos la primera linea de comentarios
    while (inputFile >> line) {
      istringstream iss(line);
      string token;
      vector<string> lineInfo;
      while (getline(iss, token, DELIMITER)) {
        lineInfo.push_back(token);
      }
      replace(lineInfo[1].begin(), lineInfo[1].end(), '_', ' ');
#ifdef DEBUG
      for (int i = 0; i < lineInfo.size(); i++) {
          cout << "Vector[" << i << "]: " << lineInfo[i] << endl;
      }
#endif
      Location auxLocation(stoi(lineInfo[0]), lineInfo[1], stoi(lineInfo[2]), stod(lineInfo[3]), stoi(lineInfo[4]));
      locations.push_back(auxLocation);
    }
    return locations;
  } else {
    cerr << "Error trying to open file: " << str;
    exit(-1);
  }
}

#endif // MRT_LOADER_HPP