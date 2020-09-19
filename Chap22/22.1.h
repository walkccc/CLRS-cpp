#ifndef ch22_1_h
#define ch22_1_h

#include "../Chap10/10.2.h"
#include "../print.h"

using namespace CLRS::CH10;

// [Page 592][22.1-3]
//   TRANSPOSE(Adj)
//   - Time: O(|V| + |E|)
//
// [Page 593][22.1-4]
//   EQUIVALENT-UNDIRECTED-GRAPH(Adj)
//   - Time: O(|V| + |E|)

namespace CLRS {
namespace CH22 {
template <typename T>
vector<List<T>> transpose(vector<List<T>>& adj) {
  vector<List<T>> adj_(adj.size());

  for (int u = 0; u < adj.size(); u++)
    for (ListNode<T>* v = adj[u].head; v; v = v->next)
      listInsert(adj_[v->key], new ListNode<T>(u));

  return adj_;
}

template <typename T>
vector<List<T>> equivalentUndirectedGraph(vector<List<T>>& adj) {
  const int n = adj.size();

  vector<List<T>> adj_(n);
  vector<vector<bool>> M(n, vector<bool>(n));

  for (int u = 0; u < n; u++)
    for (ListNode<T>* v = adj[u].head; v; v = v->next)
      if (!M[u][v->key] && u != v->key) {
        M[u][v->key] = true;
        listInsert(adj_[u], new ListNode<T>(v->key));
      }

  return adj_;
}
}  // namespace CH22
}  // namespace CLRS

#endif