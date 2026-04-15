#include <iostream>
#include <string>
using namespace std;

typedef struct{
	string npm;
	string nama_mhs;
	double nilai;
}	NilaiMK;

typedef  struct elm *alamatelm;
typedef struct elm{
	NilaiMK kontainer;
	alamatelm next;
	
}	elemen;

typedef struct {
elemen* top;
}	stack;

void buatSTkosong (stack *s){
(*s).top = NULL;
}

int iskosong (stack s){
bool hasil = false;

if(s.top == NULL){
hasil = true;
}
return hasil;
}
int jmlElemen (stack s){
	int hasil = 0;
	
	if (s.top != NULL){
	elemen *bantu;
	bantu = s.top;
	while(bantu !=NULL){
	hasil = hasil +1;
	bantu = bantu -> next;
	}
}
return hasil;
}
void push (string npm, string nama_mhs, double nilai, stack *s)	{
	elemen * info;
	info = new elemen;
	info -> kontainer.npm = npm;
	info -> kontainer.nama_mhs = nama_mhs;
	info -> kontainer.nilai = nilai;
	
	if((*s).top == NULL){
		cout << "stack penuh" << endl;
		info-> next = NULL;
		}
		else{
		info -> next = (*s).top;
		}
	(*s).top = info;
	info = NULL;
}

void pop(stack *s) {
	if ((*s).top != NULL){
	elemen *hapus = (*s).top;
	
	if(jmlElemen(*s) == 1) {
	(*s).top = NULL;
	}
	else {
	(*s).top = (*s).top -> next;
	}
	hapus -> next = NULL;
	delete hapus;
	}
	else {
	cout << "stack kosong" << endl;
	}
}

void cetakstack(stack s){
	if(s.top != NULL){
		cout << "menampilkan stack" << endl;
		elemen *bantu = s.top;
		int i = 1;
		while(bantu != NULL)
		{
			cout << "-----------------------------------------------" << endl;
			cout << "elemen ke                           : " << i << endl;
			cout << "nomor pokok mahasiswa               : " << bantu -> kontainer.npm << endl;
			cout << "nama mahasiswa                      : " << bantu -> kontainer.nama_mhs << endl;
			cout << "nilai mahsiswa                      : " << bantu -> kontainer.nilai << endl;
			bantu = bantu -> next;
			i = i + 1;
		}
		cout << "-----------------------------------------------" << endl;
	}
	else 
		{
			cout << "stack kosong" << endl;
		}
}

int main (){
 
	stack s;
	
	buatSTkosong(&s);
	cetakstack(s);
	cout << endl;
	cout << endl;
	cout << "-------------------------------"<< endl;
	push ("4523210666", "budi", 88.75, &s);
	push ("4523210777", "susi", 78.55, &s);
	push ("4523210888", "nuri", 98.65, &s);
	push ("4523210999", "bimo", 68.65, &s);
	push ("4523210222", "simo", 78.85, &s);
	push ("4523210333", "arif", 98.75, &s);
	push ("4523210444", "ella", 78.55, &s);
	cetakstack (s);
	cout << "==============================" << endl;
	cout << endl;
	cout << endl;
	pop(&s);
	cetakstack(s);
	cout << endl;
	cout << endl;
	pop(&s);
	cetakstack(s);
	cout << "==============================" << endl;
	cin.get();
}