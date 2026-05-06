#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

void Q_sort(int[], int, int);
int main(){
	int numlist[7] = {85, 92, 78, 90, 88, 75, 95};
	cout << "data sebelum diurut" << endl;
	cout << "-------------------" << endl;
	for (int d=0; d<7; d++){
		cout << setw(3) << numlist[d];
	}
	cout << endl << endl;
	Q_sort(numlist,0 ,6);
	cout << "data setelah diurut" << endl;
	cout << "-------------------" << endl;
	for (int i = 0; i<7 ; i++){
		cout << setw(3)<< numlist[i];
	}
	cin.get ();
}

void Q_sort(int angka[], int kiri, int kanan){
	int pivot, kiri_hold, kanan_hold;
	kiri_hold = kiri;
	kanan_hold = kanan;
	pivot = angka[kiri];
	while (kiri < kanan){
		while ((angka [kanan ] >= pivot) && (kiri < kanan))	kanan--;
		if(kiri !=kanan){
			angka[kiri] = angka[kanan];
			kiri++;}
		while ((angka [kiri] <= pivot) && (kiri < kanan)){
		kiri++;}
		if(kiri != kanan){
			angka[kanan] = angka[kiri];
			kanan--;} }
	angka[kiri] = pivot;
	pivot = kiri;
	kiri = kiri_hold;
	kanan = kanan_hold;
	if(kiri < pivot)
		Q_sort(angka, kiri, pivot-1);
		if (kanan > pivot)
			Q_sort(angka, pivot+1, kanan);
}	
	