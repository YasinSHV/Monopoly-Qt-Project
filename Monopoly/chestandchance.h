#ifndef CHESTANDCHANCE_H
#define CHESTANDCHANCE_H


class ChestAndChance
{
private:

public:
    ChestAndChance();

    int cardID = 0;


    virtual int chAndcomm() = 0;
};

class ChestJail : public ChestAndChance
{
public:
    int chAndcomm()
    {
        switch (cardID) {
        case 1:
            return 1;
            break;
        case 2:
            return 0;
            break;
        }
    }
};

class ChestPay : public ChestAndChance
{
    int chAndcomm()
    {
        switch (cardID) {
        case 3:
            return 111;
            break;
        case 4:
            return 200;
            break;
        case 5:
            return -50;
            break;
        case 6:
            return 45;
            break;
        case 7:
            return 222;
            break;
        case 8:
            return 20;
            break;
        case 9:
            return 100;
            break;
        case 10:
            return -100;
            break;
        case 11:
            return -150;
            break;
        case 12:
            return 25;
            break;
        case 13:
            return 100;
            break;
        case 14:
            return 333;
            break;
        case 15:
            return 10;
            break;
        case 16:
            return 100;
            break;

        }
    }
};

class ChanceMove : public ChestAndChance
{
public:
    int chAndcomm()
    {
        switch (cardID) {
        case 17:
            return 1;
            break;
        case 18:
            return 0;
            break;
        case 19:
            return 1;
            break;
        case 20:
            return 1;
            break;
        case 21:
            return 1;
            break;
        case 22:
            return 1;
            break;
        case 23:
            return 1;
            break;
        case 24:
            return 1;
            break;

        }
    }
};

class ChancePay : public ChestAndChance
{
    int chAndcomm()
    {
        switch (cardID) {
        case 25:
            return 111;
            break;
        case 26:
            return -15;
            break;
        case 27:
            return 150;
            break;
        case 28:
            return 333;
            break;
        case 29:
            return 222;
            break;
        case 30:
            return 50;
            break;
        }
    }
};
#endif // CHESTANDCHANCE_H
