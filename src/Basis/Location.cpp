
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
  str += " Categoria: " + to_string(category);
  str += " Estrellas: " + to_string(locationStars);
  str += " Duracion: " + to_string((locationDuration / 60)) + "horas \n";
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