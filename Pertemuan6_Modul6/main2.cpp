#include "Doublylist.h"

int main() {
    List L;
    kendaraan k;
    address P, hasil;
    string cari;

    // buat list
    CreateList(L);

    // isi data (contoh)
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

    // pencarian
    cout << "\nMasukkan Nomor Polisi yang dicari : ";
    cin >> cari;

    hasil = findElm(L, cari);

    if (hasil != NULL) {
        cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}
