/*
 * main.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: mme1



#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;
struct Player
{

};
struct Board
{
	char space;
	char stat;
};
void loadBoard(ifstream& fin, Board board[][20], int& locR, int& locC );
void printBoard(Board board [][20]);
void setEnd(bool& end, bool e);
void chooseCharacter();
void showCharacter();
void incHealth();
void incAttack();
void incDefense();
void incSpecial();
void incWeapon();
bool moveU(int& locR, int locC, char board[][20], bool& end);
bool moveD(int& locR, int locC, char board[][20], bool& end);
bool moveL(int locR, int& locC, char board[][20], bool& end);
bool moveR(int locR, int& locC, char board[][20], bool& end);
bool checkNewLoc(char space,  bool &end);


int main()
{
	Board board[20][20];
	ifstream fin;
	fin.open("boardL1.txt");
	int locR = 0;
	int locC = 0;
	bool gameDone = false;
    char choice = ' ';
    loadBoard(fin, board, locR, locC);
//	printBoard(board);
	//	cout << bHel << " " << bAtk << " " << bSpc << " "<< bDef << endl;
	//	cout << "(" << locR <<","<<locC<<")";
    cout << "Your starting location is (" << locR<<","<<locC<<")"<<endl;
	while(!gameDone)
	{
		cout << "Enter your choice (WASD) ";
		cin >> choice;
		switch (choice)
		{
			case 'W':
			case 'w': if(moveU(locR, locC, board, gameDone))
					  {
							cout << "You moved North one space." << endl;
					  }
					  else
						  cout << "You try moving north. There is an obstacle in your way."<<endl;
					  break;
			case 'S':
			case 's': if(moveD(locR, locC, board, gameDone))
			          {
				      	  cout << "You try moving south. You moved South one space." << endl;
			          }
					  else
						  cout << "There is an obstacle in your way."<<endl;
			          break;
			case 'A':
			case 'a':if(moveL(locR, locC, board, gameDone))
					 {
					 	 cout << "You moved west one space." << endl;
					 }
			  	     else
			  	    	 cout << "You try moving west. There is an obstacle in your way."<<endl;
					 break;
			case 'D':
			case 'd':if(moveR(locR, locC, board,  gameDone))
			         {
						cout << "You moved east one space." << endl;
			         }
			         else
			        	 cout << "You try moving east. There is an obstacle in your way."<<endl;
			         break;
			case 'B':
			case 'b':printBoard(board);
					 cout << "You printed the board you dirty cheater!"<< endl;
					 break;
			default: cout<<"Not an option dodo. Try again"<<endl; break;
		}

//		printBoard(board);

	}
	cout << endl<<endl;
	cout << "Winner!"<<endl;

	return 0;
}

void loadBoard(ifstream& fin, Board board[][20], int& locR, int& locC )
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
				board[r][c/2].space = temp.at(c);
			}
			else
			{
				if(temp.at(c)=='*'||temp.at(c)=='.')
					board[r][c/2].space = temp.at(c);
				else
				{
					board[r][c/2].stat=temp.at(c);
					board[r][c/2].space='.';
				}
			}

		}

	}

}

void printBoard(Board board [][20])
{
	for(int r=0; r<20; r++)
	{
		for(int c=0; c<20; c++)
		{
			cout<<board[r][c].space << " ";
		}

		cout<<endl;
	}
}

void setEnd(bool& end, bool e)
{
	end = e;
}
void chooseCharacter()
{

}
void showCharacter()
{

}
void incHealth()
{

}
void incAttack()
{

}
void incDefense()
{

}
void incSpecial()
{

}
void incWeapon()
{

}
bool moveU(int& locR, int locC, char board[][20], bool& end)
{
	if((locR-1)>-1 && checkNewLoc(board[locR-1][locC], end))
	{
		board[locR][locC]='.';
		locR--;
		board[locR][locC]='P';
		return true;
	}
	return false;
}
bool moveD(int& locR, int locC, char board[][20], bool& end)
{
	if((locR+1)<20 && checkNewLoc(board[locR+1][locC], end))
	{
		board[locR][locC]='.';
		locR++;
		board[locR][locC]='P';
		return true;
	}
	return false;
}
bool moveL(int locR, int& locC, char board[][20], bool& end)
{
	if((locC-1)>0 && checkNewLoc(board[locR][locC-1], end))
	{
		board[locR][locC]='.';
		locC--;
		board[locR][locC]='P';
		return true;
	}
	return false;
}
bool moveR(int locR, int& locC, char board[][20], bool& end)
{
	if((locC+1)<20 && checkNewLoc(board[locR][locC+1], end))
	{
		board[locR][locC]='.';
		locC++;
		board[locR][locC]='P';
		return true;
	}
	return false;
}
bool checkNewLoc(char space, bool &end)
{
	switch(space)
	{
	    case 'E': setEnd(end, true); return true; break;
	    case '*': return false; break;
	    default: return true; break;
	}
	return true;
}

*/
