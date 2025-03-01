#include "person.h"
#include <iostream>

Person::Person(string n, int a) : name(n), age(a) {}

Person::~Person(){}

void Person::displayInfo()
{
    cout <<name <<endl <<age <<endl;
}
