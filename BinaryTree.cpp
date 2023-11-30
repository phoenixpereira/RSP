#include <iostream>
#include <string>
using namespace std;

// Object storing single node, with data and pointers to left and right nodes
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

// Binary search tree
class BinaryTree {
private:
  Node *root;

  // Inserts node into tree recursively
  Node *insert(Node *current, int data) {
    if (current == nullptr) {
      return new Node(data);
    }

    if (data < current->data) {
      current->left = insert(current->left, data);
    } else if (data > current->data) {
      current->right = insert(current->right, data);
    }

    return current;
  }

  // Removes node from tree recursively
  Node *remove(Node *current, int data) {
    if (current == nullptr) {
      return nullptr;
    }

    if (data == current->data) {
      if (current->left == nullptr && current->right == nullptr) {
        delete current;
        return nullptr;
      } else if (current->left == nullptr) {
        Node *temp = current->right;
        delete current;
        return temp;
      } else if (current->right == nullptr) {
        Node *temp = current->left;
        delete current;
        return temp;
      } else {
        Node *parent = current;
        Node *minNode = current->right;
        while (minNode->left != nullptr) {
          parent = minNode;
          minNode = minNode->left;
        }
        current->data = minNode->data;
        if (parent == current) {
          parent->right = minNode->right;
        } else {
          parent->left = minNode->right;
        }
        delete minNode;
      }
    } else if (data < current->data) {
      current->left = remove(current->left, data);
    } else {
      current->right = remove(current->right, data);
    }

    return current;
  }

  // Searches for node with a given value in the tree recursively
  bool search(Node *current, int data) {
    if (current == nullptr) {
      return false;
    }

    if (current->data == data) {
      return true;
    } else if (data < current->data) {
      return search(current->left, data);
    } else {
      return search(current->right, data);
    }
  }

  // Prints the binary tree diagram recursively
  void printTree(Node *node, string indent, bool last) {
    if (node != nullptr) {
      cout << indent;
      if (last) {
        cout << "└╴";
        indent += "  ";
      } else {
        cout << "├╴";
        indent += "│ ";
      }
      cout << node->data << endl;

      printTree(node->left, indent, false);
      printTree(node->right, indent, true);
    }
  }

public:
  BinaryTree() { root = nullptr; }

  void insert(int data) { root = insert(root, data); }
  void remove(int data) { root = remove(root, data); }
  bool search(int data) { return search(root, data); }
  void printTreeDiagram() { printTree(root, "", true); }
};

int main() {
  BinaryTree tree = BinaryTree();

  // Inserting nodes into the tree
  tree.insert(8);
  tree.insert(3);
  tree.insert(1);
  tree.insert(10);
  tree.insert(6);
  tree.insert(14);
  tree.insert(9);

  // Printing the tree diagram
  tree.printTreeDiagram();

  // Search for 8
  int searchValue = 8;
  if (tree.search(8)) {
    cout << "Value " << searchValue << " found in tree." << endl;
  } else {
    cout << "Value " << searchValue << " not found in tree." << endl;
  }

  // Search for 0
  searchValue = 0;
  if (tree.search(searchValue)) {
    cout << "Value " << searchValue << " found in tree." << endl;
  } else {
    cout << "Value " << searchValue << " not found in tree." << endl;
  }

  // Deleting nodes from the tree
  tree.remove(10);
  tree.remove(1);
  tree.printTreeDiagram();
}
