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
struct Monster
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


void loadBoard(ifstream& fin, Board board[][20][20], int& locR, int& locC );
void printBoard(Board board [][20][20], int floor);
void setEnd(bool& end, bool e);
void chooseCharacter(Player& x);
void showCharacter(Player& x);
void incHealth(Player& x);
void incAttack(Player& x);
void incDefense(Player& x);
void incSpecial(Player& x);
void incWeapon(Player& x);
void incFloor(int& floor);
bool monsterFight(Player& x);
bool moveU(int& locR, int locC, Board board[][20][20], bool& end, Player& x, int& floor);
bool moveD(int& locR, int locC, Board board[][20][20], bool& end, Player& x, int& floor);
bool moveL(int locR, int& locC, Board board[][20][20], bool& end, Player& x, int& floor);
bool moveR(int locR, int& locC, Board board[][20][20], bool& end, Player& x, int& floor);
bool checkNewLoc(Board space,  bool &end, Player& x, int& floor);


int main()
{

	Player hero;
	Board board[2][20][20];
	ifstream fin;
	fin.open("boardL1.txt");
	int locR = 0;
	int locC = 0;
	bool gameDone = false;
    char choice = ' ';
    int floor =0;
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
			case 'w': if(moveU(locR, locC, board, gameDone, hero, floor))
					  {
							cout << "You moved North one space." << endl;
					  }
					  else
						  cout << "You try moving north. There is an obstacle in your way."<<endl;
					  break;
			case 'S':
			case 's': if(moveD(locR, locC, board, gameDone, hero,floor))
			          {
				      	  cout << "You try moving south. You moved South one space." << endl;
			          }
					  else
						  cout << "There is an obstacle in your way."<<endl;
			          break;
			case 'A':
			case 'a':if(moveL(locR, locC, board, gameDone, hero, floor))
					 {
					 	 cout << "You moved west one space." << endl;
					 }
			  	     else
			  	    	 cout << "You try moving west. There is an obstacle in your way."<<endl;
					 break;
			case 'D':
			case 'd':if(moveR(locR, locC, board,  gameDone, hero, floor))
			         {
						cout << "You moved east one space." << endl;
			         }
			         else
			        	 cout << "You try moving east. There is an obstacle in your way."<<endl;
			         break;
			case 'B':
			case 'b':printBoard(board, floor);
					 cout << "You printed the board you dirty cheater!"<< endl;
					 break;
			case 'q':
			case 'Q': showCharacter(hero);  break;
			case 'F':printBoard(board, 1); break;
			case 'e': cout << "Floor Level " << floor << endl;break;
			default: cout<<"Not an option dodo. Try again"<<endl; break;
		}

//		printBoard(board);

	}
	cout << endl<<endl;
	cout << "Winner!"<<endl;

	return 0;
}

void loadBoard(ifstream& fin, Board board[][20][20], int& locR, int& locC )
{
	string temp;
	for(int z = 0; z<2; z++)
	{
		for(int r=0; r<20; r++)
		{
			getline(fin,temp);
			for(unsigned int c =0; c<temp.length(); c+=2)
			{
				if(temp.at(c)=='P')
				{
					locR = r;
					locC = (c/2);
					board[z][r][c/2].space = temp.at(c);
					board[z][r][c/2].stat = temp.at(c);
				}
				else
				{
					if(temp.at(c)=='*'||temp.at(c)=='.')
					{
						board[z][r][c/2].space = temp.at(c);
						board[z][r][c/2].stat = temp.at(c);
					}
					else
					{
						board[z][r][c/2].stat=temp.at(c);
						board[z][r][c/2].space='.';
					}
				}

			}

		}
	}


}

