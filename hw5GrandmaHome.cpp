#include "common.h"
#include "Thing.h"
#include "Time.h"
#include "Person.h"
#include "Gps.h"
#include "Record.h"

class MyServer2 : public hw5Forest
{
public:
  MyServer2(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value move(const std::string& action,
			   const std::string& class_id,
			   const Json::Value& json_object,
			   const std::string& object_id);
};

MyServer2::MyServer2(AbstractServerConnector &connector, serverVersion_t type)
  : hw5Forest(connector, type)
{
  std::cout << "Myhw5Server Object created" << std::endl;
}

// member functions

Json::Value
MyServer2::move
(const std::string& action, const std::string& class_id, const Json::Value& json_object,const std::string& object_id)
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
    Thing grandmaThings[0];
    Person redRidingHood{"", thingArr, 3};
    Person grandma{"wolf", grandmaThings, 0};
    
    Time night{22, 10, 50};
    GPS trees{"UC Davis", "United States"};

    Person r3People[2] = {redRidingHood, grandma};

    Record four{r3People, night, trees, 2};

    four.people[0].JSON2Object(json_object);
    result["status"] = "successful";
    result["r4"] = four.dump2JSON();
  }
  return result;
}

int main(){
  HttpServer httpserver(4001);
  MyServer2 s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();
  return 0;
}