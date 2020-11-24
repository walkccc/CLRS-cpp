#ifndef Graph_h
#define Graph_h

#include <bits/stdc++.h>
using namespace std;

enum Color {
  WHITE,
  GRAY,
  BLACK,
};

string getString(Color color) {
  switch (color) {
    case WHITE:
      return "WHITE";
    case GRAY:
      return "GRAY";
    case BLACK:
      return "BLACK";
  }
  throw;
}

class Vertex {
 public:
  const string name;
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