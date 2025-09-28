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