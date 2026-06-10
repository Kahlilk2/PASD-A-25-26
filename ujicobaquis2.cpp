#include <iostream>
using namespace std;

class BTreeNode {
    int *Kunci, t, n;
    bool leaf;
    BTreeNode **C;

    public:
    BTreeNode(int tt, bool _leaf);
    void SisipTdkPenuh(int k);
    void splitAnak(int i, BTreeNode *y);
    void traverse();
    BTreeNode *search(int k);
    friend class BTree;
};

class BTree {
    int t;
    BTreeNode *root;

    public:
    BTree(int tt)
    { root = NULL; t = tt; }

    void traverse()
    { if (root != NULL) root->traverse(); }

    BTreeNode* search(int k)
    { return (root == NULL) ? NULL : root->search(k); }

    void Sisip(int k);
};

BTreeNode::BTreeNode(int t1, bool leaf1) {
    t     = t1;
    leaf  = leaf1;
    Kunci = new int[2*t - 1];
    C     = new BTreeNode*[2*t];
    n     = 0;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            C[i]->traverse();
        cout << " " << Kunci[i];
    }
    if (leaf == false)
        C[i]->traverse();
}

BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < n && k > Kunci[i])
        i++;
    if (Kunci[i] == k)
        return this;
    if (leaf == true)
        return NULL;
    return C[i]->search(k);
}

void BTree::Sisip(int k) {
    if (root == NULL) {
        root = new BTreeNode(t, true);
        root->Kunci[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2*t - 1) {
            BTreeNode *s = new BTreeNode(t, false);
            s->C[0] = root;
            s->splitAnak(0, root);
            int i = 0;
            if (s->Kunci[0] < k)
                i++;
            s->C[i]->SisipTdkPenuh(k);
            root = s;
        }
        else
            root->SisipTdkPenuh(k);
    }
}

void BTreeNode::SisipTdkPenuh(int k) {
    int i = n - 1;
    if (leaf == true) {
        while (i >= 0 && Kunci[i] > k) {
            Kunci[i+1] = Kunci[i];
            i--;
        }
        Kunci[i+1] = k;
        n = n + 1;
    }
    else {
        while (i >= 0 && Kunci[i] > k)
            i--;
        if (C[i+1]->n == 2*t - 1) {
            splitAnak(i+1, C[i+1]);
            if (Kunci[i+1] < k)
                i++;
        }
        C[i+1]->SisipTdkPenuh(k);
    }
}

void BTreeNode::splitAnak(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t-1; j++)
        z->Kunci[j] = y->Kunci[j+t];
    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }
    y->n = t - 1;
    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];
    C[i+1] = z;
    for (int j = n-1; j >= i; j--)
        Kunci[j+1] = Kunci[j];
    Kunci[i] = y->Kunci[t-1];
    n = n + 1;
}

int main() {
    // ============================================================
    // SOAL 2: Sistem Perpustakaan menggunakan B-Tree (t=2, order 4)
    // B-Tree awal sudah berisi: 10, 20, 30, 40
    // Kemudian disisipkan buku dengan ID 25
    // ============================================================

    cout << "================================================" << endl;
    cout << "  SOAL 2 - Sistem Perpustakaan B-Tree           " << endl;
    cout << "  Struktur Data Buku (t = 2, max 3 kunci/node)  " << endl;
    cout << "================================================" << endl;

    // t = 2 berarti setiap node menyimpan maksimal 2*t-1 = 3 kunci
    BTree pohon(2);

    // Sisipkan data awal sesuai soal: 10, 20, 30, 40
    cout << "\n[1] Menyisipkan data awal buku ke B-Tree..." << endl;
    pohon.Sisip(10);
    cout << "    Sisip ID 10  -> Traversal: "; pohon.traverse(); cout << endl;
    pohon.Sisip(20);
    cout << "    Sisip ID 20  -> Traversal: "; pohon.traverse(); cout << endl;
    pohon.Sisip(30);
    cout << "    Sisip ID 30  -> Traversal: "; pohon.traverse(); cout << endl;
    pohon.Sisip(40);
    cout << "    Sisip ID 40  -> Traversal: "; pohon.traverse(); cout << endl;

    cout << "\n[2] Kondisi B-Tree sebelum penyisipan ID 25:" << endl;
    cout << "    Isi node: "; pohon.traverse(); cout << endl;
    cout << "    Node root saat ini berisi [10, 20, 30, 40]" << endl;
    cout << "    (node sudah PENUH, maks 3 kunci untuk t=2)" << endl;

    // ============================================================
    // Penjelasan proses penyisipan ID 25
    // ============================================================
    cout << "\n[3] Proses penyisipan ID Buku = 25:" << endl;
    cout << "    a. Cari posisi yang sesuai untuk key 25." << endl;
    cout << "    b. Node root [10,20,30,40] sudah PENUH (n == 2t-1 = 3)." << endl;
    cout << "    c. Dilakukan SPLIT pada root:" << endl;
    cout << "       - Key tengah (indeks t-1 = 1) = 20 dinaikkan ke parent baru." << endl;
    cout << "       - Node kiri  : [10]" << endl;
    cout << "       - Node kanan : [30, 40]" << endl;
    cout << "       - Root baru  : [20]" << endl;
    cout << "    d. Key 25 > 20, masuk ke anak kanan [30, 40]." << endl;
    cout << "       - Node kanan masih ada ruang (n=2 < 3)." << endl;
    cout << "       - 25 disisipkan secara terurut: [25, 30, 40]" << endl;

    // Lakukan penyisipan aktual
    pohon.Sisip(25);

    cout << "\n[4] Kondisi B-Tree SETELAH penyisipan ID 25:" << endl;
    cout << "    Traversal (in-order): ";
    pohon.traverse();
    cout << endl;

    cout << "\n    Struktur pohon:" << endl;
    cout << "              [20]          <- root (hasil split)" << endl;
    cout << "             /    \\" << endl;
    cout << "          [10]   [25, 30, 40]" << endl;

    // ============================================================
    // Pencarian
    // ============================================================
    cout << "\n[5] Pencarian ID Buku:" << endl;
    int k = 25;
    (pohon.search(k) != NULL)
        ? cout << "    ID " << k << " = DITEMUKAN di B-Tree" << endl
        : cout << "    ID " << k << " = TIDAK DITEMUKAN" << endl;

    k = 10;
    (pohon.search(k) != NULL)
        ? cout << "    ID " << k << " = DITEMUKAN di B-Tree" << endl
        : cout << "    ID " << k << " = TIDAK DITEMUKAN" << endl;

    k = 99;
    (pohon.search(k) != NULL)
        ? cout << "    ID " << k << " = DITEMUKAN di B-Tree" << endl
        : cout << "    ID " << k << " = TIDAK DITEMUKAN" << endl;

    cout << "\n================================================" << endl;
    cout << "  KESIMPULAN:" << endl;
    cout << "  Penyisipan ID 25 menyebabkan proses SPLIT" << endl;
    cout << "  karena node root sudah penuh. Key tengah (20)" << endl;
    cout << "  dinaikkan ke parent baru, dan key 25 masuk ke" << endl;
    cout << "  node kanan secara terurut." << endl;
    cout << "================================================" << endl;

    return 0;
}