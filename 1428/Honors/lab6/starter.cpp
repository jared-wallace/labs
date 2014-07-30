// Insert your header here

#include <iostream>
#include <cstdlib>

using namespace std;
void clear_screen();

int main()
{
    // The number of rows and columns
    const int ROWS = 7;
    const int COLS = 10;
    // The board that will be displayed
    char life[ROWS][COLS];

    // We utilize the pseudo random number generator to generate
    // our initial game state
    srand ( time(NULL) );
    int cell;
    // Nested for loops since we have a two-dimensional array
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
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

    /*
     * Now you have an initialized game board. You need to accomplish two
     * main tasks: Set up your "processor", which applies the rules already
     * established (think switch statement) and write the code to display
     * each new generation. I have written a simple function to clear the
     * screen, and  I've left a sample invocation below.
     */
    clear_screen();

    return 0;
}

void clear_screen()
{
    cout << string(90, '\n');
}
