//
// Created by Marrero on 11/10/2017.
//

#include "Loader.hpp"

int Loader::loadDistances(string &path, vector<int>& distances) {
  ifstream dataFile(path, ifstream::in);
  if(dataFile.good()){

  }else {
    cerr << "Error while trying to open file: " << path << endl;
    exit(-1);
  }
}

int Loader::loadLocations(string &) {
  // TODO
}

int Loader::loadTourist(string &, Tourist& tourist) {
  // TODO
}
