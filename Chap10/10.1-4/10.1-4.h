#include "../Queue.h"

// [Page 235][10.1-4]
//   QUEUE-EMPTY(Q)
//   - Time: O(1)
//
//   QUEUE-FULL(Q)
//   - Time: O(1)
//
//   ENQUEUE(Q, x)
//   - Time: O(1)
//
//   DEQUEUE(Q)
//   - Time: O(1)

namespace CLRS {
namespace CH10 {
template <typename T>
bool queueEmpty(Queue<T>& Q) {
  if (Q.head == Q.tail)
    return true;
  else
    return false;
}

template <typename T>
bool queueFull(Queue<T>& Q) {
  if (Q.head == Q.tail + 1 or (Q.head == 0 and Q.tail == Q.size() - 1))
    return true;
  else
    return false;
}

template <typename T>
void enqueue(Queue<T>& Q, T x) {
  if (queueFull(Q)) {
    throw "overflow";
  } else {
    Q[Q.tail] = x;
    Q.tail = (Q.tail + 1) % Q.size();
  }
}

template <typename T>
T dequeue(Queue<T>& Q) {
  if (queueEmpty(Q)) {
    throw "underflow";
  } else {
    T x = Q[Q.head];
    Q.head = (Q.head + 1) % Q.size();
    return x;
  }
}
}  // namespace CH10
}  // namespace CLRS
