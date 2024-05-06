#ifndef MAINCARDCLASS_H
#define MAINCARDCLASS_H


class MainCardClass
{
public:
    MainCardClass();
    int cardID = 1;
    int owner;
    int colorId;
    int firstCost;
    int currentRent;
private:
    int rentIfHouse[5] = {0};
    int mortageVal;
    int baseRent;
    bool isMortage = false;
    bool isStation, isUtility;
};

#endif // MAINCARDCLASS_H
