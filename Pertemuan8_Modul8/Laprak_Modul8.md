# <h1 align="center">Laporan Praktikum Modul 8 - Queue </h1>
<p align="center">Anisa Keyza Husnul Khatimah - 2211102210</p>

## Dasar Teori
Queue adalah struktur data yang bekerja berdasarkan prinsip First In, First Out (FIFO), di mana elemen yang pertama kali dimasukkan akan menjadi elemen pertama yang dikeluarkan. Untuk menciptakan dan menginisialisasi queue, fungsi atau metode yang digunakan tergantung pada implementasi yang dipilih, seperti menggunakan array, linked list, atau pustaka bawaan Python.

Queue memiliki peran yang penting dalam berbagai aplikasi dan algoritma. Salah satu fungsi utamanya adalah mengatur dan mengelola antrean tugas atau operasi secara efisien. Dalam sistem komputasi, ia digunakan untuk menangani tugas-tugas seperti penjadwalan proses, antrean pesan, dan manajemen sumber daya[1].


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
### 1. ( Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:)
Type infotype: integer
 Type Queue: <
 info : array [5] of infotype {index array dalam C++
 dimulai dari 0}
 head, tail : integer
 >
 procedure CreateQueue (input/output Q: Queue)
 function isEmptyQueue (Q: Queue) → boolean
 function isFullQueue (Q: Queue) → boolean
 procedure enqueue (input/output Q: Queue, input x: infotype)
 function dequeue (input/output Q: Queue) → infotype
 procedure printInfo (input Q: Queue)
 Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
 queue Alternatif 1 (head diam, tail bergerak).

```C++
unguided 1
source code queue.cpp
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue is full!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[Q.tail] = x;
        } else {
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    infotype temp;

    if (isEmptyQueue(Q)) {
        cout << "Queue is empty!" << endl;
        return -1;
    } else {
        temp = Q.info[Q.head];

        // Geser semua data ke kiri
        for (int i = 0; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }

        Q.tail--;

        if (Q.tail < 0) {  
            Q.head = -1;
            Q.tail = -1;
        }
    }

    return temp;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }

    cout << endl;
}
```
```C++
source code queue.h
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;
typedef int infotype;

typedef struct {
    infotype info[MAX];
    int head, tail;
} Queue;

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
```C++
source code main.cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << "H - T\t| Queue info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan8_Modul8/Output/Output-Unguided1.png)

##### Output 2

Penjelasan Program:
1. Mengimplementasikan Queue sederhana berbasis array
2. Menggunakan metode head diam, tail bergerak
3. Menggeser elemen setiap kali dequeue
4. Menampilkan kondisi queue setelah setiap operasi

### 2. (Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).)

```C++
unguided 2
source code queue2.cpp
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        // jadi kosong
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i];
            if (i < Q.tail) cout << " ";
        }
    }

    cout << endl;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan8_Modul8/Output/Output-Unguided2.png)

##### Output 2

Penjelasan Program:
Program queue2.cpp adalah implementasi Queue dengan array di mana:
1. head & tail bergerak maju
2. tidak ada pergeseran elemen (lebih efisien)
3. queue penuh jika tail mencapai MAX-1
4. queue kosong jika head & tail = −1
5. setiap dequeue → head naik 1 langkah
6. setelah elemen terakhir keluar → queue diset ulang ke kosong

### 3. (Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).)

```C++
unguided 3
source code queue3.cpp
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue is full!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) { // queue is empty
        Q.head = 0;
        Q.tail = 0;
        Q.info[Q.tail] = x;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue is empty!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    // Jika hanya satu elemen
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;

    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX;
    }

    cout << endl;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan8_Modul8/Output/Output-Unguided3.png)

##### Output 2

Penjelasan Program
1. head dan tail bergerak berputar menggunakan operasi modulo (% MAX)
2. Setelah mencapai indeks terakhir (MAX-1), mereka kembali ke indeks 0
3. Tidak ada pergeseran elemen sama sekali
4. Lebih efisien daripada Alternatif 1 dan 2

## Kesimpulan
Praktikum ini dapat disimpulkan pengimplementasian struktur data Queue menggunakan array dengan tiga mekanisme berbeda, yaitu Alternatif 1, Alternatif 2, dan Alternatif 3. Alternatif 1 menggunakan metode head diam dan tail bergerak, sehingga setiap operasi dequeue mengharuskan elemen digeser ke kiri. Meskipun sederhana, mekanisme ini kurang efisien karena proses shifting memakan waktu. Alternatif 2 meningkatkan efisiensi dengan menggerakkan head dan tail tanpa melakukan pergeseran elemen, tetapi masih memiliki kelemahan karena ruang kosong di awal array tidak dapat digunakan kembali, sehingga queue bisa dianggap penuh sebelum kapasitas sebenarnya habis. Alternatif 3 atau circular queue menjadi solusi terbaik karena memanfaatkan operasi modulo untuk membuat head dan tail berputar, sehingga seluruh ruang array dapat digunakan tanpa shifting dan setiap operasi berjalan dalam waktu konstan. Dengan demikian, dari ketiga implementasi yang diuji, circular queue merupakan metode paling optimal baik dari sisi efisiensi waktu maupun penggunaan ruang memori.

## Referensi
[1] Rizki, M. (2023). Struktur Data Queue: Pengertian, Fungsi, dan Jenisnya. Url: https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/.