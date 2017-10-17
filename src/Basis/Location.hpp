#ifndef MRT_LOCATION_HPP
#define MRT_LOCATION_HPP
#include <string>

using namespace std;
class Location {
 public:
  Location();
  Location(int id, string name, int category, double stars, int duration);
  virtual ~Location();
 private:
  int locationId;
  string locationName;
  int category;
  double locationStars;
  int locationDuration;
 public:
  void setId(const int &);
  void setName(const string &);
  void setCategory(const int &);
  void setStars(const double &);
  void setDuration(const int &);
  const int getId();
  const string &getName();
  const int getCategory();
  const double getStars();
  const int getDuration();
 public:
  string toString();
 public:
  static const int HOTEL;
  static const int BEACH;
  static const int ZOO;
  static const int SIGHTSEEING;
  static const int HIKING;
  static const int AQUATIC;
  static const int ENTERTAINMENT;
  static const int STROLL;
  static const int MUSEUM;
  static const int NUM_HOTELS;
};
#endif // MRT_LOCATION_HPP