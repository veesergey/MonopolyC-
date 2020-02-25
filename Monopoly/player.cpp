#include "player.h"
#include "Property.h"
#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<time.h>

Player::Player(std::string name, std::string sigil, int money)
{
	setName(name);
	setSigil(sigil);
	setMoney(money);
	setPos(0);
}



std::string Player::getName()
{
	return name;
}

void Player::setName(std::string n)
{
	name = n;
}

std::string Player::getSigil()
{
	return sigil;
}

void Player::setSigil(std::string s)
{	
	sigil = s;
}

int Player::getMoney()
{
	return money;
}

void Player::setMoney(int m = 1500)
{
	money = m;
}

void Player::addMoney(int moneyGain)
{
	if (moneyGain > 0) {
		money += moneyGain;
	}
	else
		std::cout << moneyGain << " is an invalid amount of money." << std::endl;
}

void Player::subMoney(int moneyLoss)
{
	if (moneyLoss > 0) {
		money -= moneyLoss;
	}
	else
		std::cout << moneyLoss << " is not a valid amount." << std::endl;
}

void Player::getProperties() {
	//This function prints the list of properties a player owns.
	std::cout << "Properties of " << name << ":" << std::endl;
	if (ownedProperty.size() >= 1) {
		for (Property prop : ownedProperty) {
			std::cout << prop.getName() << std::endl;
		}
	}
	else
		std::cout << "Zero Properties Owned" << std::endl;
	
}

//This is the old function.....not used anywhere I dont think. Kept for reference and POTENTIAL USE? Prolly not though.
/*
void Player::buyProperty(std::vector<Property>& propList) {
	std::string toBuy;
	std::cout << "What property would you like to buy?: ";
	std::cin >> toBuy;
	int x = 0;
	for (Property prop : propList) {
		if (prop.getName() == toBuy && prop.getIsOwned() == true) {
			std::cout << "This property already has an owner (" << prop.getOwner() << ")." << std::endl;
			std::cout << prop.getName() << " was not purchased." << std::endl;
		}
		else if (prop.getName() == toBuy && prop.getIsOwned() == false && this->getMoney() >= prop.getCost()) {
			//Takes Money from player to buy property
			subMoney(prop.getCost());
			//Adds property to players owned property list
			ownedProperty.push_back(prop);
			//Erases property from the game object list of unowned properties
			propList.erase(propList.begin() + x);
			//Prints out the purchase was successful
			std::cout << getName() << " has purchased " << prop.getName() << std::endl;
		}
		else if (prop.getName() == toBuy && getMoney() < prop.getCost()) {
			std::cout << getName() << " has " << getMoney() << " but needs " << prop.getCost() << " to purchase " << prop.getName() << std::endl;
			std::cout << prop.getName() << " was not purchased." << std::endl;
		}
		x++;
	}
}
*/

void Player::buyProp(std::vector<Property>& unownedPropList, std::vector<Property>& board) {
	int playerPos = this->getPos();
	std::string propToBuy = board[playerPos].getName();
	int x = 0;
	for (Property prop : unownedPropList) {
		if (propToBuy == "Go" || propToBuy == "Quest" || propToBuy == "Scroll" || propToBuy == "Stocks" || propToBuy == "Quest2" || propToBuy == "TwnSqr" || propToBuy == "Scroll2" || propToBuy == "Sheriff") {
			std::cout << "Cannot purchase " << propToBuy << " as it is not a purchaseable property." << std::endl;
			break;
		}
		else if (board[playerPos].getName() == propToBuy && board[playerPos].getIsOwned() == true) {
			std::cout << "This property already has an owner (" << prop.getOwner() << ")." << std::endl;
			std::cout << prop.getName() << " was not purchased." << std::endl;
			break;
		}
		else if (prop.getName() == propToBuy && prop.getIsOwned() == false && this->getMoney() >= prop.getCost()) {
			//Takes Money from player to buy property
			subMoney(prop.getCost());
			//Adds property to players owned property list
			ownedProperty.push_back(prop);
			//Erases property from the game object list of unowned properties
			unownedPropList.erase(unownedPropList.begin() + x);
			//Prints out the purchase was successful
			std::cout << getName() << " has purchased " << prop.getName() << std::endl;
			board[playerPos].setOwner(getName());
			board[playerPos].setIsOwned(true);
			break;
		}
		else if (prop.getName() == propToBuy && getMoney() < prop.getCost()) {
			std::cout << getName() << " has " << getMoney() << " but needs " << prop.getCost() << " to purchase " << prop.getName() << std::endl;
			std::cout << prop.getName() << " was not purchased." << std::endl;
			break;
		}
		//IM IM HIDEOUS, DONT LOOK AT ME! ~The following if statement.
		x++;
	}
	
}

void Player::buyHotel(std::vector<Property>& board) {
	int playerPos = getPos();
	int curRent = board[playerPos].getRent();

	for (Property &prop : ownedProperty) {
		if (board[playerPos].getName() == prop.getName()) {
			board[playerPos].addUpgrade("H");
			board[playerPos].setRent(curRent + 150);
			prop.setRent(curRent + 150);
			std::cout << "Hotel bought for " << prop.getName() << "." << std::endl;
			subMoney(250);//Hotel PRice
		}
	}
	
	

}

void Player::sellProperty(std::vector<Property>& unownedProperty, std::vector<Property>& board) {
	//Asks the user what property to sell. User enters name. If input == owned Property, removes the property
	//From the players ownedProprety list, and adds cost of property to the players money.
	std::string toSell;
	std::cout << "What property would you like to sell?: ";
	std::cin >> toSell;
	//Using a counter to see which element it is.
	int x = 0;
	for (Property prop : ownedProperty) {
		if (prop.getName() == toSell) {
			ownedProperty.erase(ownedProperty.begin() + x);
			addMoney(prop.getCost());
			unownedProperty.push_back(prop);
			std::cout << name << " has sold " << prop.getName() << std::endl;
			board[getPos()].setOwner(" ");
			board[getPos()].setIsOwned(false);
		}
		x++;
	}
}

int Player::rollDice() {

	srand(time(0)); //seed

	int dieRoll = rand() % 5 + 1;

	return dieRoll;

}

int Player::getNewPos()
{
	int die1 = rollDice();
	int oldPos = this->position;

	if (oldPos + die1 <= 25) 
		this->position += die1;
	else if (oldPos + die1 > 25) {
		this->position += (oldPos + die1) - 25;
		addMoney(200);
	}
	else if (this->position < 0) {
		this->position = 0;
	}
	
	std::cout << getName() << " has moved " << die1 << " spaces." << std::endl;
	return this->position;
}

void Player::setPos(int x) {
	this->position = x;
}

int Player::getPos() {
	return this->position;
}

void Player::mortageProperty(Property& prop) {
	prop.mortage();
	addMoney(prop.getCost());
}

void Player::unMortageProp(Property& prop) {
	prop.unmortage();
	subMoney(prop.getCost());
}