#include "Record.h"
#include "Thing.h"
#include "Person.h"
#include "Time.h"
#include "Gps.h"

Record::Record(Person * people, Time time, GPS gps, int Npeople) {
  this->Npeople = Npeople;

  this->people = people;
  this->time = time;
  this->gps = gps;
}

Json::Value Record::dump2JSON() {
  Json::Value result;
  Json::Value peopleJson;

  for (int i = 0; i < Npeople; i++) {
    peopleJson["person" + to_string(i)] = people[i].dump2JSON();
  }

  result["people"] = peopleJson;
  result["time"] = time.dump2JSON();
  result["gps"] = gps.dump2JSON();

  return result;
}

void Record::JSON2Object(Json::Value json) {
  this->Npeople = Npeople;

  gps.JSON2Object(json["gps"]);
  time.JSON2Object(json["time"]);
  for (int i = 0; i < Npeople; i++) {
    people[i].JSON2Object(json["people"]["person" + to_string(i)]);
  }
}