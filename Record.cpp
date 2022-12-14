#include "Record.h"
#include "Thing.h"
#include "Person.h"
#include "Time.h"
#include "Gps.h"

Record::Record(Thing * things, Person * people, Time time, GPS gps, int Npeople, int Nthings) {
  this->Npeople = Npeople;
  this->Nthings = Nthings;

  this->things = things;
  this->people = people;
  this->time = time;
  this->gps = gps;
}

Json::Value Record::dump2JSON() {
  Json::Value result;
  Json::Value peopleJson;
  Json::Value thingsJson;

  for (int i = 0; i < Npeople; i++) {
    peopleJson["person" + to_string(i)] = people[i].dump2JSON();
  }

  for (int i = 0; i < Nthings; i++) {
    thingsJson["thing" + to_string(i)] = things[i].dump2JSON();
  }

  result["people"] = peopleJson;
  result["things"] = thingsJson;
  result["time"] = time.dump2JSON();
  result["gps"] = gps.dump2JSON();

  cout << result.toStyledString();

  return result;
}