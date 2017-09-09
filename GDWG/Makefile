CC=g++-4.9
CFLAGS=-std=c++14 -Wall -Werror -O2

graph: tests/Graph.h tests/Graph.tem
	cd tests && \
	$(CC) $(CFLAGS) -o ../graph test$(test).cpp && \
	rm -f tests/Graph.h tests/Graph.tem && \
	cd .. && \
	./graph | diff tests/result$(test).txt - && \
	printf "\nTest passed\n"; \
	rm -f tests/Graph.h tests/Graph.tem && \
	touch graph -t 201612141350.12

tests/Graph.h:
	cd tests && \
	ln -sf ../Graph.h . && \
	cd ..

tests/Graph.tem:
	cd tests && \
	ln -sf ../Graph.tem . && \
	cd ..

clean:
	rm -f graph tests/Graph.h tests/Graph.tem
