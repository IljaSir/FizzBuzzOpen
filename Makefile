all: fizzbuzz

fizzbuzz: main.cpp
	g++ -std=c++11 -o fizzbuzz main.cpp FizzBuzz.h
