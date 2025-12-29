# <h1 align="center">Laporan Praktikum Modul 6 -  DOUBLYLINKEDLIST(BAGIANPERTAMA)</h1>
<p align="center">Anisa Keyza Husnul Khatimah - 2211102210</p>

## Dasar Teori
Doubly Linked list adalah linked list yang masing–masing elemennya memiliki 2 successor, yaitu
successor yang menunjuk pada elemen sebelumnya (prev) dan successor yang menunjuk pada elemen
sesudahnya(next)

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. ...

```C++
source code guided 1
```
### 2. ...

```C++
source code guided 2
```

### 3. ...

```C++
```

## Unguided 
### 1. (Buatlah implementasi ADTDoubly Linked list pada file “Doublylist.cpp” dan coba hasil implementasiADTpadafile“main.cpp”)

```C++
source code unguided 1
File Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

// infotype
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

// node
struct ElmList {
    infotype info;
    ElmList* next;
    ElmList* prev;
};

typedef ElmList* address;

// list
struct List {
    address First;
    address Last;
};

// ADT
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
bool cekNopol(List L, string nopol);

#endif


File Doublylist.cpp
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last  = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

bool cekNopol(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last;   // cetak dari belakang (sesuai contoh)
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}


File main.cpp
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

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan6_Modul6/Output/Output-Unguided1.png)

##### Output 2

Penjelasan Program:
Program tersebut mengimplementasikan ADT Doubly Linked List dalam bahasa C++ untuk menyimpan data kendaraan yang terdiri dari nomor polisi, warna, dan tahun pembuatan. Pada file `Doublylist.h` didefinisikan struktur data `kendaraan` sebagai infotype, node `ElmList` yang memiliki pointer `next` dan `prev`, serta struktur `List` yang menyimpan alamat elemen pertama (`First`) dan terakhir (`Last`). File `Doublylist.cpp` berisi implementasi fungsi-fungsi dasar seperti pembuatan list, alokasi dan dealokasi node, pengecekan nomor polisi agar tidak terjadi duplikasi, penambahan data di akhir list (`insertLast`), serta penampilan isi list.

Pada `main.cpp`, program meminta pengguna memasukkan beberapa data kendaraan dan menyimpannya ke dalam doubly linked list. Sebelum menambahkan data tertentu, program memeriksa apakah nomor polisi sudah terdaftar menggunakan fungsi `cekNopol`. Setelah seluruh data dimasukkan, isi list ditampilkan menggunakan fungsi `printInfo`, yang mencetak data dari elemen terakhir ke elemen pertama dengan memanfaatkan pointer `prev`. Program ini menunjukkan bagaimana doubly linked list dapat digunakan untuk mengelola data secara dinamis dengan navigasi dua arah.


### 2. (Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address)

```C++
source code unguided 2
File Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

// infotype
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

// node
struct ElmList {
    infotype info;
    ElmList* next;
    ElmList* prev;
};

typedef ElmList* address;

// list
struct List {
    address First;
    address Last;
};

// ADT
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
bool cekNopol(List L, string nopol);
address findElm(List L, string nopol);

#endif

File Doublylist.cpp
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last  = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

bool cekNopol(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last;   // cetak dari belakang (sesuai contoh)
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;   // data ditemukan
        }
        P = P->next;
    }
    return NULL;        // data tidak ditemukan
}

File main2.cpp
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

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan6_Modul6/Output/Output-Unguided2.png)

##### Output 2

Penjelasan Program:
Fungsi `findElm` digunakan untuk mencari data kendaraan pada doubly linked list berdasarkan nomor polisi. Fungsi ini menelusuri list dari elemen pertama hingga terakhir dengan membandingkan nomor polisi pada setiap node. Jika data ditemukan, fungsi mengembalikan alamat node yang sesuai, sedangkan jika tidak ditemukan maka mengembalikan `NULL` sebagai penanda bahwa data tidak ada di dalam list.


### 3. (Hapus elemen dengan nomor polisi D003 dengan procedure delete.
procedure deleteFirst( input/output L : List,
P : address )--
procedure deleteLast( input/output L : List,
P : address )
procedure deleteAfter( input Prec : address,
input/output P : address ))

```C++
source code unguided 3
File Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

// infotype
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

// node
struct ElmList {
    infotype info;
    ElmList* next;
    ElmList* prev;
};

typedef ElmList* address;

// list
struct List {
    address First;
    address Last;
};

// ADT
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
bool cekNopol(List L, string nopol);
address findElm(List L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif

File Doublylist.cpp
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last  = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

bool cekNopol(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last;   // cetak dari belakang (sesuai contoh)
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;   // data ditemukan
        }
        P = P->next;
    }
    return NULL;        // data tidak ditemukan
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (L.First == L.Last) {
        L.First = NULL;
        L.Last = NULL;
    } else {
        L.First = P->next;
        L.First->prev = NULL;
    }
    P->next = NULL;
    P->prev = NULL;
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (L.First == L.Last) {
        L.First = NULL;
        L.Last = NULL;
    } else {
        L.Last = P->prev;
        L.Last->next = NULL;
    }
    P->next = NULL;
    P->prev = NULL;
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != NULL) {
        P->next->prev = Prec;
    }
    P->next = NULL;
    P->prev = NULL;
}

File main3.cpp
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

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan6_Modul6/Output/Output-Unguided3.png)

##### Output 2

Penjelasan Program
Penghapusan elemen dengan nomor polisi D003 diawali dengan mencari node menggunakan fungsi `findElm`. Setelah node ditemukan, posisinya ditentukan. Jika node berada di awal list digunakan `deleteFirst`, jika di akhir digunakan `deleteLast`, dan jika berada di tengah list (seperti D003) digunakan `deleteAfter` dengan node sebelumnya sebagai `Prec`. Setelah node dilepas dari list, memori dibebaskan menggunakan `dealokasi` agar struktur doubly linked list tetap konsisten.


## Kesimpulan
Praktikum Doubly Linked List berhasil menunjukkan penggunaan struktur data dinamis dengan dua pointer (`next` dan `prev`) yang memungkinkan penelusuran dan pengelolaan data secara lebih fleksibel. Melalui implementasi operasi penambahan, pencarian, dan penghapusan elemen, praktikum ini melatih pemahaman konsep pointer, manajemen memori, serta menjadi dasar penting dalam mempelajari struktur data lanjutan.


## Referensi
//