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

    // Update nilai sesuai hasil akhir Unguided 1
    nodeF->angka = 50;
    nodeC->next->angka = 20;
    nodeD->next->angka = 29;
    nodeE->angka = 45;

    cout << "Total penjumlahan : " << sumList(L) << endl;
    cout << "Total pengurangan : " << subList(L) << endl;
    cout << "Total perkalian : " << mulList(L) << endl;

    return 0;
}
