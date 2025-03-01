#include "teacher.h"
#include <iostream>

Teacher::Teacher(string n, int a, string c ) : Person(n, a), course(c) {}

void Teacher::displayInfo()
{
    cout <<name <<endl <<age <<endl <<course <<endl;
}
