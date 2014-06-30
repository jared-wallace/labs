#include <iostream>
using namespace std;

int main()
{
   char myChar = 'N';
   myChar += 32;
   cout << myChar << endl;
   myChar = 100;
   cout << myChar << endl;

   char myStr[] = "Hello";    // note the square brackets
   int index = 0;
   const int SIZE = 6;  //why?
   char reverse[6];

   while (myStr[index] != '\0')
   {
      reverse[SIZE-2-index] = myStr[index];
      index++;          //why?
   }
   reverse[SIZE-1] = '\0';

   index = 0;        //why?

   while(reverse[index] != '\0')
   {
      cout << reverse[index] << " ";
      index++;
   }
}
