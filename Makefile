CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g -O0 -Ilib
BENCHFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2 -Ilib

.PHONY: all test bench cf clean
all: test_trie bench_trie

test_trie: lib/trie.cpp lib/trie.hpp tests/test_trie.cpp tests/common_tests.hpp
	$(CXX) $(CXXFLAGS) lib/trie.cpp tests/test_trie.cpp -o $@

bench_trie: lib/trie.cpp lib/trie.hpp benchmarks/bench_trie.cpp benchmarks/common_benchmarks.hpp
	$(CXX) $(BENCHFLAGS) lib/trie.cpp benchmarks/bench_trie.cpp -o $@

cf_1703d: lib/trie.cpp lib/trie.hpp 1703d/doubleStrings.cpp
	$(CXX) $(BENCHFLAGS) lib/trie.cpp 1703d/doubleStrings.cpp -o $@

test: test_trie
	./test_trie

bench: bench_trie
	./bench_trie

cf: cf_1703d
	./cf_1703d < 1703d/input

clean:
	rm -f test_trie bench_trie cf_1703d
