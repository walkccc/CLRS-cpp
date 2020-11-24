#ifndef Graph_h
#define Graph_h

#include <bits/stdc++.h>

enum Color {
  WHITE,
  GRAY,
  BLACK,
};

using namespace std;

class Vertex {
 public:
  string name;
  Color color;
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