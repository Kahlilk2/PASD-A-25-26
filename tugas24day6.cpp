#include <iostream>
using namespace std;

class mergesort{
private:
	int *arr;
	int arrsize;
	
void merge(int arr[], int Kiri, int mid, int Kanan) {
    int n1 = mid - Kiri + 1;
    int n2 = Kanan - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[Kiri + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = Kiri;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int Kiri, int Kanan) {
    if (Kiri < Kanan) {
        int mid = Kiri + (Kanan - Kiri) / 2;
        mergeSort(arr, Kiri, mid);
        mergeSort(arr, mid + 1, Kanan);
        merge(arr, Kiri, mid, Kanan);
    }
}

public:
	mergesort(){
		arr = NULL;
		arrsize = 0;
	}
	~mergesort(){
		if(arr != NULL)
			delete[] arr;
	}

void inputdata(){
	cout << "---------------------------------" << endl;
	cout << " merge sort - ascending inputan  " << endl;
	cout << "---------------------------------" << endl;
	cout << "masukana jumlah data :";
	cin >> arrsize;
	
	arr = new int[arrsize];
	
	for (int i = 0; i < arrsize; i++){
		cout <<" masukan data ke-" << (i + 1) << ": ";
		cin >> arr[i];
	}
}

void CetakData(int data[], int size) {
    for (int i = 0; i < size; i++) {
        cout << " " << data[i];
    }
    cout << endl;
}
void proses(){
 	
	cout << "DATA SEBELUM diurutkan:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    CetakData(arr, arrsize);

    mergeSort(arr, 0, arrsize - 1);
	
    cout << endl << endl;
    cout << "DATA SETELAH diurutkan:" << endl;
    CetakData(arr, arrsize);
}
};

int main() {
    
	mergesort ms;
	ms.inputdata();	
	ms.proses();

    return 0;
}