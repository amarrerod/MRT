
#include <string>

using namespace std;

class Tourist {
 public:
  Tourist();
  Tourist(int& days, int& preferences, int& hours, int& circular);
  virtual ~Loader();
 private:
  int days, preferences, hours, circular;
 public:
  void setDays(const int&);
  void setPreferences(const int &);
  void setHours(const int&);
  void setCircular(const int &);
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