/*
 *Don't forget your header
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    /*
     *Remember, although this program compiles, it does not meet any of the requirements
     *Remove this comment before submitting
     */
    int min_value;
    int max_value;

    /*
     *initialize random seed
     *HINT=======This does not go here. This block of code must be placed
     *in the appropriate spot in the program. Remember that we can't use
     *something if it isn't created or initialized.
     *Remove this comment before submitting
     */
    srand (time(NULL));
    int secretNumber = rand() % max_value + min_value;

    return 0;
}
