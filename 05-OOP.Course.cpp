#include <iostream>
#include <list>
#include <string>

using namespace std;

/*
    Types of Constructors
*/

class User {
public:
    string FirstName;
    string LastName;
    int Age;
    string Email;
    // default ctor choice one of empty default ctor or default ctor
    // empty default ctor
    // User(){}

    // default ctor
    User(){
        FirstName = "n/a";
        LastName = "n/a";
        Age = 0;
        Email = "not set";
    }
    
    // params ctor
    User(string fName, string lName, int age){
        FirstName = fName;
        LastName = lName;
        Age = age;
        Email = fName+"_"+lName+"@mail.com";
    }
};

void GetUseraInfo(User u)
{
    cout << "FirstName: " << u.FirstName << endl;
    cout << "LastName: " << u.LastName << endl;
    cout << "Age: "<< u.Age << endl;
    cout << "Email: "<< u.Email << endl;

}


int main()
{
    User user1("woody", "hu", 30);

    GetUseraInfo(user1);

    return 0;
}