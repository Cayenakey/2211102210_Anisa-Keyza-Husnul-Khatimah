# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Anisa Keyza Husnul Khatimah - 2211102210</p>

## Dasar Teori
Array merupakan struktur data yang berisi sejumlah elemen dengan tipe data yang sama. Setiap elemen dalam array disimpan secara berurutan di dalam memori komputer. Karena semua elemen memiliki tipe data yang seragam, array sangat sesuai digunakan untuk menyimpan kumpulan data yang bersifat homogen dan jumlah elemennya sudah diketahui sejak awal[1].

Array dibagi menjadi beberapa jenis, yaitu:
1. **Array Satu Dimensi**
   Merupakan kumpulan elemen dengan tipe data sama yang tersusun dalam satu baris. Sering disebut *vektor* karena menyimpan data secara berurutan.
   *Contoh deklarasi:* `int A[5];`
2. **Array Dua Dimensi**
   Perluasan dari array satu dimensi yang membentuk baris dan kolom, mirip dengan matriks.
   *Contoh deklarasi:* `int A[3][2];`
3. **Array Tiga Dimensi**
   Digunakan untuk menyimpan data dalam bentuk tiga sisi atau tiga dimensi.
   *Contoh deklarasi:* `int A[3][4][2];`
4. **Array Banyak Dimensi**
   Merupakan pengembangan dari array sebelumnya dengan lebih banyak dimensi, namun jarang digunakan.
   *Contoh deklarasi:* `int A[3][4][2][5];`[1].

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

### 1. (Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3)

```C++
source code unguided 1
#include <iostream>
using namespace std;

const int SIZE = 3; // Ukuran matriks 3x3

// Fungsi untuk menampilkan matriks
void tampilMatriks(int M[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

// Fungsi untuk menjumlahkan matriks
void tambahMatriks(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Fungsi untuk mengurangkan matriks
void kurangMatriks(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Fungsi untuk mengalikan matriks
void kaliMatriks(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

    cout << "=== PROGRAM OPERASI MATRIKS 3x3 ===\n";

    // Input matriks A
    cout << "\nMasukkan elemen matriks A (3x3):\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> A[i][j];
        }
    }

    // Input matriks B
    cout << "\nMasukkan elemen matriks B (3x3):\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "B[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> B[i][j];
        }
    }

    cout << "\nMatriks A:\n";
    tampilMatriks(A);

    cout << "\nMatriks B:\n";
    tampilMatriks(B);

    // Operasi penjumlahan
    tambahMatriks(A, B, C);
    cout << "\nHasil Penjumlahan (A + B):\n";
    tampilMatriks(C);

    // Operasi pengurangan
    kurangMatriks(A, B, C);
    cout << "\nHasil Pengurangan (A - B):\n";
    tampilMatriks(C);

    // Operasi perkalian
    kaliMatriks(A, B, C);
    cout << "\nHasil Perkalian (A x B):\n";
    tampilMatriks(C);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/Output/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/Output/Output-Unguided1-2.png)

Penjelasan Program:
Program ini berfungsi untuk melakukan penjumlahan, pengurangan, dan perkalian matriks 3x3** menggunakan bahasa C++. Matriks disimpan dalam array dua dimensi, dan operasi dilakukan dengan perulangan bersarang. Pengguna memasukkan elemen matriks A dan B, memilih jenis operasi, lalu program menampilkan hasilnya. Program ini menerapkan konsep fungsi, array, dan struktur kontrol switch-case secara sederhana.


### 2. (Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel)

```C++
#include <iostream>
using namespace std;

// ==== Versi 1: Menggunakan POINTER ====
void tukarDenganPointer(int *a, int *b, int *c) {
    int temp = *a;  // Simpan nilai a
    *a = *b;        // a = b
    *b = *c;        // b = c
    *c = temp;      // c = nilai awal a
}

// ==== Versi 2: Menggunakan REFERENCE ====
void tukarDenganReference(int &a, int &b, int &c) {
    int temp = a;   // Simpan nilai a
    a = b;          // a = b
    b = c;          // b = c
    c = temp;       // c = nilai awal a
}

