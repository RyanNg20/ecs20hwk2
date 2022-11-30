//author: Ryan Ng
#ifndef THING_H
#define THING_H

#include "common.h"

class Thing {
  private:
  public:
    string name;
    Thing() {};
    Thing(string);
    string getName();
    Json::Value dump2JSON();
    virtual void JSON2Object(Json::Value);
};

#endif