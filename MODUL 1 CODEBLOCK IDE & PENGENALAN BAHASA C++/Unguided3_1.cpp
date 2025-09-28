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