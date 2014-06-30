#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
   int value = 0;

   cout << "Please enter a number between 1 and 25 ";
   cin >> value;

   if (value < 1 || value > 25)
   {
      cerr << "Invalid number entered, exiting program";
      cerr << endl;
      return (EXIT_FAILURE);
   }

   for (size_t i = 0; i < value; ++i)
   {
      for (size_t j = value - i; j > 0; --j)
         cout << j;
      cout << endl;
   }

   return (EXIT_SUCCESS);
}
