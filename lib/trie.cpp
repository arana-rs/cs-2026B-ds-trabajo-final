#include "trie.hpp"

Vertex::Vertex() {
    fill(begin(next), end(next), -1);
}

// la raiz es t[0]
Trie::Trie() : t(1) {}
