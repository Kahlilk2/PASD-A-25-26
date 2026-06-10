#include <iostream>
using namespace std;

struct dataarray{
	int *data;
	int jmlelemen;
};

int search12(dataarray arr, int elemen);

int main()
{
	dataarray arr;
	
	cout << "*******************" << endl;
	cout <<"**sequental search**" << endl;
	cout << "*******************" << endl;
	
	cout << "masukan jumlah elemen array :";
	cin >> arr.jmlelemen;
	
	arr.data = new int [arr.jmlelemen];
	
	cout << endl;
	cout << "isi daya nya adalah" << endl;
	cout << "-------------------" << endl;
	
	for (int i = 0; i < arr.jmlelemen; i++)
	{
		cout << "masukan data ["<< i <<"] :";
		cin >> arr.data[i];
	}
	
	cout << endl;
	cout << "data yang telah dimasukan : " << endl;
	cout << "----------------------------" << endl;
	
	for (int count = 0; count < arr.jmlelemen; count++)
	{
		cout << "\t" << "data["<< count << "] " << " --> " << arr.data[count] << endl;
	}
	
	int searchelemen = 0;
	int flaq = 0;
	cout << "*******************" << endl;
	cout << endl;
	cout << "masukan data yang akan anda cari ?"; cin >> searchelemen;
	
	flaq = search12(arr, searchelemen);
	if (flaq != -1)
		cout <<"data yang dicari ditemukan pada posisi : data["<< flaq <<"]" << endl;
	else
		cout << "data yang anda cari tidak ditemukan" << endl;
	
	delete[] arr.data;
	cin.get();
	return 0;

}

int search12(dataarray arr, int elemen)
{
		int flaq = -1;
		for (int count = 0; count< arr.jmlelemen; count++)
		{
			if(elemen == arr.data[count])
			{
				flaq = count;
				break;
			}
		}
		return flaq;
	}
	