CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g -O0 -Ilib
BENCHFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2 -Ilib

.PHONY: all test bench cf asan clean
all: test_trie test_trie_ptr bench_trie bench_trie_ptr

test_trie: lib/trie.cpp lib/trie.hpp tests/test_trie.cpp tests/common_tests.hpp
	$(CXX) $(CXXFLAGS) lib/trie.cpp tests/test_trie.cpp -o $@

test_trie_ptr: lib/trie.cpp lib/trie.hpp lib/trie_ptr.cpp lib/trie_ptr.hpp tests/test_trie_ptr.cpp tests/common_tests.hpp
	$(CXX) $(CXXFLAGS) lib/trie_ptr.cpp tests/test_trie_ptr.cpp -o $@

bench_trie: lib/trie.cpp lib/trie.hpp benchmarks/bench_trie.cpp benchmarks/common_benchmarks.hpp
	$(CXX) $(BENCHFLAGS) lib/trie.cpp benchmarks/bench_trie.cpp -o $@

cf_1703d: lib/trie.cpp lib/trie.hpp 1703d/doubleStrings.cpp
	$(CXX) $(BENCHFLAGS) lib/trie.cpp 1703d/doubleStrings.cpp -o $@

bench_trie_ptr: lib/trie.hpp lib/trie_ptr.cpp lib/trie_ptr.hpp benchmarks/bench_trie_ptr.cpp benchmarks/common_benchmarks.hpp
	$(CXX) $(BENCHFLAGS) lib/trie_ptr.cpp benchmarks/bench_trie_ptr.cpp -o $@

test: test_trie test_trie_ptr
	./test_trie
	./test_trie_ptr

bench: bench_trie bench_trie_ptr
	./bench_trie
	./bench_trie_ptr

cf: cf_1703d
	./cf_1703d < 1703d/input

# Pruebas con AddressSanitizer/LeakSanitizer: fallan si hay fugas o accesos invalidos
asan:
	$(CXX) $(CXXFLAGS) -fsanitize=address,undefined lib/trie.cpp tests/test_trie.cpp -o asan_trie
	$(CXX) $(CXXFLAGS) -fsanitize=address,undefined lib/trie_ptr.cpp tests/test_trie_ptr.cpp -o asan_trie_ptr
	./asan_trie
	./asan_trie_ptr

clean:
	rm -f test_trie bench_trie cf_1703d test_trie_ptr bench_trie_ptr asan_trie asan_trie_ptr
