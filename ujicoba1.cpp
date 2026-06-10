#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
using namespace std;

struct node
{
    struct node *left;
    struct node *right;   // BUG 1 FIX: tambah field 'right' yang hilang
    char INFO;
    struct node *link;
};

typedef struct node simpul;

simpul *root, *p, *q, *lastcurrent, *lastkiri;
simpul *current;          // BUG 2 FIX: deklarasikan 'current' di scope global

const int kiri = 0, kanan = 1;
int i, n, flag, flaghabis, level;
char x, a[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void inisialisasi()
{
    root = NULL;
}

void buatsimpul(char item)
{
    p = (simpul*) malloc(sizeof(simpul));
    if (p != NULL)
    {
        p->INFO  = item;
        p->left  = NULL;
        p->right = NULL;
        p->link  = NULL;
    }
    else
    {
        cout << "memory penuh" << endl;
        exit(1);
    }
}

void buatsimpulakar()
{
    if (root == NULL)
    {
        root        = p;
        lastcurrent = root;
        lastkiri    = root;
        current     = root;
        flag        = kiri;
        level       = 0;
        n           = 1;
        flaghabis   = 1;
    }
    else
    {
        cout << "pohon sudah ada" << endl;
        exit(1);
    }
}

void tambahsimpul()
{
    if (root != NULL)
    {
        n = n + 1;
        if (flaghabis == 1)
        {
            flaghabis           = 0;
            current             = p;
            lastcurrent->left   = p;
            flag                = kanan;
            level               = level + 1;
        }
        else
        {
            if (flag == kiri)
            {
                flag                = kanan;
                lastcurrent->left   = p;
                current->link       = p;
                current             = p;
            }
            else
            {
                lastcurrent->right  = p;
                current->link       = p;
                flag                = kiri;

                if (n == (pow(2, level + 1) - 1))
                {
                    flaghabis   = 1;
                    lastcurrent = lastkiri->left;  // BUG 3 FIX: hapus spasi 'last kiri'
                    lastkiri    = lastkiri->left;
                }
            }
        }
    }
}

void bacaurutnomor()
{
    int i, j;
    simpul *q[129], *current;
    i = 1; j = 1;
    q[i] = root;
    while (q[i] != NULL)
    {
        current = q[i];
        cout << current->INFO << endl;
        if (current->left != NULL)
        {
            j++; q[j] = current->left;
        }
        if (current->right != NULL)
        {
            j++; q[j] = current->right;  // BUG 4 FIX: q[j] bukan q[i]
        }
        i++;
    }
}

int main()
{
    int i;
    char x;
    char INFOx[20] = "PANCASILA";

    inisialisasi();

    x = INFOx[0];          // BUG 7 FIX: mulai dari index 0 ('P')
    buatsimpul(x);
    buatsimpulakar();      // BUG 5 FIX: nama fungsi yang benar

    for (i = 1; i <= 8; i++)   // index 1..8 untuk sisa 8 karakter
    {
        x = INFOx[i];
        buatsimpul(x);
        tambahsimpul();    // BUG 6 FIX: panggil tambahsimpul(), bukan insert()
    }

    bacaurutnomor();
    cin.get();
    return 0;
}