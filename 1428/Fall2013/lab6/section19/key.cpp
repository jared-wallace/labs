#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
   char choice = 'y';

   while (choice == 'y')
   {
      int quantity = 0,
          grade = 0;

      float sum = 0.0,
            avg = 0.0;

      cout << "Enter a set of grades" << endl;
      cin >> grade;
      while (grade > -1 && grade < 101)
      {
         sum += grade;
         ++quantity;
         cin >> grade;
      }

      cout << "The average of " << quantity << " grades is ";
      avg = sum / quantity;
      cout << avg << "." << endl;
      cout << endl << "Do you wish to continue? (y/n) ";
      cin >> choice;

   }

   return (EXIT_SUCCESS);
}
