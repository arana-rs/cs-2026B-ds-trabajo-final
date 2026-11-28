# Trie

Implementación de un árbol trie en C++, en dos versiones con la misma interfaz:

- `lib/trie.*`: nodos en un `vector<Vertex>` con índices; borrado perezoso.
- `lib/trie_ptr.*`: nodos con punteros (`Node* next[26]`); borrado ansioso que libera los nodos con `delete`.

## Requisitos

- `g++` con soporte para C++17
- `make`

## Compilar

```sh
make
```

Genera los ejecutables de pruebas y benchmarks de ambas versiones.

## Tests

```sh
make test
```

Ejecuta las pruebas comunes en ambas versiones y las de borrado ansioso de `TriePtr`.

## Memoria

```sh
make asan
```

Compila las pruebas con AddressSanitizer/LeakSanitizer; falla si hay fugas o accesos inválidos.

## Benchmarks

```sh
make bench
```

Compara cada versión del trie con `std::set<string>` en `insert`, `contains` (claves presentes y ausentes), `keysWithPrefix`, memoria y memoria tras borrar todas las claves, con n = 10³, 10⁴ y 10⁵ palabras aleatorias de longitud 10 (semilla fija 42, mejor de 5 corridas, `-O2`). Son los resultados que aparecen en las diapositivas.

## Problema de Codeforces

[1703D - Double Strings](https://codeforces.com/problemset/problem/1703/D), resuelto con el trie en `1703d/doubleStrings.cpp`.

```sh
make cf
```

Compila la solución y la ejecuta con el ejemplo del enunciado (`1703d/input`).

## Limpiar

```sh
make clean
```
