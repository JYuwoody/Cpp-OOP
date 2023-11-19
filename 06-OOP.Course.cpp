#include <iostream>
#include <list>
using namespace std;

/*
    polymorphism in programming
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
        int ContentQuality;

public:
    //constructors
    YouTubeChannel( string name, string ownerName){
        Name = name;
        OwnerName = ownerName;
        SubscriberCount = 0;
        ContentQuality = 0;
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
    void CheckAnalytics(){
        if(ContentQuality < 3)
            cout << Name << "has bad content" << endl;
        else
            cout << Name << "has great content" << endl;
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
        ContentQuality++;
    }
};

class SingersYouTubeChannel:public YouTubeChannel{
public: 
    SingersYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName){

    }
    void Practice(){
        // OwnerName need to set protected
        cout << OwnerName << " is taking singing classg, learning new snog, learning how to dance ..." << endl;
        ContentQuality++;
    }
};

int main()
{
    CookingYouTubeChannel cookingytChannel("Woody", "Hu");
    SingersYouTubeChannel singersytChannel("Nia-sing", "Nia");

    // cookingytChannel.PublishedVideo("C++ for Cooking");
    // cookingytChannel.PublishedVideo("C++ Cooking");
    // cookingytChannel.Subscribe();
    // cookingytChannel.GetInfo();
    cookingytChannel.Practice();
    singersytChannel.Practice();
    singersytChannel.Practice();
    singersytChannel.Practice();        

    // pointer
    YouTubeChannel* yt1 = &cookingytChannel;
    YouTubeChannel* yt2 = &singersytChannel;
    
    yt1->CheckAnalytics();
    yt2->CheckAnalytics();

    return 0;
}
