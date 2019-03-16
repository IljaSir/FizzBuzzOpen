#pragma once
#include "FizzBuzz.h"


int main() 
{
	string in;
	vector<string> str_vec;
	ifstream input;
	ofstream output;
	input.open("Input.txt");
	FizzBuzz(input, str_vec);
	input.close();
	output.open("Output.txt");
	if (output.is_open())
		output << str_vec << endl;
	else
		cout << "Output file is not opened!" << endl;
	output.close();
	getchar();
	return 0;
}


