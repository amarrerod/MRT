
#include <string>
#include "Route.hpp"
#include "Map.hpp"

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
 public:
  virtual void run() = 0;
  virtual void initParams() = 0;
  virtual string& toString() = 0;
 private:
  void printResults();
};