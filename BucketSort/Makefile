CC=g++-4.9
CFLAGS=-std=c++14 -Wall -Werror -O2 -pthread -fsanitize=address -g

all: sortTester benchmark

sortTester: sortTester.o BucketSort.o
	$(CC) $(CFLAGS) -o sortTester sortTester.o BucketSort.o

sortTester.o: sortTester.cpp BucketSort.h
	$(CC) $(CFLAGS) -c sortTester.cpp

benchmark: benchmark.o BucketSort.o
	$(CC) $(CFLAGS) -o benchmark benchmark.o BucketSort.o

benchmark.o: benchmark.cpp BucketSort.h
	$(CC) $(CFLAGS) -c benchmark.cpp

BucketSort.o: BucketSort.h BucketSort.cpp
	$(CC) $(CFLAGS) -c BucketSort.cpp

clean:
	rm -f *.o sortTester benchmark core *.out
