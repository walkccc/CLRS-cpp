#ifndef ch22_3_10_h
#define ch22_3_10_h

#include <stack>

#include "../Graph.h"

// [Page 612]
//   DFS-STACK-PRINT(G, v)
//   - Time: O(V + E)

namespace CLRS {
namespace CH22 {
int time;

void dfsVisitPrint(Graph& G, Vertex* u) {
  time++;
  u->d = time;
  u->color = GRAY;
  for (Vertex* v : G.Adj[u]) {
    if (v->color == WHITE) {
      cout << "(" << u->name << ", " << v->name << ") is a tree edge." << endl;
      v->PI = u;
      dfsVisitPrint(G, v);
    } else if (v->color == GRAY) {
      cout << "(" << u->name << ", " << v->name << ") is a back edge." << endl;
    } else if (v->d > u->d) {
      cout << "(" << u->name << ", " << v->name << ") is a forward edge."
           << endl;
    } else {
      cout << "(" << u->name << ", " << v->name << ") is a cross edge." << endl;
    }
  }
  u->color = BLACK;
  time++;
  u->f = time;
}

void dfs(Graph& G) {
  for (Vertex* u : G.V) {
    u->color = WHITE;
    u->PI = nullptr;
  }
  time = 0;
  for (Vertex* u : G.V)
    if (u->color == WHITE)
      dfsVisitPrint(G, u);
}
}  // namespace CH22
}  // namespace CLRS

#endif