#include <iostream>
#include <string>
using namespace std;

int main()
{
	struct DATABUKU{
	string k_jdlbuku;
	string k_pengarang;
	float k_terbit;
	float k_harga;}
	
	MATAKULAH Data_BK;
	
	Data_BK.k_jdlbuku = "laskar pelangi"
	Data_BK.k_pengerang = "kahlil"
	Data_BK.k_terbit = 2024;
	Data_BK.k_harga = 50000
	cout<<endl;
	cout<<endl;
	cout << "judul buku = " << Data_BK.k_jdlbuku << endl;
	cout << "pengarang  = " << Data_BK.k_pengerang << endl;
	cout << "tahun terbit = " << Data_BK.k_terbit << endl;
	cout << "harga        = " << Data_BK.k_harga << endl;
	cin.get();
}
	
	
	
	