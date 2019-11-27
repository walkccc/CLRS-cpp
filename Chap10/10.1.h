#ifndef ch10_1_h
#define ch10_1_h

#include "Queue.h"
#include "Stack.h"

// [Page 233]
//   STACK-EMPTY(S)
//   - Time: O(1)
//
//   PUSH(S, x)
//   - Time: O(1)
//
//   POP(S)
//   - Time: O(1)
//
// [Page 235]
//   ENQUEUE(Q, x)
//   - Time: O(1)
//
//   DEQUEUE(Q)
//   - Time: O(1)

namespace CLRS {
namespace CH10 {
template <typename T>
bool stackEmpty(Stack<T>& S) {
  if (S.top == 0)
    return true;
  else
    return false;
}

template <typename T>
void push(Stack<T>& S, T x) {
  S.top++;
  S[S.top] = x;
}

template <typename T>
T pop(Stack<T>& S) {
  if (stackEmpty(S)) {
    throw("underflow");
  } else {
    S.top--;
    return S[S.top + 1];
  }
}

template <typename T>
void enqueue(Queue<T>& Q, T x) {
  Q[Q.tail] = x;
  if (Q.tail == Q.size() - 1)
    Q.tail = 0;
  else
    Q.tail++;
}

template <typename T>
T dequeue(Queue<T>& Q) {
  int x = Q[Q.head];
  if (Q.head == Q.size() - 1)
    Q.head = 1;
  else
    Q.head++;
  return x;
}
}  // namespace CH10
}  // namespace CLRS

#endif