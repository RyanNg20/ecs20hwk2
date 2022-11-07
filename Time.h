//author: Ryan Ng
#ifndef TIME_H
#define TIME_H

#include "common.h"

class Time {
  private:
   int hour;
   int minute;
   int second;
  public:
    Time();
    Time(int, int, int);
    string getTime();
    string getSTime();
    Json::Value dump2JSON();
};

#endif