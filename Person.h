//author: Armin Irvije
#ifndef PERSON_H
#define PERSON_H
#include "common.h"
#include "Thing.h"

class Person {
    private:
    public: 
        string name;
        Thing *things;
        int Nthings;
        Person() {};
        Person(string person, Thing *, int);
        Json::Value dump2JSON();
        virtual void JSON2Object(Json::Value);
};

#endif