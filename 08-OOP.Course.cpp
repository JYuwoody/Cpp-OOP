#include <iostream>
#include <string>
#include <list>
using namespace std;

/*
    Relationship between Virtual Functions, Pure Virtual Functions and Abstract Classes in OOP explained
    https://www.youtube.com/watch?v=T8f4ajtFU9g&list=RDCMUCl5-BV9aRaeDVohpE4sqJiQ&index=9
*/

// class Instrument {
// public:
//     virtual void MakeSound() {
//         cout << "Instrument playing ...\n";
//     }    
// };

class Instrument {
public:
    virtual void MakeSound() = 0;
};

class Accordion:public Instrument {
public:
    void MakeSound() {
        cout << "Accordion playing ...\n";
    }    
};

class Piano:public Instrument {
public:
    void MakeSound() {
        cout << "Piano playing ...\n";
    }    
};

int main()
{
    Instrument* i1 = new Accordion();
    i1->MakeSound();    // result is "Accordion playing ..."

    Instrument* i2 = new Piano();
    i2->MakeSound();

    Instrument* instruments[2] = {i1, i2};
    for(int i=0;i<2;i++)
    {
        instruments[i]->MakeSound();
    }

    return 0;
}
