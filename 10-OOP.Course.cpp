#include <iostream>
#include <string>
#include <list>
#include <algorithm>    // include sort function
using namespace std;


class Student {
public:
    string Name;
    int Age;
    char Genger;
    float ProgrammingGrade;
    
    Student(string name, int age, char gender, float programmingGrade) {
        Name = name;
        Age = age;
        Genger = gender;
        ProgrammingGrade = programmingGrade;
    }
};

bool compareByGrade(const Student& s1, const Student& s2)
{
    return s1.ProgrammingGrade < s2.ProgrammingGrade;
}

bool compareByName(const Student& s1, const Student& s2)
{
    return s1.Name < s2.Name;
}

void PrintSort(Student students[], int size, int byGrade) 
{
    if (byGrade == 0)
        sort(students, students + size, compareByGrade);
    else if (byGrade == 1)
        sort(students, students + size, compareByName);

    // reverse(students, students+5);   // display reverse result
    
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ": " << students[i].Name << endl;
    }

    cout << "---" << endl;
}

int main()
{
    Student students[5] = {
        {"John"     , 20, 'm', 9},
        {"Bob"      , 21, 'm', 8},
        {"Alice"    , 19, 'm', 9.2},
        {"Eve"      , 20, 'm', 8.5},
        {"Saldina"  , 22, 'm', 7.2},
    };    

    for(int i=0; i<=4;i++)
    {
        if(students[i].Name == "Alice")
        {
            cout << "Alice found at index: " << i << endl;
            students[i].ProgrammingGrade = 10;
            break;
        }
    }

    PrintSort(students, 5, 0);
    PrintSort(students, 5, 1);

    Student* maxGradeStudent = max_element(students, students + 5, compareByGrade);
    Student* minGradeStudent = min_element(students, students + 5, compareByGrade);
    cout << "Max grade student is " << maxGradeStudent->Name << endl;
    cout << "Min grade student is " << minGradeStudent->Name << endl;

    return 0;
}

