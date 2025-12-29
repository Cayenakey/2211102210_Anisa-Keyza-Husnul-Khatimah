# <h1 align="center">Laporan Praktikum Modul 7 -  STACK</h1>
<p align="center">Anisa Keyza Husnul Khatimah - 2211102210</p>

## Dasar Teori
Stack merupakan salah satu bentuk struktur data dimana prinsip operasi yang digunakan seperti
tumpukan. Seperti halnya tumpukan, elemen yang bisa diambil terlebih dahulu adalah elemen yang
paling atas, atau elemen yang pertama kali masuk, prinsip ini biasa disebut LIFO (Last In First Out).

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
### 1. (BuatlahimplementasiADTStackmenggunakanArraypadafile“stack.cpp”dan“main.cpp”)

```C++
source code unguided 1
File stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

// ADT Stack
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif

File stack.cpp
#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int i = 0, j = S.top;
    while (i < j) {
        infotype temp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = temp;
        i++;
        j--;
    }
}

File main.cpp
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan7_Modul7/Output/Output-Unguided1.png)

##### Output 2

Penjelasan Program:
Program ini mengimplementasikan **ADT Stack berbasis array** dengan elemen bertipe integer dan penanda `top` sebagai posisi teratas. Operasi dasar seperti `push`, `pop`, menampilkan isi stack, dan membalik urutan stack diimplementasikan dalam file terpisah untuk menjaga modularitas program.

Pada `main.cpp`, stack diinisialisasi lalu dilakukan beberapa operasi penambahan dan penghapusan elemen. Hasil isi stack ditampilkan sebelum dan sesudah proses pembalikan, sehingga menunjukkan cara kerja stack dengan prinsip **LIFO (Last In First Out)**.


### 2. (TambahkanprosedurpushAscending(in/outS:Stack,inx:integer))

```C++
source code unguided 2
File stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

// ADT Stack
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif

File stack.cpp
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

File main2.cpp
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan7_Modul7/Output/Output-Unguided2.png)

##### Output 2

Penjelasan Program:
Program ini merupakan pengembangan ADT Stack berbasis array dengan penambahan prosedur `pushAscending`, yaitu prosedur untuk memasukkan elemen ke dalam stack sambil menjaga urutan data tetap menaik. Nilai yang dimasukkan akan ditempatkan pada posisi yang sesuai dengan cara menggeser elemen yang lebih besar, sehingga elemen terbesar selalu berada di bagian TOP.

Pada program utama, data dimasukkan ke stack menggunakan `pushAscending`, kemudian isi stack ditampilkan sebelum dan sesudah dibalik menggunakan `balikStack`. Penambahan prosedur ini menunjukkan bahwa stack dapat dimodifikasi untuk mendukung pengurutan data, tidak hanya sekadar operasi LIFO.

### 3. (Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.)

```C++
source code unguided 3
File stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

// ADT Stack
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif

File stack.cpp
#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int i = 0, j = S.top;
    while (i < j) {
        infotype temp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = temp;
        i++;
        j--;
    }
}

void pushAscending(Stack &S, infotype x) {
    int i = S.top;

    // geser elemen yang lebih besar dari x
    while (i >= 0 && S.info[i] > x) {
        S.info[i + 1] = S.info[i];
        i--;
    }

    // sisipkan x pada posisi yang tepat
    S.info[i + 1] = x;
    S.top++;
}

void getInputStream(Stack &S) {
    char ch;
    cout << "Masukkan input (tekan ENTER untuk selesai): ";

    while (true) {
        ch = cin.get();        // baca 1 karakter
        if (ch == '\n') {     // berhenti saat ENTER
            break;
        }
        if (ch >= '0' && ch <= '9') {
            push(S, ch - '0'); // konversi char ke int
        }
    }
}

File main3.cpp
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan7_Modul7/Output/Output-Unguided3.png)

##### Output 2

Penjelasan Program
Prosedur `getInputStream` digunakan untuk membaca input dari pengguna karakter demi karakter menggunakan `cin.get()`. Setiap karakter angka yang dimasukkan akan dikonversi menjadi bilangan integer dan dimasukkan ke dalam stack menggunakan operasi `push`. Proses pembacaan akan terus berlangsung hingga pengguna menekan tombol Enter, yang ditandai dengan karakter newline (`'\n'`). Dengan prosedur ini, pengguna dapat memasukkan data ke dalam stack tanpa harus menentukan jumlah elemen terlebih dahulu.


## Kesimpulan
Pada praktikum modul Stack, telah berhasil diimplementasikan struktur data stack berbasis array dengan berbagai operasi dasar seperti `push`, `pop`, dan penampilan isi stack. Selain itu, dilakukan pengembangan fungsi tambahan seperti `pushAscending` untuk menjaga urutan data secara menaik serta `getInputStream` untuk menerima input secara dinamis dari pengguna hingga tombol Enter ditekan.

Melalui praktikum ini, mahasiswa dapat memahami prinsip kerja stack dengan konsep LIFO (Last In First Out), penggunaan indeks `top` sebagai penanda elemen teratas, serta pengelolaan data dan memori secara terstruktur. Modul stack ini menjadi dasar penting dalam memahami struktur data lain yang lebih kompleks dan penerapannya dalam pemrograman.

## Referensi
//