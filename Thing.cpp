//author: Ryan Ng
#include "Thing.h"

Thing::Thing(string tempName) {
  name = tempName;
}

string Thing::getName() {
  return name;
}
Json::Value Thing::dump2JSON() {
  Json::Value result;

  result["name"] = name;
  cout << result << endl;

  return result;
}