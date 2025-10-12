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
