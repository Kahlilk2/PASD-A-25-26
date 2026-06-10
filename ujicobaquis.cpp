#include <iostream>
using namespace std;

const int T = 2; // Minimum degree (orde B-Tree)

struct BTreeNode {
    int keys[2*T - 1];
    BTreeNode* children[2*T];
    int n;          // jumlah key saat ini
    bool isLeaf;

    BTreeNode(bool leaf) : n(0), isLeaf(leaf) {
        for (int i = 0; i < 2*T; i++) children[i] = nullptr;
    }
};

class BTree {
    BTreeNode* root;

    // Split child penuh
    void splitChild(BTreeNode* parent, int i, BTreeNode* child) {
        BTreeNode* newNode = new BTreeNode(child->isLeaf);
        newNode->n = T - 1;

        // Copy T-1 keys terakhir ke newNode
        for (int j = 0; j < T - 1; j++)
            newNode->keys[j] = child->keys[j + T];

        // Copy children jika bukan leaf
        if (!child->isLeaf)
            for (int j = 0; j < T; j++)
                newNode->children[j] = child->children[j + T];

        child->n = T - 1;

        // Geser children parent
        for (int j = parent->n; j >= i + 1; j--)
            parent->children[j + 1] = parent->children[j];
        parent->children[i + 1] = newNode;

        // Geser keys parent & naikkan key tengah
        for (int j = parent->n - 1; j >= i; j--)
            parent->keys[j + 1] = parent->keys[j];
        parent->keys[i] = child->keys[T - 1];
        parent->n++;
    }

    // Insert ke node yang tidak penuh
    void insertNonFull(BTreeNode* node, int key) {
        int i = node->n - 1;

        if (node->isLeaf) {
            // Geser keys lebih besar ke kanan
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->n++;
        } else {
            // Cari child yang tepat
            while (i >= 0 && key < node->keys[i]) i--;
            i++;

            // Split jika child penuh
            if (node->children[i]->n == 2*T - 1) {
                splitChild(node, i, node->children[i]);
                if (key > node->keys[i]) i++;
            }
            insertNonFull(node->children[i], key);
        }
    }

public:
    BTree() { root = new BTreeNode(true); }

    void insert(int key) {
        BTreeNode* r = root;

        if (r->n == 2*T - 1) {
            // Root penuh → buat root baru & split
            BTreeNode* newRoot = new BTreeNode(false);
            newRoot->children[0] = r;
            splitChild(newRoot, 0, r);
            root = newRoot;
            insertNonFull(newRoot, key);
        } else {
            insertNonFull(r, key);
        }
    }

    void inorder(BTreeNode* node) {
        if (!node) return;
        for (int i = 0; i < node->n; i++) {
            inorder(node->children[i]);
            cout << node->keys[i] << " ";
        }
        inorder(node->children[node->n]);
    }

    void display() {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BTree bt;

    // Masukkan data awal
    bt.insert(10);
    bt.insert(20);
    bt.insert(30);
    bt.insert(40);

    cout << "Sebelum insert 25:" << endl;
    bt.display();

    // Sisipkan key 25
    bt.insert(25);

    cout << "Setelah insert 25:" << endl;
    bt.display();

    return 0;
}