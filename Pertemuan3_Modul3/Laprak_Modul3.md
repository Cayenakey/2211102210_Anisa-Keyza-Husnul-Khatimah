# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Anisa Keyza Husnul Khatimah - 2211102210</p>

## Dasar Teori
Abstract Data Type (ADT) merupakan model matematika yang merujuk pada sejumlah bentuk struktur data yang memiliki kegunaan atau perilaku yang serupa; atau suatu tipe data dari suatu bahasa pemrograman yang memiliki sematik yang serupa. Tipe data abstrak umumnya didefinisikan tidak secara langsung, melainkan hanya melalui operasi matematis tertentu sehingga membutuhkan penggunaan tipe data tersebut meski dengan risiko kompleksitas yang lebih tinggi atas operasi tersebut.[1].

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

### 1. (Buat program yang dapat menyimpan data mahasiswa (max 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas)

```C++
source code unguided 1
#include <iostream>
#include <iomanip>
using namespace std;

// Struktur data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

// Menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa data[10]; 
    int jumlah;

    cout << "=== PROGRAM DATA NILAI MAHASISWA ===" << endl;
    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlah;

    if (jumlah > 10) {
        cout << "Jumlah melebihi batas maksimal (10)!" << endl;
        return 0;
    }

    cout << endl;
    // Input data mahasiswa
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin.ignore();
        getline(cin, data[i].nama);
        cout << "NIM    : ";
        getline(cin, data[i].nim);
        cout << "Nilai UTS   : ";
        cin >> data[i].uts;
        cout << "Nilai UAS   : ";
        cin >> data[i].uas;
        cout << "Nilai Tugas : ";
        cin >> data[i].tugas;

        // Hitung nilai akhir dengan fungsi
        data[i].nilaiAkhir = hitungNilaiAkhir(data[i].uts, data[i].uas, data[i].tugas);

        cout << endl;
    }

    // Tampilkan hasil
    cout << fixed << setprecision(2);
    cout << "\n=== DATA NILAI MAHASISWA ===" << endl;
    cout << left << setw(5) << "No"
         << setw(20) << "Nama"
         << setw(15) << "NIM"
         << setw(10) << "UTS"
         << setw(10) << "UAS"
         << setw(10) << "Tugas"
         << setw(12) << "Nilai Akhir" << endl;
    cout << string(80, '-') << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(5) << i + 1
             << setw(20) << data[i].nama
             << setw(15) << data[i].nim
             << setw(10) << data[i].uts
             << setw(10) << data[i].uas
             << setw(10) << data[i].tugas
             << setw(12) << data[i].nilaiAkhir
             << endl;
    }

    return 0;
}


```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan3_Modul3/Output/Output-Unguided1.png)

##### Output 2

Penjelasan Program:
1. Struct Mahasiswa digunakan untuk menyimpan data tiap mahasiswa (nama, nim, uts, uas, tugas, nilaiAkhir).
2. Fungsi hitungNilaiAkhir() menghitung nilai akhir berdasarkan bobot yang ditentukan.
3. Program membatasi input maksimal 10 mahasiswa.
4. Data ditampilkan dalam format tabel dengan iomanip agar rapi.

### 2. (Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
type pelajaran <
namaMapel : string
kodeMapel : string

function create_pelajaran( namapel : string,
kodepel : string ) -> pelajaran
procedure tampil_pelajaran( input pel : pelajaran)

Buatlah implmentasi ADT pelajran pada file "pelajaran.cpp"
Cobalah hasil implementasi ADT pada file "main.cpp"
using namespace std;
int main(){
string namapel = "Struktur Data";
string kodepel = "STD";
pelajaran pel = create_pelajaran(namapel,kodepel);
tampil_pelajaran(pel);

return 0;
}

contoh output hasil:
nama pelajaran : Struktur Data
nilai : STD)

```C++
source code unguided 2
File pelajaran.h
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

// Definisi tipe data pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Fungsi untuk membuat pelajaran baru
pelajaran create_pelajaran(string namapel, string kodepel);

// Prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif

File pelajaran.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

// Implementasi fungsi create_pelajaran
pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

// Implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "Nama pelajaran : " << pel.namaMapel << endl;
    cout << "Nilai : " << pel.kodeMapel << endl;
}

File main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan3_Modul3/Output/Output-Unguided2.png)

##### Output 2

Penjelasan Program
1. Fungsi ini menerima tiga parameter: uts, uas, dan tugas.
2. Kemudian menghitung nilai akhir mahasiswa dengan rumus:
    NilaiAkhir=(0.3xUTS)+(0.4xUAS)+(0.3xTugas)
3. Nilai yang dihasilkan kemudian dikembalikan ke program utama (menggunakan return) dan disimpan ke variabel data[i].nilaiAkhir.

### 3. (Buatlah program dengan ketentuan:
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi buah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variable yang ditunjuk oleh 2 buah pointer)


```C++
source code unguided 3
#include <iostream>
using namespace std;

// Menampilkan isi array 2D 3x3
void tampilArray(int arr[3][3], string nama) {
    cout << "Isi array " << nama << " :" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Untuk menukar isi dua array 2D pada posisi tertentu
void tukarElemenArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// Menukar nilai yang ditunjuk oleh dua pointer
void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    // Dua pointer integer
    int x = 10, y = 20;
    int *ptr1 = &x;
    int *ptr2 = &y;

    // Tampilkan array awal
    tampilArray(A, "A (sebelum ditukar)");
    tampilArray(B, "B (sebelum ditukar)");

    // Tukar isi array pada posisi tertentu (misalnya baris 1 kolom 2 → indeks [1][2])
    cout << "Menukar elemen A[1][2] dan B[1][2]..." << endl;
    tukarElemenArray(A, B, 1, 2);

    cout << "\nSetelah penukaran elemen tertentu:" << endl;
    tampilArray(A, "A");
    tampilArray(B, "B");

    // Menukar nilai dari dua pointer
    cout << "Nilai sebelum tukar pointer: x = " << x << ", y = " << y << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Nilai setelah tukar pointer:  x = " << x << ", y = " << y << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/blob/main/Pertemuan3_Modul3/Output/Output-Unguided3.png)

##### Output 2

Penjelasan Program
1. pelajaran.h → berisi deklarasi struktur dan prototipe fungsi/prosedur (sebagai header file ADT).
2. pelajaran.cpp → berisi implementasi dari fungsi dan prosedur yang dideklarasikan di header.
3. main.cpp → program utama untuk menguji ADT dengan memanggil fungsi create_pelajaran() dan tampil_pelajaran().

## Kesimpulan
Praktikum ini dapat disimpulkan bahwa penggunaan array mempermudah pengolahan data seperti mencari nilai maksimum, minimum, dan rata-rata. Penerapan fungsi membuat program lebih terstruktur, sedangkan pointer dan reference membantu memahami cara kerja memori dalam pertukaran data. Selain itu, penggunaan switch-case dan looping memungkinkan pembuatan program interaktif berbasis menu. Secara keseluruhan, praktikum ini memperkenalkan dasar penting C++ seperti array, fungsi, pointer, dan kontrol alur program yang menjadi fondasi untuk pemrograman lebih lanjut.

## Referensi
[1] Wikipedia (2022). Tipe Data Abstract. Diakses 26 Desember 2022, dari https:https://id.wikipedia.org/wiki/Tipe_data_abstrak