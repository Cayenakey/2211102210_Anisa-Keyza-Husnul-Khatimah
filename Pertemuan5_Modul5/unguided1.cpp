#include "ListAngka.h"

int main() {
    linkedList L;
    createList(L);

    address nodeA = alokasi(8);
    address nodeB = alokasi(13);
    address nodeC = alokasi(18);
    address nodeD = alokasi(25);
    address nodeE = alokasi(33);
    address nodeF = alokasi(40);
    address nodeHapus = NULL;

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);
    delAfter(L, nodeHapus, nodeC);

    printList(L);
    cout << endl;

    updateFirst(L);
    updateAfter(L, nodeD);
    updateLast(L);
    updateAfter(L, L.first);

    printList(L);

    return 0;
}
