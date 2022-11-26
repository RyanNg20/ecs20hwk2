#include "Thing.h"
#include "Time.h"
#include "Person.h"
#include "Gps.h"
#include "Record.h"
#include "client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;

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

  char r1Name[8] = {'r', '1', '.', 'j', 's', 'o', 'n'}; //name of the file that we will put records in
  char r2Name[8] = {'r', '2', '.', 'j', 's', 'o', 'n'}; //name of the file that we will put records in
  char r3Name[8] = {'r', '3', '.', 'j', 's', 'o', 'n'}; //name of the file that we will put records in
  char r4Name[8] = {'r', '4', '.', 'j', 's', 'o', 'n'}; //name of the file that we will put records in
  Json::Value json1 = one.dump2JSON();
  Json::Value json2 = two.dump2JSON();
  Json::Value json3 = three.dump2JSON();
  Json::Value json4 = four.dump2JSON();
  Json::Value json1Out;
  Json::Value json2Out;
  Json::Value json3Out;
  Json::Value json4Out;

  myJSON2File(r1Name, &json1); //make json file using jsonIn
  myJSON2File(r2Name, &json2); //make json file using jsonIn
  myJSON2File(r3Name, &json3); //make json file using jsonIn
  myJSON2File(r4Name, &json4); //make json file using jsonIn
  myFile2JSON(r1Name, &json1Out); //read read json file and shove it into jsonOut
  myFile2JSON(r2Name, &json2Out); //read read json file and shove it into jsonOut
  myFile2JSON(r3Name, &json3Out); //read read json file and shove it into jsonOut
  myFile2JSON(r4Name, &json4Out); //read read json file and shove it into jsonOut

  //convert Json to object using jsonOut
  r1.JSON2Object(json1Out);
  r2.JSON2Object(json2Out);
  r3.JSON2Object(json3Out);
  r4.JSON2Object(json4Out);

  //print Json::Value's to console
  // cout << r1.dump2JSON().toStyledString();
  // cout << r2.dump2JSON().toStyledString();
  // cout << r3.dump2JSON().toStyledString();
  // cout << r4.dump2JSON().toStyledString();

  HttpClient httpclient("http://127.0.0.1:4000");
  client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;

  Json::Value test;

  test["location"] = "test";

  try {
    // myv = myClient.move(test.toStyledString());
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  cout << myv.toStyledString() << std::endl;
}