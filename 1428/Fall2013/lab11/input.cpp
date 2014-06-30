#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
   srand(time(NULL));
   ofstream fout;
   fout.open("input.txt");
   int grade = 0;

   for (int i = 0; i < 75; i++)
   {
      do
      {
         grade = rand()%100+1;
      }while(grade < 40);
      fout << grade << endl;
   }
   return 0;
}
