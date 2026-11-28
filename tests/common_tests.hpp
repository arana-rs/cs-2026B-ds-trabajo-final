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
    check(trie.size() == 1, "Trie posee 1 claves");
    check(trie.t.size() == 5, "El árbol posee 5 nodos");
    check(trie.contains("hola") == 1, "La clave fue guardada");
    check(trie.contains("hol") == 0, "Un prefijo no es una clave guardada");
    check(trie.contains("holaa") == 0, "Clave no existente");

    trie.remove("hola");
    check(trie.isEmpty() == true, "Trie vacio despues de eliminacion");
    check(trie.size() == 0, "Trie posee 0 claves");
    check(trie.t.size() == 1, "El árbol solo posee la raiz");
    check(trie.contains("hola") == 0, "Clave no existente");
    
    trie.insert("hola"); 
    check(trie.longestPrefixOf("holaquetal") == "hola" , "Devuelve hola");
       
    trie.insert("universidad");
    trie.insert("universo");
    trie.insert("universal");
    trie.insert("universidades");
    trie.insert("universalidad");
    trie.insert("agua");
    trie.insert("oso");
    check(trie.isEmpty() == false, "Trie ya no esta vacio");
    check(trie.size() == 7, "Trie posee 7 claves");
    check(trie.t.size() == 28, "El árbol posee 28 nodos");
    check(trie.contains("agua") == 1, "La clave fue guardada");
    check(trie.contains("oso") == 1, "La clave fue guardada");
    check(trie.contains("universal") == 1, "La clave fue guardada");
    check(trie.contains("universalidad") == 1, "La clave fue guardada");
    check(trie.contains("universidad") == 1, "La clave fue guardad");
    check(trie.contains("universidades") == 1, "La clave fue guardad");
    check(trie.contains("universalidades") == 0, "Clave no existente");
    check(trie.contains("univers") == 0, "Clave no existente");
    check(trie.contains("uni") == 0, "Clave no existente");

    trie.remove("hola");
    check(trie.size() == 7, "Trie posee 7 claves");
    check(trie.t.size() == 28, "El árbol posee 28 nodos");

    trie.remove("agu");
    check(trie.size() == 7, "Trie posee 7 claves");
    check(trie.t.size() == 28, "El árbol posee 28 nodos");

	trie.remove("agua");
    check(trie.size() == 6, "Trie posee 6 claves");
    check(trie.t.size() == 24, "El árbol posee 24 nodos");

	trie.remove("univers");
    check(trie.size() == 6, "Trie posee 6 claves");
    check(trie.t.size() == 24, "El árbol posee 24 nodos");

	trie.remove("univeralidad");
    check(trie.size() == 5, "Trie posee 5 claves");
    check(trie.t.size() == 20, "El árbol posee 20 nodos");
    check(trie.contains("universal") == 1, "La clave no fue alterada");

	trie.remove("universidad");
    check(trie.size() == 4, "Trie posee 4 claves");
    check(trie.t.size() == 20, "El árbol posee 20 nodos");
    check(trie.contains("universidades") == 1, "La clave no fue alterada");

	trie.remove("universo");
    check(trie.size() == 3, "Trie posee 3 claves");
    check(trie.t.size() == 19, "El árbol posee 19 nodos");
    check(trie.contains("universidades") == 1, "La clave no fue alterada");

	trie.insert("uni");
    check(trie.size() == 4, "Trie posee 4 claves");
    check(trie.t.size() == 19, "El árbol posee 19 nodos");
    check(trie.contains("uni") == 1, "Clave fue guardad");

	trie.remove("universal");
	trie.remove("universidades");
    check(trie.size() == 2, "Trie posee 2 claves");
    check(trie.t.size() == 7, "El árbol posee 7 nodos");
    check(trie.contains("uni") == 1, "La clave no fue alterada");
    check(trie.contains("oso") == 1, "La clave no fue alterada");

	trie.remove("uni");
	trie.remove("oso");
    check(trie.isEmpty() == true, "Trie vacio despues de eliminacion");
    check(trie.size() == 0, "Trie posee 0 claves");
    check(trie.t.size() == 1, "El árbol solo posee la raiz");


    cout << "Pruebas comunes superadas\n";
}
