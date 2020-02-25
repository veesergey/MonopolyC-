#pragma once
#include<iostream>
#include"player.h"
#include"Property.h"
void windowSize()
{
	HANDLE buff = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD sizeOfBuff;
	sizeOfBuff.X = 1600;
	sizeOfBuff.Y = 900;
	SetConsoleScreenBufferSize(buff, sizeOfBuff);

	RECT r;
	//Find the Console Window
	HWND console = GetConsoleWindow();
	// Get the size of screen to the variable desktop
	GetWindowRect(console, &r);
	int width = 1600;
	int height = 900;
	MoveWindow(console, r.left, r.top, width, height, TRUE);

}







