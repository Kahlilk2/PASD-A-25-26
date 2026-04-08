#include <iostream>
#include <string.h>
using namespace std;

typedef struct{
	string npm;
	string nama_mhs;
	double nilai;
}	nilaiMK;


typedef struct {
	int top;
	nilaiMK dat[20];
}	stack;


void buatSTkosong(stack *S){
	(*S).top = -1;
}

bool iskosong(stack S){
	bool hasil = false;
	
	if (S.top == -1) {
	hasil = true;
	}
	return hasil;
}

bool ispenuh (stack S){
	bool hasil = false;
	
	if (S.top == 9){
	hasil = true;
	}
	return hasil;
}

void push(string npm, string nama_mhs, double nilai, stack *S) {
	if (ispenuh(*S) == 1){
		cout << "stack penuh" << endl;
	}
	else{
	if(iskosong(*S) == 1){
	(*S).top = 0;
	(*S).dat[0].npm = npm;
	(*S).dat[0].nama_mhs = nama_mhs;
	(*S).dat[0].nilai = nilai;
	}
	else{
	(*S).top = (*S).top + 1;
	(*S).dat[0].npm = npm;
	(*S).dat[0].nama_mhs = nama_mhs;
	(*S).dat[0].nilai = nilai;
	}
	}
}

void pop (stack *S){
	if((*S).top == 0) {
	(*S).top = -1;
	}
	else{
		if((*S).top != -1) {
		(*S).top = (*S).top -1;
		}
	}
}

void cetakstack(stack S)
{
 if (S.top != -1)
 {
	cout << "menampilkan stack " << endl;
	int i;
	for(i=S.top; i>=0; i--)
	{
		cout << "-------------------------------------------" << endl;
		cout << " elemen ke                          : " << i << endl;
		cout << " nomor pokok mahasiwa               : " << S.dat[i].npm<< endl;
		cout << " nama mahasiswa                     : " << S.dat[i].nama_mhs << endl;
		cout << " nilai mahasiwa                     : " << S.dat[i].nilai << endl;
		cout << "-------------------------------------------" << endl;
	}
}
else	
	{
	cout << "stack kosong " << endl;
	}
}

int main(){
	stack S;
	
	buatSTkosong(&S);
	cetakstack(S);
	cout << endl;
	cout << endl;
	cout << "-----------------------" << endl;
	push("4525210030", "kahlil", 90.85, &S);
	push("4525210014", "antonio", 80.85, &S);
	push("4525210019", "dafa", 50.75, &S);
	push("4525210031", "karel", 60.78, &S);
	cetakstack(S);
	cout << "=======================" << endl;
	cout << endl;
	cout << endl;
	pop(&S);
	cetakstack(S);
	cout << endl;
	cout << endl;
	pop(&S);
	cetakstack(S);
	cout << "=======================" << endl;

cin.get();
}

