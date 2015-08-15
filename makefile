all : callByName.o test
callByName.o: callByName.h callByName.cpp
	c++  -c -o callByName.o -std=c++11 callByName.cpp 
test.o: test.cpp callByName.h
	c++  -c -o test.o -std=c++11 test.cpp 
test: test.o callByName.o
	c++ -o test -std=c++11 callByName.o test.o
clean:
	rm -f test.o callByName.o test
.PHONY: all clean
