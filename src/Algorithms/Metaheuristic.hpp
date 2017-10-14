
#include <string>
#include "../Route.hpp"
#include "../Map.hpp"

using namespace std;
class Metaheuristic {
 public:
  Metaheuristic();
  Metaheuristic(const string name);
  virtual ~Metaheuristic();
 public:
  virtual void run() = 0;
  virtual void initParams() = 0;
  string toString();
  virtual void printResults();
 private:
  string name;
  vector<Route> solutions;
  Map map;
};