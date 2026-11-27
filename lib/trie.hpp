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
public:
    vector<Vertex> t;

    Trie();

    void insert(const string& key);
    bool contains(const string& key) const;
    void remove(const string& key);
    bool isEmpty() const;
    int size() const;

    string longestPrefixOf(const string& s) const;
    vector<string> keysWithPrefix(const string& s) const;
    vector<string> keysThatMatch(const string& s) const;
    vector<string> keys() const;
};
