#include "trie_ptr.hpp"

Node::Node() { fill(begin(next), end(next), nullptr); }

TriePtr::TriePtr() : root(new Node()), n(0), cnt(1) {}

TriePtr::~TriePtr() { clear(root); }

// postorden: primero los hijos, luego el nodo
void TriePtr::clear(Node *x) {
  if (x == nullptr)
    return;
  for (int c = 0; c < K; c++)
    clear(x->next[c]);
  delete x;
}

void TriePtr::insert(const string &key) {
  Node *x = root;
  for (char ch : key) {
    int c = ch - 'a';
    if (x->next[c] == nullptr) {
      x->next[c] = new Node();
      cnt++;
    }
    x = x->next[c];
  }
  if (!x->output) {
    x->output = true;
    n++;
  }
}

bool TriePtr::contains(const string &key) const {
  Node *x = root;
  for (char ch : key) {
    x = x->next[ch - 'a'];
    if (x == nullptr)
      return false;
  }
  return x->output;
}

void TriePtr::remove(const string &key) { remove(root, key, 0); }

// borrado ansioso: devuelve nullptr si el nodo quedo sin clave ni hijos
Node *TriePtr::remove(Node *x, const string &key, int d) {
  if (x == nullptr)
    return nullptr;
  if (d == (int)key.size()) {
    if (x->output) {
      x->output = false;
      n--;
    }
  } else {
    int c = key[d] - 'a';
    x->next[c] = remove(x->next[c], key, d + 1);
  }
  if (x->output || x == root)
    return x;
  for (int c = 0; c < K; c++)
    if (x->next[c] != nullptr)
      return x;
  delete x;
  cnt--;
  return nullptr;
}

bool TriePtr::isEmpty() const { return n == 0; }

int TriePtr::size() const { return n; }

int TriePtr::nodes() const { return cnt; }

string TriePtr::longestPrefixOf(const string &s) const {
  Node *x = root;
  int len = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    x = x->next[s[i] - 'a'];
    if (x == nullptr)
      break;
    if (x->output)
      len = i + 1;
  }
  return s.substr(0, len);
}

vector<string> TriePtr::allPrefixOf(const string &str) const {
  vector<string> res;
  Node *x = root;
  for (int i = 0; i < (int)str.size(); i++) {
    x = x->next[str[i] - 'a'];
    if (x == nullptr)
      break;
    if (x->output)
      res.push_back(str.substr(0, i + 1));
  }
  return res;
}

void TriePtr::collect(Node *x, string &pre, vector<string> &res) const {
  if (x->output)
    res.push_back(pre);
  for (int c = 0; c < K; c++) {
    if (x->next[c] != nullptr) {
      pre.push_back(char('a' + c));
      collect(x->next[c], pre, res);
      pre.pop_back();
    }
  }
}

vector<string> TriePtr::keysWithPrefix(const string &pre) const {
  vector<string> res;
  Node *x = root;
  for (char ch : pre) {
    x = x->next[ch - 'a'];
    if (x == nullptr)
      return res;
  }
  string cur = pre;
  collect(x, cur, res);
  return res;
}

vector<string> TriePtr::keys() const { return keysWithPrefix(""); }

void TriePtr::collect(Node *x, string &pre, const string &pat,
                      vector<string> &res) const {
  if (x == nullptr)
    return;
  size_t d = pre.size();
  if (d == pat.size()) {
    if (x->output)
      res.push_back(pre);
    return;
  }
  char next = pat[d];
  for (int c = 0; c < K; c++) {
    char ch = char('a' + c);
    if (next == '.' || next == ch) {
      pre.push_back(ch);
      collect(x->next[c], pre, pat, res);
      pre.pop_back();
    }
  }
}

vector<string> TriePtr::keysThatMatch(const string &pat) const {
  vector<string> res;
  string pre = "";
  collect(root, pre, pat, res);
  return res;
}
