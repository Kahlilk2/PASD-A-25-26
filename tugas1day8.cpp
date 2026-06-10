#include <iostream>
using namespace std;

int search01(int A[], int jmlelemenarray, int elemen);

int main()
{
	int jmlelemenarray;
	
	cout << "*******************" << endl;
	cout <<"**sequental search**" << endl;
	cout << "*******************" << endl;
	
	cout << "masukan jumlah elemen array :";
	cin >> jmlelemenarray;
	
	int *data = new int [jmlelemenarray];
	
	cout << endl;
	cout << "isi daya nya adalah" << endl;
	cout << "-------------------" << endl;
	
	for (int i = 0; i < jmlelemenarray; i++)
	{
		cout << "masukan data ["<< i <<"] :";
		cin >> data[i];
	}
	
	cout << endl;
	cout << "data yang telah dimasukan : " << endl;
	cout << "----------------------------" << endl;
	
	for (int count = 0; count < jmlelemenarray; count++)
	{
		cout << "\t" << "data["<< count << "] " << " --> " << data[count] << endl;
	}
	
	int searchelemen = 0;
	int flaq = 0;
	cout << "*******************" << endl;
	cout << endl;
	cout << "masukan data yang akan anda cari ?"; cin >> searchelemen;
	
	flaq = search01(data, jmlelemenarray, searchelemen);
	if (flaq != -1)
		cout <<"data yang dicari ditemukan pada posisi : data["<< flaq <<"]" << endl;
	else
		cout << "data yang anda cari tidak ditemukan" << endl;
	cin.get();
	return 0;
	
	delete[] data;
}

int search01(int tika[], int jmlelemenarray, int elemen)
{
		int flaq = -1;
		for (int count = 0; count< jmlelemenarray; count++)
		{
			if(elemen == tika[count])
			{
				flaq = count;
				break;
			}
		}
		return flaq;
	}
	