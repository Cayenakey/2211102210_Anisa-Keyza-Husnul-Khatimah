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
