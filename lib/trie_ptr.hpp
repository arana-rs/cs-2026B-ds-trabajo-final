#pragma once

#include "trie.hpp"

struct Node {
  Node *next[K];
  bool output = false;

  Node();
};

class TriePtr {
private:
  Node *root;
  int n;
  int cnt; // nodos reservados, incluida la raiz

  Node *remove(Node *x, const string &key, int d);
  void clear(Node *x);
  void collect(Node *x, string &pre, vector<string> &res) const;

  void collect(Node *x, string &pre, const string &pat,
               vector<string> &res) const;

public:
  TriePtr();
  ~TriePtr();
  TriePtr(const TriePtr &) = delete;
  TriePtr &operator=(const TriePtr &) = delete;

  void insert(const string &);
  bool contains(const string &) const;
  void remove(const string &);
  bool isEmpty() const;
  int size() const;
  int nodes() const;

  string longestPrefixOf(const string &) const;
  vector<string> keysWithPrefix(const string &) const;
  vector<string> keysThatMatch(const string &) const;
  vector<string> keys() const;

  vector<string> allPrefixOf(const string &) const;
};
