#include <iostream>
#include "User.h"
using namespace std;

struct ClubData {
    char name[1024];
    int vodkaPrice;
    int whiskeyPrice;
    char musicType[1024];
};

class Club {
private:
    char name[1024];
    int vodkaPrice;
    int whiskeyPrice;
    int capacity;
    int capacityLeft;
    char musicType[1024];
public:
    Club(const char* name, int vodkaPrice, int whiskeyPrice, const char* musicType, int capacity) {
        strcpy(this->name, name);
        this->vodkaPrice = vodkaPrice;
        this->whiskeyPrice = whiskeyPrice;
        strcpy(this->musicType, musicType);
        this->capacity = capacity;
        this->capacityLeft = capacity;
    }
    Club() : Club("Unknown", 0, 0, "Unknown",0) {};
    virtual bool ValidateData(int vodkaPrice, int whiskeyPrice) = 0;
    virtual bool ValidateClient(UserData& ud) = 0;
    
    int getVodkaPrice()
    {
        return this->vodkaPrice;
    }
    int getWhiskeyPrice()
    {
        return this->whiskeyPrice;
    }
    char* getMusicType()
    {
        return this->musicType;
    }
    bool AddClient()
    {
        if (this->capacityLeft == 0)
            return false;
        this->capacityLeft--;
        return true;
    }
    bool RemoveClient()
    {
        if (this->capacityLeft == this->capacity)
            return false;
        this->capacityLeft++;
        return true;
    }

    ClubData getClubData() 
    {
        ClubData cd;
        strcpy(cd.name, this->name);
        cd.vodkaPrice = this->vodkaPrice;
        cd.whiskeyPrice = this->whiskeyPrice;
        strcpy(cd.musicType, this->musicType);
        return cd;
    }
    void CopyFrom(const Club& other)
    {
        int len = strlen(other.name);
        char* name=new char[len+1];
        strcpy(name, other.name); //copy name
        vodkaPrice = other.vodkaPrice;
        whiskeyPrice = other.whiskeyPrice;
        int len1 = strlen(other.musicType);
        char* musictype = new char[len1 + 1];
        strcpy(musictype, other.musicType);
    }
    void Free() 
    {
        delete[] name;
        vodkaPrice = whiskeyPrice = 0;
        delete[] musicType;
    }
    Club& operator=(const Club& other)
    {
        if (this != &other)
        {
            Free(); 

            CopyFrom(other); 
        }
        return *this; 
    }

    char* get_name()  
    {
        return name;
    }
    
    void printfullinfo() 
    {
        cout << " Name: " << name << " Vodka price: " << vodkaPrice <<" Whiskey price: "<<whiskeyPrice<<" musicType: " <<musicType<<endl;
    };
};