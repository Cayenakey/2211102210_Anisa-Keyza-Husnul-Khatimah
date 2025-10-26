#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

// =======================
// TYPE DEFINITION
// =======================
typedef int dataAngka;

struct node {
    dataAngka angka;
    node* next;
};

typedef node* address;

struct linkedList {
    address first;
};

// =======================
// FUNCTION & PROCEDURE DECLARATIONS
// =======================

// Dasar Linked List
void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &p);
void printList(linkedList L);
void insertFirst(linkedList &L, address p);
void insertLast(linkedList &L, address p);
void insertAfter(linkedList &L, address p, address prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &pHapus, address prec);

// Update
void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address prec);

// Search
void SearchByData(linkedList L, int data);
void SearchByAddress(linkedList L, address nodeCari);
void SearchByRange(linkedList L, int nilaiMin);

// Aritmetika
int sumList(linkedList L);
int subList(linkedList L);
int mulList(linkedList L);

#endif
