#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include"Property.h"
class Player {
public: 
	//n = name, s = sigil, m = money. Still needs a vector of property objects. 
	Player(std::string name, std::string sigil, int money);
	std::vector<Property> ownedProperty;
	std::vector<Property> mortagedProperty;

	//Getters and setters for name
	std::string getName();
	void setName(std::string);

	//Getter and setter for sigil
	std::string getSigil();
	void setSigil(std::string);

	//Getter setter for properties
	void getProperties();

	//Overloaded Property function. One asks what property you would like to sell, in the other it must be passed as a reference. Not sure which to use.
	void sellProperty(std::vector<Property>&, std::vector<Property>&);
	void sellProperty();

	//Overloaded Buy property  function. Overloading it on dec/13/2017 because theres more code complete. keeping old one just in case.
	void buyProperty(std::vector<Property>&);
	void buyProp(std::vector<Property>&, std::vector<Property>&);

	//Upgrades/HOtels
	void buyHotel(std::vector<Property>&);

	//Getter, setter for money. Also add money and subtract money function. Does basic check to make sure of no neg numbers or zero.
	int getMoney();
	void setMoney(int);
	void addMoney(int moneyGain);
	void subMoney(int moneyLoss);
	//Getts and setters for position
	void setPos(int);
	int getPos();
	int getNewPos();
	int rollDice();
	
	//Mortage methods

	void mortageProperty(Property&);

	void unMortageProp(Property&);

private:
	std::string name;
	std::string sigil;
	int money;
	
	int position;
};