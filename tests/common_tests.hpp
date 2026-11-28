#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline void check(bool condition, const char *message) {
  if (!condition) {
    cerr << "FALLO: " << message << '\n';
    exit(EXIT_FAILURE);
  }
}

template <class T> void common_tests() {
  T trie;
  check(trie.t.size() == 1, "Trie comienza solo con la raiz");
  check(trie.isEmpty() == true, "Trie comienza vacío");
  check(trie.size() == 0, "Trie comienza con 0 claves");
  check(!trie.t[0].output, "La raiz no es fin de palabra");

  trie.insert("hola");

  check(trie.longestPrefixOf("holaquetal") == "hola", "Devuelve hola");

  check(trie.isEmpty() == false, "Trie ya no esta vacio");
  check(trie.size() == 1, "Trie posee 1 claves");
  check(trie.t.size() == 5, "El árbol posee 5 nodos");
  check(trie.contains("hola") == 1, "La clave fue guardada");
  check(trie.contains("hol") == 0, "Un prefijo no es una clave guardada");
  check(trie.contains("holaa") == 0, "Clave no existente");

  trie.insert("hola");
  check(trie.size() == 1, "Insertar una clave repetida no cambia el tamaño");
  check(trie.t.size() == 5, "Insertar una clave repetida no crea nodos");

  trie.remove("hola");
  check(trie.isEmpty() == true, "Trie vacio despues de eliminacion");
  check(trie.size() == 0, "Trie posee 0 claves");
  check(trie.contains("hola") == 0, "Clave no existente");

  trie.insert("universidad");
  trie.insert("universo");
  trie.insert("universal");
  trie.insert("universidades");
  trie.insert("universalidad");
  trie.insert("agua");
  trie.insert("oso");

  check(trie.allPrefixOf("universalidadx") ==
            vector<string>{"universal", "universalidad"},
        "Prefijos validos en orden");
  check(trie.allPrefixOf("universidades") ==
            vector<string>{"universidad", "universidades"},
        "El prefijo de la clave exacta se incluye");
  check(trie.allPrefixOf("xyz").empty(),
        "Prefijo sin coincidencias devuelve vacio");

  check(trie.keysThatMatch("...") == vector<string>{"oso"},
        "Longitud 3 comodines devuelve oso");
  check(trie.keysThatMatch("a..a") == vector<string>{"agua"},
        "a..a devuelve agua");
  check(trie.keysThatMatch("univers......") ==
            vector<string>{"universalidad", "universidades"},
        "Comodin de 13 devuelve ambas ordenadas");
  check(trie.keysThatMatch(".....").empty(),
        "Math sin coincidencias de 5 comodines devuelve vacio");

  check(trie.isEmpty() == false, "Trie ya no esta vacio");
  check(trie.size() == 7, "Trie posee 7 claves");
  check(trie.contains("agua") == 1, "La clave fue guardada");
  check(trie.contains("oso") == 1, "La clave fue guardada");
  check(trie.contains("universal") == 1, "La clave fue guardada");
  check(trie.contains("universalidad") == 1, "La clave fue guardada");
  check(trie.contains("universidad") == 1, "La clave fue guardad");
  check(trie.contains("universidades") == 1, "La clave fue guardad");
  check(trie.contains("universalidades") == 0, "Clave no existente");
  check(trie.contains("univers") == 0, "Clave no existente");
  check(trie.contains("uni") == 0, "Clave no existente");
  check(trie.keysWithPrefix("univers") ==
            vector<string>{"universal", "universalidad", "universidad",
                           "universidades", "universo"},
        "Devuelve las 5 claves ordenadas");
  check(trie.keysWithPrefix("universa") ==
            vector<string>{"universal", "universalidad"},
        "Devuelve universal y universalidad");
  check(trie.keysWithPrefix("agu") == vector<string>{"agua"}, "Devuelve agua");
  check(trie.keysWithPrefix("xyz").empty(),
        "Prefijo inexistente devuelve vacio");
  check(trie.keysWithPrefix("") == trie.keys(),
        "Devuelve todas las claves ordenadas");

  trie.remove("hola");
  check(trie.size() == 7, "Trie posee 7 claves");

  trie.remove("agu");
  check(trie.size() == 7, "Trie posee 7 claves");

  trie.remove("agua");
  check(trie.size() == 6, "Trie posee 6 claves");
  check(trie.keysWithPrefix("agu").empty(), "No devuelve claves eliminadas");

  check(trie.keysThatMatch("a..a").empty(),
        "a..a ya no devuelve agua ya que se borro");

  trie.remove("univers");
  check(trie.size() == 6, "Trie posee 6 claves");

  trie.remove("universalidad"); // SAS
  check(trie.size() == 5, "Trie posee 5 claves");
  check(trie.contains("universal") == 1, "La clave no fue alterada");

  trie.remove("universidad");
  check(trie.size() == 4, "Trie posee 4 claves");
  check(trie.contains("universidades") == 1, "La clave no fue alterada");

  trie.remove("universo");
  check(trie.size() == 3, "Trie posee 3 claves");
  check(trie.contains("universidades") == 1, "La clave no fue alterada");

  trie.insert("uni");
  check(trie.size() == 4, "Trie posee 4 claves");
  check(trie.contains("uni") == 1, "Clave fue guardad");

  trie.remove("universal");
  trie.remove("universidades");
  check(trie.size() == 2, "Trie posee 2 claves");
  check(trie.contains("uni") == 1, "La clave no fue alterada");
  check(trie.contains("oso") == 1, "La clave no fue alterada");

  trie.remove("uni");
  trie.remove("oso");
  check(trie.isEmpty() == true, "Trie vacio despues de eliminacion");
  check(trie.size() == 0, "Trie posee 0 claves");
  check(trie.keysWithPrefix("").empty(),
        "Un trie vacio devuelve un vector de prefix vacio");

  cout << "Pruebas comunes superadas\n";
}
