//Author: Armin Irvije
#include "common.h"

#ifndef GPS_
#define GPS_

class GPS {
  private:
    string city;
    string country;
  public:
    GPS() {};
    GPS(string theCity, string theCountry);
    string getGps();
    Json::Value dump2JSON();
    virtual void JSON2Object(Json::Value);
};

#endif