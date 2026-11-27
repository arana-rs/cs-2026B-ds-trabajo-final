#include "trie.hpp"

Vertex::Vertex() {
    fill(begin(next), end(next), -1);
}

// la raiz es t[0]
Trie::Trie() : n(0), t(1) {}

void Trie::insert(const string& key){
	int v = 0;
	for(char ch : key){
		int c = ch - 'a';
		if(t[v].next[c] == -1){
			t[v].next[c] = t.size();
			t.emplace_back();
		}
		v = t[v].next[c];
	}
	t[v].output = true;
	n++;
}

bool Trie::contains(const string& key)const{
 int v = 0;
 for(char c : key){
    int pos = c - 'a';
    if(this->t[v].next[pos] == -1) return false;
    v = t[v].next[pos];   
  }
  return t[v].output;
}

bool Trie::isEmpty()const{
	return n == 0;;
}

int Trie::size()const{
	return n;
}
