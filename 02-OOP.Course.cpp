#include <iostream>
#include <list>
using namespace std;

/*
    constructors and class methods
*/

// class define data type
class YouTubeChannel{
    public:
        string Name;
        string OwnerName;
        int SubscriberCount;
        list<string> PublishedVideoTitle;
    //constructors
    YouTubeChannel( string name, string ownerName){
        Name = name;
        OwnerName = ownerName;
        SubscriberCount = 0;
    }

    void GetInfo(){
        cout << "Name: " << Name  << endl;
        cout << "OwnerName: " << OwnerName  << endl;
        cout << "SubscriberCount: " << SubscriberCount  << endl;
        cout << "video: " << endl;
        for(string videoTitle : PublishedVideoTitle)
        {
            cout << videoTitle << endl;
        }        
    }
};

// constructors
int main()
{
    YouTubeChannel ytChannel("Woody", "Hu");
    ytChannel.PublishedVideoTitle.push_back("C++ for first");
    ytChannel.PublishedVideoTitle.push_back("C++ 123");
    ytChannel.PublishedVideoTitle.push_back("C++ 456");
    YouTubeChannel ytChannel2("Tony", "Lee");

    ytChannel.GetInfo();
    ytChannel2.GetInfo();

    return 0;
}
