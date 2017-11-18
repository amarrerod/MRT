
#include <sstream>
#include <iomanip>
#include "Location.hpp"

const int Location::HOTEL = 0;
const int Location::BEACH = 1;
const int Location::ZOO = 2;
const int Location::SIGHTSEEING = 3;
const int Location::HIKING = 4;
const int Location::AQUATIC = 5;
const int Location::ENTERTAINMENT = 6;
const int Location::STROLL = 7;
const int Location::MUSEUM = 8;
const int Location::NUM_HOTELS = 3;

Location::Location() :
    locationId(-1),
    locationName(""),
    category(-1),
    locationStars(-1.0),
    locationDuration(-1) {}

Location::~Location() {
}

Location::Location(int id, string name, int category, double stars, int duration) {
  locationId = id;
  locationName = name;
  this->category = category;
  locationStars = stars;
  locationDuration = duration;
}

string Location::toString() {
  string str = "Localizacion: ";
  str += " Nombre: " + locationName;
  str += " Categoria: " + categoryStr(category);
  stringstream stars, duration;
  stars << fixed << setprecision(1) << locationStars;
  int minutes = locationDuration % 60;
  int hours = (locationDuration - minutes) / 60;
  duration << hours << " horas " << minutes << " minutos";
  str += " Estrellas: " + stars.str() + " Duración: " + duration.str() + "\n";
  return str;
}

const double Location::getStars() {
  return locationStars;
}

const int Location::getDuration() {
  return locationDuration;
}

const int Location::getId() {
  return locationId;
}

const int Location::getCategory() {
  return category;
}

string Location::categoryStr(const int i) {
  string result = "";
  switch (i) {
    case HOTEL: result = "HOTEL";
      break;
    case BEACH: result = "PLAYA";
      break;
    case ZOO: result = "ZOO";
      break;
    case SIGHTSEEING: result = "MIRADOR";
      break;
    case HIKING: result = "SENDERISMO";
      break;
    case AQUATIC: result = "ACUÁTICA";
      break;
    case ENTERTAINMENT: result = "ENTRETENIMIENTO";
      break;
    case STROLL: result = "PASEO";
      break;
    case MUSEUM: result = "MUSEO";
      break;
    default: result = "";
      break;
  }
  return result;
}
