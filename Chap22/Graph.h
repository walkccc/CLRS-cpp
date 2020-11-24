#ifndef Graph_h
#define Graph_h

#include <bits/stdc++.h>

#define WHITE "WHITE"
#define GRAY "GRAY"
#define BLACK "BLACK"

using namespace std;

class Vertex {
 public:
  string name;
  string color;
  int d = 0;
  int f = 0;
  int cc;
  Vertex* PI;
  Vertex() : color(WHITE), d(INT_MAX), PI(nullptr) {
  }
  Vertex(const string& name) : name(name) {
  }
};

class Graph {
 public:
  vector<Vertex*> V;
  map<Vertex*, vector<Vertex*>> Adj;
};

#endif