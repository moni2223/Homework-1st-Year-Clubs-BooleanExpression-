#include "UserStaticData.h"
using namespace std;

struct UserData {
    char name[1024];
    char reqMusicType[10];
    char reqMusicTypeAlt[10];
    int reqVodkaCount;
    int reqWhiskeyCount;
    int money;
    int age;
};

class User {
private:
    UserStaticData usd;

    char name[1024];
    int age;
    int money;
    int vodkaCount;
    int whiskeyCount;
    char musicType[15];
    char inclub[100];
public:
    User(const char* name, int age, int money, int vodkaCount, int whiskeyCount, const char* musicType) 
    {
        strcpy(this->name, name);
        this->age = age;
        this->money = money;
        this->vodkaCount = vodkaCount;
        this->whiskeyCount = whiskeyCount;
        strcpy(this->musicType, musicType);
        if(this-> age!= 0)printallinfo();
        
    }
    User() :User("Unknown", 0, 0, 0, 0, "Unknown") {};
    UserData getUserData() {
        UserData ud;
        strcpy(ud.reqMusicType, this->musicType);
    
        if (strlen(ud.reqMusicType) == strlen("Rock")) 
            strcpy(ud.reqMusicTypeAlt, usd.Rockalt());
        else if(strlen(ud.reqMusicType) == strlen("Pop folk"))
            strcpy(ud.reqMusicTypeAlt, usd.Popfolkalt());
        else if (strlen(ud.reqMusicType) == strlen("House"))
            strcpy(ud.reqMusicTypeAlt, usd.Housealt());
        else if (strlen(ud.reqMusicType) == strlen("All"))
            strcpy(ud.reqMusicTypeAlt, usd.Allalt());

        ud.reqVodkaCount = this->vodkaCount;
        ud.reqWhiskeyCount = this->whiskeyCount;
        ud.money = this->money;
        ud.age = this->age;
        strcpy(ud.name, this->name);
        return ud;
    }
    void set_inclub(const char* inclub) 
    {
        strcpy(this->inclub, inclub);
    }
    char* get_inclub() 
    {
        return inclub;
    }
    char* get_name() 
    {
        return name;
    }
    void CopyFrom(const User& other)
    {
        strcpy(name, other.name); //copy name
        age = other.age;
        money = other.money;
        vodkaCount = other.vodkaCount;
        whiskeyCount = other.whiskeyCount;
        strcpy(musicType, other.musicType);
    }
    void Free()
    {
        vodkaCount = whiskeyCount = age = money = 0;
    }
    User& operator=(const User& other)
    {
        if (this != &other)
        {
            Free();

            CopyFrom(other);
        }
        return *this;
    }
    int get_age() 
    {
        return age;
    }

    void printallinfo()
    {
        cout << "Name: " << this->name << " Age: " << this->age 
            << " Cash: " << this->money << " Vodkas: " 
            << this->vodkaCount << " Whiskeys: " 
            << this->whiskeyCount << " Music: " << this->musicType << endl;
    }
};