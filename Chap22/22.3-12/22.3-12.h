#ifndef ch22_3_12_h
#define ch22_3_12_h

#include <stack>

#include "../Graph.h"

// [Page 612]
//   DFS-CC(G)
//   - Time: O(V + E)
//
//   DFS-VISIT-CC(G, u)
//   - Time: O(E)

namespace CLRS {
namespace CH22 {
int time;

void printCC(Graph& G) {
  for (Vertex* u : G.V) {
    cout << u->name << ".cc = " << u->cc << endl;
  }
}

void dfsVisitCC(Graph& G, Vertex* u) {
  time++;
  u->d = time;
  u->color = GRAY;
  for (Vertex* v : G.Adj[u]) {
    if (v->color == WHITE) {
      v->cc = u->cc;
      v->PI = u;
      dfsVisitCC(G, v);
    }
  }
  u->color = BLACK;
  time++;
  u->f = time;
}

void dfsCC(Graph& G) {
  for (Vertex* u : G.V) {
    u->color = WHITE;
    u->PI = nullptr;
  }
  time = 0;
  int cc = 1;
  for (Vertex* u : G.V)
    if (u->color == WHITE) {
      u->cc = cc;
      cc++;
      dfsVisitCC(G, u);
    }
}
}  // namespace CH22
}  // namespace CLRS

#endif