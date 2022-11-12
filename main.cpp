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

  //part 2

  //making all of the objects we need (need to make new ones because we need to make new record and then fill it using json2Object)
  Time morning2;
  Time noon2;
  Time evening2;
  Time night2;

  GPS village2;
  GPS path2;
  GPS trees2;

  Person redRidingHood2;
  Person mom2;
  Person wolf2;
  Person grandma2;

  Thing cap2;
  Thing cake2;
  Thing wine2;

  Person r1People2[1] = {redRidingHood};
  Person r2People2[1] = {mom};
  Person r3People2[2] = {redRidingHood, wolf};
  Person r4People2[1] = {grandma};
  
  Thing r1Things2[1] = {cap};
  Thing r2Things2[2] = {cake, wine};
  Thing r3Things2[0] = {};
  Thing r4Things2[0] = {};

  Person *people2;
  Thing *things2;

  people2 = r1People2;
  things2 = r1Things2;

  Record r1{things2, people2, morning2, village2, 1, 1};

  people2 = r2People2;
  things2 = r2Things2;

  Record r2{things2, people2, noon2, village2, 1, 2};

  people2 = r3People2;
  things2 = r3Things2;

  Record r3{things2, people2, evening2, path2, 2, 0};

  people2 = r4People2;
  things2 = r4Things2;

  Record r4{things2, people2, night2, trees2, 1, 0};

  char fileName[7] = {'r', 'e', 'c', 'o', 'r', 'd', 's'}; //name of the file that we will put records in
  Json::Value jsonIn;
  Json::Value jsonOut;

  //combine all of the Json::Value's to make jsonIn
  jsonIn["r1"] = one.dump2JSON();
  jsonIn["r2"] = two.dump2JSON();
  jsonIn["r3"] = three.dump2JSON();
  jsonIn["r4"] = four.dump2JSON();

  myJSON2File(fileName, &jsonIn); //make json file using jsonIn
  myFile2JSON(fileName, &jsonOut); //read read json file and shove it into jsonOut

  //convert Json to object using jsonOut
  r1.JSON2Object(jsonOut["r1"]);
  r2.JSON2Object(jsonOut["r2"]);
  r3.JSON2Object(jsonOut["r3"]);
  r4.JSON2Object(jsonOut["r4"]);

  //print Json::Value's to console
  cout << r1.dump2JSON().toStyledString();
  cout << r2.dump2JSON().toStyledString();
  cout << r3.dump2JSON().toStyledString();
  cout << r4.dump2JSON().toStyledString();
}