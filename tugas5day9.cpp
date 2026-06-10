#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *left;
    Node *right;
};

Node *root = NULL;

Node* buatNode(string data)
{
    Node *baru = new Node;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

Node* insert(Node *root, string data)
{
    if(root == NULL)
        return buatNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    int menu, jenis, n;
    string dataString;
    int dataInt;
    float dataFloat;

    do
    {
        cout << "===== MENU BINARY TREE =====" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Cetak" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> menu;

        if(menu == 1)
        {
            cout << "Pilih Jenis Data" << endl;
            cout << "1. String" << endl;
            cout << "2. Integer" << endl;
            cout << "3. Float" << endl;
            cout << "Pilihan : ";
            cin >> jenis;

            cout << "Jumlah Data : ";
            cin >> n;

            if(jenis == 1)
            {
                for(int i=1; i<=n; i++)
                {
                    cout << "Data String ke-" << i << " : ";
                    cin >> dataString;
                    root = insert(root, dataString);
                }
            }
            else if(jenis == 2)
            {
                for(int i=1; i<=n; i++)
                {
                    cout << "Data Integer ke-" << i << " : ";
                    cin >> dataInt;
                    root = insert(root, to_string(dataInt));
                }
            }
            else if(jenis == 3)
            {
                for(int i=1; i<=n; i++)
                {
                    cout << "Data Float ke-" << i << " : ";
                    cin >> dataFloat;
                    root = insert(root, to_string(dataFloat));
                }
            }
        }
        else if(menu == 2)
        {
            cout << "Isi Binary Tree (InOrder) : " << endl;
            inorder(root);
            cout << endl;
        }

    } while(menu != 3);

    return 0;
}