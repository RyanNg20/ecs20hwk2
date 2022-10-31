//Author: Armin Irvije 
#include "Gps.h"

GPS::GPS(string theCity, string theCountry) {
    city =  theCity;
    country = theCountry;
}

void GPS::getGps() {
    //cout << "GPS:\n";
    cout << city << ", " << country << "\n";
}   