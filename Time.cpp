#include "Time.h"

Time::Time() {}

Time::Time(int tempHour, int tempMinute, int tempSecond) {
  if (tempHour >= 24 || tempMinute >= 60 || tempSecond >= 60) throw "Hour should be less then 24, minute/second should be less then 60";

  hour = tempHour;
  minute = tempMinute;
  second = tempSecond;
}

string Time::getTime() {
  return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
}

string Time::getSTime() {
  if (hour > 12) return to_string(hour - 12) + ":" + to_string(minute) + " pm";
  else return to_string(hour) + ":" + to_string(minute) + " am";
}