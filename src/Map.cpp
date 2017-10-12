//
// Created by Marrero on 11/10/2017.
//

#include "Map.hpp"

Map::Map():
	numberOfLocations(-1) {
}

Map::~Map() {
}

Map::Map(const int num, vector<Location>& locations) {
	numberOfLocations = num;
	this->locations = locations;
}


Map::Map(const int num, vector<Location>& locations, vector<int> distances) {
	numberOfLocations = num;
	this->locations = locations;
	this->distances = distances;
}
