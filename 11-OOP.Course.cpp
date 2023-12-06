#include <iostream>
#include <string>
#include <list>
#include <algorithm>    // include sort function
using namespace std;

/*
    Dynamic Arrays of Objects 
*/

class Student {
public:
    string Name;
    int Age;
    char Genger;
    float ProgrammingGrade;

};

void PrintStudent(Student* student, int size)
{
    for(int i=0;i<size;i++)
    {
        cout << "student" << i+1 << endl;
        cout << student[i].Name << "\t";
        cout << student[i].Age << "\t";
        cout << student[i].Genger << "\t";
        cout << student[i].ProgrammingGrade <<endl;
    }
}

void KeyinStudent(Student* student, int start, int end)
{
    for(int i=start;i<end;i++)
    {
        cout << "student" << i+1 << endl;

        Student s;
        cout << "Name: ";
        cin >> s.Name;
        cout << "Age: ";
        cin >> s.Age;
        cout << "Genger: ";
        cin >> s.Genger;
        cout << "ProgrammingGrade: ";
        cin >> s.ProgrammingGrade;
        student[i] = s;
    }
}

int main()
{
    int size;
    Student* student;

    cout << "Enter size: ";
    cin >> size;
    student = new Student[size];

    KeyinStudent(student, 0, size);


    char choice;
    cout <<"Do you want a bigger array?" << endl;
    cin >> choice;
    if(choice == 'n' || choice == 'N')
    {
        delete [] student;
        return 0;
    }

    int newSize;
    cout <<"Enter new size: ";
    cin >> newSize;
    Student* newstudent;
    newstudent = new Student[newSize];
    // memcpy(newstudent, student,sizeof(Student)*size); // this will false, deep copy vs shallow copy
    for(int i=0;i<size;i++)
    {
        newstudent[i] = student[i];
    }
    delete [] student;
    student = newstudent;

    KeyinStudent(student, size, newSize);

    cout << "---" << endl;
    PrintStudent(student, newSize);


    delete [] student;
    return 0;
}

