#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include <vector>

class Student : Person
{
public:
    Student(string, int, string);
    void addGrade(int);
    double calculateAverage();
    virtual void displayInfo() override;
    static void printStudents();
    static vector<Student *> students;
    static void sortStudents();
    static void findByName(string);

private:
    string studentID;
    vector<int> grades;

};

#endif // STUDENT_H
