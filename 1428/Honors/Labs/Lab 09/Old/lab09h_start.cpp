/*
 * main.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: mme1
 */


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

/******************************************************************************
 * These Functions have already been done for you.
 ******************************************************************************/
void loadBoard(ifstream& fin, char board[][20], int& locR, int& locC );
void printBoard(char board [][20]);
/******************************************************************************/
/******************************************************************************/

//The below functions need parameters. You must use passByRef and passByVal
//for this program to work.
/*Hint #1
 * Four of these six functions have almost identical parameters
 * Hint #2
 * Of those four, they can be grouped into groups of two which have identical
 * parameters
 */
void setEnd();
bool moveU();
bool moveD();
bool moveL();
bool moveR();
bool checkNewLoc();


int main()
{
	char board[20][20];
	ifstream fin;
	fin.open("boardL1.txt");
	int locR = 0;
	int locC = 0;
	bool gameDone = false;
    char choice = ' ';

    //CALL THE LOAD BOARD FUNCTION!


	while(!gameDone)
	{

		switch (choice)
		{

		}



	}

	return 0;
}

/****************
 * My gift to you
 ****************/
/******************************************************************************
******************************************************************************/
void loadBoard(ifstream& fin, char board[][20], int& locR, int& locC )
{
	string temp;
	for(int r=0; r<20; r++)
	{
		getline(fin,temp);
		for(unsigned int c =0; c<temp.length(); c+=2)
		{
			if(temp.at(c)=='P')
			{
				locR = r;
				locC = (c/2);
			}
			board[r][c/2] = temp.at(c);
		}

	}

}
/******************************************************************************/
void printBoard(char board [][20])
{
	for(int r=0; r<20; r++)
	{
		for(int c=0; c<20; c++)
		{
			cout<<board[r][c] << " ";
		}

		cout<<endl;
	}
}
/******************************************************************************
******************************************************************************/
void setEnd()
{
	//Implement this function here.
	//Don't forget to put your parameters in!

}
bool moveU()
{
	//Implement this function here.
	//Don't forget to put your parameters in!
	return false;
}
bool moveD()
{
	//Implement this function here.
	//Don't forget to put your parameters in!
	return false;
}
bool moveL()
{
	//Implement this function here.
	//Don't forget to put your parameters in!
	return false;
}
bool moveR()
{
	//Implement this function here.
	//Don't forget to put your parameters in!
	return false;
}

bool checkNewLoc()
{
	//Implement this function here.
	//Don't forget to put your parameters in!
	return false;
}

*/
