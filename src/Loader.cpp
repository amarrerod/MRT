//
// Created by Marrero on 11/10/2017.
//

#include "Loader.hpp"

int Loader::loadDistances(string &path) {
  ifstream dataFile(path, ifstream::in);
  if(dataFile.good()){

  }else {
    cerr << "Error while trying to open file: " << path << endl;
    exit(-1);
  }
}

int Loader::loadCategories(string &) {
  // TODO
}

int Loader::loadLocations(string &) {
  // TODO
}

int Loader::loadTourist(string &) {
  // TODO
}
