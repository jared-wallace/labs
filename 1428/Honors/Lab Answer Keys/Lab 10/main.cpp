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

struct Player
{
	string name;
	int health;
	int attack;
	int defense;
	int special;
	int weapon;
};
struct Board
{
	char space;
	char stat;
};


void loadBoard(ifstream& fin, Board board[][20], int& locR, int& locC );
void printBoard(Board board [][20]);
void setEnd(bool& end, bool e);
void chooseCharacter(Player& x);
void showCharacter(Player& x);
void incHealth(Player& x);
void incAttack(Player& x);
void incDefense(Player& x);
void incSpecial(Player& x);
void incWeapon(Player& x);
bool moveU(int& locR, int locC, Board board[][20], bool& end, Player& x);
bool moveD(int& locR, int locC, Board board[][20], bool& end, Player& x);
bool moveL(int locR, int& locC, Board board[][20], bool& end, Player& x);
bool moveR(int locR, int& locC, Board board[][20], bool& end, Player& x);
bool checkNewLoc(Board space,  bool &end, Player& x);



int main()
{
	Player hero;
	Board board[20][20];
	ifstream fin;
	fin.open("boardL1.txt");
	int locR = 0;
	int locC = 0;
	bool gameDone = false;
    char choice = ' ';
    loadBoard(fin, board, locR, locC);
    chooseCharacter(hero);
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
			case 'w': if(moveU(locR, locC, board, gameDone, hero))
					  {
							cout << "You moved North one space." << endl;
					  }
					  else
						  cout << "You try moving north. There is an obstacle in your way."<<endl;
					  break;
			case 'S':
			case 's': if(moveD(locR, locC, board, gameDone, hero))
			          {
				      	  cout << "You try moving south. You moved South one space." << endl;
			          }
					  else
						  cout << "There is an obstacle in your way."<<endl;
			          break;
			case 'A':
			case 'a':if(moveL(locR, locC, board, gameDone, hero))
					 {
					 	 cout << "You moved west one space." << endl;
					 }
			  	     else
			  	    	 cout << "You try moving west. There is an obstacle in your way."<<endl;
					 break;
			case 'D':
			case 'd':if(moveR(locR, locC, board,  gameDone, hero))
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
			case 'q':
			case 'Q': showCharacter(hero);  break;
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

void chooseCharacter(Player& x)
{
	cout << "Enter your name.\n";
	cin >> x.name;
	cout << "It is time to choose the classification of your avatar \n";
	cout << "Enter W for Warrior, M for Magician, V for Valkyrie, or D for dwarf. \n";
	char choice;
	cin >> choice;
	switch(choice)
	{
		case 'w':
		case 'W':
		{
			x.name = x.name + "-Warrior";
			x.attack = 25;
			x.defense = 15;
			x.special = 5;
			x.health = 25;
			x.weapon = 2;
		}break;
		case 'm':
		case 'M':
		{
			x.name = x.name + "-Magician";
			x.attack = 5;
			x.defense = 10;
			x.special = 25;
			x.health = 30;
			x.weapon = 0;
		}break;
		case 'v':
		case 'V':
		{
			x.name = x.name + "-Valkyrie";
			x.attack = 20;
			x.defense = 25;
			x.special = 10;
			x.health = 20;
			x.weapon = 1;
		}break;
		case 'd':
		case 'D':
		{
			x.name = x.name + "-Dwarf";
			x.attack = 18;
			x.defense =22;
			x.special = 3;
			x.health = 23;
			x.weapon = 4;
		}break;
		default:
		cout <<"Incorrect option! You are set to mortal. Good luck\n";
		x.name = x.name + "-Mortal";
		x.attack = 5;
		x.defense = 3;
		x.special = 0;
		x.health = 15;
		x.weapon = 0;	break;

	}
}
void showCharacter(Player& x)
{
	cout << "Name - " << x.name << endl;
	cout << "Health - " << x.health << endl;
	cout << "Attack - " << x.attack << endl;
	cout << "Special - " << x.special << endl;
	cout << "Defense - " << x.defense << endl;
	cout << "Weapon - " << x.weapon << endl;
}
void incHealth(Player& x)
{
	x.health+=5;
	cout << "Your health has increased + 5"<<endl;
}
void incAttack(Player& x)
{
	x.attack++;
	cout << "Your attack has increased + 1"<<endl;
}
void incDefense(Player& x)
{
	x.defense++;
	cout << "Your defense has increased + 1"<<endl;
}
void incSpecial(Player& x)
{
	x.special++;
	cout << "Your special has increased + 1"<<endl;
}
void incWeapon(Player& x)
{
	x.weapon++;
	cout << "Your weapon has increased + 1"<<endl;
}

bool moveU(int& locR, int locC, Board board[][20], bool& end, Player& x)
{
	if((locR-1)>-1 && checkNewLoc(board[locR-1][locC], end, x))
	{
		board[locR][locC].space='.';
		locR--;
		board[locR][locC].space='P';
		return true;
	}
	return false;
}
bool moveD(int& locR, int locC, Board board[][20], bool& end, Player& x)
{
	if((locR+1)<20 && checkNewLoc(board[locR+1][locC], end, x))
	{
		board[locR][locC].space='.';
		locR++;
		board[locR][locC].space='P';
		return true;
	}
	return false;
}
bool moveL(int locR, int& locC, Board board[][20], bool& end, Player& x)
{
	if((locC-1)>0 && checkNewLoc(board[locR][locC-1], end, x))
	{
		board[locR][locC].space='.';
		locC--;
		board[locR][locC].space='P';
		return true;
	}
	return false;
}
bool moveR(int locR, int& locC, Board board[][20], bool& end, Player& x)
{
	if((locC+1)<20 && checkNewLoc(board[locR][locC+1], end, x))
	{
		board[locR][locC].space='.';
		locC++;
		board[locR][locC].space='P';
		return true;
	}
	return false;
}
bool checkNewLoc(Board space, bool &end, Player& x)
{
	switch(space.stat)
	{
	    case 'E': setEnd(end, true); return true; break;
	    case '*': return false; break;
	    case 'A': incAttack(x); break;
	    case 'D': incDefense(x); break;
	    case 'S': incSpecial(x); break;
	    case 'W': incWeapon(x); break;
	    case 'H': incHealth(x); break;
	    case 'B':
	    default: return true; break;
	}
	return true;
}

