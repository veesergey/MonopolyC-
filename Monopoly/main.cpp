#include<iostream>
#include<iomanip>
#include<windows.h>
#include<vector>
#include<algorithm>
#include<string>
#include "Property.h"
#include"Game.h"
#include"functions.h"
#include "player.h"
using namespace std;

int main()

{	//Adjusts the window size to 1600 by 900
	windowSize();
	//Creates game object Monopoly
	Game monopoly;
	
	monopoly.playerTurns();

	monopoly.victory();

	system("pause");

	return 0;
}