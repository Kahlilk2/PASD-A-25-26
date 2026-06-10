#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct node {
	char INFO;
	struct node* LEFT;
	struct node* RIGHT;
};

typedef struct node simpul;
simpul *Root, *P, *Q[30], *R, *current;
char X;

void inisialisasi(){
	Root = NULL;
	P = NULL;
}

void buatsimpul (char X){
	P = (simpul*) malloc (sizeof(simpul));
	if (P != NULL){
		P-> INFO = X;
		P-> LEFT = NULL;
		P-> RIGHT = NULL;
}}
	
void buatsimpulakar(){
	if(Root == NULL){
		if (P != NULL){
		Root = P;
			P-> LEFT = NULL;
			P-> RIGHT = NULL;
		}
		else{
			cout << "simpul belum dibuaut" << endl;
		}
	}
	else{
		cout <<"pohon sudah ada!!!"<< endl;
	}
}

void inserturutnomer(char input[6]){
	int i, j, flag;
	char X;
	flag = 0;
	i=1;
	j=1;
	Q[i] = Root;
	while (flag == 0 && j < 6){
		X = input [j-1];
		if (X != '0'){
			buatsimpul (X);
			current = Q[i];
			current -> LEFT = P;
			j++;
			Q[j] = P; }
		else {
			flag = 1;
			j++;
			Q[j] = NULL; }
			if(flag == 0){
				X = input [j-1];
				if (X != '0'){
					buatsimpul(X);
					current ->RIGHT = P;
					j++;
					Q[j] = P; }}

			else {
				flag = 1;
				j++;
				Q[j] = NULL;}
				i++;	}}
				
void bacaurutnomer(){
	int i, j, n, counter;
	i=1; j=1;n=1;counter=0;
	int level=0;
	while (Q[i] != NULL){
		current = Q[i];
		if (i == 1){
			cout << endl;
			cout <<"level " << level << endl;
			}
		cout << current -> INFO << " - ";
		counter++;
		if(counter == n){
				level++;
				cout << "level " << level << " " << endl;
		}
		if (counter == n){
			cout << endl;
			counter = 0;
			n = n*2;
		}
		if (current -> LEFT != NULL){
			j++;
			Q[i] = current -> LEFT;
		}
		if (current -> LEFT != NULL){
			j++;
			Q[i] = current -> RIGHT;
		}
		i++;
	}
}
int main(){
char Root = 'R';
char daun[6] = {'S', 'U', 'V', 'W', 'Y','Z'};
inisialisasi();
buatsimpul(Root);
buatsimpulakar();
inserturutnomer(daun);
bacaurutnomer();
return 0;
}	
	
	
			