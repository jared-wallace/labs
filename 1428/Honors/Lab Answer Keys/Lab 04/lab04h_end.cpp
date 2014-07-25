#include <iostream>
using namespace std;

int main()
{
	//Declare our constants
	const int OP_ADD = 0;
	const int OP_SUB = 1;
	const int OP_MUL = 2;
	const int OP_DIV = 3;
	const int OP_EXP = 4;
	const int OP_RED = 5;
	const int OP_WRT = 6;
	const int OP_STR = 7;

	// Declare our variables
	int memory[256];
	int numInstructions=0;
	int instruction[512]={0};
	int data0[512]={0};
	int data1[512]={0};
	int data2[512]={0};

	cout << "Enter the number of instructions for your program:: ";
	cin >> numInstructions;
	for(int x=0; x<numInstructions; x++)
	{
		cin >> instruction[x] >> data0[x] >> data1[x] >> data2[x];
	}


	// Process each instruction in the arrays
	for(int i=0; i<numInstructions; i++)
	{
		switch(instruction)
		{
			case OP_ADD:
				memory[data0[i]] = memory[data1[i]] + memory[data2[i]];
				break;
			case OP_SUB:
				memory[data0[i]] = memory[data1[i]] - memory[data2[i]];
				break;
			case OP_MUL:
				memory[data0[i]] = memory[data1[i]] * memory[data2[i]];
				break;
			case OP_DIV:
				memory[data0[i]] = memory[data1[i]] / memory[data2[i]];
				break;
			case OP_EXP:
				data0 = pow(data1,data2);
				break;
			case OP_RED:
				cout << "Enter a number:";
				cin >> memory[data0[i]];
				break;
			case OP_WRT:
				cout << memory[data0[i]] << endl;
				break;
			case OP_STR:
				memory[data0[i]]=data1[i];
				break;
			default:
				cout <<"Error in instruction. Exiting program.";
				return -1;


	    }
	}


	return 0;
}

