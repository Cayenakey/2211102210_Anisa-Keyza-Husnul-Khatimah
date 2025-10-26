#include "ListAngka.h"

// =======================
// DASAR LINKED LIST
// =======================
void createList(linkedList &L) {
    L.first = NULL;
}

address alokasi(dataAngka x) {
    address p = new node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = NULL;
}

void printList(linkedList L) {
    address p = L.first;
    while (p != NULL) {
        cout << p->angka;
        if (p->next != NULL) cout << " - ";
        p = p->next;
    }
    cout << " -" << endl;
}

void insertFirst(linkedList &L, address p) {
    p->next = L.first;
    L.first = p;
}

void insertLast(linkedList &L, address p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        address last = L.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    }
}

void insertAfter(linkedList &L, address p, address prec) {
    if (prec != NULL) {
        p->next = prec->next;
        prec->next = p;
    }
}

int nbList(linkedList L) {
    int count = 0;
    address p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void delAfter(linkedList &L, address &pHapus, address prec) {
    if (prec != NULL && prec->next != NULL) {
        pHapus = prec->next;
        prec->next = pHapus->next;
        pHapus->next = NULL;
    }
}

// =======================
// UPDATE FUNCTIONS
// =======================
void updateFirst(linkedList &L) {
    if (L.first != NULL) {
        cout << "Masukkan update data node pertama: " << endl;
        cout << "Masukkan angka : ";
        cin >> L.first->angka;
        cout << "Data berhasil diupdate!" << endl << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.first == NULL) return;
    address last = L.first;
    while (last->next != NULL) last = last->next;

    cout << "Masukkan update data node terakhir: " << endl;
    cout << "Masukkan angka : ";
    cin >> last->angka;
    cout << "Data berhasil diupdate!" << endl << endl;
}

void updateAfter(linkedList &L, address prec) {
    if (prec != NULL && prec->next != NULL) {
        cout << "Masukkan update data node setelah node " << prec->angka << " : " << endl;
        cout << "Masukkan angka : ";
        cin >> prec->next->angka;
        cout << "Data berhasil diupdate!" << endl << endl;
    }
}

// =======================
// SEARCH FUNCTIONS
// =======================
void SearchByData(linkedList L, int data) {
    address p = L.first;
    int pos = 1;
    bool found = false;
    while (p != NULL) {
        if (p->angka == data) {
            cout << "Data " << data << " ditemukan pada posisi ke-" << pos << "!" << endl;
            found = true;
            break;
        }
        p = p->next;
        pos++;
    }
    if (!found)
        cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
    cout << endl;
}

void SearchByAddress(linkedList L, address nodeCari) {
    address p = L.first;
    int pos = 1;
    bool found = false;
    while (p != NULL) {
        if (p == nodeCari) {
            cout << "Node ditemukan pada posisi ke-" << pos << "!" << endl;
            cout << "Alamat node : " << p << endl;
            found = true;
            break;
        }
        p = p->next;
        pos++;
    }
    if (!found)
        cout << "Node dengan alamat " << nodeCari << " tidak ditemukan dalam list!" << endl;
    cout << endl;
}

void SearchByRange(linkedList L, int nilaiMin) {
    address p = L.first;
    int pos = 1;
    cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
    while (p != NULL) {
        if (p->angka >= nilaiMin) {
            cout << "-----------------------------------------------" << endl;
            cout << "Data ditemukan pada posisi ke-" << pos << ", nilai : " << p->angka << endl;
        }
        p = p->next;
        pos++;
    }
    cout << "-----------------------------------------------" << endl;
}

// =======================
// ARITMETIKA FUNCTIONS
// =======================
int sumList(linkedList L) {
    int total = 0;
    address p = L.first;
    while (p != NULL) {
        total += p->angka;
        p = p->next;
    }
    return total;
}

int subList(linkedList L) {
    if (L.first == NULL) return 0;
    int total = L.first->angka;
    address p = L.first->next;
    while (p != NULL) {
        total -= p->angka;
        p = p->next;
    }
    return total;
}

int mulList(linkedList L) {
    if (L.first == NULL) return 0;
    int total = 1;
    address p = L.first;
    while (p != NULL) {
        total *= p->angka;
        p = p->next;
    }
    return total;
}
