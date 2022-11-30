#include "common.h"
#include "Thing.h"
#include "Time.h"
#include "Person.h"
#include "Gps.h"
#include "Record.h"

int main () {
  Thing cap{"cap"};
  Thing cake{"cake"};
  Thing wine{"wine"};

  Time morning{8, 10, 50};
  GPS village{"San Ramon", "United States"};
  Thing r1Things[1] = {cap};
  Person redRidingHood{"Little Red Riding Hood", r1Things, 1};
  Person r1People[1] = {redRidingHood};

  Record one{r1People, morning, village, 1};

  Time noon{12, 10, 50};
  GPS trees{"UC Davis", "United States"};
  Thing r2Things[3] = {cap, cake, wine};
  Person redRidingHood2{"Little Red Riding Hood", r2Things, 3};
  Thing r2MomThings[0];
  Person mom{"mom", r2MomThings, 0};
  Person r2People[2] = {redRidingHood2, mom};

  Record two{r2People, noon, trees, 2};

  HttpClient httpclient("http://127.0.0.1:4000");
  hw5Home myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;

  try {
    myv = myClient.move("move", "Person", two.dump2JSON()["people"]["person0"], "001");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }

  cout << "RECORD1: " << endl << one.dump2JSON().toStyledString() << endl << endl;
  cout << "RECORD2: " << endl << two.dump2JSON().toStyledString() << endl << endl;
  cout << "RECORD3: " << endl << myv["r3"].toStyledString() << endl << endl;
  cout << "RECORD4: " << endl << myv["r4"].toStyledString() << endl << endl;
  return 0;
}