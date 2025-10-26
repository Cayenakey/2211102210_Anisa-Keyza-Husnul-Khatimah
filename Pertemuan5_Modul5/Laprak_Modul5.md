# <h1 align="center">Laporan Praktikum Modul 5 - ADT Singly Linked list </h1>
<p align="center">Anisa Keyza Husnul Khatimah - 2211102210</p>

## Dasar Teori
ADT Singly Linked List (Abstract Data Type Singly Linked List) adalah struktur data dinamis yang terdiri dari kumpulan elemen yang disebut node, di mana setiap node menyimpan data dan pointer (penunjuk) ke node berikutnya dalam daftar[1].

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

### ADT Singly Linked list (Buatlah ADT Singly Linked list sebagai berikut:)
```C++
source code ListAngka.h
#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

// TYPE DEFINITION
typedef int dataAngka;

struct node {
    dataAngka angka;
    node* next;
};

typedef node* address;

struct linkedList {
    address first;
};

// FUNCTION & PROCEDURE DECLARATIONS
// Dasar Linked List
void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &p);
void printList(linkedList L);
void insertFirst(linkedList &L, address p);
void insertLast(linkedList &L, address p);
void insertAfter(linkedList &L, address p, address prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &pHapus, address prec);

// Update
void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address prec);

// Search
void SearchByData(linkedList L, int data);
void SearchByAddress(linkedList L, address nodeCari);
void SearchByRange(linkedList L, int nilaiMin);

// Aritmetika
int sumList(linkedList L);
int subList(linkedList L);
int mulList(linkedList L);

#endif
```
```C++
source code ListAngka.cpp
#include "ListAngka.h"

// DASAR LINKED LIST
void createList(linkedList &L) {
    L.first = NULL;
}

address alokasi(dataAngka x) {
    address p = new node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = NULL;
}

void printList(linkedList L) {
    address p = L.first;
    while (p != NULL) {
        cout << p->angka;
        if (p->next != NULL) cout << " - ";
        p = p->next;
    }
    cout << " -" << endl;
}

void insertFirst(linkedList &L, address p) {
    p->next = L.first;
    L.first = p;
}

void insertLast(linkedList &L, address p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        address last = L.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    }
}

void insertAfter(linkedList &L, address p, address prec) {
    if (prec != NULL) {
        p->next = prec->next;
        prec->next = p;
    }
}

int nbList(linkedList L) {
    int count = 0;
    address p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void delAfter(linkedList &L, address &pHapus, address prec) {
    if (prec != NULL && prec->next != NULL) {
        pHapus = prec->next;
        prec->next = pHapus->next;
        pHapus->next = NULL;
    }
}

// UPDATE FUNCTIONS
void updateFirst(linkedList &L) {
    if (L.first != NULL) {
        cout << "Masukkan update data node pertama: " << endl;
        cout << "Masukkan angka : ";
        cin >> L.first->angka;
        cout << "Data berhasil diupdate!" << endl << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.first == NULL) return;
    address last = L.first;
    while (last->next != NULL) last = last->next;

    cout << "Masukkan update data node terakhir: " << endl;
    cout << "Masukkan angka : ";
    cin >> last->angka;
    cout << "Data berhasil diupdate!" << endl << endl;
}

void updateAfter(linkedList &L, address prec) {
    if (prec != NULL && prec->next != NULL) {
        cout << "Masukkan update data node setelah node " << prec->angka << " : " << endl;
        cout << "Masukkan angka : ";
        cin >> prec->next->angka;
        cout << "Data berhasil diupdate!" << endl << endl;
    }
}

// SEARCH FUNCTIONS
void SearchByData(linkedList L, int data) {
    address p = L.first;
    int pos = 1;
    bool found = false;
    while (p != NULL) {
        if (p->angka == data) {
            cout << "Data " << data << " ditemukan pada posisi ke-" << pos << "!" << endl;
            found = true;
            break;
        }
        p = p->next;
        pos++;
    }
    if (!found)
        cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
    cout << endl;
}

void SearchByAddress(linkedList L, address nodeCari) {
    address p = L.first;
    int pos = 1;
    bool found = false;
    while (p != NULL) {
        if (p == nodeCari) {
            cout << "Node ditemukan pada posisi ke-" << pos << "!" << endl;
            cout << "Alamat node : " << p << endl;
            found = true;
            break;
        }
        p = p->next;
        pos++;
    }
    if (!found)
        cout << "Node dengan alamat " << nodeCari << " tidak ditemukan dalam list!" << endl;
    cout << endl;
}

void SearchByRange(linkedList L, int nilaiMin) {
    address p = L.first;
    int pos = 1;
    cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
    while (p != NULL) {
        if (p->angka >= nilaiMin) {
            cout << "-----------------------------------------------" << endl;
            cout << "Data ditemukan pada posisi ke-" << pos << ", nilai : " << p->angka << endl;
        }
        p = p->next;
        pos++;
    }
    cout << "-----------------------------------------------" << endl;
}

// ARITMETIKA FUNCTIONS
int sumList(linkedList L) {
    int total = 0;
    address p = L.first;
    while (p != NULL) {
        total += p->angka;
        p = p->next;
    }
    return total;
}

int subList(linkedList L) {
    if (L.first == NULL) return 0;
    int total = L.first->angka;
    address p = L.first->next;
    while (p != NULL) {
        total -= p->angka;
        p = p->next;
    }
    return total;
}

int mulList(linkedList L) {
    if (L.first == NULL) return 0;
    int total = 1;
    address p = L.first;
    while (p != NULL) {
        total *= p->angka;
        p = p->next;
    }
    return total;
}
```
```C++
source code main.cpp
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
```
### Output Main :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan5_Modul5/Output/Output-main.png)

