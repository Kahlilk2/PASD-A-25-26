#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct NodeDSG 
{
	struct NodeDSG *Left_DSG;
	char INFO_DSG;
	struct NodeDSG *Right_DSG;
};

typedef struct NodeDSG SimpulDSG; // Variabel Global
SimpulDSG *Root_DSG;
SimpulDSG *P_DSG;
SimpulDSG *Current_DSG;

void InisialisasiDSG()
{
Root_DSG = NULL;
P_DSG = NULL;
}

void BuatSimpulDSG(char item_DSG)
{
	P_DSG = (SimpulDSG*) malloc(sizeof(SimpulDSG));
	if(P_DSG != NULL)
	{
		P_DSG->INFO_DSG = item_DSG;
		P_DSG->Left_DSG = NULL;
		P_DSG->Right_DSG = NULL;
	}
	else
	{
		cout << "Memory Penuh" << endl;
		exit(1);
	}
}

void BuatSimpulAkarDSG()
{
	if(Root_DSG == NULL)
	{
		Root_DSG = P_DSG;
	}
	else
	{
	cout << "Pohon Sudah Ada" << endl;
	}
}

void InsertDSG(int nomor_DSG, char item_DSG)
{
	SimpulDSG *Q_DSG[129];
	for(int k_DSG = 0; k_DSG < 129; k_DSG++)
	{
	Q_DSG[k_DSG] = NULL;
	}
	int i_DSG = 1;
	int j_DSG = 1;
	Q_DSG[i_DSG] = Root_DSG;
	while(Q_DSG[i_DSG] != NULL)
	{
	Current_DSG = Q_DSG[i_DSG];
// LEFT
	if(Current_DSG->Left_DSG == NULL)
	{
	Current_DSG->Left_DSG = P_DSG;
	break;
	}
	else
	{
		j_DSG++;
		Q_DSG[j_DSG] = Current_DSG->Left_DSG;
	}
		if(Current_DSG->Right_DSG == NULL)
	{
	Current_DSG->Right_DSG = P_DSG;
	break;
	}
	else
	{	
	j_DSG++;
	Q_DSG[j_DSG] = Current_DSG->Right_DSG;
	}
	i_DSG++;
	}
}

void BacaUrutNomorDSG()
{
int i_DSG, j_DSG;
int level_DSG, jumlahLevel_DSG, counter_DSG;
SimpulDSG *Q_DSG[129];
for(int k_DSG = 0; k_DSG < 129; k_DSG++)
{
Q_DSG[k_DSG] = NULL;
}
i_DSG = 1;
j_DSG = 1;
level_DSG = 0;
jumlahLevel_DSG = 1;
counter_DSG = 0;
Q_DSG[i_DSG] = Root_DSG;

cout << endl;
cout << "Tampilan Binary Tree Level Per Level" << endl;
cout << "====================================" << endl;
while(Q_DSG[i_DSG] != NULL)
{
Current_DSG = Q_DSG[i_DSG];
cout << Current_DSG->INFO_DSG;
counter_DSG++;
if(Current_DSG->Left_DSG != NULL)
{
j_DSG++;
Q_DSG[j_DSG] = Current_DSG->Left_DSG;
}
if(Current_DSG->Right_DSG != NULL)
{
j_DSG++;
Q_DSG[j_DSG] = Current_DSG->Right_DSG;
}
if(counter_DSG == jumlahLevel_DSG || Q_DSG[i_DSG + 1] == NULL)
{
cout << " - Level " << level_DSG << endl;
level_DSG++;
jumlahLevel_DSG = jumlahLevel_DSG * 2;
counter_DSG = 0;
}
else
{
cout << " - ";
}
i_DSG++;
}
}

int main()
{
int i_DSG, n_DSG;
char X_DSG;
int num_DSG[20] =
{0,22,66,28,11,7,63,14,4,10};
char INFOX_DSG[20] = "PANCASILA";
InisialisasiDSG();
X_DSG = INFOX_DSG[0];
BuatSimpulDSG(X_DSG);
BuatSimpulAkarDSG();
for(i_DSG = 1; i_DSG < 9; i_DSG++)
{
n_DSG = num_DSG[i_DSG];
X_DSG = INFOX_DSG[i_DSG];
BuatSimpulDSG(X_DSG);
InsertDSG(n_DSG, X_DSG);
}
BacaUrutNomorDSG();
cin.get();
return 0;
}