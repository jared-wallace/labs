#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
const int SIZE = 100;
const char* NAME = "input.txt";

void print_grades(int array[], int counter, float average);
float calculate_average(int array[], int counter);
void curve(int array[], int counter);
bool read_grades(int array[], int& counter);

int main()
{
   int array[SIZE] = {0};
   int counter = 0;
   if (!read_grades(array, counter))
      return 1;
   curve(array, counter);
   float average = calculate_average(array, counter);
   print_grades(array, counter, average);


}

bool read_grades(int array[], int& counter)
{
   ifstream fin;
   fin.open(NAME);
   if (!fin)
   {
      cerr << "Error reading in file";
      return false;
   }

   int grade = 0;
   fin >> grade;
   while (grade >= 0 && grade <= 100)
   {
      array[counter] = grade;
      counter++;
      fin >> grade;
   }
   return true;
}

void curve(int array[], int counter)
{
   int min = array[0];
   for (int i = 1; i < counter; i++)
   {
      if (array[i] < min)
         min = array[i];
   }
   int curveAmount = 70-min;

   for (int i = 0; i < counter; i++)
   {
      array[i] += curveAmount;
      if (array[i] > 100)
         array[i] = 100;
   }
}

float calculate_average(int array[], int counter)
{
   int sum;

   for (int i = 0; i < counter; i++)
   {
      sum += array[i];
   }

   return (sum/counter);

}

void print_grades(int array[], int counter, float average)
{
   int rows = counter / 3;
   int extra = counter % 3;
   int j = 0;

   for (int i = 0; i < rows; i++)
   {
      cout << array[j] << " " << array[j+1] << " " << array[j+2];
      cout << endl;
      j += 3;
   }
   switch (extra)
   {
      case 0:
         break;
      case 1:
         cout << array[counter-1];
         break;
      case 2:
         cout << array[counter-2] << array[counter-1];
         break;
      default:
         cerr << "You screwed up somewhere genius";
   }

   cout << "And the average was: " << average;
}


