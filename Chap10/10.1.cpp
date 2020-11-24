#include "10.1.h"

#include "../print.h"

using namespace CLRS::CH10;

int main() {
  print(string("Chapter 10.1 Stacks and queues"));

  cout << "Initialize a stack S as Figure 10.1\n";
  Stack<int> S = {15, 6, 2, 9};
  S.setTop();
  print(S);

  cout << "\nPerform PUSH(S, 17) and PUSH(S, 3)\n";
  push(S, 17);
  push(S, 3);
  print(S);

  cout << "\nPerform POP(S)\n";
  cout << pop(S) << endl;

  cout << "\nInitialize a queue Q[1..12] as Figure 10.2\n";
  Queue<int> Q = {0, 0, 0, 0, 0, 0, 15, 6, 9, 8, 4, 0};
  Q.setHead();
  Q.setTail();
  print(Q);

  cout << "\nPerform ENQUEUE(Q, 17)\n";
  enqueue(Q, 17);
  print(Q);

  cout << "\nPerform ENQUEUE(Q, 3)\n";
  enqueue(Q, 3);
  print(Q);

  cout << "\nPerform ENQUEUE(Q, 5)\n";
  enqueue(Q, 5);
  print(Q);

  cout << "\nPerform DEQUEUE(Q)\n";
  dequeue(Q);
  cout << "Q.head = " << Q.head << endl;
  cout << "Q.tail = " << Q.tail << endl;
}
