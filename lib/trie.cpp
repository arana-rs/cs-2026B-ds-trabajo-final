#include "trie.hpp"

Vertex::Vertex() { fill(begin(next), end(next), -1); }

// la raiz es t[0]
Trie::Trie() : n(0), t(1) {}

void Trie::insert(const string &key) {
  int v = 0;
  for (char ch : key) {
    int c = ch - 'a';
    if (t[v].next[c] == -1) {
      t[v].next[c] = t.size();
      t.emplace_back();
    }
    v = t[v].next[c];
  }
  t[v].output = true;
  n++;
}
bool Trie::contains(const string &key) const {
  int v = 0;
  for (char c : key) {
    int pos = c - 'a';
    if (this->t[v].next[pos] == -1)
      return false;
    v = t[v].next[pos];
  }
  return t[v].output;
}

bool Trie::isEmpty() const { return n == 0; }
string Trie::longestPrefixOf(const string &s) const {
  int v = 0, len = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    int pos = s[i] - 'a';
    if (t[v].next[pos] == -1)
      break;
    v = t[v].next[pos];
    if (t[v].output)
      len = i + 1;
  }
  return s.substr(0, len);
}
void Trie::remove(const string &key) {
  int v = 0;
  for (char ch : key) {
    int c = ch - 'a';
    if (t[v].next[c] == -1)
      return;
    v = t[v].next[c];
  }
  if (t[v].output) {
    t[v].output = false;
    n--;
  }
}

vector<string> Trie::keys() const { return keysWithPrefix(""); }

void Trie::collect(int v, string &pre, vector<string> &res) const {
  if (t[v].output)
    res.push_back(pre);

  for (int c = 0; c < K; c++) {
    if (t[v].next[c] != -1) {
      pre.push_back(char('a' + c));
      collect(t[v].next[c], pre, res);
      pre.pop_back();
    }
  }
}

vector<string> Trie::keysWithPrefix(const string &pre) const {
  vector<string> res = {};

  int v = 0;
  for (char ch : pre) {
    int pos = ch - 'a';
    if (t[v].next[pos] == -1)
      return res;
    v = t[v].next[pos];
  }

  string cur = pre;
  collect(v, cur, res);
  return res;
}

void Trie::collect(int v, string &pre, const string &pat,
                   vector<string> &res) const {
  size_t d = pre.size();

  // CASO cerrado digo base
  if (v == -1)
    return;

  if (d == pat.size() && t[v].output) // Profunidad y nodo terminal deseados
    res.push_back(pre);

  if (d == pat.size())
    return;

  char next = pat[d];
  for (int c = 0; c < K; c++) {
    char ch = char('a' + c);
    if (next == '.' || next == ch) {
      pre.push_back(ch);
      collect(t[v].next[c], pre, pat, res);
      pre.pop_back();
    }
  }
}

vector<string> Trie::keysThatMatch(const string &pat) const {
  vector<string> res;

  string pre = "";
  collect(0, pre, pat, res);
  return res;
}

int Trie::size() const { return n; }
