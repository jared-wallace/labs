/*
 *This is the starter code for the happy prime application. Make sure
 *you add the correct header before submitting
 */
#include <iostream>

using namespace std;


bool IsPrime(int number);
bool IsHappy(int number, int cycle[]);
bool CycleContains(int cycle[], int number);
void SelectionSort(int cycle[], int size);
bool AddToCycle(int number, int cycle[], int& cursor_position);

const int SIZE = 20;

int main()
{
    int number;
    cout << "Enter a number to see if it's a Happy Prime!\n";
    cin >> number;
    int cycle[SIZE];
    int result = 0;
    if ( IsPrime(number) )
        result += 1;
    if ( IsHappy(number, cycle) )
        result += 4;
    switch (result)
    {
        case 0:
            cout << "The number is Sad and not Prime...\n";
            break;
        case 1:
            cout << "The number is a Sad Prime...\n";
            break;
        case 4:
            cout << "The number is Happy but not Prime...\n";
            break;
        case 5:
            cout << "The number is a Happy Prime!\n";
            break;
        default:
            cerr << "You screwed something up";
    }
}

bool IsPrime(int number)
{
    for(int x = 2; x < number / 2; x++)
        if(number % x == 0)
            return false;
    return true;
}

bool IsHappy(int number, int cycle[])
{
    int cursor_position = 0;
    int sum = 0;
    int digit = 0;
    while( number != 1 && AddToCycle(number, cycle, cursor_position) )
    {
        sum = 0;
        while (number > 0)
        {
            digit = (number % 10);
            sum += digit * digit;
            number /= 10;
        }
        number = sum;
    }
    if (number == 1)
        return true;
    return false;
}

bool AddToCycle(int number, int cycle[], int& cursor_position)
{
    if( CycleContains(cycle, number) )
        return false;
    cycle[cursor_position++] = number;
    SelectionSort(cycle, cursor_position);
    return true;
}

bool CycleContains(int cycle[], int number)
{
    for(int x = 0; x < SIZE; x++)
        if(cycle[x] == number)
            return true;
    return false;
}

void SelectionSort(int cycle[], int size)
{
    int swp;
    for(int x = 0; x < size; x++)
    {
        for(int y = x + 1; y < size; y++)
        {
            swp = cycle[x];
            cycle[x] = cycle[y];
            cycle[y] = swp;
        }
    }
}
