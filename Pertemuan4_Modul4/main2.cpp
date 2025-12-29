#include "Singlylist.h"

int main() {
    List L;
    address P, Prec;

    createList(L);

    // Soal no 1 (awal)
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    // delete node 9 (deleteFirst)
    deleteFirst(L, P);
    dealokasi(P);

    // delete node 2 (deleteLast)
    deleteLast(L, P);
    dealokasi(P);

    // delete node 8 (deleteAfter)
    Prec = L.first;          // menunjuk ke 12
    deleteAfter(Prec, P);    // hapus setelah 12 → 8
    dealokasi(P);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    // delete seluruh list
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
