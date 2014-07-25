#include <iostream>

using namespace std;


bool isPrime(int num);
bool isHappy(int num, int cycle[]);
bool cycleContains(int cycle[], int size, int num);
void selSort(int cycle[], int size);
bool cycleAdd(int num, int cycle[], int& curPos);


int main()
{
   int num;
   cout << "Enter a number to see if it's a Happy Prime!\n";
   cin >> num;
   int cycle[20];
   bool prime = isPrime(num);
   bool happy = isHappy(num, cycle);
   if( prime && happy)
   {
      cout << "The number is a Happy Prime!\n";
   }
   else
      if(happy && ! prime)
      {
         cout << "The number is Happy but not Prime...\n";
      }
      else
         if(!happy && prime)
         {
            cout << "The number is a Sad Prime...\n";
         }
         else
         {
            cout << "The number is Sad and not Prime...\n";
         }
}

bool isPrime(int num)
{
   for(int x = 2; x < num/2; x++)
      if(num % x == 0)
         return false;
   return true;
}

bool isHappy(int num, int cycle[])
{
   int curPos = 0;
   int sum = 0;
   int digit = 0;
   while(num !=1 && cycleAdd(num, cycle, curPos))
   {
      sum = 0;
      while(num > 0)
      {
         digit = (num % 10);
         sum += digit * digit;
         num /=10;
      }
      num = sum;
   }
   if(num == 1)
      return true;
   return false;
}

bool cycleAdd(int num, int cycle[], int& curPos)
{
   if(cycleContains(cycle, 20, num))
      return false;
   cycle[curPos++]=num;
   selSort(cycle, curPos);
   return true;
}

bool cycleContains(int cycle[], int size, int num)
{
   for(int x = 0; x <size; x++)
      if(cycle[x] == num)
         return true;
   return false;
}

void selSort(int cycle[], int size)
{
   int swp;
   for(int x = 0; x < size; x++)
   {
      for(int y = x+1; y<size; y++)
      {
         swp = cycle[x];
         cycle[x] = cycle[y];
         cycle[y] = swp;
      }
   }
}

