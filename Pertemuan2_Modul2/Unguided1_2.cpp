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

// Fungsi untuk penjumlahan matriks
void tambahMatriks(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Fungsi untuk pengurangan matriks
void kurangMatriks(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Fungsi untuk perkalian matriks
void kaliMatriks(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], hasil[SIZE][SIZE];
    int pilihan;

    cout << "=== PROGRAM OPERASI MATRIKS 3x3 ===\n";

    // Input elemen matriks A
    cout << "\nMasukkan elemen matriks A:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    // Input elemen matriks B
    cout << "\nMasukkan elemen matriks B:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    // Menu operasi
    cout << "\nPilih operasi yang ingin dilakukan:\n";
    cout << "1. Penjumlahan Matriks\n";
    cout << "2. Pengurangan Matriks\n";
    cout << "3. Perkalian Matriks\n";
    cout << "Pilihan: ";
    cin >> pilihan;

    cout << "\nMatriks A:\n";
    tampilMatriks(A);
    cout << "\nMatriks B:\n";
    tampilMatriks(B);

    // Proses sesuai pilihan
    switch (pilihan) {
        case 1:
            tambahMatriks(A, B, hasil);
            cout << "\nHasil Penjumlahan Matriks (A + B):\n";
            tampilMatriks(hasil);
            break;
        case 2:
            kurangMatriks(A, B, hasil);
            cout << "\nHasil Pengurangan Matriks (A - B):\n";
            tampilMatriks(hasil);
            break;
        case 3:
            kaliMatriks(A, B, hasil);
            cout << "\nHasil Perkalian Matriks (A x B):\n";
            tampilMatriks(hasil);
            break;
        default:
            cout << "\nPilihan tidak valid!\n";
            break;
    }

    return 0;
}
