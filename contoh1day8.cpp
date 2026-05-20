#include <iostream>
using namespace std;

int search01(int A[], int, int);
int main()
{
	const int jmlelemenarray = 11;
	int tika[jmlelemenarray] = {22,61,15,66,18,25,34,87,55,45,10};
	cout << "*******************" << endl;
	cout <<"**sequental search**" << endl;
	cout << "*******************" << endl;
	cout << "isi data nya adalah" << endl;
	cout << "___________________" << endl;
	cout << endl;	
	for (int count = 0; count < jmlelemenarray; count++)
	{
		cout <<"\t"<<"data"<<count<<"j"<< "-->"<< tika[count] << endl;
	}
	int searchelemen = 0;
	int flaq = 0;
	cout << "*******************" << endl;
	cout << endl;
	cout << "masukan data yang akan anda cari ?"; cin >> searchelemen;
	
	flaq = search01(tika, jmlelemenarray, searchelemen);
	if (flaq != -1)
		cout <<"data yang dicari ditemukan pada posisi : data["<< flaq <<"]" << endl;
	else
		cout << "data yang anda cari tidak ditemukan" << endl;
	cin.get();
	return 0;
}
int searc01(int tika[], int jmlelemenarray, int elemen)
	{
		int flaq = -1;
		for (int count = 0; count < jmlelemenarray; count++)
		{
			if(elemen == tika[count])
			{
				flaq = count;
				break;
			}
		}
		return flaq;
	}