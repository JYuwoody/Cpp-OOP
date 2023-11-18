#include <iostream>
#include <list>
using namespace std;

/*
    encapsulation in programming: private
    using public to change private parameter
*/

// class define data type
class YouTubeChannel{
private:
        string Name;
        string OwnerName;
        int SubscriberCount;
        list<string> PublishedVideoTitle;
public:
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
    void Subscribe(){
        SubscriberCount++;
    }
    void UnSubscribe(){
        if(SubscriberCount>0)
            SubscriberCount--;
    }    
    void PublishedVideo(string title){
        PublishedVideoTitle.push_back(title);
    }

};

int main()
{
    YouTubeChannel ytChannel("Woody", "Hu");

    ytChannel.PublishedVideo("C++ for first");
    ytChannel.PublishedVideo("C++ 123");
    ytChannel.PublishedVideo("C++ 456");
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.UnSubscribe();

    ytChannel.GetInfo();


    return 0;
}
