#include <iostream>
#include <cmath>
using namespace std;

const double g = 9.8;

int main(){
	int pilihan ;
	double v030, sudut30;
	double sudut_rad;
	
	cout << "===========================" << endl;
	cout << "  PROGRAM GERAK 2 DIMENSI  " << endl;
	cout << "===========================" << endl;
	
	
	cout << "masukan kecepatan awal v0 (m/s) :";
	cin >> v030;
	cout << "masukan sudut lempar (derajat)  :";
	cin >> sudut30;
	
	sudut_rad = sudut30 * M_PI / 180.0;
	
	cout << endl;
	cout << "pilihan  : " << endl;
	cout << "1. kecepatan awal arah X dan arah Y " << endl;
	cout << "2. tinggi maksimun benda" << endl;
	cout << "3. jarak maksimum benda" << endl;
	cout << "masukan pilihan (1/2/3) : " ;
	cin >> pilihan ;
	cout << endl;
	
	if (pilihan == 1){
		double v0X30, v0Y30;
		
		v0X30 = v030 * cos(sudut_rad);
		v0Y30 = v030 * sin(sudut_rad);
		
		cout << "===========================" << endl;
		cout << " hasil perhitungan :       " << endl;
		cout << "kecepatan awal arah X (v0X) = " << v0X30 << " m/s " << endl;
		cout << "kecepatan awal arah Y (v0Y) = " << v0Y30 << " m/s " << endl;
		cout << "===========================" << endl;
		
	} else if (pilihan == 2 ) {
		double hmaX30, v0Y30;
		
		v0Y30 = v030 * sin(sudut_rad);
		hmaX30 = (v0Y30 * v0Y30 ) / (2.0 *g);
		
		cout << "===========================" << endl;
		cout << " hasil perhitungan :       " << endl;
		cout << "tinggi maksimum (h_max) = " << hmaX30 << " m " << endl;
		cout << "===========================" << endl;
	
	} else if (pilihan == 3 ) {
		double rmaX30, v0Y30;
		
	rmaX30 = (v030 * v030 * sin(2.0 * sudut_rad)) /g;
		
		cout << "===========================" << endl;
		cout << " hasil perhitungan :       " << endl;
		cout << "jarak maksimum (r) = " << rmaX30 << " m " << endl;
		cout << "===========================" << endl;
		}else {
		cout << " pilihan tidak valid" << endl;
	}
return 0;
}

