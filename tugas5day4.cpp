#include <iostream>
#include <string>
using namespace std;

#define MAX 10

string queue[MAX];
int awal = -1, akhir =-1;

bool isempty() {return akhir == -1;}
bool isfull() {return akhir == MAX - 1;}

void init(){
	awal = 0; akhir = 4;
	queue[0] = "Maemo";
	queue[1] = "symbian";
	queue[2] = "Mac";
	queue[3] = "Windows";
	queue[4] = "iphone";
}
void enqueue(string data){
	if (isfull()) {cout << "queue penuh!\n"; return;}
	if (isempty()) {awal = 0; akhir = 0;}
	else akhir++;
	queue[akhir] = data;
}

void insertat(int pos, string data){
	if (isfull()) {cout << "queue penuh!\n"; return;}
	for (int i = akhir ; i>= pos; i--)
		queue[i + 1] = queue[i];
		queue[pos] = data;
		akhir++;
}

void dequeue(){
	if(isempty()){cout << "queue kosong!\n"; return;}
	for ( int i = awal; i< akhir; i++)
		queue[i] = queue[i + 1];
	akhir--;
	if(akhir == -1) awal = -1;
}

void tampil(){
	if(isempty()){cout << "queue kosong.\n"; return;}
	cout <<"isi queue : ";
	for ( int i = awal; i<= akhir; i++)
		cout << "[" << queue[i] << "]";
	cout << "\n";
}

int findindex(string data) {
	for (int i = awal; i <= akhir; i++)
		if (queue[i] == data) return i;
	return -1;
}

int main(){
	init();
	tampil();
	
	cout << endl;
	cout << "memasukan iphone 5 diatas iphone";
	init();
	int pos = findindex("iphone");
	insertat(pos, "iphone 5");
	tampil();
	
	cout << endl;
	cout << "memasukan windows phone diatas windows";
	init();
	pos = findindex("windows");
	insertat(pos, "windows phone");
	tampil();
	
	cout << endl;
	cout << "memasukan snowleopard setelah mac";
	init();
	pos = findindex("mac") + 1;
	insertat(pos, "snowleopard");
	tampil();
	
	cout << endl;
	cout << "memasukan symbian bille setelah symbian";
	init();
	pos = findindex("symbian") + 1;
	insertat(pos, "symbian bille");
	tampil();
	
	cout << endl;
	cout << "memasukan meamo 4 paling bawah";
	init();
	enqueue("maemo 4");
	tampil();
	
	return 0;
}
	
	