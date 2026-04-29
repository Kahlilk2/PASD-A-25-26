#include <iostream>
#include <string>
using namespace std;
// bagian 1
typedef struct{
	string kode_barang;
	string nama_barang;
	int jumlah_stok;
	
} nilaiMK;
// bagian 2
typedef struct elm *pointerelm;
typedef struct elm{
	nilaiMK kontainer;
	pointerelm next;
} pointer;
// bagian 3
typedef struct{
	pointer *first;
	pointer *last;
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
		pointer *bantu;
		bantu = Q.first;
	
	while(bantu != NULL){
		hasil = hasil + 1;
		bantu = bantu -> next;
	}
	}
	return hasil;
}

void ADD(string kode_barang, string nama_barang, int jumlah_stok, queue *Q){
	pointer *info;
	info = new pointer;
	info -> kontainer.kode_barang = kode_barang ;
	info -> kontainer.nama_barang = nama_barang;
	info -> kontainer.jumlah_stok = jumlah_stok;
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
		pointer *hapus = (*Q).first;
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
		pointer *bantu = Q.first;
		int i = 1;
		while (bantu != NULL)
		{
		
			cout << "-------------------------------------" << endl;
			cout << "elemen ke               :" << i << endl;
			cout << "kode barang   :" << bantu -> kontainer.kode_barang << endl;
			cout << " nama  barang         :" << bantu -> kontainer.nama_barang << endl;
			cout << " jumlah stok       :" << bantu -> kontainer.jumlah_stok << endl;
			
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
	ADD ("1", "hanphone", 2, &Q);
	ADD ("2", "kulkas", 3, &Q);
	ADD ("3", "tv", 4, &Q);
	ADD ("4", "laptop", 4, &Q);
	cetakqueue(Q);
	cout << "====== ===================" << endl;
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
	
