#include <iostream>
using namespace std;

struct mahasiswa {
	public:
	char npm [12];
	char nama [40];
	float ipk;
	};

int main (){
	mahasiswa mhs;
	cout << "nomor pokok mahasiswa    = " ; cin >> mhs.npm;
	cout << "nama mahasiswa           = " ; cin >> mhs.nama;
	cout << "index prestasi kumulatif = " ; cin >> mhs.ipk;
	cout << endl;
	cout << " -------------------------------------------- " << endl;
	cout << "               data saya                      " << endl;	
	cout << " -------------------------------------------- " << endl;
	cout << "nomor pokok mahasiswa    = " << mhs.npm << endl;
	cout << "nama mahasiswa           = " << mhs.nama << endl;
	cout << "index prestasi kumulatif = " << mhs.ipk << endl;
	cout << endl;

cin.get();
}