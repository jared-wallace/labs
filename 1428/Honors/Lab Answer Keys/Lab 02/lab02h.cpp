/*
 * test.cpp
 *
 *  Created on: Apr 23, 2013
 *      Author: mme1
 */

#include <iostream>
using namespace std;

int main()
{
	const int OP_ADD = 0;
	const int OP_SUB = 1;
	const int OP_MUL = 2;
	const int OP_DIV = 3;
	const int OP_MOD = 4;
	const int OP_EXP = 5;
	const int OP_RED = 6;
	const int OP_WRT = 7;

	int inst, data0, data1, data2;
	string source;

	cout << "Enter the value of the operation you wish to perform ";
	cin >> inst;
	cout << "Enter the first value ";
	cin >> data1;
	cout << "Enter the second value ";
	cin >> data2;

	if(inst == OP_ADD)
	{
		data0 = data1 + data2;
	}
	else if(inst == OP_SUB)
	{
		data0 = data1 - data2;
	}
	else if(inst == OP_MUL)
	{
		data0 = data1 * data2;
	}
	else if(inst == OP_DIV)
	{
		if(data2 == 0)
		{
			cout << "You can't divide by 0!!! Setting data0 to -2"<<endl;
			data0 = -2;
		}
		else
		{
			data0 = data1 / data2;
		}
	}
	else
	{
		cout << "Not a valid option!" << endl;
		data0 = -1;
	}
	cout << "The operation on data1 and data2 yielded " << data0 << endl;
	return 0;
}
