#include <iostream>
using namespace std;

int main()
{
	// Declare our variables
	int memory[256];
	int numInstructions=0;
	int instruction[512][4]={0};

	// Process each instruction in the arrays
	for(int i=0; i<numInstructions; i++)
	{
		switch(instruction[i][0])
		{
			case 0:
				memory[instruction[i][1]] = memory[instruction[i][2]] + memory[instruction[i][3]];
				break;
			case 1:
				memory[instruction[i][1]] = memory[instruction[i][2]] - memory[instruction[i][3]];
				break;
			case 2:
				memory[instruction[i][1]] = memory[instruction[i][2]] * memory[instruction[i][3]];
				break;
			case 3:
				memory[instruction[i][1]] = memory[instruction[i][2]] / memory[instruction[i][3]];
				break;
			case 4:
				memory[instruction[i][1]]=1;
				for(int i=0; i<memory[instruction[i][3]]; i++)
					memory[instruction[i][1]] *= memory[instruction[i][2]];
				break;
			case 5:
				cout << "Enter a number:";
				cin >> memory[instruction[i][1]];
				break;
			case 6:
				cout << memory[instruction[i][1]] << endl;
				break;
			case 7:
				memory[instruction[i][1]]=instruction[i][2];
				break;
			case 8:
				i+=memory[instruction[i][1]] - 1;
				break;
			case 9:
				if(memory[instruction[i][2]]==memory[instruction[i][3]])
					i+=memory[instruction[i][1]] - 1;
				break;
			case 10:
				memory[instruction[i][1]]=rand() % (instruction[i][3] - instruction[i][2]) + instruction[i][2];
				break;
		}
	}
	return 0;
}

