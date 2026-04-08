#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
 
struct Mahasiswa {
    long long nim;
    string nama;
    float quiz, uts, uas, na;
    string index;
};
 
string tentukanIndex(float na, string index) {
    if (na >= 80)       index = "A";
    else if (na >= 76)  index = "A-";
    else if (na >= 72)  index = "B+";
    else if (na >= 68)  index = "B";
    else if (na >= 64)  index = "B-";
    else if (na >= 60)  index = "C+";
    else if (na >= 56)  index = "C";
    else if (na >= 45)  index = "D";
    else                index = "E";
}
 
int main() {
    int n, i;
    cout << "Jumlah mahasiswa: ";
    cin >> n;
 
    Mahasiswa mhs[n];
 
    for (i = 0; i < n; i++) {
        cout << "Pengisian Data Mahasiswa Ke-" << (i + 1) << endl;
        cout << "NIM        : "; cin >> mhs[i].nim;
        cout << "NAMA       : "; cin.ignore(); getline(cin, mhs[i].nama);
        cout << "Nilai QUIZ : "; cin >> mhs[i].quiz;
        cout << "Nilai UTS  : "; cin >> mhs[i].uts;
        cout << "Nilai UAS  : "; cin >> mhs[i].uas;
 
        mhs[i].na = (mhs[i].quiz + mhs[i].uts + mhs[i].uas) / 3.0;
        mhs[i].index = tentukanIndex(mhs[i].na, mhs[i].index);
    }
 
    cout << "Data yang telah dimasukan adalah :" << endl;
    cout << left
         << "| " << setw(6)  << "NIM"
         << " | " << setw(10) << "NAMA"
         << " | " << setw(4)  << "QUIS"
         << " | " << setw(3)  << "UTS"
         << " | " << setw(3)  << "UAS"
         << " | " << setw(6)  << "N A"
         << " | " << setw(5)  << "INDEX"
         << " |" << endl;
 
    for (int i = 0; i < n; i++) {
        cout << "| " << setw(6)  << mhs[i].nim
             << " | " << setw(10) << mhs[i].nama
             << " | " << setw(4)  << (int)mhs[i].quiz
             << " | " << setw(3)  << (int)mhs[i].uts
             << " | " << setw(3)  << (int)mhs[i].uas
             << " | " << setw(6)  << fixed << setprecision(2) << mhs[i].na
             << " | " << setw(5)  << mhs[i].index
             << " |" << endl;
    }
 
    cin.get();
}