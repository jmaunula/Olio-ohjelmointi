#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;
class Person
{
public:
    Person(string, int);
    ~Person();
    virtual void displayInfo();
protected:
    string name;
    int age;

};

#endif // PERSON_H
