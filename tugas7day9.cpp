#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std; // using namespace std

struct node
{
	struct node *left;
	struct node *right; // deklarasi right
	char INFO;
	
};

typedef struct node simpul ;
simpul *root, *p,*q, *lastcurrent, *lastkiri;
simpul *current; // deklarasi current

void inisialisasi()
{
	root = NULL;
	p = NULL;
}

void buatsimpul(char item)
{
	p = (simpul*) malloc(sizeof(simpul));
	if(p != NULL)
	{
		p -> INFO = item;
		p -> left = NULL;
		p -> right = NULL;
	
	}
	else{
		cout << "memory penuh " << endl;
		exit(1);
	}
}
void buatsimpulakar()
{
	if(root == NULL)
	{
		root = p;
	}
	else{
		cout << "pohon sudah ada" << endl;
		exit(1);
	}
}

void Insert(int nomor, char item)
{
	simpul *q[129];
	for(int k = 0; k < 129; k++)
	{
	q[k] = NULL;
	}
	int i = 1;
	int j = 1;
	q[i] = root;
	while(q[i] != NULL)
	{
	current = q[i];
// LEFT
	if(current->left == NULL)
	{
	current->left = p;
	break;
	}
	else
	{
		j++;
		q[j] = current->left;
	}
		if(current->right == NULL)
	{
	current->right = p;
	break;
	}
	else
	{	
	j++;
	q[j] = current->right;
	}
	i++;
	}
}

void bacaurutnomor(){
	int i, j;
	int level, jumlahLevel, counter;
	simpul *q[129];
	for(int k = 0; k < 129; k++)
	{
		q[k] = NULL;
	}
	i = 1;
	j = 1;
	level = 0;
	jumlahLevel = 1;
	counter = 0;
	q[i] = root;

	cout << endl;
	cout << "Tampilan Binary Tree Level Per Level" << endl;
	cout << "====================================" << endl;
	while(q[i] != NULL)
	{
	current = q[i];
	cout << current->INFO;
	counter++;
	if(current->left != NULL)
	{
		j++;
		q[j] = current->left;
	}
	if(current->right != NULL)
	{
		j++;
		q[j] = current->right;
	}
	if(counter == jumlahLevel || q[i + 1] == NULL)
	{
		cout << " - Level " << level << endl;
		level++;
		jumlahLevel = jumlahLevel * 2;
		counter = 0;
	}
	else
	{
		cout << " - ";
	}
	i++;
	}
}

int main()
{
	int i, n;
	char x;
	int num[20] = {0,22,66,28,11,7,63,14,4,10};
	char INFOx[] = "PANCASILA";
	inisialisasi();
	x = INFOx[0]; // mulai dari index 0
	buatsimpul (x);
	buatsimpulakar(); // buatakar
	
	for (i=1; i<=9; i++) // index 1..8
	{
		n = num[i];
		x= INFOx[i];
		buatsimpul(x);
		Insert(n,x); //  tambah sinpul
	}
	bacaurutnomor();
	cin.get();
}


