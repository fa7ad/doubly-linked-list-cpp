#ifndef DOUBLYLINKEDLIST_HH
#define DOUBLYLINKEDLIST_HH

#include "node.hh"
#include <iostream>
using namespace std;

struct DoublyLinkedList {
  Node* head;
  DoublyLinkedList () {
    head = nullptr;
  }
  Node* search (int key) {
    Node* it = head;
    while(it != nullptr) {
      if (it->val == key) {
        return it;
      } else {
        it = it->next;
      }
    }
    return nullptr;
  }
  bool insertAfterPosition(int i, int val) {
    Node* it = head;
    int p = 0;
    while(it != nullptr) {
      p++;
      if (p == i) {
        Node* temp = new Node(val, it->next, it);
        it->next = temp;
        return true;
      } else {
        it = it->next;
      }
    }
    return false;
  }
  bool insertAfterValue(int key, int val){
    Node* it = search(key);
    if (it == nullptr)
      return false;
    else {
      Node* temp = new Node(val, it->next, it);
      it->next = temp;
      return true;
    }
  }
  void insertAtHead(int val) {
    Node* temp = new Node(val, head, nullptr);
    head = temp;
  }
  void insertAtEnd(int val) {
    Node* it = head;
    if(it == nullptr){
      insertAtHead(val);
      return;
    }
    while(it->next != nullptr)
      it = it->next;
    Node* temp = new Node (val, nullptr, it);
    it->next = temp;
  }
  bool deleteAtHead() {
    Node *it = head;
    if(it == nullptr)
      return false;
    head = it->next;
    delete head;
    return true;
  }
  bool deleteByValue(int val) {
    Node *it = head;
    while(it != nullptr) {
      if (it->val == val){
        it->prev->next = it->next;
        return true;
      } else {
        it = it->next;
      }
    }
    return false;
  }
  bool deleteByPosition(int idx) {
    Node* it = head;
    int i = 0;
    while(it != nullptr) {
      if (idx == ++i){
        it->prev->next = it->next;
        return true;
      } else {
        it = it->next;
      }
    }
    return false;
  }
  void print () {
    Node* it = head;
    while(it != nullptr) {
      cout << it->val << " ";
      it = it->next;
    }
    cout << endl;
  }
  void rprint () {
    Node* it = head;
    while(it->next != nullptr)
      it = it->next;
    while(it != nullptr) {
      cout << it->val << " ";
      it = it->prev;
    }
    cout << endl;
  }
};

#endif // DOUBLYLINKEDLIST_HH
