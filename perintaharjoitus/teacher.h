#ifndef TEACHER_H
#define TEACHER_H
#include "person.h"

class Teacher : Person
{
public:
    Teacher(string, int, string);
    virtual void displayInfo() override;
private:
    string course;
};

#endif // TEACHER_H
