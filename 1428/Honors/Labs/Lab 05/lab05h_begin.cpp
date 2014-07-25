#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int memory[256];

	string progName;
	cout << "Enter the program name:";
	cin >> progName;

	ifstream program;
	program.open(progName.c_str());
	if(! program)
	{
		cout << "Error opening program" << endl;
		return 1;
	}

	while(! program.eof())
	{
		int instruction, data0, data1, data2;

		program >> instruction >> data0 >> data1 >> data2;
		switch(instruction)
		{
			case 0:	// add
				memory[data0] = memory[data1] + memory[data2];
				break;

			case 1:	// subtract
				memory[data0] = memory[data1] - memory[data2];
				break;

			case 2:	// multiply
				memory[data0] = memory[data1] * memory[data2];
				break;

			case 3:	// divide
				memory[data0] = memory[data1] / memory[data2];
				break;

			case 4:	// exponent
				memory[data0] = 1;
				for(int i=0; i<memory[data2]; i++)
					memory[data0] *= memory[data1];
				break;

			case 5:	// read
				cout << "Enter a number:";
				cin >> memory[data0];
				break;

			case 6:	// write
				cout << "Number:" << memory[data0];
				break;

			case 7:	// store
				memory[data0]=data1;
				break;
		}
	}

	program.close();
}

