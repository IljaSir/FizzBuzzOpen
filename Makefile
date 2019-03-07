all: fizzbuzz

fizzbuzz: main.cpp
	g++ -o fizzbuzz main.cpp

clean:
	rm -f fizzbuzz
