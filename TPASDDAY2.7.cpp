#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
 

typedef struct {
    string nama_mk;
    int sks;
    string nilai_huruf;
    double nilai_angka;
} MataKuliah;
 
class Mahasiswa {
public:
    string nama;
    string nim;
    int jml_mk;
    MataKuliah mk[100];
 
    void inputData();
    void hitungIPK();
    void tampilKHS();
 
private:
    int total_sks;
    double ipk;
};
 
void garis() {
    for (int i = 0; i < 100; i++) cout << "~";
    cout << endl;
}
 
void Mahasiswa::inputData() {
    cout << "Nama Mahasiswa          : "; cin.ignore(); getline(cin, nama);
    cout << "Nomor Induk Mahasiswa   : "; getline(cin, nim);
    cout << "Banyaknya Mata Kuliah   : "; cin >> jml_mk;
    cout << endl;
 
    for (int i = 0; i < jml_mk; i++) {
        cout << "-- Mata Kuliah ke-" << (i + 1) << " --" << endl;
        cout << "   Nama Mata Kuliah  : "; cin.ignore(); getline(cin, mk[i].nama_mk);
        cout << "   SKS               : "; cin >> mk[i].sks;
        cout << "   Nilai Huruf       : "; cin >> mk[i].nilai_huruf;
        cout << "   Nilai Angka       : "; cin >> mk[i].nilai_angka;
        cout << endl;
    }
}
 
void Mahasiswa::hitungIPK() {
    total_sks = 0;
    double total_bobot = 0;
 
    for (int i = 0; i < jml_mk; i++) {
        total_sks   += mk[i].sks;
        total_bobot += mk[i].nilai_angka * mk[i].sks;
    }
 
    if (total_sks > 0)
        ipk = total_bobot / total_sks;
    else
        ipk = 0;
}
 
void Mahasiswa::tampilKHS() {
    hitungIPK();
 
    garis();
    cout << setw(35) << "KARTU HASIL STUDI[KHS]" << endl;
    garis();
    cout << endl;
 
    cout << left;
    cout << "Nama Mahasiswa" << setw(20) << " " << ": " << nama  << endl;
    cout << "Nomor Induk Mahasiswa" << setw(13) << " " << ": " << nim    << endl;
    cout << endl;
 
    cout << "Mata Kuliah Yang Ditempuh  :" << endl;
    garis();
    cout << left
         << setw(5)  << " No"
         << setw(50) << " Mata Kuliah"
         << setw(6)  << " SKS"
         << setw(14) << " Nilai Huruf"
         << " Nilai Angka" << endl;
    garis();
 
    for (int i = 0; i < jml_mk; i++) {
        cout << left
             << " " << setw(4)  << (i + 1)
             << " " << setw(40) << mk[i].nama_mk
             << " " << setw(5)  << mk[i].sks
             << " " << setw(13) << mk[i].nilai_huruf
             << " " << fixed << setprecision(2) << mk[i].nilai_angka
             << endl;
    }
 
    garis();
    cout << endl;
    cout << left;
    cout << "Jumlah Mata Kuliah Yang Diambil  = " << jml_mk    << endl;
    cout << "Jumlah SKS                       = " << total_sks << endl;
    cout << "Indeks Prestasi Komulatif [IPK]  = " << fixed << setprecision(2) << ipk << endl;
    garis();
}
 
int main() {
    int jml_mhs;
 
    cout << "Jumlah Mahasiswa : "; cin >> jml_mhs;
    cout << endl;
 
    Mahasiswa mhs[jml_mhs];
 
    for (int i = 0; i < jml_mhs; i++) {
        cout << "===== Input Data Mahasiswa Ke-" << (i + 1) << " =====" << endl;
        mhs[i].inputData();
    }
 
    for (int i = 0; i < jml_mhs; i++) {
        mhs[i].tampilKHS();
        cout << endl;
    }
 
    cin.get();
    
}