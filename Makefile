EECS448_Lab07: main.o Test.o
	g++ -std=c++11 -Wall -g main.o Test.o -o EECS448_Lab07

main.o: main.cpp Node.h LinkedList.h Test.h
	g++ -std=c++11 -Wall -g -c main.cpp

Test.o: Test.cpp Test.h
	g++ -std=c++11 -Wall -g -c Test.cpp

clean:
	rm *.o EECS448_Lab07
	echo clean done
