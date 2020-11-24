#ifndef ch22_3_7_h
#define ch22_3_7_h

#include <stack>

#include "../Graph.h"

// [Page 611]
//   DFS-STACK(G)
//   - Time: O(V + E)

namespace CLRS {
namespace CH22 {
int time;

void printGraph(const Graph& G) {
  for (int i = 0; i < G.V.size(); ++i) {
    if (i > 0 && i % 3 == 0)
      cout << endl;
    cout << setw(5) << getString(G.V[i]->color) << " ";
    cout << G.V[i]->name << " ";

    if (G.V[i]->d == 0)
      cout << setw(2) << " ";
    else
      cout << setw(2) << G.V[i]->d;

    if (G.V[i]->d == 0 && G.V[i]->f == 0)
      cout << " ";
    else
      cout << "/";

    if (G.V[i]->f == 0)
      cout << setw(2) << " ";
    else
      cout << setw(2) << G.V[i]->f;
    cout << setw(2) << " ";
    if (i == G.V.size() - 1)
      cout << endl << endl;
  }
}

Vertex* firstWhiteNeighbor(const Graph& G, Vertex* u) {
  for (Vertex* v : G.Adj.at(u))  // explore edge (u, v)
    if (v->color == WHITE)
      return v;
  return nullptr;
}

void dfsVisitStack(const Graph& G, Vertex* u) {
  std::stack<Vertex*> S{{u}};  // analogous to dfsVisit(G, u)
  u->d = ++time;               // white vertex u has just been discovered
  u->color = GRAY;
  while (!S.empty()) {
    u = S.top();
    Vertex* v = firstWhiteNeighbor(G, u);
    if (v == nullptr) {
      // u's adjacency list has been fully explored
      S.pop();
      u->f = ++time;
      u->color = BLACK;  // blacken u; it is finished
    } else {
      // u's adjacency list hasn't been fully explored
      v->PI = u;
      v->d = ++time;
      v->color = GRAY;
      S.push(v);
    }
  }

  cout << "After exploring vertex " << u->name << "'s forest:\n\n";
  printGraph(G);
}

void dfsStack(const Graph& G) {
  for (Vertex* u : G.V) {
    u->color = WHITE;
    u->PI = nullptr;
  }
  time = 0;
  for (Vertex* u : G.V)
    if (u->color == WHITE)
      dfsVisitStack(G, u);
}
}  // namespace CH22
}  // namespace CLRS

#endif