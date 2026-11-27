#pragma once

#include <cstdlib>
#include <iostream>
using namespace std;

inline void check(bool condition, const char* message) {
    if (!condition) {
        cerr << "FALLO: " << message << '\n';
        exit(EXIT_FAILURE);
    }
}

template<class T>
void common_tests() {
    T trie;
    check(trie.t.size() == 1, "Trie comienza solo con la raiz");
    check(!trie.t[0].output, "La raiz no es fin de palabra");

    // TODO: insert, contains, remove, keysWithPrefix y prefijos
    cout << "Pruebas comunes superadas\n";
}
