#pragma once

#include <bits/stdc++.h>
using namespace std;

const int K = 26;

struct Vertex {
  int next[K];
  bool output = false;

  Vertex();
};

class Trie {
private:
  int n;

public:
  vector<Vertex> t;

  Trie();

  void insert(const string &);
  bool contains(const string &) const;
  void remove(const string &);
  bool isEmpty() const;
  int size() const;

  string longestPrefixOf(const string &) const;
  vector<string> keysWithPrefix(const string &) const;
  vector<string> keysThatMatch(const string &) const;
  vector<string> keys() const;
};
