#ifndef HOUSECARDS_H
#define HOUSECARDS_H

class HouseCards
{
public:
    HouseCards(int _colorID, int _firstBuy, int _baseRent, bool _station
               , bool _utility, int house1, int house2, int house3, int house4, int hotel);

    int cardID = 1;
    int owner = -1;
    int colorId;
    int firstCost;
    int houseCost = 50;
    int houseCount = -1;
    bool hasHotel = false;
    int mortageVal;
    bool isMortage = false;
    bool isStation, isUtility;
    HouseCards() {}

    void setRent();
    int getRent(int station, int n3);

private:
    int currentRent;
    int rentIfHouse[5] = {0};
    int baseRent;
};

#endif // HOUSECARDS_H
