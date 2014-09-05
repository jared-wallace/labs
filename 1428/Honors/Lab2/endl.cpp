#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream f;
    f.open("test.txt");

    if(!f)
        cerr << "Error opening file";

    int arr[20];
    for (int i = 0; i < 20; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < 20; i++)
    {
        // Writes to file
        //f << arr[i] << endl;
        // Doesn't write to file
        f << arr[i] << "\n";
    }
    int* ptr = NULL;
    cout << *ptr;

    return 0;
}
