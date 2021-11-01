#include <iostream>
#include <string>
#include "node.h"

// Generic BST
template <class T>

// The root node of the tree and definitions
struct BST {
    Node<T> *root;
    BST();

    void UpdateNode(Node<T> *root, T *data, T *replace);
    Node<T> *RemoveNode(Node<T> *rt, T *data);
    void InsertNode (T *data);
    void inOrder(Node<T> *n);
    void preOrder(Node<T> *n);
    void postOrder(Node<T> *n);
};
