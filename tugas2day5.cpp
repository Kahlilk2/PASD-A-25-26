#include <iostream>
#include <string>
using namespace std;

typedef struct{
	string npm;
	string nama_mhs;
	double nilai;
} nilaiMK;

typedef struct elm *alamatelm;
typedef struct elm{
	nilaiMK kontainer;
	alamatelm next;
} elemen;

class queue{
private:
	elemen *first;
	elemen *last;

public:

queue(){
	first = NULL;
	last = NULL;
}

int iskosong(){
	bool hasil = false;
	
	if(first == NULL){
		hasil = true;
	}
	return hasil;
}

int jmlelemen (){
	int hasil = 0;
	
	if(first != NULL) {
		elemen *bantu;
		bantu = first;
	
	while(bantu != NULL){
		hasil = hasil + 1;
		bantu = bantu -> next;
	}
	}
	return hasil;
}

void ADD(string npm, string nama_mhs, double nilai){
	elemen *info;
	info = new elemen;
	info -> kontainer.npm = npm;
	info -> kontainer.nama_mhs = nama_mhs;
	info -> kontainer.nilai = nilai;
	info -> next = NULL;

		if(first == NULL){
			first = info;
		}
		else{
			last -> next = info;
		}
		last = info;
		info = NULL;
}

void DEL(){
	if (first != NULL);{
		elemen *hapus = first;
		if(jmlelemen() == 1){
		first = NULL;
		last = NULL;
	}
	else {
		first = first -> next;
		hapus -> next = NULL;
	}
	delete hapus;
	}
}

void cetakqueue(){
	if(first != NULL){
		cout << "menampilkan queue" << endl;
		elemen *bantu = first;
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
};

int main(){
	queue Q;
	Q.cetakqueue();
	cout << endl;
	cout << "------------------------------" << endl;
	Q.ADD ("4525210666", "budi", 88.75 );
	Q.ADD ("4525210777", "susi", 98.65 );
	Q.ADD ("4525210888", "nuri", 78.85 );
	Q.ADD ("4525210999", "bimo", 68.55 );
	Q.ADD ("4525210555", "arif", 78.85 );
	Q.ADD ("4525210444", "rido", 98.65 );
	Q.ADD ("4525210222", "fila", 68.55 );
	Q.cetakqueue();
	cout << "=========================" << endl;
	cout << endl;
	cout << endl;
	Q.DEL();
	Q.cetakqueue();
	cout << endl;
	cout << endl;
	Q.DEL();
	Q.cetakqueue();
	cout << "=========================" << endl;
	return 0;
}
	
