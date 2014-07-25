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
	srand (time(NULL));
	int secretNumber = rand() % max_value + min_value;

	return 0;
}



