#include <iostream>

using namespace std;

int main()
{
   char original[] = "I am a C-string";
   const int SIZE = 16;
   int index = 0;
   while(original[index] != '\0')
   {
      cout << original[index];
      index++;
   }

   /*
    *first section
    */
   index = 0;
   char reverse[SIZE];
   while(original[index] != '\0')
   {
      reverse[14-index] = original[index];
      index++;
   }
   reverse[SIZE-1] = '\0';

   index = 0;
   cout << endl;
   cout << "The original string in reverse is: ";

   while (reverse[index] != '\0')
   {
      cout << reverse[index];
      index++;
   }

   cout << endl;

   /*
    *second section
    */
   int ascii[SIZE-1];
   index = 0;
   while(original[index] != '\0')
   {
      ascii[index] = original[index];
      index++;
   }
   index = 0;
   cout << "The ascii values of each character in the original array are: ";
   while (ascii[index] != '\0')
   {
      cout << ascii[index];
      cout << " ";
      index++;
   }
   cout << endl;

   /*
    *third section
    */
   char upper[SIZE];
   index = 0;
   while(original[index] != '\0')
   {
      if (original[index] >= 97 && original[index] <= 122)
         upper[index] = original[index] - 32;
      else
         upper[index] = original[index];
      index++;
   }
   upper[SIZE-1] = '\0';

   cout << "The original string converted to uppercase is: ";
   index = 0;

   while(upper[index] != '\0')
   {
      cout << upper[index] << " ";
      index++;
   }
}
