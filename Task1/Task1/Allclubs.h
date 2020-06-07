#include "Alltypeclubs.h"
#include <map>
using namespace std;
bool isequalarrays(char* temp, char* temp1)
{
    int len = strlen(temp);
    int len1 = strlen(temp1);
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (temp[i] == temp1[i])count++;
        else break;
    }
    if (count == len)return 1;
    else return 0;
}
bool isequalarrays1(char* temp, const char* temp1) 
{
    int len = strlen(temp);
    int len1 = strlen(temp1);
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (temp[i] == temp1[i])count++;
        else break;
    }
    if (count == len)return 1;
    else return 0;
}

Club** clubs = new Club*[100];
User* peopleinClubs = new User[3];
static int personid = 0;
static int clubsid = 0;

class Clubs {
public:
    bool addFolkClub(const char* name, int vodkaPrice, int whiskeyPrice, const char* singerName) {
        FolkClub* fc = new FolkClub(name, vodkaPrice, whiskeyPrice, singerName);
        bool valid = fc->ValidateData(vodkaPrice, whiskeyPrice);
        if (valid) {
            clubs[clubsid] = fc;
            clubsid++;
        }
        return valid;
    }
    bool addHouseClub(const char* name, int vodkaPrice, int whiskeyPrice, int djCount) {
        HouseClub* hc = new HouseClub(name, vodkaPrice, whiskeyPrice, djCount);
        bool valid = hc->ValidateData(vodkaPrice, whiskeyPrice);
        if (valid) {
            clubs[clubsid] = hc;
            clubsid++;
        }
        return valid;
    }
    bool addRockClub(const char* name, int vodkaPrice, int whiskeyPrice) {
        RockClub* rc = new RockClub(name, vodkaPrice, whiskeyPrice);
        bool valid = rc->ValidateData(vodkaPrice, whiskeyPrice);
        if (valid) {
            clubs[clubsid] = rc;
            clubsid++;
        }
        return valid;
    }
    bool addToClub(User& usr, const char* clubName) {
        UserData ud = usr.getUserData();
        int clubid = 0;
        for (int i = 0; i < clubsid; i++)
        {
            if (isequalarrays1(clubs[i]->get_name(), clubName) == 1) 
                clubid = i;
        }

        Club* club = clubs[clubid];
        if (club == 0) return false;

        bool valid = club->ValidateClient(ud);
        if (!valid) return valid;

        ClubData cd = club->getClubData();

        int totalPrice = ud.reqVodkaCount * cd.vodkaPrice;
        totalPrice += ud.reqWhiskeyCount * cd.whiskeyPrice;
        if (totalPrice > ud.money) return false;
        char allword[] = "All";
        if (isequalarrays(ud.reqMusicType, allword)==0) 
        {
            if (isequalarrays(ud.reqMusicType,cd.musicType) == 0 && isequalarrays(ud.reqMusicTypeAlt, cd.musicType) == 0)
                return false;
        }

        valid = club->AddClient();
        if (!valid) return valid;

        char hashSignature[100];
        strcpy(hashSignature, ud.name);
        strcat(hashSignature, cd.name);
        peopleinClubs[personid] = usr;
        peopleinClubs[personid].set_inclub(club->get_name());
        personid++;
        return true;
    }
    bool removeFromClub(const char* personName, const char* clubName) {
        bool foundclub = 0;
        for (int i = 0; i < clubsid; i++)
        {
            if (isequalarrays1(clubs[i]->get_name(), clubName) == 1) 
            {
                foundclub = 1;
                break;
            }
        }
        if (foundclub == 1) 
        {
            for (int i = 0; i < personid; i++)
            {
                if (isequalarrays1(peopleinClubs[i].get_inclub(), clubName) == 1 
                    && isequalarrays1(peopleinClubs[i].get_name(),personName) ==1 ) 
                {
                    peopleinClubs[i].set_inclub("None");
                    return true;

                }
            }
        }
        return false;
    }
};