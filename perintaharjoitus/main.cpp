#include "teacher.h"
#include <person.h>
#include <student.h>

using namespace std;

vector<Student*> Student::students;

int main()
{
    Student s1("Pekka", 20, "asdad1");
    Student s2("Touko", 32, "fasfd");
    Student s3("Tauno", 25, "asfa");
    Student s4("Joni", 34, "gfdg");
    Student s5("Sara", 23, "tyutu");
    Student s6("Lauri", 21, "fdfs");


    Student::findByName("a");
    return 0;
}
