#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
public:
    Player();
    int colorSets[9] = {0};
    int stationCount = 0;
    int houseCount = 0;
    int hotelCount = 0;
    int lastThrough = 0;
    int jailTime = 0;
    int offer = 0;
    int sender = 0;

    void SetName(std::string);
    std::string GetName();

    void SetIconId(int);
    int GetIconId();

    void SetBalance(int);
    int GetBalance();

//    void SetPostion(int x);
//    int getY();
//    int getX();

    void setInJail(bool);
    bool getInJail();

    void SetJailFree(bool);
    bool GetJailFree();

    void SetBankrupt(bool);
    bool GetBankrupt();


    int matX = 10, matY = 10;

private:
    std::string name;
    int balance = 1500;
    int iconId = -1;
    bool bankrupt = false, hasJailFree = false, inJail = false;


};

#endif // PLAYER_H
