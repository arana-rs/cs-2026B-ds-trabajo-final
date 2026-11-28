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
	return n == 0;
}
string Trie::longestPrefixOf(const string& s)const {
	int v = 0, len = 0;
	for(int i = 0; i <(int)s.size() ; i++  ){
	   int pos = s[i] - 'a';
	   if ( t[v].next[pos] == -1 ) break;
	   v= t[v].next[pos];
	   if(t[v].output) len = i + 1;
	}
        return s.substr(0 , len);	
	
}
void Trie::remove(const string& key){
	int v = 0;
	for(char ch : key){
	 int c = ch - 'a';
	 if(t[v].next[c] == -1) return;
	 v = t[v].next[c];
	}
	if(t[v].output)
	t[v].output = false;
	n--;
}
int Trie::size()const{
	return n;
}
