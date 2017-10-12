
#include "Metaheuristic.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;
const string EXTENSION = ".rs";
const string PATH = "D:\\Proyectos\\MRT\\results\\";

void Metaheuristic::printResults() {
  milliseconds milliseconds1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  string milisecondsString = to_string(milliseconds1.count());
  string fileName = PATH + name + milisecondsString + EXTENSION;
  // TODO: Meter los resultados en el fichero
  ofstream outputFile(fileName, ifstream::out);
  if (outputFile.is_open()) {
    auto end = chrono::system_clock::now();
    time_t timeStamp = chrono::system_clock::to_time_t(end);
    outputFile << ctime(&timeStamp);
  } else {
    cerr << "Error trying to write results in: " + fileName << endl;
    exit(-1);
  }
}