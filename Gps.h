//Author: Armin Irvije
#include "common.h"

#ifndef GPS_
#define GPS_

class GPS{

    private:

      string city;
      string country;

    public:

      GPS(string theCity, string theCountry);

      void getGps();

};

#endif