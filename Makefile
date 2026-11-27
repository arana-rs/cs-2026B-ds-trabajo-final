CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Ilib

main: src/main.cpp lib/trie.cpp lib/trie.hpp
	$(CXX) $(CXXFLAGS) src/main.cpp lib/trie.cpp -o main

run: main
	./main

clean:
	rm -f main
