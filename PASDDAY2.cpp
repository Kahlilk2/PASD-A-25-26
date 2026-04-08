//contoh 1 day 2 pasd

#include <iostream>
#include <string>
using namespace std;

typedef int angka;
typedef float pecahan;
typedef char huruf[30];

int main(){
	angka umur;
	pecahan pecah;
	huruf nama;
	huruf karakter;
	cout << " masukan umur anda  : " ; cin >> umur;
	cout << " umur anda adalah " << umur << endl;
	cout << endl;
	cout << " masukan bilangan pecahan  : " ; cin >> pecah;
	cout << " bilangan pecahan " << pecah << endl;
	cout << endl;
	cout << " masukan nama : " ; cin >> nama;
	cout << " nama amda " << nama << endl;
	cout << endl;
	cout << " masukan satu huruf : " ; cin >> karakter;
	cout << " satu hurud " << karakter << endl;
	cout << endl;
	
	cin.get();
}
