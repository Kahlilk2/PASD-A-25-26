#include <iostream>
#include <string>
using namespace std;

struct khl {
    string info;
    khl* next;
};

struct Stack {
    khl* top;
};

void buatKosong(Stack *s) {
    s->top = NULL;
}

void pushDepan(string x, Stack *s) {
    khl* baru = new khl;
    baru->info = x;
    baru->next = s->top;
    s->top = baru;
}

void tampil(Stack s) {
    khl* bantu = s.top;
    while (bantu != NULL) {
        cout << bantu->info << endl;
        bantu = bantu->next;
    }
}

khl* cari(string x, Stack s) {
    khl* bantu = s.top;
    while (bantu != NULL) {
        if (bantu->info == x) return bantu;
        bantu = bantu->next;
    }
    return NULL;
}

void tambahsetelah(string setelah, string dataBaru, Stack *s) {
    khl* p = cari(setelah, *s);
    if (p != NULL) {
        khl* baru = new khl;
        baru->info = dataBaru;
        baru->next = p->next;
        p->next = baru;
    }
}

void tambahPalingBawah(string dataBaru, Stack *s) {
    khl* baru = new khl;
    baru->info = dataBaru;
    baru->next = NULL;

    if (s->top == NULL) {
        s->top = baru;
        return;
    }

    khl* bantu = s->top;
    while (bantu->next != NULL) {
        bantu = bantu->next;
    }
    bantu->next = baru;
}

int main() {
    Stack S;
    buatKosong(&S);

    pushDepan("Maemo", &S);
    pushDepan("Symbian", &S);
    pushDepan("Mac", &S);
    pushDepan("Windows", &S);
    pushDepan("Iphone", &S);

    tambahsetelah("Iphone", "Iphone 5", &S);
    tambahsetelah("Windows", "Windows Phone", &S);
    tambahsetelah("Mac", "SnowLeopard", &S);
    tambahsetelah("Symbian", "Symbian Belle", &S);
    tambahPalingBawah("Maemo 4", &S);

    tampil(S);
    return 0;
}