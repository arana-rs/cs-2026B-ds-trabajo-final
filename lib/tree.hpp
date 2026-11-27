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
};