void printBoard(Board board [][20][20], int floor)
{
	for(int r=0; r<20; r++)
	{
		for(int c=0; c<20; c++)
		{
			cout<<board[floor][r][c].stat << " ";
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
void incFloor(int& floor)
{
	if(floor==1)
	{
		floor--;
		cout << "You find a staircase and go up a floor."<<endl;
	}
	else
	{
		floor++;
		cout << "You find a staircase and go down a floor."<<endl;
	}

}

bool monsterFight(Player& x)
{
	Monster b;
	b.name ="Gorgon";
	b.health = 100;
	b.attack = 10;
	b.defense = 5;
	b.special =1;
	b.weapon=1;
	cout << "You have encountered a " << b.name <<"! You must fight to survive."<<endl;
	int pStartH = x.health;

	int attacks =0;
	int damage;
	while(true)
	{
		if(attacks == 3)
		{
			damage = (x.attack * x.weapon * x.special - b.defense*b.special);
			b.health -= damage;
			cout << "You special attack the monster! You do " << damage << " damage "<<endl;
			damage = (b.attack * b.weapon - x.defense);;
			x.health -= damage;
			cout << "The monster attacks you! You lose " << damage << " health" <<endl;
			sleep(5);
		}
		else
			if(attacks == 5)
			{
				damage = (x.attack * x.weapon - b.defense);
				b.health -= damage;
				cout << "You attack the monster! You do " << damage << " damage "<<endl;
				damage = (b.attack * b.weapon *b.special - x.defense*x.special);
				x.health -= damage;
				cout << "The monster special attacks you! You lose " << damage << " health" <<endl;
				sleep(5);
			}
			else
			{
				damage = (x.attack * x.weapon - b.defense);
				b.health -= damage;
				cout << "You attack the monster! You do " << damage << " damage "<<endl;
				damage = (b.attack * b.weapon - x.defense);;
				x.health -= damage;
				cout << "The monster attacks you! You lose " << damage << " health" <<endl;
				sleep(5);
			}

		attacks++;
		if(x.health < 0)
		{
			cout << "You were slain by the monster. Game over. \n";
			return false;
		}
		if(b.health < 0)
		{
			cout << "You have slain the mighty " << b.name << ". You may continue on your quest."<<endl;
			cout << "You lost " << pStartH - x.health << " health." << endl;
			return true;
		}
	}
	return false;
}


bool moveU(int& locR, int locC, Board board[][20][20], bool& end, Player& x, int& floor)
{
	if((locR-1)>-1 && checkNewLoc(board[floor][locR-1][locC], end, x, floor))
	{
		board[floor][locR][locC].space='.';
		board[floor][locR][locC].stat='.';
		locR--;
		board[floor][locR][locC].space='P';
		board[floor][locR][locC].stat='P';
		return true;
	}
	return false;
}
bool moveD(int& locR, int locC, Board board[][20][20], bool& end, Player& x, int& floor)
{
	if((locR+1)<20 && checkNewLoc(board[floor][locR+1][locC], end, x, floor))
	{
		board[floor][locR][locC].space='.';
		board[floor][locR][locC].stat='.';
		locR++;
		board[floor][locR][locC].space='P';
		board[floor][locR][locC].stat='P';
		return true;
	}
	return false;
}
bool moveL(int locR, int& locC, Board board[][20][20], bool& end, Player& x, int& floor)
{
	if((locC-1)>0 && checkNewLoc(board[floor][locR][locC-1], end, x,  floor))
	{
		board[floor][locR][locC].space='.';
		board[floor][locR][locC].stat='.';
		locC--;
		board[floor][locR][locC].space='P';
		board[floor][locR][locC].stat='P';
		return true;
	}
	return false;
}
bool moveR(int locR, int& locC, Board board[][20][20], bool& end, Player& x, int& floor)
{
	if((locC+1)<20 && checkNewLoc(board[floor][locR][locC+1], end, x, floor))
	{
		board[floor][locR][locC].space='.';
		board[floor][locR][locC].stat='.';
		locC++;
		board[floor][locR][locC].space='P';
		board[floor][locR][locC].stat='P';
		return true;
	}
	return false;
}
bool checkNewLoc(Board space, bool &end, Player& x, int& floor)
{
	switch(space.stat)
	{
	    case 'E': setEnd(end, true);break;
	    case '*': return false; break;
	    case 'A': incAttack(x); break;
	    case 'D': incDefense(x); break;
	    case 'S': incSpecial(x); break;
	    case 'W': incWeapon(x); break;
	    case 'H': incHealth(x); break;
	    case 'X': incFloor(floor);break;
	    case 'M': if(!monsterFight(x))
	    				setEnd(end,false);break;
	    default: return true; break;
	}
	return true;
}

