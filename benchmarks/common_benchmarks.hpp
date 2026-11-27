#pragma once

#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

// Semilla fija
inline vector<string> random_words(int n, int len, unsigned seed = 42) {
    mt19937 rng(seed);
    uniform_int_distribution<int> letter('a', 'z');
    vector<string> words(n, string(len, 'a'));
    for (auto& w : words)
        for (auto& ch : w)
            ch = letter(rng);
    return words;
}

template<class F>
double measure_ms(F f) {
    auto start = chrono::steady_clock::now();
    f();
    auto end = chrono::steady_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}

template<class T>
void common_benchmarks() {
    cout << "n\tms\n";
    for (int n : {1000, 10000, 100000}) {
        vector<string> words = random_words(n, 10);
        double ms = measure_ms([&] {
            T trie;
            // TODO: insertar, contains y keysWithPrefix.
        });
        cout << n << '\t' << ms << '\n';
    }
}
