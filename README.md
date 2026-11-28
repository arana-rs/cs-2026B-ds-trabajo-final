# Trie

Implementación de un árbol trie en C++.

## Requisitos

- `g++` con soporte para C++17
- `make`

## Compilar

```sh
make
```

Genera los ejecutables `test_trie` y `bench_trie`.

## Tests

```sh
make test
```

## Benchmarks

```sh
make bench
```

Compara el trie con `std::set<string>` en `insert`, `contains` (claves presentes y ausentes), `keysWithPrefix` y memoria, con n = 10³, 10⁴ y 10⁵ palabras aleatorias de longitud 10 (semilla fija 42, mejor de 5 corridas, `-O2`). Son los resultados que aparecen en las diapositivas.

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
