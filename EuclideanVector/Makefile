CC=g++-4.9
CFLAGS=-std=c++14 -Wall -Werror -O2 -fsanitize=address

all: EuclideanVectorTester

EuclideanVectorTester: EuclideanVectorTester.o EuclideanVector.o
	$(CC) $(CFLAGS) EuclideanVectorTester.o EuclideanVector.o -o EuclideanVectorTester

EuclideanVectorTester.o: EuclideanVectorTester.cpp EuclideanVector.h
	$(CC) $(CFLAGS) -c EuclideanVectorTester.cpp

EuclideanVector.o: EuclideanVector.cpp EuclideanVector.h
	$(CC) $(CFLAGS) -c EuclideanVector.cpp

clean:
	rm -f *.o

vclean:
	rm -f *.o EuclideanVectorTester
