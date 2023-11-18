#include <iostream>
#include <list>
using namespace std;

/*
    inheritance in programming
*/

// class define data type
class YouTubeChannel{
private:
        string Name;
        // string OwnerName;        // move to protected let class CookingYouTubeChannel can use it
        int SubscriberCount;
        list<string> PublishedVideoTitle;

protected:
        string OwnerName;

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

//inheritance YouTubeChannel
class CookingYouTubeChannel:public YouTubeChannel{
public: 
    CookingYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName){

    }
    void Practice(){
        // OwnerName need to set protected
        cout << OwnerName << " practicing cooking, learning new recippes, experimenting with spices ..." << endl;
    }
};

int main()
{
    CookingYouTubeChannel cookingytChannel("Woody", "Hu");

    cookingytChannel.PublishedVideo("C++ for Cooking");
    cookingytChannel.PublishedVideo("C++ Cooking");
    cookingytChannel.Subscribe();
    cookingytChannel.GetInfo();
    cookingytChannel.Practice();

    YouTubeChannel ytChanne("Ton", "Lee");
    ytChanne.Subscribe();
    ytChanne.GetInfo();
    // class YouTubeChannel can't using Practice()
    // ytChanne.Practice();

    CookingYouTubeChannel cookingytChannel2("Eric", "Ch");
    cookingytChannel2.Practice();

    return 0;
}
