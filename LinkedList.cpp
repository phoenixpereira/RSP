#include <iostream>
using namespace std;

// Object storing single node, with data and pointer to next node
struct Node {
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

// Singly linked list
class LinkedList {
public:
  Node *head, *tail;

  LinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  // Insert new node at end of list
  void insert(int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      this->tail->next = newNode;
      this->tail = newNode;
    }
  }

  // Delete node with given data from list
  void remove(int data) {
    if (head == nullptr) {
      cout << "Linked list is empty, nothing to delete";
      return;
    } else {
      for (Node *curr = head; curr != nullptr; curr = curr->next) {
        if (curr->next->data == data) {
          curr->next = curr->next->next;
          return;
        }
      }
    }
    return;
  }

  // Display all nodes in list
  void display() {
    for (Node *curr = head; curr != nullptr; curr = curr->next) {
      cout << curr->data << " ";
    }
    cout << endl;
  }
};

// Main function
int main(void) {
  LinkedList *list = new LinkedList();
  list->remove(1);
  list->display();

  list->insert(1);
  list->insert(2);
  list->insert(3);
  list->insert(4);
  list->insert(5);
  list->display();

  list->remove(3);
  list->display();
}