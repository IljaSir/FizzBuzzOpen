all: fizzbuzz testfizzbuzz

fizzbuzz: main.cpp
	g++ -std=c++11 -o fizzbuzz main.cpp FizzBuzz.h
	
testfizzbuzz: test.cpp
	g++ -std=c++11 -o testfizzbuzz Test.cpp FizzBuzz.h
