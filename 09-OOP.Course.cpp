#include <iostream>
#include <string>
#include <list>
using namespace std;


class Student {
public:
    string Name;
    int Age;
    char Genger;
    virtual void Study() = 0;
};

class ProgrammingStudent:public Student {
public:
    void Study() {
        cout << "Learning programming\n" << endl;
    }
};

class ArtsStudent:public Student {
public:
    void Study() {
        cout << "Learning to paint\n" << endl;
    }
};

class MusicStudent:public Student {
public:
    void Study() {
        cout << "Learning to play piano and to sing\n" << endl;
    }
};

int main()
{
    Student* students[3];
    students[0] = new ProgrammingStudent();
    students[1] = new ArtsStudent();
    students[2] = new MusicStudent();
    
    for(int i=0;i<=2;i++)
    {
        students[i]->Study();
    }

    for(int i=0;i<=2;i++)
    {
        delete students[i];
    }

    return 0;
}

