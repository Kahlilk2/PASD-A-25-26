#include <iostream>
#include <string>
using namespace std;

typedef struct{
	string nama;
}benda;

typedef struct elm *alamatelm;
typedef struct elm{
	benda kontainer;
	alamatelm next;
}elemen;

typedef struct{
	elemen *first;
	elemen *last;
}queue;

void buatQUkosong(queue *Q){
	(*Q).first = NULL;
	(*Q).last = NULL;;
}

int iskosong(queue Q){
	bool hasil = false;
	if(Q.first == NULL){
		hasil = true;
	}
	return hasil;
}

int jmlelemen (queue Q){
	int hasil = 0;
	if(Q.first != NULL){
		elemen *bantu;
		bantu = Q.first;
		while (bantu !=NULL){
			hasil = hasil + 1;
			bantu = bantu -> next;
		}
	}
	return hasil;
}

void add(string nama, queue *Q){
	elemen *info;
	info = new elemen;
	info -> kontainer.nama = nama;
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

void addsetelah (string target, string nama_baru, queue *Q){
	if((*Q).first !=NULL){
		elemen *bantu = (*Q).first;
		while(bantu != NULL){
			if(bantu -> kontainer.nama == target){
				elemen *info = new elemen ;
				info -> kontainer.nama = nama_baru;
				info -> next = bantu -> next;
				bantu -> next = info;
				if(bantu == (*Q).last){
					(*Q).last = info;
				}
				return;
			}
			bantu = bantu -> next;
		}
		cout << "elemen" << target << "tidak ditemukan" << endl;
	}
	else{
		cout <<"queue kosong" << endl;
	}
}

void delnama(string target, queue *Q){
	if((*Q).first != NULL){
		elemen *bantu = (*Q).first;
		elemen *bantu2 = NULL;
		while (bantu != NULL){
			if (bantu -> kontainer.nama == target){
				if(bantu2 == NULL){
					(*Q).first = bantu -> next;
				}
				else{
					bantu2 -> next = bantu -> next;
				}
				if(bantu == (*Q).last){
					(*Q).last = bantu2;
				}
				bantu -> next = NULL;
				delete bantu;
				return;
			}
			bantu2 = bantu;
			bantu = bantu -> next;
		}
		cout << "elemen" << target << "tidak ditemukan" << endl;
	}
	else {
		cout <<"queue kosong" << endl;
	}
}

void del(queue *Q){
	if((*Q).first != NULL){
		elemen *hapus = (*Q).first;
		
		if(jmlelemen(*Q) == 1){
			(*Q).first = NULL;
			(*Q).last = NULL;
		}
		else{
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
		while (bantu != NULL){
			cout << "-----------------------------------" << endl;
			cout << "elemen ke      : " << i << endl;
			cout << "nama benda     : " << bantu -> kontainer.nama << endl;
			bantu = bantu -> next;
			i=i+1;
		}
		cout <<"-----------------------------------" << endl;
	}
	else {
		cout << "queue kosong" << endl;
	}
}

int main(){
	queue Q;
	buatQUkosong(&Q);
	cout << "queue awal : A-B-C" << endl;
	cout << endl;
	add("A", &Q);
	add("B", &Q);
	add("C", &Q);
	cetakqueue(Q);
	cout << endl;
	
	cout << "a. masukan d setelah a" << endl;
	addsetelah("A", "D", &Q);
	cetakqueue(Q);
	cout << endl;
	
	cout << "b. masukan f paling akhir dengan a, b, c hilang" << endl;
	delnama("A", &Q);
	delnama("B", &Q);
	delnama("C", &Q);
	add("F", &Q);
	cetakqueue(Q);
	cout << endl;
	
	buatQUkosong(&Q);
	add("A", &Q);
	add("B", &Q);
	add("C", &Q);
	
	cout << "c. masukan f paling akhir dengan a, b, c hilang" << endl;
		delnama("A", &Q);
	delnama("B", &Q);
	delnama("C", &Q);
	add("F", &Q);
	cetakqueue(Q);
	cout << endl;
	
	buatQUkosong(&Q);
	add("A", &Q);
	add("B", &Q);
	add("C", &Q);
	
	cout << "d.masukan e setelah b" << endl;
	addsetelah("B", "E", &Q);
	cetakqueue(Q);
	cout << endl;
	
	return 0;
}
	