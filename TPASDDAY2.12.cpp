#include <iostream>
#include <string>
using namespace std;
 

typedef struct {
    string nama;
    int umur;
} InfoData;
 

typedef struct {
    int top;
    InfoData Dat[10];
} stack;
 

void buatSTkosong(stack *S) {
    (*S).top = -1;
}
 

bool isKosong(stack S) {
    bool hasil = false;
    if (S.top == -1) {
        hasil = true;
    }
    return hasil;
}
 

bool isPenuh(stack S) {
    bool hasil = false;
    if (S.top == 9) {
        hasil = true;
    }
    return hasil;
}
 

void push(string nama, int umur, stack *S) {
    if (isPenuh(*S) == 1) {
        cout << "Stack Penuh" << endl;
    } else {
        if (isKosong(*S) == 1) {
            
            (*S).top = 0;
            (*S).Dat[0].nama = nama;
            (*S).Dat[0].umur = umur;
        } else {
            
            (*S).top = (*S).top + 1;
            (*S).Dat[(*S).top].nama = nama;
            (*S).Dat[(*S).top].umur = umur;
        }
    }
}
 

void Pop(stack *S) {
    if ((*S).top == 0) {
       
        (*S).top = -1;
    } else {
        if ((*S).top != -1) {
            
            (*S).top = (*S).top - 1;
        }
    }
}
 

void CetakNamaUmur(stack S) {
    if (S.top != -1) {
        for (int i = 0; i <= S.top; i++) {
            cout << "Nama & Umur : " << S.Dat[i].nama;
            
            int pad = 8 - S.Dat[i].nama.length();
            for (int j = 0; j < pad; j++) cout << " ";
            cout << "- " << S.Dat[i].umur << endl;
        }
    } else {
        cout << "Stack Kosong" << endl;
    }
}
 

void garis() {
    for (int i = 0; i < 65; i++) cout << "~";
    cout << endl;
}
 

void CetakSatuBaris(stack S) {
    if (S.top != -1) {
        cout << "Nama : ";
        for (int i = 0; i <= S.top; i++) {
            cout << S.Dat[i].nama << " --" << S.Dat[i].umur;
            if (i < S.top) cout << "   ";
        }
        cout << endl;
    } else {
        cout << "Stack Kosong" << endl;
    }
}
 

bool hapusData(string nama, stack *S) {
    int posisi = -1;
    for (int i = 0; i <= (*S).top; i++) {
        if ((*S).Dat[i].nama == nama) {
            posisi = i;
            break;
        }
    }
    if (posisi == -1) return false;
 
    
    for (int i = posisi; i < (*S).top; i++) {
        (*S).Dat[i] = (*S).Dat[i + 1];
    }
    (*S).top--;
    return true;
}
 

void CetakSetelahHapus(stack S) {
    if (S.top != -1) {
        for (int i = 0; i <= S.top; i++) {
            cout << S.Dat[i].nama << " --" << S.Dat[i].umur;
            if (i < S.top) cout << "   ";
        }
        cout << endl;
    } else {
        cout << "Stack Kosong" << endl;
    }
}
 
int main() {
    stack S;
 
    buatSTkosong(&S);
 
    
    push("Fanny",   10, &S);
    push("Tiara",   63, &S);
    push("Ilham",   28, &S);
    push("Cinthya", 66, &S);
    push("Candra",  22, &S);
 
    CetakNamaUmur(S);
    cout << endl;
    garis();
    CetakSatuBaris(S);
    garis();
 
    hapusData("Tiara", &S);
 
    cout << endl;
    garis();
    CetakSetelahHapus(S);
 
    cin.get();
  
}