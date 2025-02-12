#include <algorithm>
#include <iostream>
#include <student.h>
#include <vector>
#include <string>


using namespace std;


int main ()
{
    int selection = 0;
    vector<Student>studentList;
    studentList.push_back(Student("Pena", 23));
    studentList.push_back(Student("Kalevi", 21));
    studentList.push_back(Student("Tauno", 43));
    studentList.push_back(Student("Touko", 54));
    studentList.push_back(Student("Iikka", 25));
    string name;
    int age;

    do
    {
        cout <<endl;
        cout <<"Select"<<endl;
        cout <<"Add students = 0"<<endl;
        cout <<"Print all students = 1"<<endl;
        cout <<"Sort and print students according to Name = 2"<<endl;
        cout <<"Sort and print students according to Age = 3"<<endl;
        cout <<"Find and print student = 4"<<endl;
        cin >>selection;

        switch(selection)
        {
        case 0:
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            cout <<"Enter student name: " <<endl;
            cin >>name;
            cout <<"Enter student age: " <<endl;
            cin >>age;
            studentList.push_back(Student(name, age));
            break;

        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            for_each(studentList.begin(), studentList.end(), [](Student& s)
            {
                cout <<"Student " <<s.getName() <<" " <<s.getAge() <<endl;
            });
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            sort(studentList.begin(), studentList.end(), [](Student& s1, Student& s2)
                {
                    return s1.getName() < s2.getName();
                });
            for_each(studentList.begin(), studentList.end(), [](Student& s)
                {
                    cout <<"Student " <<s.getName() <<" " <<s.getAge() <<endl;
                });
            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            sort(studentList.begin(), studentList.end(), [](Student& s1, Student& s2)
                {
                return s1.getAge() < s2.getAge();
                });
            for_each(studentList.begin(), studentList.end(), [](Student& s)
                {
                    cout <<"Student " <<s.getName() <<" " <<s.getAge() <<endl;
                });
            break;

        case 4:
        {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            cout <<"Enter student name to be found: " <<endl;
            cin >>name;
            auto it = find_if(studentList.begin(), studentList.end(), [name](Student& s)
                {
                return name == s.getName();
                });
            if(it != studentList.end())
            {
                cout <<"Student " <<it->getName() <<" " <<it->getAge() <<endl;
            }
            break;
        }

        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
    }

    while(selection < 5);

    return 0;
}

