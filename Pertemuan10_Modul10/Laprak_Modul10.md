# <h1 align="center">Laporan Praktikum Modul 10 -  TREE (BAGIAN PERTAMA)</h1>
<p align="center">Anisa Keyza Husnul Khatimah - 2211102210</p>

## Dasar Teori
Secara harfiah, rekursif berarti suatu proses pengulangan sesuatu dengan cara kesamaan-diri atau
suatu proses yang memanggil dirinya sendiri. Prosedur dan fungsi merupakan sub program yang
sangat bermanfaat dalam pemrograman, terutama untuk program atau proyek yang besar.
Manfaat penggunaan sub program antara lain adalah :
1. meningkatkan readibility, yaitu mempermudah pembacaan program
2. meningkatkan modularity, yaitu memecah sesuatu yang besar menjadi modul-modul atau
bagian-bagian yang lebih kecil sesuai dengan fungsinya, sehingga mempermudah
pengecekan, testing dan lokalisasi kesalahan.
3. meningkatkan reusability, yaitu suatu sub program dapat dipakai berulang kali dengan hanya
memanggil sub program tersebut tanpa menuliskan perintah-perintah yang semestinya
diulang-ulang.
SubProgramRekursifadalahsubprogramyangmemanggildirinyasendiriselamakondisipemanggilan
dipenuhi. Prinsip rekursif sangat berkaitan erat dengan bentuk induksi matematika. 

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
### 1. ( Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”)

```C++
source code unguided 1
File bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

#define Nil NULL

// ADT BST
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

#endif

File bstree.cpp
#include "bstree.h"

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // jika x == root->info, data duplikat → diabaikan
}

address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

File main.cpp
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);

    printInorder(root);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan10_Modul10/Output/Output-Unguided1.png)

##### Output 2

Penjelasan Program:
Program tersebut mengimplementasikan ADT Binary Search Tree (BST) menggunakan pointer (linked list). Pada file `bstree.h` didefinisikan struktur `Node` yang berisi data integer serta pointer ke anak kiri dan kanan, sedangkan file `bstree.cpp` berisi implementasi fungsi dasar BST seperti alokasi node, penyisipan data sesuai aturan BST, pencarian node, dan penelusuran inorder.

Pada `main.cpp`, program membuat sebuah BST lalu memasukkan beberapa nilai ke dalam tree. Data duplikat diabaikan saat proses penyisipan. Fungsi `printInorder` digunakan untuk menampilkan isi tree secara terurut menaik, karena traversal inorder pada BST selalu menghasilkan urutan data yang terurut.


### 2. (Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsihitungJumlahNode( root:address ) : integer
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
➢ fungsihitungTotalInfo( root:address, start:integer ) : integer
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
➢ fungsihitungKedalaman( root:address, start:integer ) : integer)

```C++
source code unguided 2
File bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

#define Nil NULL

// ADT BST
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif

File bstree.cpp
#include "bstree.h"

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // jika x == root->info, data duplikat → diabaikan
}

address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info 
           + hitungTotalInfo(root->left) 
           + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    }
    int kiri  = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return (kiri > kanan) ? kiri : kanan;
}

File main2.cpp
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6); // duplikat
    insertNode(root,7);

    printInorder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan10_Modul10/Output/Output-Unguided2.png)

##### Output 2

Penjelasan Program:
Fungsi **`hitungJumlahNode`** digunakan untuk menghitung total node dalam BST dengan menelusuri seluruh node secara rekursif. Fungsi **`hitungTotalInfo`** menghitung jumlah seluruh nilai (info) yang tersimpan pada node-node BST dengan menjumlahkan nilai setiap node. Sedangkan fungsi **`hitungKedalaman`** menentukan kedalaman maksimum BST dengan membandingkan kedalaman subtree kiri dan kanan secara rekursif.


### 3. (Print tree secara pre-order dan post-order)

```C++
source code unguided 3
File bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

#define Nil NULL

// ADT BST
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);
void printPreorder(address root);
void printPostorder(address root);

#endif

File bstree.cpp
#include "bstree.h"

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // jika x == root->info, data duplikat → diabaikan
}

address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info 
           + hitungTotalInfo(root->left) 
           + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    }
    int kiri  = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return (kiri > kanan) ? kiri : kanan;
}

void printPreorder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " - ";
    }
}

File main3.cpp
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = Nil;

    // Insert data ke BST
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); // duplikat, diabaikan
    insertNode(root, 7);

    // InOrder
    cout << "Inorder : ";
    printInorder(root);
    cout << endl;

    // PreOrder
    cout << "Preorder : ";
    printPreorder(root);
    cout << endl;

    // PostOrder
    cout << "Postorder : ";
    printPostorder(root);
    cout << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan10_Modul10/Output/Output-Unguided3.png)

##### Output 2

Penjelasan Program
Traversal **pre-order** menampilkan data dengan urutan **root–left–right**, yaitu node akar dicetak terlebih dahulu sebelum subtree kiri dan kanan. Traversal ini digunakan untuk melihat urutan pembentukan struktur tree.

Traversal **post-order** menampilkan data dengan urutan **left–right–root**, yaitu node akar dicetak terakhir setelah seluruh subtree diproses. Traversal ini biasanya digunakan untuk proses penghapusan atau evaluasi struktur Binary Search Tree.


## Kesimpulan
Pada praktikum modul Binary Search Tree (BST), telah berhasil diimplementasikan struktur data tree menggunakan pointer dengan aturan penyusunan data berdasarkan nilai. Melalui penerapan operasi dasar seperti penyisipan node, pencarian data, serta berbagai metode traversal (inorder, preorder, dan postorder), mahasiswa dapat memahami cara kerja dan struktur BST secara menyeluruh.

Selain itu, fungsi tambahan seperti perhitungan jumlah node, total nilai node, dan kedalaman tree memberikan pemahaman lebih lanjut mengenai analisis struktur dan karakteristik BST. Praktikum ini menjadi dasar penting dalam memahami struktur data non-linier serta penerapannya dalam pengolahan data yang terorganisir dan efisien.


## Referensi
//