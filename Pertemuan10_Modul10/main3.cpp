#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = Nil;

    // Insert data ke BST
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); // duplikat, diabaikan
    insertNode(root, 7);

    // InOrder
    cout << "Inorder : ";
    printInorder(root);
    cout << endl;

    // PreOrder
    cout << "Preorder : ";
    printPreorder(root);
    cout << endl;

    // PostOrder
    cout << "Postorder : ";
    printPostorder(root);
    cout << endl;

    return 0;
}
