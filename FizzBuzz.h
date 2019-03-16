#pragma once
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

static bool isDev_by_3(const string& num)
{
	int sum = 0;
	for (auto x : num)
	{
		if (x == '-') continue;
		sum += (int)x - '0';
	}
	if (sum < 10) return (sum == 3 || sum == 6 || sum == 9 || sum == 0);
	else return isDev_by_3(to_string(sum));
}

static bool isDev_by_5(const string& num)
{
	int sum = 0;
	auto it = num.end() - 1;
	if (*it == '0' || *it == '5') return true;
	return false;
}

static void FizzBuzz(ifstream& fs, vector<string>& str_vec) {
	string in;
	if (fs.is_open())
	{
		while (fs >> in)
		{
			try
			{
				if (in.find_first_not_of("-0123456789") != string::npos)
					throw invalid_argument("String must contain only numbers!");
			}
			catch (const invalid_argument& e)
			{
				cout << e.what() << endl;
				exit(-1);
			}
			if (isDev_by_3(in) && isDev_by_5(in))
				str_vec.push_back("fizzbuzz");
			else if (isDev_by_3(in))
				str_vec.push_back("fizz");
			else if (isDev_by_5(in))
				str_vec.push_back("buzz");
			else
				str_vec.push_back(in);
		}
	}
	else
		cout << "Input file is not opened!" << endl;
}

/*
static void areTestsCorrect() {
	ifstream input;
	input.open("Tests.txt");
	vector<string> test_str_vec;
	FizzBuzz(input, test_str_vec);
	input.close();
	input.open("Answers.txt");
	string ans;
	int i = 0;
	while (input >> ans)
	{
		assert(ans == test_str_vec[i]);
		i++;
	}
	input.close();
	cout << "TESTS OK" << endl;
}
*/
