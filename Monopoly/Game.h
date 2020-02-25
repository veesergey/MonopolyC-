#pragma once
#include<iostream>
#include<string>
#include"Card.h"
#include"player.h"
#include"Property.h"


class Game{

public:
	//blank constructor, game doesnt really have attributes
	Game();
	//Vectors
	std::vector<Property> unownedProperty;
	std::vector<Player> playerList;
	std::vector<std::string> sigilList;
	std::vector<Property> board;
	//Many functions taken from 'functions.h'
	void welcome();

	int getHumans();

	void createPlayers();

	//SO MANY PRINT FUNCTIONS OMG...Thinking of adding more. "Whenever you're copying and pasting code, make a function instead." ~The ever-wise and all-knowing Jon Ventullet. ~ Vitaliy Sergeychik
	void printTile(Property);
	
	void printTopRow(std::vector<Property>, Player);

	void printMidRow1(std::vector<Property>, int, int, Player);

	void printMidRow2(std::vector<Property>, int, int, Player);

	void printMidRow(std::vector<Property>, int, int, Player);

	void printBotRow(std::vector<Property>, Player);

	void printBoard(std::vector<Property>, Player);

	void addPlayersToBoard();

	void printPlayers(std::vector<Player> &playerList);

	void printProperties(std::vector<Property> &propertyList);

	void playerTurns();

	int diceRoll();

	void movePlayer(Player &player);

	void movePlayerManual(Player& player, int);

	void checkNewTile(std::vector<Property>&, std::vector<Player>&, Player&);

	void travelRailRoad(Player);

	void checkPlayers(std::vector<Player>&);

	void victory();

private:
	
};