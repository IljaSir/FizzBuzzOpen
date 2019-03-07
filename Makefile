
out: main.o
	g++ main.o -o out

main.o:
	g++ -c main.cpp

clean:
	rm *.o out