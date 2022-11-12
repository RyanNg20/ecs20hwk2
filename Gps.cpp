//Author: Armin Irvije 
#include "Gps.h"

GPS::GPS(string theCity, string theCountry) {
    city =  theCity;
    country = theCountry;
}

string GPS::getGps() {
    string location = city + "," + country;
    return location;
}

Json::Value GPS::dump2JSON() {
    Json::Value result;
    result["city"] = city;
    result["country"] = country;
    return result;
}

void GPS::JSON2Object(Json::Value json) {
    city = json["city"].asString();
    country = json["country"].asString();
}