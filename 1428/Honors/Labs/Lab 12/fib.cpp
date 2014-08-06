#include <iostream>
#include <cstdlib>

using namespace std;

int fib(int x);

int main(int argc, char *argv[])
{
   for(int x = 0; x<atoi(argv[1])+1; x++)
      cout << "fib " << x << " : " << fib(x) << endl;
}

int fib(int x)
{
   if(x==0)
      return 0;
   if(x == 1)
      return 1;
   return fib(x-1) + fib(x-2);
}
