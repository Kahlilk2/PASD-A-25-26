#include <iostream>
#include <iomanip>
using namespace std;

struct Pelanggan {
    char nama[50];
    char alamat[50];
    int umur;
    char jenis_kelamin;
    char no_telp[20];
};

int main() {
    int n;

    cout << "Jumlah Pelanggan: ";
    cin >> n;

  
    Pelanggan *data = new Pelanggan[n];

   
    for (int i = 0; i < n; i++) {
        cout << "Data Pelanggan ke-" << i+1 << endl;

        cout << "Nama        : ";
        cin >> data[i].nama;

        cout << "Alamat      : ";
        cin >> data[i].alamat;

        cout << "Umur        : ";
        cin >> data[i].umur;

        cout << "Jenis Kelamin (L/P): ";
        cin >> data[i].jenis_kelamin;

        cout << "No Telp     : ";
        cin >> data[i].no_telp;
    }

   
    cout << "Data Pelanggan Toko:" << endl;
    cout << left << setw(15) << "Nama"
         << setw(15) << "Alamat"
         << setw(10) << "Umur"
         << setw(10) << "Kelamin"
         << setw(15) << "No Telp" << endl;

    cout << "-------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << data[i].nama
             << setw(15) << data[i].alamat
             << setw(10) << data[i].umur
             << setw(10) << data[i].jenis_kelamin
             << setw(15) << data[i].no_telp << endl;
    }

    
    delete[] data;

   cin.get();
}