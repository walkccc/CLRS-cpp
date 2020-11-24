#include "22.3.h"

#include "../print.h"

using namespace CLRS::CH22;

int main() {
  {
    print(string("22.3 Depthfirst search"));

    cout << "Initialize a directed graph as Figure 22.4\n";
    Graph G;
    Vertex* u = new Vertex("u");
    Vertex* v = new Vertex("v");
    Vertex* w = new Vertex("w");
    Vertex* x = new Vertex("x");
    Vertex* y = new Vertex("y");
    Vertex* z = new Vertex("z");
    G.V.push_back(u);
    G.V.push_back(v);
    G.V.push_back(w);
    G.V.push_back(x);
    G.V.push_back(y);
    G.V.push_back(z);

    G.Adj[u].push_back(v);
    G.Adj[u].push_back(x);

    G.Adj[v].push_back(y);

    G.Adj[w].push_back(y);
    G.Adj[w].push_back(z);

    G.Adj[x].push_back(v);

    G.Adj[y].push_back(x);

    G.Adj[z].push_back(z);

    cout << "\nPerform DFS(G)\n";
    dfs(G);
  }

  {
    print(string("22.3-2"));

    cout << "Initialize a directed graph as Figure 22.6\n";

    Graph G;
    Vertex* q = new Vertex("q");
    Vertex* r = new Vertex("r");
    Vertex* s = new Vertex("s");
    Vertex* t = new Vertex("t");
    Vertex* u = new Vertex("u");
    Vertex* v = new Vertex("v");
    Vertex* w = new Vertex("w");
    Vertex* x = new Vertex("x");
    Vertex* y = new Vertex("y");
    Vertex* z = new Vertex("z");
    G.V.push_back(q);
    G.V.push_back(r);
    G.V.push_back(s);
    G.V.push_back(t);
    G.V.push_back(u);
    G.V.push_back(v);
    G.V.push_back(w);
    G.V.push_back(x);
    G.V.push_back(y);
    G.V.push_back(z);

    G.Adj[q].push_back(s);
    G.Adj[q].push_back(t);
    G.Adj[q].push_back(w);

    G.Adj[r].push_back(u);
    G.Adj[r].push_back(y);

    G.Adj[s].push_back(v);

    G.Adj[t].push_back(x);
    G.Adj[t].push_back(y);

    G.Adj[u].push_back(y);

    G.Adj[v].push_back(w);

    G.Adj[w].push_back(s);

    G.Adj[x].push_back(z);

    G.Adj[y].push_back(q);

    G.Adj[z].push_back(x);

    cout << "\nPerform DFS(G)\n";
    dfs(G);
  }
}