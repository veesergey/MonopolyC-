#pragma once
#include <iostream>

 class Card
{	private:
	std::string name;
	std::string desc; 
	//Make card function getPayment or Give payment
	//Make also function that sees if card sends player to jail
	bool toJail;
	int giveMoney;
	int getMoney;
public:
	Card();
	Card(std::string name,std::string desc, bool toJail, int giveMoney, int getMoney)
	{
		this->name = name;
		this->desc = desc;
		this->toJail = toJail;
		this->giveMoney = giveMoney;
		this->getMoney = getMoney;
	}
	void setname(std::string name)
	{
		this->name = name;
	}
	void setdesc(std::string dec)
	{
		this->name = desc;
	}
	void SettoJail(bool toJail)
	{
		this->toJail = toJail;
	}
	void setGiveMoney(int giveMoney)
	{
		this->giveMoney = giveMoney;
	}
	void setGetMoney(int getMoney)
	{
		this->getMoney = getMoney;
	}
	std::string getName()
	{
		return name;
	}
	std::string getDesc()
	{
		return desc;
	}
	bool getToJail()

	{
		return this->toJail;
	}
	int getGiveMoney()
	{
		return this->giveMoney;
	}
	int getGetMoney()
	{
		return this->getMoney;
	}

};
