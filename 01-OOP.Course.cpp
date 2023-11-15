#include <iostream>
#include <list>
using namespace std;

/*
Introduction to classes and objects
https://www.youtube.com/watch?v=iVLQeWbgbXs&list=PL43pGnjiVwgTJg7uz8KUGdXRdGKE0W_jN
*/

// class define data type
class YouTubeChannel{
    public:
        string Name;
        string OwnerName;
        int SubscriberCount;
        list<string> PublishedVideoTitle;
};

int main()
{
    YouTubeChannel ytChannel;
    ytChannel.Name = "Woody";
    ytChannel.OwnerName = "Hu";
    ytChannel.SubscriberCount = 1800;
    ytChannel.PublishedVideoTitle = {"C++ for first", "C++ class", "C++ public"};

    cout << "Name: " << ytChannel.Name  << endl;
    cout << "OwnerName: " << ytChannel.OwnerName  << endl;
    cout << "SubscriberCount: " << ytChannel.SubscriberCount  << endl;
    cout << "video: " << endl;
    for(string videoTitle : ytChannel.PublishedVideoTitle)
    {
        cout << videoTitle << endl;
    }

    return 0;
}