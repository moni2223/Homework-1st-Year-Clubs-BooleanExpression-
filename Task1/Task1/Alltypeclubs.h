#include "Clubs.h"

class FolkClub : public Club 
{
private:
    char singerName[100];
public:
    FolkClub(const char* name, int vodkaPrice, int whiskeyPrice, const char* singerName)
        :Club(name, vodkaPrice, whiskeyPrice, "Pop folk", 70)
    {
        strcpy(this->singerName, singerName);
    }
    bool ValidateData(int vodkaPrice, int whiskeyPrice) {
        if (vodkaPrice >= 20 && whiskeyPrice >= 35)
            return true;
        return false;
    }
    bool ValidateClient(UserData& ud) {
        if (ud.age < 18)
            ud.money -= 20;
        return true;
    }
};

class HouseClub : public Club 
{
private:
    int djCount;
public:
    HouseClub(const char* name, int vodkaPrice, int whiskeyPrice, int djCount)
        :Club(name, vodkaPrice, whiskeyPrice, "House", 1000)
    {
        this->djCount = djCount;
    }
    bool ValidateData(int vodkaPrice, int whiskeyPrice) {
        if (vodkaPrice >= 30 && whiskeyPrice >= 40)
            return true;
        return false;
    }
    bool ValidateClient(UserData& ud) {
        if (ud.age < 18)
            return false;
        return true;
    }
};

class RockClub : public Club 
{
public:
    RockClub(const char* name, int vodkaPrice, int whiskeyPrice)
        :Club(name, vodkaPrice, whiskeyPrice, "Rock", 30)
    {
    }
    bool ValidateData(int vodkaPrice, int whiskeyPrice) {
        if (vodkaPrice >= 40 && whiskeyPrice >= 30)
            return true;
        return false;
    }
    bool ValidateClient(UserData& ud) {
        if (ud.age < 18)
            return false;
        return true;
    }
};

