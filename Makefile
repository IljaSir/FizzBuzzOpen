all: fizzbuzz testfizzbuzz

fizzbuzz: main.cpp
	g++ -std=c++11 -o fizzbuzz main.cpp FizzBuzz.h
	
testfizzbuzz: Test.cpp
	g++ -std=c++11 -I$(BOOST_ROOT) Test.cpp FizzBuzz.h -o testfizzbuzz
