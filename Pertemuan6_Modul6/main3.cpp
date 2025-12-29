#include "Doublylist.h"

int main() {
    List L;
    kendaraan k;
    address P, Prec, target;
    string hapus;

    // buat list
    CreateList(L);

    // isi data awal
    k.nopol = "D001";
    k.warna = "hitam";
    k.thnBuat = 90;
    insertLast(L, alokasi(k));

    k.nopol = "D003";
    k.warna = "putih";
    k.thnBuat = 70;
    insertLast(L, alokasi(k));

    k.nopol = "D004";
    k.warna = "kuning";
    k.thnBuat = 90;
    insertLast(L, alokasi(k));

    // hapus data
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapus;

    target = findElm(L, hapus);

    if (target != NULL) {
        if (target == L.First) {
            deleteFirst(L, P);
        } else if (target == L.Last) {
            deleteLast(L, P);
        } else {
            Prec = target->prev;
            deleteAfter(Prec, P);
        }

        dealokasi(P);
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus.\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    cout << "\nDATA LIST 1\n";
    printInfo(L);

    return 0;
}
