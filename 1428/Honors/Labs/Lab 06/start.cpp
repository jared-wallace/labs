

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	//NUMBER OF ROWS AND COLUMNS
	const int ROWS = 7;
	const int COLS = 10;
	char life[ROWS][COLS];
	
	//RANDOM NUMBER GENERATOR TO CREATE INITIAL GENERATION
	srand (time(NULL));
	int cell;
	
	for(int r=0; r<ROWS; r++)
	{
		for(int c =0; c<COLS;c++)
		{
			cell = rand() % 7;
			if(cell >= 5)
			{
				life[r][c] = '*';
			}
			else
			{
				life[r][c]=' ';
			}
		}
	}


	return 0;

}