CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Ilib

main: src/main.cpp lib/tree.cpp lib/tree.hpp
	$(CXX) $(CXXFLAGS) src/main.cpp lib/tree.cpp -o main

run: main
	./main

clean:
	rm -f main
