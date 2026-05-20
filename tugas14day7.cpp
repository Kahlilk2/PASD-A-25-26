#include<string.h>
#include<iostream>
using namespace std;

class bubblesort
{
	private:
	int A[10];
	int n;
	
	public:
	void input()
	{
		cout << "masukan jumlah data = ";
		cin >> n;
		cout << endl;
		
		for(int i = 0; i < n ; i++)
		{
			cout << "masukan data ke-" << " = ";
			cin >> A[i];
		}
		cout << endl;
	}

void tampil()
{
	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void bubble_sort_asc()
{
	int k, flag, i, x;
	k = 0;
	flag = 1;
	while(k <= n-2 && flag == 1){
		i = 0;
		flag = 1;
		while(i <= n-2-k){
			if(A[i] > A[i+1]){
				flag = 1;
				x = A[i];
				A[i] = A[i+1];
				A[i+1] = x;
			}
			i++;
		}
		k++;
	}
}

void proses()
{
	cout <<" \ndata awal  : ";
	tampil();
	
	cout <<"\nproses bubble sort ascending...." << endl;
	cout <<"-----------------------------------" << endl;
	
	bubble_sort_asc();
	
	cout << "\ndata terurut (ascending) : ";
	tampil();
}
};

int main()
{
	bubblesort obj;
	
	cout <<"*----------------------------*" << endl;
	cout <<"*selamat datang di aplikasi  *" << endl;
	cout <<"*bubble sort ascending     *" << endl;
	cout <<"*----------------------------*" << endl;
	
	obj.input();

	
	cout <<"\nproses bubble sort ...." << endl;
	cout <<"-----------------------------------" << endl;
	
	obj.proses();
	
	cout <<"*----------------------------*" << endl;
	cout <<"terima kasih" << endl;
	cout <<"*----------------------------*" << endl;
	cin.get();
}	
	