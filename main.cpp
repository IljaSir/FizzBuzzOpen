#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cassert>
#include<stdexcept>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) 
{
	for (auto x : v) os << x << " ";
	return os;
}

bool dev_by_3(const string& num) 
{
	int sum = 0;
	for (auto x : num) 
	{
		if (x == '-') continue;
		sum += (int)x - '0';
	}
	if (sum < 10) return (sum == 3 || sum == 6 || sum == 9 || sum == 0);
	else return dev_by_3(to_string(sum));
}

bool dev_by_5(const string& num) 
{
	int sum = 0;
	auto it = num.end() - 1;
	if (*it == '0' || *it == '5') return true;
	return false;
}

int main() 
{
	bool TestMode = true; // TestMode flag
	string in;
	vector<string> str_vec;
	ifstream input;
	ofstream output;
	if (!TestMode) input.open("Input.txt");
	else input.open("Tests.txt");
	if (input.is_open()) 
	{
		while (input >> in) 
		{
			try 
			{
				if (in.find_first_not_of("-0123456789") != string::npos)
					throw invalid_argument("String must contain only numbers!");
			}
			catch (const invalid_argument& e) 
			{
				output.open("Output.txt");
				if (output.is_open()) 
				{
					output << e.what() << endl;
					output.close();
					exit(-1);
				}
			}
			if (dev_by_3(in) && dev_by_5(in)) 
				str_vec.push_back("fizzbuzz");
			else if (dev_by_3(in))
				str_vec.push_back("fizz");
			else if (dev_by_5(in))
				str_vec.push_back("buzz");
			else
				str_vec.push_back(in);
		}
		input.close();
		if (!TestMode)
		{
			output.open("Output.txt");
			if (output.is_open())
				output << str_vec << endl;
			else
				cout << "Output file is not opened!" << endl;
			output.close();
		}
		else
		{
			input.open("Answers.txt");
			string ans;
			int i = 0;
			while (input >> ans)
			{
				assert(ans == str_vec[i]);
				i++;
			}
			cout << "TESTS OK" << endl;
			input.close();
		}
	}
	else
		cout << "Input file is not opened!" << endl;
	getchar();
	return 0;
}