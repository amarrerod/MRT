
#include <string>
#include "Route.hpp"

using namespace std;
class Metaheuristic {
 public:
  Metaheuristic();
  Metaheuristic(string &name);
  virtual ~Metaheuristic();
 private:
  string name;
  vector<Route> solutions;
  Map map;
};