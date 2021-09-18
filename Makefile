CFLAGS := -Wall -Werror
CXX := g++

all: start

start: main.o check.o
	$(CXX) $(CFLAGS) main.o check.o -o src/main
	./src/main

check.o:
	$(CXX) $(CFLAGS) -c src/check.cpp -o check.o

main.o:
	$(CXX) $(CFLAGS) -c src/main.cpp -o main.o

clean:
	find . -name "*.o" -exec rm '{}' \;
	find . -name "*.d" -exec rm '{}' \;
	find . -name "*.a" -exec rm '{}' \;
	
run: start clean

testing: teststart clean

teststart: test.o check.o
	$(CXX) $(CFLAGS) test.o check.o -o src/test
	./src/test
	
test.o:
	$(CXX) $(CFLAGS) -c src/test.cpp -o test.o
	
