//author: Ryan Ng
#include "Thing.h"

Thing::Thing(string tempName) {
  name = tempName;
}

Json::Value Thing::dump2JSON() {
  Json::Value result;

  result["name"] = name;
  
  return result;
}
void Thing::JSON2Object(Json::Value json) {
    name = json["name"].asString();
}