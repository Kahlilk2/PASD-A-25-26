#include <iostream>
#include <string>
using namespace std;
// bagian 1
typedef struct{
	string npm;
	string nama_mhs;
	double nilai;
} nilaiMK;
// bagian 2
typedef struct elm *alamatelm;
typedef struct elm{
	nilaiMK kontainer;
	alamatelm next;
} elemen;
// bagian 3
typedef struct{
	elemen *first;
	elemen *last;
} queue;
// bagian 4
void buatQUkosong (queue *Q){
	(*Q).first = NULL;
	(*Q).last = NULL;
}
// bagian5
int iskosong(queue Q){
	bool hasil = false;
	
	if(Q.first == NULL){
		hasil = true;
	}
	return hasil;
}
// bagian6
int jmlelemen (queue Q){
	int hasil = 0;
	
	if(Q.first != NULL) {
		elemen *bantu;
		bantu = Q.first;
	
	while(bantu != NULL){
		hasil = hasil + 1;
		bantu = bantu -> next;
	}
	}
	return hasil;
}

void ADD(string npm, string nama_mhs, double nilai, queue *Q){
	elemen *info;
	info = new elemen;
	info -> kontainer.npm = npm;
	info -> kontainer.nama_mhs = nama_mhs;
	info -> kontainer.nilai = nilai;
	info -> next = NULL;

		if((*Q).first == NULL){
			(*Q).first = info;
		}
		else{
			(*Q).last -> next = info;
		}
		(*Q).last = info;
		info = NULL;
}

void DEL(queue *Q){
	if ((*Q).first != NULL);{
		elemen *hapus = (*Q).first;
		if(jmlelemen(*Q) == 1){
		(*Q).first = NULL;
		(*Q).last = NULL;
	}
	else {
		(*Q).first = (*Q).first -> next;
		hapus -> next = NULL;
	}
	delete hapus;
	}
}

void cetakqueue(queue Q){
	if(Q.first != NULL){
		cout << "menampilkan queue" << endl;
		elemen *bantu = Q.first;
		int i = 1;
		while (bantu != NULL)
		{
		
			cout << "-------------------------------------" << endl;
			cout << "elemen ke               :" << i << endl;
			cout << "nomor pokok mahasiswa   :" << bantu -> kontainer.npm << endl;
			cout << " nama mahasiswa         :" << bantu -> kontainer.nama_mhs << endl;
			cout << " nilai mahasiswa        :" << bantu -> kontainer.nilai << endl;
			
		bantu = bantu -> next;
		i = i + 1;
		}	
		cout << "--------------------------------------" << endl;
	}
	else {
		cout << "queue kosong " << endl;
	}
}

int main(){
	queue Q;
	buatQUkosong(&Q);
	cetakqueue(Q);
	cout << endl;
	cout << "------------------------------" << endl;
	ADD ("4525210666", "budi", 88.75, &Q);
	ADD ("4525210777", "susi", 98.65, &Q);
	ADD ("4525210888", "nuri", 78.85, &Q);
	ADD ("4525210999", "bimo", 68.55, &Q);
	ADD ("4525210555", "arif", 78.85, &Q);
	ADD ("4525210444", "rido", 98.65, &Q);
	ADD ("4525210222", "fila", 68.55, &Q);
	cetakqueue(Q);
	cout << "=========================" << endl;
	cout << endl;
	cout << endl;
	DEL(&Q);
	cetakqueue(Q);
	cout << endl;
	cout << endl;
	DEL(&Q);
	cetakqueue(Q);
	cout << "=========================" << endl;
	return 0;
}
	
