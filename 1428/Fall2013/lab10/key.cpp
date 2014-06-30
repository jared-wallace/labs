#include <iostream>

using namespace std;

float calculateOT(float);
float calculateBase(float);

const float PAY_RATE = 20.55;
const float BASE_HOURS = 30.0;
const float OT_MULTIPLIER = 1.5;

int main()
{

   float hours = 0;
   float OT = 0.0, nonOT = 0;

   cout << "Please enter the amount of hours worked: ";
   cin >> hours;
   while(hours < 0)
   {
      cout << endl;
      cout << "Please re-enter the amount of hours." << endl;
      cout << "Negative numbers are unacceptable." << endl;
      cout << "Enter the correct amount of hours: ";
      cin >> hours;
   }

   nonOT = calculateBase(hours);
   OT = calculateOT(hours);

   cout << "Your base pay for this period is: " << nonOT << endl;
   cout << "Your overtime pay for this period is: " << OT;
   cout << "Your total pay for this period is: " << (OT+nonOT);

   return 0;

}

float calculateBase(float hours)
{
   if (hours > BASE_HOURS)
      return BASE_HOURS*PAY_RATE;
   return hours*PAY_RATE;
}

float calculateOT(float hours)
{
   if (hours > BASE_HOURS)
      return (hours-BASE_HOURS)*OT_MULTIPLIER*PAY_RATE;
   return 0;
}
