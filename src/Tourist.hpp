
#include <string>

using namespace std;

class Tourist {
 public:
  Tourist();
  Tourist(int& startPoint, int& days, int& preferences, int& hours, int& circular);
  virtual ~Loader();
 private:
  int start, days, preferences, hours, circular;
 public:
  void setStartPoint(const int&);
  void setDays(const int&);
  void setPreferences(const int &);
  void setHours(const int&);
  void setCircular(const int &);
  int getStartPoint();
  int getDays();
  int getPreferences();
  int getHours();
  int getCircular();
 public:
  string& toString();
 public:
  static const int CIRCULAR;
  static const int LINEAL;
  static const int DISTANCE;
  static const int RATE;
};