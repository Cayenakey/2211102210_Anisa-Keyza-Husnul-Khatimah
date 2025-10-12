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
