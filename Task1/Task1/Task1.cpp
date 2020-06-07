#include <iostream>
#include "Allclubs.h"

using namespace std;

int main() {
    
    Clubs clubs;
    cout<<clubs.addFolkClub("Planeta Painer", 30, 50, "Malkata")<<endl;
    cout<<clubs.addRockClub("V mazeto na Pesho metula", 50, 40)<<endl;
    cout<<clubs.addFolkClub("33", 50, 60, "Azis")<<endl;
    
    User pesho("Pesho", 21, 200, 1, 0, "Pop folk");
    User gosho("Gosho", 21, 200, 1, 0, "Rock");
    User cvetanka("Cvetanka", 18, 20, 1, 2, "Pop folk");
    User koceto("Koceto", 23, 500, 0, 2, "All");
    
    cout << clubs.addToClub(pesho, "Planeta Painer") << endl;//1
    cout << clubs.addToClub(gosho, "Planeta Painer") << endl;//0
    cout << clubs.addToClub(cvetanka, "Planeta Painer") << endl;//0
    cout << clubs.addToClub(koceto, "V mazeto na Pesho metula") << endl;//1

    cout << "Remove tests" << endl;

    cout << clubs.removeFromClub("Pesho", "Planeta Painer") << endl;//1
    cout << clubs.removeFromClub("Gosho", "Planeta Painer") << endl;//0
    cout << clubs.removeFromClub("Koceto", "V mazeto na Pesho metula") << endl;//1
    return 0;
    
}