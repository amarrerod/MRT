//
// Created by Marrero on 11/10/2017.
//

#include "Route.hpp"

string Route::toString() {
  string resultStr = "";
  for (int i = 0; i < route.size(); ++i) {
    resultStr += route[i] + " ";
  }
  resultStr += "| " + to_string(rate) + "\n";
  return resultStr;
}