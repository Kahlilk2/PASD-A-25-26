#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
#define true 1
#define false 0

struct biodata {
	char nama[20];
	int usia;
};
struct biodata mhs;
struct biodata queue[MAX];
void init(void);
int full(void);
int empty(void);
struct biodata entridata(void);
void enqueue (struct biodata mhs);
struct biodata dequeue(void);
void display (struct biodata mhs);
void baca(void);
int awal,akhir;
char nocomment[10];

int main(){
char pilih;
cout <<" == program entri data mahasiswa ==\n";
init();
do{
	cout << " menu pilihan : \n";
	cout << "1. input data\n";
	cout << "2. hapus data\n";
	cout << "3. lihat daftar mahasiswa\n";
	cout << "4. hapus semua data\n";
	cout << "5. selesai.\n";
	cout << "pilihan 1 sd 5 : ";
	cin >> pilih;
	switch(pilih){
		case '1' : mhs = entridata(); enqueue(mhs); break;
		case '2' : cout << "\ndata yang dihapus : \n";
				mhs = dequeue(); display(mhs); break;
		case '3' : baca(); break;
		case '4' : init(); cout <<"\ndata telah kosong\n";			break;
		case '5' : break;
		default : cout << "pilih 1 sd 5!";
				break; }
	cout << "\n";
}while(pilih != '5');
return 0; }

void init(void){
	awal = -1;
	akhir = -1;
}
void enqueue(struct biodata mhs){
	if(empty() == true){
		awal = 0;
		akhir = 0;
		queue[awal] = mhs;
	}else if(full()!= true){
	akhir++;
	queue[akhir]=mhs;
	}else cout << "queue sudah penuh...\n";
}

struct biodata dequeue(void){
	int i;
	if (empty() != true){
		mhs=queue[awal];
		for(i=awal; i<=akhir;i++)
			queue[i]=queue[i+1];
		akhir--;
		
	}else cout << "queue kosong...\n";
return(mhs);
}
int full(void){
	if(akhir == MAX-1) return(true);
	else return(false);
}
int empty(void){
	if(akhir == -1) return(true);
	else return(false);
}

void baca(void){
	int i;
	cout << "\nisi queue  : \n";
	if(empty() != true){
		for(i=awal; i<=akhir; i++){
			display(queue[i]);
		}
	}else cout << "data kosong";
	cout << endl;
}

struct biodata entridata(void){
	struct biodata mhs;
	cout << "\n";
	cout << "masukan nama : "; cin >> mhs.nama;
	cout << "masukan usia : "; cin >> mhs.usia;
	return(mhs);
}
void display(struct biodata mhs){
	cout << endl;
	cout << "nama : " << mhs.nama << "\n";
	cout << "usia : " << mhs.usia << "\n";
}