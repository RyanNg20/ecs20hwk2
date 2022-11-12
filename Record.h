#ifndef RECORD_H
#define RECORD_H

#include "common.h"
#include "Thing.h"
#include "Person.h"
#include "Time.h"
#include "Gps.h"

class Record{
  private:
  public:
    int Npeople;
    int Nthings;

    Person *people;
    Thing *things;
    Time time;
    GPS gps;
    Record() {};
    Record(Thing *, Person *, Time, GPS, int, int);
    virtual Json::Value dump2JSON();
};

#endif