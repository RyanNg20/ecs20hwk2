//author: Armin Irvije
#include "Person.h"
#include "Thing.h"

Person::Person(string person,  Thing * thingPtr, int Nthings){
    name = person;
    things = thingPtr;
    this->Nthings = Nthings; 
}

Json::Value Person::dump2JSON(){
    Json::Value result;
    result["name"] = name;
    for (int i = 0; i < Nthings; i++) {
        result["things"]["thing" + to_string(i)] = this->things[i].dump2JSON();
    }
    return result;
}

void Person::JSON2Object(Json::Value json) {

    for (int i = 0; i < Nthings; i++) {
        things[i].JSON2Object(json["things"]["thing" + to_string(i)]);
    }

    name = json["name"].asString();
}