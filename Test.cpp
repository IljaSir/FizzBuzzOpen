#pragma once
#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "FizzBuzz.h"

BOOST_AUTO_TEST_SUITE(TestFizzBuzz)

BOOST_AUTO_TEST_CASE(Equal) {
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
		BOOST_CHECK(ans == test_str_vec[i]);
		i++;
	}
	input.close();
}

BOOST_AUTO_TEST_SUITE_END()
