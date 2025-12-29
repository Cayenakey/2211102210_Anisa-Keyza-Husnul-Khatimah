#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int i = 0, j = S.top;
    while (i < j) {
        infotype temp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = temp;
        i++;
        j--;
    }
}

void pushAscending(Stack &S, infotype x) {
    int i = S.top;

    // geser elemen yang lebih besar dari x
    while (i >= 0 && S.info[i] > x) {
        S.info[i + 1] = S.info[i];
        i--;
    }

    // sisipkan x pada posisi yang tepat
    S.info[i + 1] = x;
    S.top++;
}

void getInputStream(Stack &S) {
    char ch;
    cout << "Masukkan input (tekan ENTER untuk selesai): ";

    while (true) {
        ch = cin.get();        // baca 1 karakter
        if (ch == '\n') {     // berhenti saat ENTER
            break;
        }
        if (ch >= '0' && ch <= '9') {
            push(S, ch - '0'); // konversi char ke int
        }
    }
}
