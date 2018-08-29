#ifndef NODE_HH
#define NODE_HH

struct Node {
  int val;
  Node *next, *prev;
  Node (int v, Node* n, Node *p = nullptr) {
    val = v;
    next = n;
    prev = p;
  }
};
#endif // NODE_HH
