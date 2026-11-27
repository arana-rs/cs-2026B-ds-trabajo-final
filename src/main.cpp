#include "tree.hpp"

int main() {
    Trie trie;
    cout << "vertices: " << trie.t.size() << "\n";
    cout << "raiz next[0]: " << trie.t[0].next[0] << "\n";
    return 0;
}
