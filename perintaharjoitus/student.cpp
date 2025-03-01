#include "student.h"
#include <iostream>
#include <algorithm>

using namespace std;


Student::Student(string n, int a, string s) : Person(n, a), studentID(s)
{
    students.push_back(this);
}

void Student::printStudents()
{
    for (Student *s  : students)
    {
        s->displayInfo();
    }
}

void Student::sortStudents()
{
    sort(students.begin(), students.end(), [](Student *a, Student *b){
        return a->name < b->name;
    });
}

void Student::findByName(string name)
{
    auto it = find_if(students.begin(), students.end(), [name](Student *s){
        return name == s->name;
    });

    if(it != students.end())
    {
        (*it)->displayInfo();
    }
    else cout <<"Not found" <<endl;
}

void Student::addGrade(int grade)
{
    grades.push_back(grade);
}

double Student::calculateAverage()
{
    if(grades.empty()) return 0;
    double average = 0.0;

    for (int g : grades)
    {
        average += g;
    }
    average /= grades.size();
    return average;
}

void Student::displayInfo()
{
    cout <<name <<endl <<age <<endl <<studentID <<endl;
    for (int g : grades)
    {
        cout <<g <<endl;
    }
    cout <<calculateAverage() <<endl;
    cout << endl;
}

