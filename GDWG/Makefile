CC=g++-4.9
CFLAGS=-std=c++14 -Wall -Werror -O2

graph:
	cd tests && \
	ln -sf ../Graph.h . && \
	ln -sf ../Graph.tem . && \
	$(CC) $(CFLAGS) -o ../graph test$(test).cpp && \
	rm -f tests/Graph.h tests/Graph.tem && cd ..

clean:
	rm -f graph tests/Graph.h tests/Graph.tem
