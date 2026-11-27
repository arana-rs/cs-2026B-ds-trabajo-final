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
    check(trie.isEmpty() == true, "Trie comienza vacío");
    check(trie.size() == 0, "Trie comienza con 0 claves");
    check(!trie.t[0].output, "La raiz no es fin de palabra");

    trie.insert("hola");
    check(trie.isEmpty() == false, "Trie ya no esta vacio");
    check(trie.size() == 1, "Trie posee 1 clave");
    check(trie.t.size() == 5, "El árbol posee 5 nodos");
    check(trie.contains("hola") == 1, "La clave fue guardada");
    check(trie.contains("hol") == 0, "Un prefijo no es una clave guardada");
    check(trie.contains("holaa") == 0, "Clave no existente");

    // TODO: insert, contains, remove, keysWithPrefix y prefijos
    cout << "Pruebas comunes superadas\n";
}
