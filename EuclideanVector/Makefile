CC=g++-4.9
CFLAGS=-std=c++14 -Wall -Werror -O2 -fsanitize=address

all: EuclideanVectorTester

EuclideanVectorTester: Test.o EuclideanVector.o
	$(CC) $(CFLAGS) Test$(test).o EuclideanVector.o -o EuclideanVectorTester

Test.o: Test$(test).cpp EuclideanVector.h
	$(CC) $(CFLAGS) -c Test$(test).cpp

EuclideanVector.o: EuclideanVector.cpp EuclideanVector.h
	$(CC) $(CFLAGS) -c EuclideanVector.cpp

clean:
	rm -f *.o

vclean:
	rm -f *.o EuclideanVectorTester
