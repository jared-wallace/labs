#include <iostream>
#include <cstdlib>

using namespace std;

int sum(int start, int stop);

int main(int argc,  char *argv[])
{
   int start = atoi(argv[1]);
   int stop = atoi(argv[2]);
   int answer = sum(start,stop);
   cout << "The sum of all the numbers from " << start << " to " << stop << " is: " << answer << endl;
}

int sum(int start, int stop)
{
   if(start > stop)
      return 0;
   start += sum(start +1, stop);
   return start;
}

