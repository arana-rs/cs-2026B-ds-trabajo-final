CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g -O0 -Ilib
BENCHFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2 -Ilib

.PHONY: all run test bench clean
all: main test_trie bench_trie

main: lib/trie.cpp lib/trie.hpp src/main.cpp
	$(CXX) $(CXXFLAGS) lib/trie.cpp src/main.cpp -o $@

test_trie: lib/trie.cpp lib/trie.hpp tests/test_trie.cpp tests/common_tests.hpp
	$(CXX) $(CXXFLAGS) lib/trie.cpp tests/test_trie.cpp -o $@

bench_trie: lib/trie.cpp lib/trie.hpp benchmarks/bench_trie.cpp benchmarks/common_benchmarks.hpp
	$(CXX) $(BENCHFLAGS) lib/trie.cpp benchmarks/bench_trie.cpp -o $@

run: main
	./main

test: test_trie
	./test_trie

bench: bench_trie
	./bench_trie

clean:
	rm -f main test_trie bench_trie
