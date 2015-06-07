all: example.cpp finally.hpp
	g++ -o example example.cpp -std=c++11
clean:
	rm -f example
