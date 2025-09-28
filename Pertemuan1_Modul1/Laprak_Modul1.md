# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Anisa Keyza Husnul Khatimah - 2211102210</p>

## Dasar Teori
Tipe data merupakan sebuah jenis nilai atau berupa nilai apa yang akan  ditampung  oleh  sebuah  variabel.  Tipe  data  ini  wajib  ada  ketika  akan membuat  sebuah  variabel  agar  variabel  tersebut  memiliki  nilai  yang  spesifik dan  jelas  ketika  digunakan  nantinya[1]. Variabel adalah proses mendefinisikan sebuah variabel dengan menetapkan nama dan tipe datanya. Hal ini memberitahu komputer untuk mengalokasikan memori yang dibutuhkan dan mengenali variabel tersebut saat program dijalankan[2].

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

### 1. (Buatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut (bahasa c++))

```C++
source code unguided 1
#include <iostream>
using namespace std;

int main() {
    float a, b;

    // Input dua bilangan float
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    // Operasi aritmatika
    cout << "\nHasil Penjumlahan: " << (a + b) << endl;
    cout << "Hasil Pengurangan: " << (a - b) << endl;
    cout << "Hasil Perkalian  : " << (a * b) << endl;

    if (b != 0) {
        cout << "Hasil Pembagian  : " << (a / b) << endl;
    } else {
        cout << "Hasil Pembagian  : Tidak terdefinisi (pembagian dengan nol)" << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/Output/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/Output/Output-Unguided1-2.png)

Penjelasan Program:
1. Input → Program meminta pengguna memasukkan dua bilangan (a dan b).
2. Proses → Dilakukan operasi aritmatika dasar:
   - Penjumlahan (a + b)
   - Pengurangan (a - b)
   - Perkalian (a * b)
   - Pembagian (a / b) → hanya dilakukan jika b ≠ 0, agar tidak terjadi error pembagian dengan nol.
3. Output → Program menampilkan hasil dari masing-masing operasi ke layar.

### 2. (Buatlah sebuah program yang menerima masukkan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-inputkan user adalah bilangan bulat positif mulai dari 0 s.d 100, contoh: 79: tujuh puluh sembilan)

```C++
#include <iostream>
#include <string>
using namespace std;

string angkaKeTulisan(int n) {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", 
                       "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh",
                       "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas",
                       "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", 
                        "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (n < 20) {
        return satuan[n];
    } else if (n < 100) {
        int p = n / 10;  // puluhan
        int s = n % 10;  // satuan
        if (s == 0) return puluhan[p];
        else return puluhan[p] + " " + satuan[s];
    } else if (n == 100) {
        return "seratus";
    }
    return "Diluar jangkauan (0 - 100)";
}

int main() {
    int angka;
    cout << "Masukkan bilangan bulat (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan!" << endl;
    } else {
        cout << angka << " : " << angkaKeTulisan(angka) << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/Output/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/Output/Output-Unguided2-2.png)

Penjelasan Program
1. Fungsi angkaKeTulisan(int n):
   - Jika n < 20 → langsung ambil dari array satuan.
   - Jika 20 ≤ n < 100 → dihitung puluhan (n/10) dan satuan (n%10), lalu digabung (misalnya 42 → "empat puluh dua").
   - Jika n == 100 → ditulis "seratus".
   - Jika di luar 0–100 → kembalikan "Diluar jangkauan (0 - 100)".
2. Fungsi main():
   - Meminta input angka dari pengguna.
   - Jika input tidak valid (kurang dari 0 atau lebih dari 100), tampil pesan error.
   - Jika valid, tampilkan angka sekaligus bentuk tulisannya.

### 3. (Buatlah program yang dapat memberikan input dan output sbb. input: 3 uotput: 3 2 1 * 1 2 3 2 1 * 1 2 1 * 1 *)

```C++
source code guided 3
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:\n";
    for (int i = n; i >= 0; i--) {
        // Spasi di awal baris
        for (int s = 0; s < (n - i); s++) {
            cout << "  "; // dua spasi biar rapi
        }

        // Angka menurun
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // Tanda *
        cout << "* ";

        // Angka menaik
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/Output/Output-Unguided3-1.png)

##### Output 2
(https://github.com/Cayenakey/2211102210_Anisa-Keyza-Husnul-Khatimah/Output/Output-Unguided3_2.png)

Penjelasan Program
Program di atas berfungsi untuk menampilkan pola berbentuk segitiga simetris yang terdiri dari angka menurun, tanda bintang *, dan angka menaik. Pertama, program meminta pengguna memasukkan sebuah bilangan bulat n sebagai tinggi pola. Kemudian, melalui perulangan dari n hingga 0, program mencetak baris demi baris. Pada setiap baris, bagian pertama berupa spasi yang jumlahnya bertambah setiap baris untuk membuat pola rata ke kanan. Setelah itu, program mencetak angka menurun dari nilai i hingga 1, kemudian menampilkan tanda * sebagai pusat pola, dan diakhiri dengan angka menaik dari 1 hingga i. Hasil akhirnya adalah pola segitiga simetris dengan * di tengah, angka menurun di sebelah kiri, serta angka menaik di sebelah kanan.

## Kesimpulan
Praktikum ini menunjukkan bagaimana program dapat menerima input dari pengguna, melakukan proses perhitungan atau pengolahan data, dan menghasilkan output yang sesuai dengan yang diharapkan. Program pertama menekankan penggunaan tipe data float dan operasi aritmatika, program kedua mengilustrasikan penggunaan fungsi untuk mengubah angka menjadi teks, serta program ketiga memperlihatkan bagaimana perulangan bersarang dapat digunakan untuk mencetak pola angka simetris. 

## Referensi
[1] M. Taufik, Deden P., Ana Rahma. (2022). Buku belajar bahasa pemrograman dengan C++. CV Widina Media Utama. Diakses 11 November 2022, dari https://repository.penerbitwidina.com/publications/558527/belajar-dasar-pemrograman-dengan-c#id-section-content 
<br>[2] Rozzi Kesuma, Novia Hasdyna. (2025). "BUKU ALGORITMA DAN PEMROGRAMAN: KONSEP DASAR, LOGIKA, DAN IMPLEMENTASI DENGAN C++ & PYTHON". Payakumbuh: PT. Serasi Media Teknologi. Diakses pada Juni 2025 melalui https://books.google.co.id/books?hl=id&lr=&id=6kBlEQAAQBAJ&oi=fnd&pg=PA1&dq=pengertian+c%2B%2B&ots=bk_HB9tOFH&sig=jd1QChljRqlFWv1cG7HGrbkuHBg&redir_esc=y#v=onepage&q=pengertian%20c%2B%2B&f=false.

