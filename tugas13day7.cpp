#include<string.h>
#include<iostream>
using namespace std;

int A[] = {45, 25, 21, 23, 30, 35, 40, 33};
int n = 8;

void tukar(int a, int b)
{
	int t;
	t = A[b];
	A[b] = A[a];
	A[a] = t;
}

void tampil()
{
	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void bubble_sort_des()
{
	int k, flag, i, x;
	k = 0;
	flag = 1;
	while(k <= n-2 && flag == 1){
		i = 0;
		flag = 1;
		while(i <= n-2-k){
			if(A[i] < A[i+1]){
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

int main()
{
	cout <<"*----------------------------*" << endl;
	cout <<"*selamat datang di aplikasi  *" << endl;
	cout <<"*bubble sort descending      *" << endl;
	cout <<"*----------------------------*" << endl;
	
	cout << "\ndata awal   : ";
	tampil();
	
	cout <<"\nproses bubble sort descending...." << endl;
	cout <<"-----------------------------------" << endl;
	
	bubble_sort_des();
	
	cout << "\ndata terurut (descending) : ";
	tampil();
	
	cout <<"*----------------------------*" << endl;
	cout <<"terima kasih" << endl;
	cout <<"*----------------------------*" << endl;
	cin.get();
}	
	