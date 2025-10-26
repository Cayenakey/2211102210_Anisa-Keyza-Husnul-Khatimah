#include "ListAngka.h"

int main() {
    linkedList L;
    createList(L);

    // Alokasi node
    address nodeA = alokasi(8);
    address nodeB = alokasi(13);
    address nodeC = alokasi(18);
    address nodeD = alokasi(25);
    address nodeE = alokasi(33);
    address nodeF = alokasi(40);

    // Operasi sesuai urutan soal
    insertFirst(L, nodeB);         
    insertLast(L, nodeA);           
    insertAfter(L, nodeD, nodeB);    
    insertFirst(L, nodeC);           
    insertLast(L, nodeE);         
    insertFirst(L, nodeF);          

    address nodeHapus = NULL;
    delAfter(L, nodeHapus, nodeC);  

    // Output akhir
    printList(L); 

    return 0;
}
