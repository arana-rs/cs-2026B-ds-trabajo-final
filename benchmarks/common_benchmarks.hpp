#pragma once

#include <algorithm>
#include <chrono>
#include <iostream>
#include <malloc.h>
#include <random>
#include <set>
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

// Mejor de 5 corridas para reducir el ruido
template<class F>
double measure_ms(F f) {
    double best = 1e18;
    for (int r = 0; r < 5; r++) {
        auto start = chrono::steady_clock::now();
        f();
        auto end = chrono::steady_clock::now();
        best = min(best, chrono::duration<double, milli>(end - start).count());
    }
    return best;
}

// Bytes reservados en el heap (bloques normales + bloques grandes con mmap)
inline size_t heap_bytes() {
    struct mallinfo2 m = mallinfo2();
    return m.uordblks + m.hblkhd;
}

// Alternativa: std::set<string> con la misma interfaz
struct SetDict {
    set<string> s;

    void insert(const string& key) { s.insert(key); }
    bool contains(const string& key) const { return s.count(key); }

    vector<string> keysWithPrefix(const string& pre) const {
        vector<string> res;
        for (auto it = s.lower_bound(pre); it != s.end() && it->compare(0, pre.size(), pre) == 0; ++it)
            res.push_back(*it);
        return res;
    }
};

struct BenchResult {
    double insert_ms, hit_ms, miss_ms, prefix_ms;
    double mb;
    long long found;
};

template<class T>
BenchResult run_benchmark(const vector<string>& words, const vector<string>& misses,
                          const vector<string>& prefixes) {
    BenchResult r;
    r.insert_ms = measure_ms([&] {
        T d;
        for (auto& w : words)
            d.insert(w);
    });

    size_t before = heap_bytes();
    T d;
    for (auto& w : words)
        d.insert(w);
    r.mb = (heap_bytes() - before) / 1e6;

    long long hits = 0, fake = 0, pre = 0;
    r.hit_ms = measure_ms([&] {
        hits = 0;
        for (auto& w : words)
            hits += d.contains(w);
    });
    r.miss_ms = measure_ms([&] {
        fake = 0;
        for (auto& w : misses)
            fake += d.contains(w);
    });
    r.prefix_ms = measure_ms([&] {
        pre = 0;
        for (auto& p : prefixes)
            pre += d.keysWithPrefix(p).size();
    });

    // Se usa para comprobar que ambas estructuras dan el mismo resultado
    r.found = hits * 1000000LL + fake * 1000LL + pre;
    return r;
}

template<class T>
void common_benchmarks() {
    cout << "n\toperacion\ttrie_ms\tset_ms\n";
    for (int n : {1000, 10000, 100000}) {
        vector<string> words = random_words(n, 10);
        vector<string> misses = random_words(n, 10, 7);
        vector<string> prefixes = random_words(1000, 3, 99);

        BenchResult a = run_benchmark<T>(words, misses, prefixes);
        BenchResult b = run_benchmark<SetDict>(words, misses, prefixes);

        if (a.found != b.found) {
            cerr << "ERROR: trie y set no coinciden para n = " << n << '\n';
            return;
        }

        cout << n << "\tinsert\t" << a.insert_ms << '\t' << b.insert_ms << '\n';
        cout << n << "\tcontains (hit)\t" << a.hit_ms << '\t' << b.hit_ms << '\n';
        cout << n << "\tcontains (miss)\t" << a.miss_ms << '\t' << b.miss_ms << '\n';
        cout << n << "\tkeysWithPrefix\t" << a.prefix_ms << '\t' << b.prefix_ms << '\n';
        cout << n << "\tmemoria (MB)\t" << a.mb << '\t' << b.mb << '\n';
    }
}
