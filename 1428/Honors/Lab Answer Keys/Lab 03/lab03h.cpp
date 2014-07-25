/*
 * lab03h.cpp
 *
 *  Created on: Sep 17, 2013
 *      Author: mme1
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	/* This program will not currently run correctly, you MUST prompt
	 * the user for the values of min_value and max_value. Be aware that the
	 * range of the number to chose will be min_value <= num < max_value.
	 */
	int min_value;
	int max_value;

	/* initialize random seed */
	//HINT=======This does not go here. This block of code must be placed
	//in the appropriate spot in the program. Remember that we can't use
	//something if it isn't created or initialized.
//	srand (time(NULL));
//	int secretNumber = rand() % max_value + min_value;


	char choice = 'n';

	do
	{
		cout << "Enter the min value you wish to use." << endl;
		cin >> min_value;
		cout << "Enter the max value you wish to use." << endl;
		cin >> max_value;

		srand (time(NULL));
		int secretNumber = rand() % max_value + min_value;

		int guess;
		int numTries = 0;
		bool answer = false;
		do
		{
			cout << "Enter your guess." << endl;
			cin >> guess;
			if (guess < min_value || guess >= max_value)
			{
				cout << "You entered a number outside of the range!" << endl
					 << "The range is " << min_value << " to " << max_value << endl;
			}
			else
			{
				if(guess == secretNumber)
				{
					cout << "Correct! It took you " << numTries << " to guess!" <<endl;
					answer = true;
				}
				else
				{
					if(guess < secretNumber)
					{
						cout << "You guessed to low! Try again!" << endl;
					}
					else
						if(guess > secretNumber)
						{
							cout << "You guessed to high! Try again!" << endl;
						}
				}
			}
			numTries++;
		}while(!answer);

		cout << "Do you want to play again? (y or n)" << endl;
		cin >> choice;

	}while(choice != 'n');

	cout << "Goodbye!";




	return 0;
}



