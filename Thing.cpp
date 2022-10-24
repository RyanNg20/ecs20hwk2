#include "Thing.h"

Thing::Thing() {}

Thing::Thing(string personName) {
  name = personName;
}

string Thing::getName() {
  return name;
}
