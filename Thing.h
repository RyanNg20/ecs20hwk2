//author: Ryan Ng
#ifndef THING_H
#define THING_H

#include "common.h"

class Thing {
  private:
    string name;
  public:
    Thing() {};
    Thing(string);
    string getName();
    Json::Value dump2JSON();
    void JSON2Object(Json::Value);
};

#endif