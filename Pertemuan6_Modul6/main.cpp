#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    kendaraan k;
    address P;

    // Data 1
    cout << "masukkan nomor polisi: ";
    cin >> k.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> k.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> k.thnBuat;

    P = alokasi(k);
    insertLast(L, P);

    // Data 2
    cout << "\nmasukkan nomor polisi: ";
    cin >> k.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> k.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> k.thnBuat;

    P = alokasi(k);
    insertLast(L, P);

    // Data 3 (duplikat nopol)
    cout << "\nmasukkan nomor polisi: ";
    cin >> k.nopol;

    if (cekNopol(L, k.nopol)) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        cout << "masukkan warna kendaraan: ";
        cin >> k.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> k.thnBuat;
        P = alokasi(k);
        insertLast(L, P);
    }

    // Data 4
    cout << "\nmasukkan nomor polisi: ";
    cin >> k.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> k.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> k.thnBuat;

    P = alokasi(k);
    insertLast(L, P);

    cout << "\nDATA LIST 1\n";
    printInfo(L);

    return 0;
}
