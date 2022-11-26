#include "common.h"
#include "server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include "client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

// using namespace jsonrpc;

// class MyServer : public server
// {
// public:
//   MyServer(AbstractServerConnector &connector, serverVersion_t type);
//   virtual Json::Value move(const std::string& action,
// 			   const std::string& class_id,
// 			   const Json::Value& json_object,
// 			   const Json::Value& location,
// 			   const std::string& object_id);
//   virtual Json::Value search(const std::string& action,
// 			     const std::string& class_id,
// 			     const std::string& object_id);
//   virtual Json::Value dump2JSON(const std::string& action,
// 				const std::string& arguments,
// 				const std::string& class_id,
// 				const std::string& host_url,
// 				const std::string& object_id);
// };

// MyServer::MyServer(AbstractServerConnector &connector, serverVersion_t type)
//   : server(connector, type)
// {
//   std::cout << "Myhw5Server Object created" << std::endl;
// }

// // member functions

// Json::Value
// MyServer::move
// (const std::string& action, const std::string& class_id,
//  const Json::Value& json_object, const Json::Value& location,
//  const std::string& object_id)
// {
//   Json::Value result;
//   return result;
// }

// Json::Value
// MyServer::search
// (const std::string& action, const std::string& class_id,
//  const std::string& object_id)
// {
//   Json::Value result;
//   return result;
// }

// Json::Value
// MyServer::dump2JSON
// (const std::string& action, const std::string& arguments,
//  const std::string& class_id, const std::string& host_url,
//  const std::string& object_id)
// {
//     Json::Value result;
//   return result;
// }

int main(){
  return 0;
}