#pragma once
#include <iostream>
#include <string>
class Property
{
private:
	std::string name;
	int cost;
	bool isOwned;
	int rent;
	std::string owner = " ";
	

public:
	Property(std::string name = "", int cost = 0, int rent = 0, bool isOwned = false)
	{
		this->name = name;
		this->cost = cost;
		this->isOwned = isOwned;
		this->rent = rent;
	}
	void setname(std::string name)
	{
		this->name = name;
	}
	void setcost(int cost)
	{
		this->cost = cost;
	}
	void setIsOwned(bool isOwned)
	{
		this->isOwned = isOwned;
	}
	std::string getName()
	{
		return this->name;
	}
	int getCost()
	{
		return this->cost;
	}
	bool getIsOwned()
	{
		return this->isOwned;
	}

	void setRent(int rent) {
		this->rent = rent;
	}

	int getRent() {
		return this->rent;
	}

	//Tile stuff - Added Night of dec/13/2017
	std::vector<std::string> onTile;


	void addToTile(std::string toAdd) {
		onTile.push_back(toAdd);
	}

	void takeOffTile(std::string toDel) {
		int x = 0;
		for (std::string thing : onTile) {
			if (thing == toDel)
				onTile.erase(onTile.begin() + x);
			x++;
		}
	}

	std::string getOnTile() {
		std::string onTileString;
		for (std::string thing : onTile) {
			onTileString += thing;
		}
		return onTileString;
	}

	void printOnTile() {
		for (std::string thing : onTile) {
			std::cout << thing << " ";
		}
	}

	//More tile stuff, but upgrades to properties, like hotels/turrets. potential implementation.
	std::vector<std::string> upgrades; //max 2 turret, 4 hotels. If this gets implemented.

	void addUpgrade (std::string toAdd){
		upgrades.push_back(toAdd);
	}

	std::string getUpgrade() {
		std::string upgradeString;
		for (std::string upgrade : upgrades) {
			upgradeString += upgrade;
		}
		return upgradeString;
	}

	
	void setOwner(std::string name) {
		this->owner = name;
	}
	

	std::string getOwner() {
		return this->owner;
	}

	void mortage() {
		mortageStatus = true;
	}

	void unmortage() {
		mortageStatus = false;
	}

	bool mortageStatus = false;

};
 
class railRoad :public Property
{
	/*/Can travel to other places in the board, Only if x player owns all 4 properties
	So this property will not be able to take any houses or anything like that.
	/*/
};

