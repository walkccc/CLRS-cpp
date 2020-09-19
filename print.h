#ifndef print_h
#define print_h

#include <iostream>
#include <vector>

#include "./Chap06/Heap.h"
#include "./Chap10/List.h"
#include "./Chap10/Queue.h"
#include "./Chap10/Stack.h"

using namespace std;

void print(int val) { cout << val << " "; }

void print(string str) {
  for (int i = 0; i < str.length() + 2; i++) cout << "-";
  cout << "\n " << str << " \n";
  for (int i = 0; i < str.length() + 2; i++) cout << "-";
  cout << endl;
}

template <typename T>
void print(vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}

template <typename T>
void print(Heap<T>& A) {
  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}

template <typename T>
void print(Queue<T>& Q) {
  for (int i = 0; i < Q.size(); i++) {
    cout << Q[i] << " ";
  }
  cout << "\n";
}

template <typename T>
void print(Stack<T>& S) {
  for (int i = 0; i < S.size(); i++) {
    cout << S[i] << " ";
  }
  cout << "\n";
}

template <typename T>
void print(List<T>& L) {
  for (ListNode<T>* curr = L.head; curr; curr = curr->next) {
    cout << curr->key << " ";
  }
  cout << "\n";
}

template <typename T>
void print(List_<T>& L) {
  for (ListNode<T>* curr = L.nil->next; curr != L.nil; curr = curr->next) {
    cout << curr->key << " ";
  }
  cout << "\n";
}

template <typename T>
void print(vector<vector<T>>& vec) {
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec[0].size(); j++) {
      cout << vec[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

#endif