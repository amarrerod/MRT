
#include "Tourist.hpp"

const int Tourist::CIRCULAR = 0;
const int Tourist::LINEAL = 1;
const int Tourist::DISTANCE = 0;
const int Tourist::RATE = 1;

int Tourist::start = -1;
int Tourist::days = -1;
int Tourist::preferences = -1;
int Tourist::time = -1;
int Tourist::circular = -1;

Tourist::~Tourist() {}

void Tourist::setParams(const int startPoint, const int numDays, const int pref, const int duration, const int cir) {
  start = startPoint;
  days = numDays;
  preferences = pref;
  time = duration;
  circular = cir;
}

string Tourist::toString() {
  string str = "Turista \n";
  str += "\t Punto de inicio: " + to_string(start) + "\n";
  str += "\t Dias: " + to_string(days) + "\n";
  str += "\t Preferencias: ";
  str += (preferences == DISTANCE) ? "distancia\n" : "puntuacion\n";
  str += "\t Tiempo de ruta: " + to_string((time / 60)) + " horas \n";
  str += "\t Recorrido: ";
  str += (circular == CIRCULAR) ? "circular\n" : "lineal\n";
  return str;
}
