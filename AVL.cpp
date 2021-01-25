//
// Created by ArShAm on 1/20/2021.
//

#include "AVL.h"
#include <cmath>
#include <stdexcept>

using namespace std;

int AVL::getHeight(Node *node) {
    if (node == nullptr)
        return 0;
    else
        return 1 + max(getHeight(node->left), getHeight(node->right));
}

int AVL::getHeight() {
    return getHeight(tree);
}


void AVL::updateHeightNode(Node *&node) {
    node->height = (short) (max(getHeight(node->left), getHeight(node->right)) + 1);


}

Node *AVL::rotateRight(Node *&node) {
    Node *left = node->left;
    Node *right = left->right;
    left->right = node;
    node->left = right;
    updateHeightNode(node);
    updateHeightNode(left);
    return left;
}

Node *AVL::rotateLeft(Node *&node) {
    Node *right = node->right;
    Node *left = right->left;
    right->left = node;
    node->right = left;
    updateHeightNode(node);
    updateHeightNode(right);
    return right;
}

Node *AVL::reBalance(Node *&node) {
    updateHeightNode(node);
    int bal = getBalance(node);
    if (bal > 1) {
        if (getHeight(node->right->right) > getHeight(node->right->left)) {
            node = rotateLeft(node);
        } else {
            node->right = rotateRight(node->right);
            node = rotateLeft(node);
        }
    } else if (bal < -1) {
        if (getHeight(node->left->left) > getHeight(node->left->right))
            node = rotateRight(node);
        else {
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        }
    }
    return node;
}

Node *AVL::addNode(Node *&node, int data) {
    if (node == nullptr) {
        Node *temp = new Node();
        temp->data = data;
        return temp;
    } else if (node->data > data) {
        node->left = addNode(node->left, data);
    } else if (node->data <= data) {
        node->right = addNode(node->right, data);
    }
    return reBalance(node);
}

Node *AVL::deleteNode(Node *&node, int data) {
    if (node == nullptr) {
        return nullptr;
    } else if (node->data < data) {
        node->right = deleteNode(node->right, data);
    } else if (node->data > data) {
        node->left = deleteNode(node->left, data);
    } else {
        if (node->left == nullptr || node->right == nullptr) {
            node = (node->left == nullptr) ? node->right : node->left;
        } else {
            Node *mostLeftChild = node->right;
            node->data = mostLeftChild->data;
            node->right = deleteNode(node->right, node->data);
        }
    }
    if (node != nullptr) {
        node = reBalance(node);
    }
    return node;
}

//Node *AVL::search(int key) {
//    Node *node = tree;
//    while (node != nullptr) {
//        if (node->data == key) {
//            break;
//        }
//        node = node->data < key ? node->right : node->left;
//    }
//    return node;
//}

Node *AVL::getTree() const {
    return tree;
}

int AVL::getBalance(Node *&n) {
    return (n == nullptr) ? 0 : getHeight(n->right) - getHeight(n->left);

}

Node *AVL::find(Node *&node, int data) {
    if (node != nullptr) {
        if (node->data == data)
            return node;
        else if (node->data < data)
            return find(node->right, data);
        else
            return find(node->left, data);
    } else
        return nullptr;
}

