
#include <string>
#include "Solutions.hpp"

using namespace std;
class Metaheuristic {
 public:
  Metaheuristic();
  Metaheuristic(string &name);
  virtual ~Metaheuristic();
 private:
  string name;
  Solutions solutions;
};