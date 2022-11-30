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

    Person *people;
    Time time;
    GPS gps;
    Record() {};
    Record(Person *, Time, GPS, int);
    Json::Value dump2JSON();
    virtual void JSON2Object(Json::Value);
};

#endif