int main() {
    int x, y, z;

    cout << "=== PROGRAM TUKAR NILAI 3 VARIABEL (Pointer & Reference) ===\n";

    // Input nilai
    cout << "\nMasukkan nilai pertama (x): ";
    cin >> x;
    cout << "Masukkan nilai kedua (y): ";
    cin >> y;
    cout << "Masukkan nilai ketiga (z): ";
    cin >> z;

    cout << "\nNilai sebelum ditukar:\n";
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    // ==== Menukar menggunakan POINTER ====
    tukarDenganPointer(&x, &y, &z);
    cout << "\nSetelah ditukar dengan POINTER:\n";
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    // ==== Menukar kembali menggunakan REFERENCE ====
    tukarDenganReference(x, y, z);
    cout << "\nSetelah ditukar lagi dengan REFERENCE:\n";
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/Output/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/Output/Output-Unguided2-2.png)

Penjelasan Program
Program ini menukar nilai tiga variabel (x, y, z) dengan dua cara: 
1. Fungsi pointer memakai alamat memori untuk menukar nilai, sedangkan reference langsung mengakses variabel aslinya.
2. Pengguna memasukkan tiga nilai, program menukar dengan pointer lalu mengembalikannya dengan reference.
Intinya, program ini memperlihatkan perbedaan cara kerja pointer dan reference dalam mengubah nilai variabel di C++.

### 3. (Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} 
### Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :
### --- Menu Program Array ---
### 1. Tampilkan isi array
### 2. cari nilai maksimum
### 3. cari nilai minimum
### 4. Hitung nilai rata - rata)

```C++
source code guided 3
#include <iostream>
using namespace std;

// Deklarasi array global
int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
const int N = 10; // jumlah elemen array

// ==== Fungsi untuk mencari nilai maksimum ====
int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks)
            maks = arr[i];
    }
    return maks;
}

// ==== Fungsi untuk mencari nilai minimum ====
int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

// ==== Prosedur untuk menghitung rata-rata ====
void hitungRataRata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    float rata = total / n;
    cout << "Nilai rata-rata dari array = " << rata << endl;
}

// ==== Prosedur untuk menampilkan isi array ====
void tampilArray(int arr[], int n) {
    cout << "Isi array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;
}

// ==== Program utama ====
int main() {
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilArray(arrA, N);
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, N) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, N) << endl;
                break;
            case 4:
                hitungRataRata(arrA, N);
                break;
            case 5:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }

    } while (pilihan != 5);

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/Output/Output-Unguided3-1.png)

##### Output 2
(https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/Output/Output-Unguided3_2.png)

Penjelasan Program
1. Menu ditampilkan berulang kali dengan do-while selama pilihan ≠ 5.
2. Pengguna memilih menu (1–5).
3. switch-case digunakan agar setiap pilihan menjalankan fungsi/prosedur yang sesuai:
   - case 1 → tampilkan isi array.
   - case 2 → cari nilai maksimum.
   - case 3 → cari nilai minimum.
   - case 4 → hitung rata-rata.
   - case 5 → keluar dari program.
4. Jika input salah → tampil pesan "Pilihan tidak valid!".

## Kesimpulan
Praktikum ini dapat disimpulkan bahwa penggunaan array mempermudah pengolahan data seperti mencari nilai maksimum, minimum, dan rata-rata. Penerapan fungsi membuat program lebih terstruktur, sedangkan pointer dan reference membantu memahami cara kerja memori dalam pertukaran data. Selain itu, penggunaan switch-case dan looping memungkinkan pembuatan program interaktif berbasis menu. Secara keseluruhan, praktikum ini memperkenalkan dasar penting C++ seperti array, fungsi, pointer, dan kontrol alur program yang menjadi fondasi untuk pemrograman lebih lanjut.

## Referensi
[1] Arie Setya P. (2020). Struktur Data Array Dua Dimensi pada Pemprograman C++. Diakses 04 April 2020, dari https:https://osf.io/preprints/osf/vyech 