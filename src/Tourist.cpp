
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

Tourist::Tourist(int &startPoint, int &days, int &preferences, int &time, int &circular) {
  start = startPoint;
  this->days = days;
  this->preferences = preferences;
  this->time = time;
  this->circular = circular;
}