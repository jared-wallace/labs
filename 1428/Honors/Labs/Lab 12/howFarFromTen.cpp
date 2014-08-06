#include <iostream>

using namespace std;

int howFarFromTen(int x, int count);
int main()
{
   int num;
   int count = 0;
   cout << "Enter a num to see how far it is from ten: ";
   cin >> num;
   cout << howFarFromTen(num, count) << endl;
}

int howFarFromTen(int x, int count)
{
   if(x==10)
      return count;
   howFarFromTen(x+1,count+1);
}


