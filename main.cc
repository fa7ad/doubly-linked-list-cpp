// Task20180719-1
#include <iostream>
#include "doublylinkedlist.hh"

using namespace std;

int main() {
  int n, m;
  cin >> n;
  DoublyLinkedList list;
  for(int i = 0; i < n; i++){
    cin >> m;
    list.insertAtEnd(m);
  }

  list.print();
  list.deleteByValue(40);
  list.print();
  list.rprint();

  return 0;
}
