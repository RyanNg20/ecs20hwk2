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
    virtual Json::Value dump2JSON();
};

#endif