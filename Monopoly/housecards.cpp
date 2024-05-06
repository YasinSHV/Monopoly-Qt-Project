#include "housecards.h"


HouseCards::HouseCards(int _colorID, int _firstBuy, int _baseRent,bool _station
                       , bool _utility, int house1, int house2, int house3, int house4, int hotel)

{
   static int id = 1; cardID = id++;
   colorId = _colorID;
   firstCost = _firstBuy;
   baseRent = _baseRent;
   mortageVal = (firstCost / 2);
   isStation = _station;
   isUtility = _utility;

   if(cardID <= 6)
    houseCost = 50;
   else if(cardID > 6 && cardID < 15)
       houseCost = 100;
   else if(cardID > 14 && cardID < 23)
       houseCost = 150;
   else if(cardID > 22 && cardID < 29)
       houseCost = 200;

   currentRent = _baseRent;

   rentIfHouse[0] =house1;
      rentIfHouse[1] =house2;
         rentIfHouse[2] =house3;
            rentIfHouse[3] = house4;
               rentIfHouse[4] = hotel;
}

int HouseCards::getRent(int station, int n3)
{
    int x = currentRent;
    if(isStation)
    {
     x = x*station;
     return x;
    }else if(isUtility)
    {
        x = 4 * n3;
       return x;
    }else if(houseCount != -1)
    {
        return rentIfHouse[houseCount];
    }
    else{
     return currentRent;}
}