### 1. (Buatlah procedure updateFirst, updateLast, dan updateAfter dengan rincian sebagai berikut :
Procedure updateFirst ( input / output L : List ) 
Procedure updateLast ( input / output L : List ) 
Procedure updateAfter ( input / output L : List, input nodePrev : address ) 
(Kemudian pada “main.cpp” lakukanlah :) 
➢ Update data 40 menjadi 50 
➢ Update data 8 menjadi 29 
➢ Update data 33 menjadi 45 
➢ Update data 18 menjadi 20 
➢ Tampilkan seluruh list setelah diupdate )

```C++
source code unguided 1
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan5_Modul5/Output/Output-Unguided1.png)

##### Output 2

Penjelasan Program:
Program ini membuat dan memanipulasi singly linked list yang berisi angka. Langkah-langkahnya:
1. Membuat list kosong dan beberapa node berisi data angka.
2. Menyisipkan node ke awal, akhir, dan setelah node tertentu sehingga terbentuk urutan data seperti 40 → 18 → 13 → 25 → 8 → 33.
3. Menghapus satu node setelah node tertentu.
4. Menampilkan isi list.
5. Melakukan update (mengubah nilai) pada node pertama, terakhir, dan node setelah posisi tertentu.
6. Menampilkan kembali hasil perubahan list.

### 2. (Buatlah procedure SearchByData, SearchByAddress, dan SearchByRange dengan rincian sebagai berikut : 
Procedure SearchByData( input L : List, input data : integer ) 
Procedure SearchByAddress( input L : List, input node : address ) 
Procedure SearchByRange( input L : List, input nilaiMin : integer ) 
Kemudian pada “main.cpp” lakukanlah : 
➢ Mencari data nilai 20 
➢ Mencari data nilai 55 
➢ Mencari data alamat nodeB 
➢ Mencari data alamat nodeA 
➢ Mencari data dengan nilai minimal 40)

```C++
source code unguided 2
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

    // Update nilai list sesuai dengan hasil akhir Unguided 1
    nodeF->angka = 50;
    nodeC->next->angka = 20;
    nodeD->next->angka = 29;
    nodeE->angka = 45;

    printList(L);
    cout << endl;

    // Search
    SearchByData(L, 20);
    SearchByData(L, 55);
    SearchByAddress(L, nodeB);
    SearchByAddress(L, nodeA);
    SearchByRange(L, 40);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan5_Modul5/Output/Output-Unguided2.png)

##### Output 2

Penjelasan Program:
1. Menambahkan node ke awal, akhir, dan setelah node tertentu.
2. Menghapus node setelah node tertentu.
3. Mengubah nilai beberapa node agar sesuai urutan akhir.
4. Menampilkan isi list.
5. Mencari node berdasarkan nilai, alamat, atau rentang nilai.

### 3. (Lakukanlah operasi aritmetika penjumlahan, pengurangan, dan perkalian terhadap semua data yang ada didalam list tersebut! Untuk penjumlahan nilai awal adalah 0, untuk pengurangan nilai awal adalah nilai node pertama (first), untuk perkalian nilai awal adalah 1.)

```C++
source code unguided 3
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan5_Modul5/Output/Output-Unguided3.png)

##### Output 2

Penjelasan Program
1. Membuat list dan menyisipkan node ke awal, akhir, dan setelah node tertentu.
2. Menghapus node setelah node tertentu.
3. Memperbarui nilai node agar sesuai urutan akhir (50 → 18 → 20 → 29 → 8 → 45).
4. Menghitung hasil operasi matematika pada seluruh elemen list:
   - sumList(L) → menjumlahkan semua node
   - subList(L) → mengurangkan nilai node secara berurutan
   - mulList(L) → mengalikan semua node

## Kesimpulan
Praktikum ini dapat disimpulkan penerapan ADT Singly Linked List, yang memungkinkan penyimpanan data secara dinamis melalui node yang berisi nilai dan penunjuk ke node berikutnya. Operasi seperti insert, delete, dan update mempermudah manipulasi data tanpa perlu menggeser elemen seperti pada array. Selain itu, pencarian berdasarkan nilai, alamat, atau rentang, serta operasi aritmetika (sum, sub, mul) menunjukkan fleksibilitas linked list dalam penyimpanan dan pemrosesan data. Dengan demikian, singly linked list merupakan struktur data dinamis yang efisien dan adaptif untuk berbagai kebutuhan manipulasi data.

## Referensi
[1] Dale, N., & Lewis, J. (2013). Computer Science Illuminated (6th ed.). Jones & Bartlett Learning.