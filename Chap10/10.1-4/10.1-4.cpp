#include "10.1-4.h"

#include "../../print.h"

using namespace CLRS::CH10;

void printQueue(Queue<int>& Q) {
  print(Q);
  cout << "Q.head = " << Q.head << endl;
  cout << "Q.tail = " << Q.tail << endl;
}

int main() {
  print(string("10.1-4"));

  cout << "Initialize a queue Q[1..5]\n";
  Queue<int> Q = {0, 0, 0, 1, 0};
  Q.setHead();
  Q.setTail();
  printQueue(Q);

  cout << "\nPerform ENQUEUE(Q, 1)\n";
  enqueue(Q, 1);
  printQueue(Q);

  cout << "\nPerform ENQUEUE(Q, 2)\n";
  enqueue(Q, 2);
  printQueue(Q);

  cout << "\nPerform ENQUEUE(Q, 5)\n";
  enqueue(Q, 5);
  printQueue(Q);

  cout << "\nPerform DEQUEUE(Q)\n";
  dequeue(Q);
  printQueue(Q);

  cout << "\nPerform DEQUEUE(Q)\n";
  dequeue(Q);
  printQueue(Q);

  cout << "\nPerform DEQUEUE(Q)\n";
  dequeue(Q);
  printQueue(Q);
}
