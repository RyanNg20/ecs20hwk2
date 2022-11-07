#include "Thing.h"
#include "Time.h"
#include "Person.h"
#include "Gps.h"
#include "Record.h"

int main () {
  Time morning{8, 10, 50};
  Time noon{12, 10, 50};
  Time evening{14, 10, 50};
  Time night{22, 10, 50};

  GPS village{"San Ramon", "United States"};
  GPS path{"CA99", "United States"};
  GPS trees{"UC Davis", "United States"};

  Person redRidingHood("Little Red Riding Hood");
  Person mom{"mom"};
  Person wolf{"wolf"};
  Person grandma{"grandma"};

  Thing cap{"cap"};
  Thing cake{"cake"};
  Thing wine{"wine"};

  Person r1People[1] = {redRidingHood};
  Person r2People[1] = {mom};
  Person r3People[2] = {redRidingHood, wolf};
  Person r4People[1] = {grandma};
  
  Thing r1Things[1] = {cap};
  Thing r2Things[2] = {cake, wine};
  Thing r3Things[0] = {};
  Thing r4Things[0] = {};

  Person *people;
  Thing *things;

  people = r1People;
  things = r1Things;

  Record one{things, people, morning, village, 1, 1};

  people = r2People;
  things = r2Things;

  Record two{things, people, noon, village, 1, 2};

  people = r3People;
  things = r3Things;

  Record three{things, people, evening, path, 2, 0};

  people = r4People;
  things = r4Things;

  Record four{things, people, night, trees, 1, 0};

  one.dump2JSON();
  two.dump2JSON();
  three.dump2JSON();
  four.dump2JSON();
}