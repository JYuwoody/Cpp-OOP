#include <iostream>
#include <string>
#include <list>
using namespace std;

/*
    Operator Overloading
    https://www.youtube.com/watch?v=BnMnozsSPmw&list=RDCMUCl5-BV9aRaeDVohpE4sqJiQ&index=8
*/
class YouTubeChannel{
public:
    string Name;
    int SubscriberCount;

    YouTubeChannel( string name, int subscriberCount){
        Name = name;
        SubscriberCount = subscriberCount;
    }
    //+++ fix  void operator-= cannot work >>>
    // operator== 函數中使用了 const 修飾符，這樣就能夠讓 std::list 中的 remove 函數正確地使用這個運算子來比較物件了
    bool operator==(const YouTubeChannel& channel) const{
        return this->Name == channel.Name;
    }
    //+++ fix  void operator-= cannot work <<<
};

//+++ step1 overloadiong operator<<
ostream& operator<<(ostream& COUT, YouTubeChannel& ytChannel)
{
    COUT << "Name" << ytChannel.Name << endl;
    COUT << "Subscribers" << ytChannel.SubscriberCount << endl;

    return COUT;
}

struct MyCollection{
    list <YouTubeChannel>myChannels;

    void operator+=(YouTubeChannel& channel){
        this->myChannels.push_back(channel);
    }
    // need add bool operator==
    void operator-=(YouTubeChannel& channel){
        this->myChannels.remove(channel);
    }    
};

//+++ step2 overloadiong operator<<
ostream& operator<<(ostream& COUT, MyCollection& myCollection)
{
    for(YouTubeChannel ytChannel:myCollection.myChannels)
        COUT << ytChannel << endl;


    return COUT;
}

int main()
{
    YouTubeChannel yt1 = YouTubeChannel("woody", 7500);
    YouTubeChannel yt2 = YouTubeChannel("secend", 17500);

    // cout << yt1 << yt2;
    // operator<<(cout, yt1);// same as cout << yt1;
    cout << yt1;

    cout << "---------------------------------\n" << endl;
    // operator+
    MyCollection MyCollection;
    MyCollection += yt1;
    MyCollection += yt2;

    cout << MyCollection;

    cout << "---------------------------------\n" << endl;
    MyCollection -= yt1;
    cout << MyCollection;

    return 0;
}
