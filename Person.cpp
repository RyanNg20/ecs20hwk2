//author: Armin Irvije
#include "Person.h"

Person::Person(string person){
    name = person;
}

string Person::getPerson(){
    return name;
}

Json::Value Person::dump2JSON(){
    Json::Value result;
    result["name"] = name;
    return result;
}