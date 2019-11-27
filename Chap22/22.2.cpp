#include "22.2.h"
#include "../print.h"

using namespace CLRS::CH22;

int main() {
  print(string("22.2 Breadth-ﬁrst search"));

  cout << "Initialize an undirected graph as Figure 22.3\n";

  Graph G;
  Vertex* r = new Vertex("r");
  Vertex* s = new Vertex("s");
  Vertex* t = new Vertex("t");
  Vertex* u = new Vertex("u");
  Vertex* v = new Vertex("v");
  Vertex* w = new Vertex("w");
  Vertex* x = new Vertex("x");
  Vertex* y = new Vertex("y");
  G.V.push_back(r);
  G.V.push_back(s);
  G.V.push_back(t);
  G.V.push_back(u);
  G.V.push_back(v);
  G.V.push_back(w);
  G.V.push_back(x);
  G.V.push_back(y);

  G.Adj[r].push_back(v);
  G.Adj[r].push_back(s);

  G.Adj[s].push_back(w);
  G.Adj[s].push_back(r);

  G.Adj[t].push_back(x);
  G.Adj[t].push_back(w);
  G.Adj[t].push_back(u);

  G.Adj[u].push_back(y);
  G.Adj[u].push_back(x);
  G.Adj[u].push_back(t);

  G.Adj[v].push_back(r);

  G.Adj[w].push_back(t);
  G.Adj[w].push_back(x);
  G.Adj[w].push_back(s);

  G.Adj[x].push_back(y);
  G.Adj[x].push_back(w);
  G.Adj[x].push_back(u);
  G.Adj[x].push_back(t);

  G.Adj[y].push_back(x);
  G.Adj[y].push_back(u);

  cout << "\nPerform BFS(G, s)\n";
  bfs(G, s);
  printGraph(G);

  cout << "\nPerform PRINT-PATH(G, s, y)\n";
  printPath(G, s, y);

  cout << "\n\nPerform PRINT-PATH(G, s, t)\n";
  printPath(G, s, t);
}