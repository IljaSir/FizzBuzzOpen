all: fizzbuzz testfizzbuzz

fizzbuzz: main.cpp
	g++ -std=c++11 -o fizzbuzz main.cpp FizzBuzz.h
	
testfizzbuzz: Test.cpp
	g++ -std=c++11 -I/Users/iljas/boost_1_69_0 Test.cpp FizzBuzz.h -o testfizzbuzz
