#include <iostream>
using namespace std;

struct barang{
	public:
	char kode [12];
	char nama [40];
	float harga;
	};

int main (){
	barang brg;
	cout << "masukan kode barang   = " ; cin >> brg.kode;
	cout << "masukan nama barang   = " ; cin >> brg.nama;
	cout << "masukan harga barang  = " ; cin >> brg.harga;
	cout << endl;
	cout << " -------------------------------------------- " << endl;
	cout << "               data barang yang tersimpan                    " << endl;	
	cout << " -------------------------------------------- " << endl;
	cout << "kode barang  = " <<brg.kode<< endl;
	cout << "nama barang  = " << brg.nama << endl;
	cout << "harga barang = " <<brg.harga<< endl;
	cout << endl;

cin.get();
}