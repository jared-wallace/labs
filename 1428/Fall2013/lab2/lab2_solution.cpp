#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int a,
      b,
      c;    //for this simple assignment, these names are acceptable
  double result1 = 0.0,
         result2 = 0.0;
  a = b = c = 0;  //you can chain assignments like this

  cout << "Enter the values for a,b, and c. Press <enter> after each value." << endl;
  cin >> a >> b >> c;

  //Now it's time for some math
  result1 = (((b*-1) + sqrt((b*b-(4*a*c))))/(2*a));
  result2 = (((b*-1) - sqrt((b*b-(4*a*c))))/(2*a));

  cout << "The first result is " << result1 << " and the second result is " << result2 << ".\n";

}
