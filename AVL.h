//
// Created by ArShAm on 1/20/2021.
//

#ifndef AVL_AVL_H
#define AVL_AVL_H

#include "Node.h"

class AVL {
private:
    Node *tree;

    int getHeight(Node *tree);

    void updateHeightNode(Node *&n);

    Node *rotateRight(Node *&node);

    Node *rotateLeft(Node *&node);

    Node *reBalance(Node *&node);

    Node *addNode(Node *&node, int data);

    Node *deleteNode(Node *&node, int data);

    int getBalance(Node *&node);

    Node *find(Node *&node, int data);

public:
    int getHeight();


//    Node *search(int data);

    void reBalance() {
        tree = reBalance(tree);
    }

    void addNode(int data) {
        tree = addNode(tree, data);
    }

    Node *getTree() const;

    void deleteNode(int data) {
        tree = deleteNode(tree, data);
    }

    Node *find(int data) {
        return find(tree, data);
    }
};

#endif //AVL_AVL_H
