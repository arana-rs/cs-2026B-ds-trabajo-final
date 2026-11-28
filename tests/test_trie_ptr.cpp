#include "common_tests.hpp"
#include "trie_ptr.hpp"

int main() {
  common_tests<TriePtr>();

  // Borrado ansioso: remove libera los nodos que quedan sin clave ni hijos
  TriePtr a;
  a.insert("sol");
  a.insert("so");
  a.insert("sal");
  a.insert("oso");
  check(a.nodes() == 9, "El trie de {sol, so, sal, oso} tiene 9 nodos");

  a.remove("sa");
  check(a.nodes() == 9, "Borrar un prefijo que no es clave no libera nodos");

  a.remove("sol");
  check(a.nodes() == 8, "remove(sol) libera el nodo de la l");

  a.remove("so");
  check(a.nodes() == 7, "remove(so) libera el nodo de la o");
  check(a.contains("sal") && a.contains("oso"), "Las demas claves siguen");

  TriePtr b;
  b.insert("sal");
  b.insert("oso");
  check(a.nodes() == b.nodes(),
        "Misma cantidad de nodos que construirlo desde cero (Proposicion F)");

  a.remove("sal");
  a.remove("oso");
  check(a.isEmpty(), "Trie vacio despues de borrar todo");
  check(a.nodes() == 1, "Despues de borrar todo solo queda la raiz");

  cout << "Pruebas de TriePtr superadas\n";
}
