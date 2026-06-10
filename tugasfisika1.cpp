#include <iostream>
using namespace std;

int main (){
	int pilihan ;
	
	cout << "===========================" << endl;
	cout << "  PROGRAM GERAK 1 DIMENSI  " << endl;
	cout << "===========================" << endl;
	cout << "pilihan  : " << endl;
	cout << "1. waktu tempuh (t)" << endl;
	cout << "2. kecepatan awal (v0)" << endl;
	cout << "3. percepatan (a)" << endl;
	cout << "masukan pilihan (1/2/3) : " ;
	cin >> pilihan ;
	cout << endl;
	
	if (pilihan == 1){
		double a30, v030, vt30, t30;
		
		cout << "menghitung waktu tempuh" << endl;
		cout << "masukan kecepatan awal v0 (m/s) :";
		cin >> v030;
		cout << "masukan percepatan (m/s^2) :";
		cin >> a30;
		cout << "masukan kecepatan akhir vt (m/s) :";
		cin >> vt30;
		
		if (a30 == 0){
			cout << "\n error percepatan tidak boleh 0 untuk menghitung waktu " << endl;
		} else{
			t30 = (vt30 - v030)/a30;
			cout << "===========================" << endl;
			cout << " hasil perhitungan :       " << endl;
			cout << "waktu tempuh (t) = " << t30 << " s " << endl;
			cout << "===========================" << endl;
		}
		
	} else if (pilihan == 2 ) {
		double a30, v030, vt30, t30;
		
		cout << "menghitung kecepatan awal" << endl;
		cout << "masukan kecepatan akhir vt (m/s) :";
		cin >> vt30;
		cout << "masukan percepatan (m/s^2) :";
		cin >> a30;
		cout << "masukan waktu tempuh t (s) :";
		cin >> t30;
		
			v030 = (vt30 - a30)/t30;
			cout << "===========================" << endl;
			cout << " hasil perhitungan :       " << endl;
			cout << "kecepatan awal (v0)= " << v030 << " m/s " << endl;
			cout << "===========================" << endl;
			
	} else if (pilihan == 3 ) {
		double a30, v030, vt30, t30;
		
		cout << "menghitung kecepatan " << endl;
		cout << "masukan kecepatan awal v0 (m/s) :";
		cin >> v030;
		cout << "masukan waktu tempuh t (s)      :";
		cin >> t30;
		cout << "masukan kecepatan akhir vt(m/s) :";
		cin >> vt30;
		
		if (t30 == 0){
			cout << "\n error percepatan tidak boleh 0 untuk menghitung waktu " << endl;
		} else{
		
			a30 = (vt30 - v030)/t30;
			cout << "===========================" << endl;
			cout << " hasil perhitungan :       " << endl;
			cout << " percepatan (a)= " << a30 << " m/s^2 " << endl;
			cout << "===========================" << endl;
		}
	}else {
		cout << " pilihan tidak valid" << endl;
	}
return 0;
}
	
	