
#include "Tourist.hpp"

const int Tourist::CIRCULAR = 0;
const int Tourist::LINEAL = 1;
const int Tourist::DISTANCE = 0;
const int Tourist::RATE = 1;

Tourist::Tourist() :
	start(0),
	days(0),
	preferences(0),
	time(0),
	circular(0) {}

Tourist::~Tourist() {}

Tourist::Tourist(int& startPoint, int& days, int& preferences, int& time, int& circular) {
	start = startPoint;
	this->days = days;
	this->preferences = preferences;
	this->time = time;
	this->circular = circular;
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