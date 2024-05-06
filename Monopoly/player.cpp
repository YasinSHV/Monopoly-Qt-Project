#include "player.h"

Player::Player()
{

}


void Player::SetName(std::string _name){name = _name;}
std::string Player::GetName(){return name;}


void Player::SetIconId(int id){iconId = id;}
int Player::GetIconId(){return iconId;}


void Player::SetBalance(int val){balance += val;}
int Player::GetBalance(){return balance;}


void Player::setInJail(bool jail){inJail = jail;}
bool Player::getInJail(){return inJail;}

void Player::SetJailFree(bool jailfree) {hasJailFree = jailfree;}
bool Player::GetJailFree(){return hasJailFree;}


void Player::SetBankrupt(bool bank){bankrupt = bank;}
bool Player::GetBankrupt() {return bankrupt;}
