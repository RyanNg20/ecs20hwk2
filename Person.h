//author: Armin Irvije
#ifndef PERSON_H
#define PERSON_H
#include "common.h"

class Person {
    private:
        string name;
    public: 
        Person() {};
        Person(string person);
        string getPerson();
        Json::Value dump2JSON();
        virtual void JSON2Object(Json::Value);
};

#endif