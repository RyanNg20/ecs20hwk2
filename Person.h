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
        virtual Json::Value dump2JSON();
};

#endif