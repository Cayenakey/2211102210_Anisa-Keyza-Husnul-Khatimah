# <h1 align="center">Laporan Praktikum Modul 4 - SINGLYLIST</h1>
<p align="center">Anisa Keyza Husnul Khatimah - 2211102210</p>

## Dasar Teori
//

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

### 1. (Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”, Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp” Kemudian buat program utama didalam file “main.cpp” dengan implementasi, Output yang diharapkan : 9 12 8 0 2)

```C++
source code unguided 1
File Singlylist.h

#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;

struct List {
    address first;
};

// PROTOTYPE
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif

File Singlylist.cpp

#include "Singlylist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

File  main.pp
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan4_Modul4/Output/Output-Unguided1.png)

##### Output 2

Penjelasan Program:
Program di atas mengimplementasikan ADT Singly Linked List menggunakan bahasa C++ yang dipisahkan ke dalam tiga file, yaitu Singlylist.h sebagai header, Singlylist.cpp sebagai file implementasi, dan main.cpp sebagai program utama. Pada file header didefinisikan tipe data ElmList sebagai node yang berisi data (info) dan pointer ke node berikutnya (next), serta struktur List yang menyimpan pointer ke elemen pertama. Selain itu, header juga berisi prototype fungsi dasar seperti createList, alokasi, insertFirst, dan printInfo agar dapat digunakan di file lain.

Pada file implementasi, fungsi-fungsi tersebut direalisasikan untuk membentuk dan mengelola linked list. Fungsi createList menginisialisasi list kosong, alokasi membuat node baru, dan insertFirst menambahkan node di awal list sehingga elemen terakhir yang dimasukkan akan berada di posisi paling depan. Pada main.cpp, program membuat beberapa node dengan nilai 2, 0, 8, 12, dan 9 lalu memasukkannya ke dalam list menggunakan insertFirst. Hasil akhirnya ditampilkan dengan printInfo, sehingga urutan data yang tercetak mencerminkan sifat LIFO (Last In First Out) pada operasi penambahan di awal linked list.

### 2. (Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().)

```C++
source code unguided 2
File Singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;

struct List {
    address first;
};

// BASIC
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

// DELETE & COUNT
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif


File Singlylist.cpp
#include "Singlylist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

/* ================= DELETE ================= */

void deleteFirst(List &L, address &P) {
    P = L.first;
    L.first = P->next;
    P->next = NULL;
}

void deleteLast(List &L, address &P) {
    address Q;
    if (L.first->next == NULL) {
        P = L.first;
        L.first = NULL;
    } else {
        Q = L.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = NULL;
    }
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

/* ================= COUNT & DELETE ALL ================= */

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.first != NULL) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}


File main2.cpp
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

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan4_Modul4/Output/Output-Unguided2.png)

##### Output 2

Penjelasan Program
Program tersebut merupakan implementasi **ADT Singly Linked List** dalam bahasa C++ yang dibagi ke dalam tiga file, yaitu `Singlylist.h`, `Singlylist.cpp`, dan `main2.cpp`. Pada file header didefinisikan struktur node `ElmList` yang menyimpan data (`info`) dan pointer ke node berikutnya (`next`), serta struktur `List` yang menyimpan alamat node pertama. Selain itu, disediakan prototype fungsi dasar untuk membuat list, menambah elemen di awal, menampilkan isi list, serta fungsi penghapusan dan perhitungan jumlah node agar dapat digunakan secara modular pada file lain.

Pada file implementasi, seluruh fungsi direalisasikan untuk mengelola operasi linked list, seperti penghapusan node pertama (`deleteFirst`), node terakhir (`deleteLast`), node setelah elemen tertentu (`deleteAfter`), menghitung jumlah node (`nbList`), dan menghapus seluruh isi list (`deleteList`). Pada `main2.cpp`, program membentuk linked list awal dengan beberapa data, kemudian melakukan penghapusan node sesuai instruksi soal, yaitu menghapus nilai 9, 2, dan 8. Setelah itu, program menampilkan sisa elemen beserta jumlah node yang tersimpan, lalu menghapus seluruh node dan menampilkan kembali jumlah node untuk memastikan bahwa list telah kosong.

## Kesimpulan
Pada praktikum Modul Singly Linked List ini, mahasiswa telah berhasil memahami dan mengimplementasikan konsep dasar struktur data linked list menggunakan bahasa pemrograman C++. Melalui pembuatan ADT (Abstract Data Type) yang dipisahkan ke dalam file header dan file implementasi, praktikum ini melatih pemahaman tentang struktur data dinamis, penggunaan pointer, serta prinsip modularitas program. Operasi dasar seperti pembuatan list, penambahan data, penampilan isi list, hingga penghapusan node pada posisi tertentu dapat dijalankan dengan baik sesuai dengan algoritma yang telah dirancang.

## Referensi
//