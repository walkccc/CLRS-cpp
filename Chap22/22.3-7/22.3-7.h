#ifndef ch22_3_7_h
#define ch22_3_7_h

#include <stack>
#include "../Graph.h"

#define WHITE "WHITE"
#define GRAY "GRAY"
#define BLACK "BLACK"

// [Page 611]
//   DFS-STACK(G)
//   - Time: O(V + E)

namespace CLRS {
namespace CH22 {
void printGraph(Graph& G) {
  for (int i = 0; i < G.V.size(); i++) {
    if (i > 0 && i % 3 == 0) cout << endl;
    cout << setw(5) << G.V[i]->color << " ";
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
    if (i == G.V.size() - 1) cout << endl << endl;
  }
}

void dfsStack(Graph& G) {
  for (Vertex* u : G.V) {
    u->color = WHITE;
    u->PI = nullptr;
  }
  int time = 0;
  std::stack<Vertex*> S;
  for (Vertex* u : G.V) {
    if (u->color == WHITE) {
      time++;
      u->d = time;
      u->color = GRAY;
      S.push(u);
      printGraph(G);
      while (!S.empty()) {
        Vertex* v = S.top();
        bool isNeighborhoodsAllDiscovered = true;
        if (v->color == GRAY) {
          for (Vertex* w : G.Adj[v]) {
            if (w->color == WHITE) {
              time++;
              w->d = time;
              w->color = GRAY;
              S.push(w);
              printGraph(G);
              isNeighborhoodsAllDiscovered = false;
              break;
            }
          }
        }
        if (isNeighborhoodsAllDiscovered) {
          time++;
          v->f = time;
          v->color = BLACK;
          S.pop();
          printGraph(G);
        }
      }
    }
  }
}
}  // namespace CH22
}  // namespace CLRS

#endif