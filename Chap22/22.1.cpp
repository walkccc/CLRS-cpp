#include "22.1.h"
#include "../print.h"

using namespace CLRS::CH22;

void print(vector<List<int>>& adj) {
  for (int i = 0; i < adj.size(); i++) {
    cout << i << " ";
    print(adj[i]);
  }
}

int main() {
  print(string("22.1 Representations of graphs"));

  cout << "Initialize an adjacency list as Figure 22.2\n";
  cout << "(Note that the indices are all -1)\n";
  vector<List<int>> adj(6);
  listInsert(adj[0], new Node<int>(3));
  listInsert(adj[0], new Node<int>(1));
  listInsert(adj[1], new Node<int>(4));
  listInsert(adj[2], new Node<int>(4));
  listInsert(adj[2], new Node<int>(5));
  listInsert(adj[3], new Node<int>(1));
  listInsert(adj[4], new Node<int>(3));
  listInsert(adj[5], new Node<int>(5));
  print(adj);

  print(string("22.1-3"));

  vector<List<int>> adj_ = transpose(adj);
  print(adj_);

  print(string("22.1-4"));

  adj_ = equivalentUndirectedGraph(adj);
  print(adj_);
}