#ifndef ch22_2_h
#define ch22_2_h

#include "../Chap10/10.1-4/10.1-4.h"
#include "../print.h"
#include "Graph.h"

using namespace CLRS::CH10;

// [Page 595]
//   BFS(G, s)
//   - Time: O(V + E)
//
// [Page 601]
//   PRINT-PATH(G, s, v)
//   - Time: O(# of vertices in the path)

namespace CLRS {
namespace CH22 {
int iterationCounter = -1;

void printGraph(Graph& G) {
  iterationCounter++;
  if (iterationCounter == 0)
    cout << "(a) ";
  else if (iterationCounter == 1)
    cout << "(b) ";
  else if (iterationCounter == 2)
    cout << "(c) ";
  else if (iterationCounter == 3)
    cout << "(d) ";
  else if (iterationCounter == 4)
    cout << "(e) ";
  else if (iterationCounter == 5)
    cout << "(f) ";
  else if (iterationCounter == 6)
    cout << "(g) ";
  else if (iterationCounter == 7)
    cout << "(h) ";
  else
    cout << "(i) ";

  for (int i = 0; i < G.V.size(); i++) {
    if (i == 4)
      cout << endl << "    ";
    cout << setw(5) << G.V[i]->color << " ";

    if (G.V[i]->d == INT_MAX)
      cout << "∞";
    else
      cout << G.V[i]->d;
    cout << " ";

    if (G.V[i]->PI == nullptr)
      cout << "N";
    else
      cout << G.V[i]->PI->name;
    cout << " ";
  }
}

void printQueue(Queue<Vertex*>& Q) {
  cout << "  Q ";
  for (int i = Q.head; i != Q.tail; i = (i + 1) % Q.size()) {
    cout << Q[i]->d << " ";
  }
  cout << endl << endl;
}

void bfs(Graph& G, Vertex* s) {
  for (Vertex* u : G.V) {
    if (u == s)
      continue;
    u->color = WHITE;
    u->d = INT_MAX;
    u->PI = nullptr;
  }
  s->color = GRAY;
  s->d = 0;
  s->PI = nullptr;
  Queue<Vertex*> Q(4);
  Q.head = Q.tail = 0;
  enqueue(Q, s);
  while (!queueEmpty(Q)) {
    printGraph(G);
    printQueue(Q);
    Vertex* u = dequeue(Q);
    for (Vertex* v : G.Adj[u]) {
      if (v->color == WHITE) {
        v->color = GRAY;
        v->d = u->d + 1;
        v->PI = u;
        enqueue(Q, v);
      }
    }
    u->color = BLACK;
  }
}

void printPath(Graph& G, Vertex* s, Vertex* v) {
  if (v == s) {
    cout << s->name << " ";
  } else if (v->PI == nullptr) {
    cout << "no path from " << s->name << " to " << v->name << " exists"
         << endl;
  } else {
    printPath(G, s, v->PI);
    cout << v->name << " ";
  }
}
}  // namespace CH22
}  // namespace CLRS

#endif