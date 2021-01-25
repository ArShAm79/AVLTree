#include <iostream>
#include "AVL.h"

using namespace std;

void printBT(const std::string &prefix, const Node *node, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "(--");

        std::cout << node->data << std::endl;

        printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void printBT(const Node *node) {
    printBT("", node, false);
}

int fac(int num) {
    int ans = 0;
    int pow = 1;
    for (int i = 1; i <= num; ++i) {
        pow = pow * i;
        ans += pow;
    }
    return ans;
}

int main() {
//    AVL avl = *new AVL();
//    for (int i = 0; i < 10; ++i) {
//        avl.addNode(i);
//    }
//    printBT(avl.getTree());
    cout<<fac(10);
    return 0;
}
