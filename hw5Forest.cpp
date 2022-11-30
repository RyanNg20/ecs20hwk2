#include "common.h"
#include "Thing.h"
#include "Time.h"
#include "Person.h"
#include "Gps.h"
#include "Record.h"

class MyServer : public hw5Forest
{
public:
  MyServer(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value move(const std::string& action,
			   const std::string& class_id,
			   const Json::Value& json_object,
			   const std::string& object_id);
};

MyServer::MyServer(AbstractServerConnector &connector, serverVersion_t type)
  : hw5Forest(connector, type)
{
  std::cout << "Myhw5Forest Object created" << std::endl;
}

// member functions

Json::Value MyServer::move(const std::string& action, const std::string& class_id, const Json::Value& json_object, const std::string& object_id)
{
  Json::Value result;
  int error_code;

  if (object_id.empty())
  {
    result["status"] = "failed";
    result["reason"] = ("object_id is null");
    error_code = -2;
  }

  if ((json_object.isNull() == true) || (json_object.isObject() == false))
  {
    result["status"] = "failed";
    result["reason"] = ( "json_object has to be an object" );
    error_code = -4;
  }

  if (class_id == "Person")
  {
    Thing cap;
    Thing cake;
    Thing wine;
    Thing thingArr[3] = {cap, cake, wine};
    Thing wolfThings[0] = {};
    Person redRidingHood{"", thingArr, 3};
    Person wolf{"wolf", wolfThings, 0};
    
    Time evening{14, 10, 50};
    GPS path{"CA99", "United States"};

    Person r3People[2] = {redRidingHood, wolf};

    Record three{r3People, evening, path, 2};

    three.people[0].JSON2Object(json_object);
    result["status"] = "successful";
    result["r3"] = three.dump2JSON();

    HttpClient httpclient("http://127.0.0.1:4001");
    hw5Home myClient(httpclient, JSONRPC_CLIENT_V2);
    Json::Value myv;

    try {
      myv = myClient.move("move", "Person", three.dump2JSON()["people"]["person0"], "002");
    } catch (JsonRpcException &e) {
      cerr << e.what() << endl;
    }
    result["r4"] = myv["r4"];
  }

  return result;
}

int main(){
  HttpServer httpserver(4000);
  MyServer s(httpserver, JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  cout << "Hit enter to stop the server" << endl;
  getchar();
  s.StopListening();
  return 0;
}