#include "Singlylist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

/* ================= DELETE ================= */

void deleteFirst(List &L, address &P) {
    P = L.first;
    L.first = P->next;
    P->next = NULL;
}

void deleteLast(List &L, address &P) {
    address Q;
    if (L.first->next == NULL) {
        P = L.first;
        L.first = NULL;
    } else {
        Q = L.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = NULL;
    }
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

/* ================= COUNT & DELETE ALL ================= */

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.first != NULL) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
