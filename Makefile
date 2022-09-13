CC = g++
CFLAGS = -Wall -g -std=c++11

shared_ptr_test:
	$(CC) $(CFLAGS) -o shared_ptr_test shared_ptr_test.cpp

clean:
	rm -f shared_ptr_test