
#include<stdio.h>
#include<iostream>
#include<stdlib.h>  
#include<string.h>
using namespace std;
void BUAT_SIMPUL(int X);
void AWAL();
void CETAK();
void INSERTKANAN();
struct Node {      
    int INFO;
    struct Node *LINK;
};
typedef struct Node Simpul;
Simpul *P, *FIRST, *LAST, *Q; 
int X;
int main() {
    int A[7] = {101,102,103,104,105}; 
    int I;
    FIRST = NULL;  
    I=0;
    X=A[I];
    BUAT_SIMPUL(X);
    AWAL();       
    for(I=1; I<=4; I++)   
    {                     
        X=A[I];
        BUAT_SIMPUL(X);
        INSERTKANAN();
    }
    cout<<"daftar nomor antrian sekarang :   ";
    CETAK();
    X = 999;
    BUAT_SIMPUL(X);
    INSERTKANAN();   
    cout<<endl;
    cout<<"daftar antrian pengan baru :   ";
    CETAK();
    cout<<endl;
    cin.get();
}

void BUAT_SIMPUL(int X)   //Fungsi membuat sebuah simpul baru
{
    P=(Simpul*) malloc(sizeof(Simpul));
    if(P != NULL) {
        P -> INFO = X;
    }
    else {
        cout<<"Pembuatan Simpul Tidak Berhasil"<<endl;
        cin.get();
        exit(1);
    }
}

void AWAL()   //Fungsi membuat simpul awal
{
    FIRST = P;
    LAST = P;
    P -> LINK = NULL;
}

void INSERTKANAN()    //Fungsi menginsert simpul disebelah kanan
{
    LAST -> LINK = P;
    LAST = P;
    P -> LINK = NULL;
}

void CETAK()    //Fungsi mencetak isi seluruh simpul
{
    int X;
    Q = FIRST;
    while(Q != NULL) {
        X = Q -> INFO;
        cout<<" "<< X;
        Q = Q -> LINK;
    }
}