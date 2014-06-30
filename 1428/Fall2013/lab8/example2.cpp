#include <iostream>

using namespace std;

int main()
{
   const int SIZE = 5;
   int myArray[SIZE] = {0};

   for (int i = 0; i < SIZE; ++i)
   {
      cout << "Enter an integer value ";
      cin >> myArray[i];
   }

   for (int i = 0; i < SIZE; ++i)
   {
      cout << myArray[i] << " ";
   }
}
