#include <iostream>
#include <string>
using namespace std;

typedef struct{
	string npm;
	string nama_mhs;
	double nilai;
} nilaiMK;

typedef struct{
	int first;
	int last;
	nilaiMK dat[10];
} queue;

void buatQUkosong (queue *Q){
	(*Q).first = -1;
	(*Q).last = -1;
}

bool iskosong(queue Q){
	bool hasil = false;
	
	if(Q.first == -1){
		hasil = true;
	}
	return hasil;
}
bool ispenuh (queue Q){
	bool hasil = false;
	
	if(Q.last == 9) {
		hasil = true;
	}
	return hasil;
}

void ADD(string npm, string nama_mhs, double nilai, queue *Q){
	if (iskosong(*Q) == 1){
		(*Q).first = 0;
		(*Q).last = 0;
		(*Q).dat[0].npm = npm;
		(*Q).dat[0].nama_mhs = nama_mhs;
		(*Q).dat[0].nilai = nilai;
	}
	else {
		if(ispenuh(*Q) != 1){
			(*Q).last = (*Q).last + 1;
			(*Q).dat[(*Q).last].npm = npm;
			(*Q).dat[(*Q).last].nama_mhs = nama_mhs;
			(*Q).dat[(*Q).last].nilai = nilai;
		}
		else{
			cout << "QUEUE PENUH" << endl;
		}
	}
}

void DEL(queue *Q){
	if ((*Q).last == 0){
		(*Q).first = -1;
		(*Q).last = -1;
	}
	else {
		int i;
		for (i=((*Q).first + 1); 1<= (*Q).last; i++){
			(*Q).dat[i-1].npm = (*Q).dat[i].npm;
			(*Q).dat[i-1].nama_mhs = (*Q).dat[i].nama_mhs;
			(*Q).dat[i-1].nilai = (*Q).dat[i].nilai;
		}
		(*Q).last = (*Q).last - 1;
	}
}

void cetakqueue(queue Q){
	if(Q.first != -1){
		cout << "menampilkan queue" << endl;
		cout << "-----------------" << endl;
		int i;
		for(i=Q.last; i>=Q.first; i--){
			cout << "-------------------------------------" << endl;
			cout << "elemen ke               :" << i << endl;
			cout << "nomor pokok mahasiswa   :" << Q.dat[i].npm << endl;
			cout << " nama mahasiswa         :" << Q.dat[i].nama_mhs << endl;
			cout << " nilai mahasiswa        :" << Q.dat[i].nilai << endl;
			cout << "--------------------------------------" << endl;
		}
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
	
