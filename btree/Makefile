CC=g++-4.9
CFLAGS=-std=c++14 -Wall -Werror -O2 -fsanitize=address

default: test00

%: %.cpp btree.h btree_iterator.h
	$(CC) $(CFLAGS) -o btree $< && \
	touch btree -t 201612141350.12
	./btree | diff $@.txt - && \
	printf "\nTest passed\n" || printf "\nTest failed\n"

clean:
	rm -f *.o btree core
