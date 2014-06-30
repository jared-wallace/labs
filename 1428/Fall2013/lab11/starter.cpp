#include <iostream>

using namespace std;




// prototype for print function
void print_grades(int array[], int counter, float average);
















void print_grades(int array[], int counter, float average)
{
   int rows = counter / 3;
   int extra = counter % 3;
   int j = 0;

   for (int i = 0; i < rows; i++)
   {
      cout << array[j] << " " << array[j+1] << " " << array[j+2];
      cout << endl;
      j += 3;
   }
   switch (extra)
   {
      case 0:
         break;
      case 1:
         cout << array[counter-1];
         break;
      case 2:
         cout << array[counter-2] << array[counter-1];
         break;
      default:
         cerr << "You screwed up somewhere genius";
   }

   cout << "And the average was: " << average;
}
