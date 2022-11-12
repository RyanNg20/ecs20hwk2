#ifndef COMMON_H
#define COMMON_H

#include <strings.h>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <exception> 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>

#include <arpa/inet.h>

using namespace std;

// utility functions
void myPrintLog(std::string content, std::string fname);
int myParseJSON(std::string input, Json::Value * jv_ptr);
char *myFile2String(char *f_name);
int myFile2JSON(char *f_name, Json::Value * jv_ptr);
int myJSON2File(char *f_name, Json::Value * jv_ptr);

#endif