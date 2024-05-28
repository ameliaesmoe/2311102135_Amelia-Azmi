# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>
<p align="center">Amelia Azmi_2311102135</p>

## Dasar Teori

#### Graph

Graf adalah representasi grafik yang melibatkan sekumpulan objek yang dilambangkan dengan simpul atau verteks, dan relasi-relasi biner antar objek-objek diskret tersebut yang dilambangkan dengan rusuk atau sisi atau edge. Berdasarkan ada tidaknya gelang atau sisi ganda pada suatu graf, graf dapat digolongkan menjadi dua jenis:

1. Graf Sederhana
Graf sederhana adalah graf yang tidak mengandung gelang maupun sisi ganda. Contoh graf sederhan direfresentasikan dengan jaringan computer.Pada graf sederhan sisi merupakan pasangan tak terurut, Jadi sisi (u,v) sama saja dengan (v,u).
2. Graf tak Sederhana
Graf tak sederhana adalah graf yang mengndung sisi ganda atau gelang. Graf sederhana dibagi menjadi dua macam, yaitu gaf ganda dan graf semu. Graf ganda adalah graf yang mengnadung sisi ganda. Sedangkan graf semu adalah graf yang mengandung gelang. Sisi pada graf semu dapat terhubung ke dirinya sendiri.

Berdasarkan orientasi arah pada sisi, maka graf dibedakan menjadi dua jenis:

1. Graf Tak Berarah
Graf Tak Berarah adalah graf yang sisinya tidak mempunyai orientasi arah. Urutan pasangan simpul pada graf beraaah tidak diperhatikan, jadi sisi (u,v) sama dengan (v,u). contoh graf tak berarah dalam kehidupan sehari hari adalah jaringan pada saluran secara dua arah.
2. Graf Berarah
Graf Berarah adalah graf yang setiap ssinya diberikan orientasi arah. Sisi sisinya yang berarah ini biasa disebut busur. Pada graf berarah, sisi(u,v) tidak sama dengan (v,u). untuk busur (u,v), simpul u merupakan simpul terminal. Dalam kehidupan sehari- hari, garaf berarah biasa sring dipakai untuk menggambarkan aliran suatu proses

#### Tree
Pohon ( tree) adalah graph terhubung yang tidak mengandung sirkuit. Pohon (tree) merupakan stuktur data yang tidak linier yang digambarkan dengan hubungan yang bersifat hirarkis antar satu elemen (Teddy Marcus; 2005).
Jenis pohon dalam sturktur data sebagai berikut :

a. Full binary tree

Binary tree yang tiap nodenya memiliki satu root dan dua  root.

![Alt text](<Tree 1.1.png>)

b. Complete binary tree

Pohon ini mirip dengan Full Bianry Tree, namun pada tiap sub tree boleh memiliki panjang path yang berbeda node kecuali leaf yang meiliki 0 atau 2 anak.

![Alt text](<tree 1.2.png>)

c. Skewed binary tree

Pohon yang semua nodenya kecuali daun hanya memiliki satu anak (child).

![Alt text](skewed-trees-1024x421.png)

Struktur data tree dapat dirangkum sebagai berikut :

![Alt text](<Tree 1.4.png>)

Operasi pada Tree :

a. Create: digunakan untuk membentuk binary tree baru yang masih kosong.

b. Clear: digunakan untuk mengosongkan binary tree yang sudah ada ataumenghapus semua node pada binary tree.

c. isEmpty: digunakan untuk memeriksa apakah binary tree masih kosong atau tidak.

d. Insert: digunakan untuk memasukkan sebuah node kedalam tree.

e. Find: digunakan untuk mencari root, parent, left child, atau right child dari suatu node dengan syarat tree tidak boleh kosong.

f. Update: digunakan untuk mengubah isi dari node yang ditunjuk oleh pointer current dengan syarat tree tidak boleh kosong.

g. Retrive: digunakan untuk mengetahui isi dari node yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.

h. Delete Sub: digunakan untuk menghapus sebuah subtree (node beserta seluruh descendant-nya) yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.

i. Characteristic: digunakan untuk mengetahui karakteristik dari suatu tree. Yakni size, height, serta average lenght-nya.

j. Traverse: digunakan untuk mengunjungi seluruh node-node pada tree dengan cara traversal. Terdapat 3 metode traversal yang dibahas dalam modul ini yakni Pre-Order, In-Order, dan Post-Order.



## Guided 

### 1. [Program Graph]

```C++
#include <iostream>

using namespace std;

int main () {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}; 
    int cari = 10;
    bool ketemu = false; // Variabel boolean untuk melacak apakah nilai ditemukan
    int i;

    // Loop melalui array untuk mencari nilai
    for (i = 0; i < n; i++) { 
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    cout << "Program Sequential Search" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    // Memeriksa apakah nilai ditemukan dan mencetak pesan yang sesuai
    if (ketemu) { 
        cout << "\nAngka " << cari << " ditemukan pada indeks ke- " << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}
```
Program diatas merupakan implementasi dasar dari algoritma pencarian linier (sequential search) dalam bahasa pemrograman C++. Program ini dimulai dengan mendeklarasikan dan menginisialisasi beberapa variabel penting: `n` yang mewakili ukuran array, `data` yang merupakan array berisi sepuluh elemen integer, `cari` yang merupakan nilai yang ingin dicari dalam array, serta `ketemu`, sebuah variabel boolean yang digunakan untuk melacak apakah nilai yang dicari ditemukan dalam array. Nilai awal `ketemu` adalah `false`, menandakan bahwa nilai belum ditemukan. Variabel `i` digunakan sebagai indeks untuk iterasi. Dalam loop `for`, program melakukan iterasi melalui setiap elemen array dari indeks `0` hingga `n-1`. Pada setiap iterasi, program memeriksa apakah elemen saat ini (`data[i]`) sama dengan nilai `cari`. Jika ditemukan kesamaan, `ketemu` diubah menjadi `true` dan loop dihentikan menggunakan pernyataan `break` untuk menghindari iterasi yang tidak perlu. Setelah loop selesai, program mencetak pesan pembuka "Program Sequential Search" dan menampilkan isi array. Kemudian, program memeriksa nilai `ketemu` untuk menentukan hasil pencarian. Jika `ketemu` bernilai `true`, program mencetak bahwa angka yang dicari ditemukan pada indeks tertentu. Jika tidak, program mencetak bahwa angka tersebut tidak ditemukan dalam array. Program ini menggambarkan cara kerja pencarian linier yang sederhana namun efektif untuk dataset kecil, meskipun kurang efisien untuk dataset yang lebih besar karena memiliki kompleksitas waktu O(n).

### 2. [Program Tree]

```C++
#include <iostream>
#include <iomanip>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat sebagai root." << endl;
    } else {
        cout << "\nTree sudah ada!" << endl;
    }
}

Pohon* insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

Pohon* insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        } else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent) {
                cout << "Parent : (tidak punya parent)" << endl;
            } else {
                cout << "Parent : " << node->parent->data << endl;
            }
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node) {
                cout << "Sibling : " << node->parent->left->data << endl;
            } else if (node->parent != NULL && node->parent->right != node && node->parent->left == node) {
                cout << "Sibling : " << node->parent->right->data << endl;
            } else {
                cout << "Sibling : (tidak punya sibling)" << endl;
            }
            if (!node->left) {
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            } else {
                cout << "Child Kiri : " << node->left->data << endl;
            }
            if (!node->right) {
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            } else {
                cout << "Child Kanan : " << node->right->data << endl;
            }
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            if (node != root) {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    } else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() {
    cout << "\nSize Tree : " << size() << endl;
    cout << "Height Tree : " << height() << endl;
    cout << "Average Node of Tree : " << size() / height() << endl;
}

int main() {
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);

    retrieve(nodeC);

    find(nodeC);

    cout << "\nSize Tree: " << size() << endl;
    cout << "Height Tree: " << height() << endl;
    cout << "Average Node of Tree: " << size() / height() << endl;

    cout << "\nPreOrder: ";
    preOrder();
    cout << "\nInOrder: ";
    inOrder();
    cout << "\nPostOrder: ";
    postOrder();
    cout << endl;

    return 0;
}
```
Program diatas merupakan implementasi lengkap dari struktur data pohon biner dalam bahasa pemrograman C++. Program ini dimulai dengan mendefinisikan struktur `Pohon`, yang memiliki atribut untuk menyimpan data (karakter), serta pointer untuk menghubungkan node kiri, kanan, dan induknya. Fungsi `init` menginisialisasi pohon dengan mengatur root ke `NULL`, sementara fungsi `isEmpty` memeriksa apakah pohon kosong. Fungsi `buatNode` membuat node baru sebagai root jika pohon belum ada, dan jika pohon sudah ada, fungsi ini menampilkan pesan bahwa pohon sudah ada. Fungsi `insertLeft` dan `insertRight` digunakan untuk menambahkan node baru sebagai anak kiri atau kanan dari node yang ditentukan, asalkan tidak ada anak kiri atau kanan pada node tersebut. Fungsi `update` memungkinkan perubahan data pada node tertentu, sedangkan fungsi `retrieve` dan `find` digunakan untuk mengambil dan menampilkan informasi detail tentang node tertentu, termasuk data, parent, sibling, dan child-nya.

Program ini juga mendukung berbagai metode traversal pohon: `preOrder`, `inOrder`, dan `postOrder`, yang masing-masing mencetak data node dalam urutan pre-order, in-order, dan post-order. Selain itu, program ini menyediakan fungsi untuk menghapus node: `deleteTree` menghapus seluruh node dalam pohon, `deleteSub` menghapus subtree dari node tertentu, dan `clear` menghapus seluruh pohon. Fungsi `size` menghitung jumlah total node dalam pohon, sedangkan `height` menghitung tinggi pohon, yang digunakan dalam fungsi `characteristic` untuk mencetak ukuran, tinggi, dan rata-rata node dalam pohon.

Dalam fungsi `main`, program membuat pohon dengan root 'A' dan menambahkan beberapa node untuk membentuk struktur pohon yang lebih kompleks. Program juga menunjukkan contoh penggunaan fungsi `update` untuk mengubah data node, serta fungsi `retrieve` dan `find` untuk mengakses dan menampilkan data node. Terakhir, program menghitung dan menampilkan ukuran, tinggi, dan rata-rata node dalam pohon, serta melakukan traversal pohon dengan metode pre-order, in-order, dan post-order. Secara keseluruhan, program ini menyediakan berbagai operasi untuk manipulasi dan pengelolaan pohon biner, menjadikannya alat yang komprehensif untuk bekerja dengan struktur data pohon.

## Unguided 

### 1. [Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya]

![Alt text](<Soal unguided1.png>)

```C++
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk mencetak header matriks
void printHeader(const vector<string> &simpul_2311102135, int n)
{
    cout << setw(15) << " ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << simpul_2311102135[i];
    }
    cout << endl;
}

// Fungsi untuk mencetak baris matriks ketetanggaan
void printRows(const vector<string> &simpul_2311102135, const vector<vector<int>> &busur_2311102135, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << simpul_2311102135[i];
        for (int j = 0; j < n; j++)
        {
            cout << setw(15) << busur_2311102135[i][j];
        }
        cout << endl;
    }
}

// Fungsi untuk menampilkan graf berdasarkan matriks ketetanggaan
void tampilGraph(const vector<string> &simpul_2311102135, const vector<vector<int>> &busur_2311102135, int n)
{
    printHeader(simpul_2311102135, n);
    printRows(simpul_2311102135, busur_2311102135, n);
}

int main()
{
    // Mendeklarasikan variabel untuk menyimpan jumlah simpul
    int n;

    // Mencetak prompt untuk meminta input jumlah simpul
    cout << "Silakan masukkan jumlah simpul: ";

    // Membaca input jumlah simpul dari pengguna
    cin >> n;

    // Deklarasi vektor untuk menyimpan nama simpul
    vector<string> simpul_2311102135(n);

    // Meminta input nama simpul dari pengguna
    for (int i = 0; i < n; i++)
    {
        cout << "Nama simpul " << i + 1 << " : ";
        cin >> simpul_2311102135[i];
    }

    // Deklarasi vektor dua dimensi untuk menyimpan bobot antar simpul matriks ini akan menyimpan bobot untuk setiap pasangan simpul
    vector<vector<int>> busur_2311102135(n, vector<int>(n, 0));

    // Mencetak prompt untuk meminta input bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;

    // Meminta input bobot antar simpul dari pengguna
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << simpul_2311102135[i] << "--> " << simpul_2311102135[j] << " = ";
            cin >> busur_2311102135[i][j];
        }
    }

    // Memanggil fungsi tampilGraph untuk menampilkan representasi matriks ketetanggaan dari graf yang telah diinput
    tampilGraph(simpul_2311102135, busur_2311102135, n);

    return 0;
}
```
#### Output:

![Alt text](<screenshoot unguided 1.png>)

Program diatas merupakan program C++ yang bertujuan untuk merepresentasikan dan menampilkan sebuah graf berbobot menggunakan matriks ketetanggaan. Langkah pertama dalam program ini adalah meminta pengguna untuk memasukkan jumlah simpul (nodes) dalam graf. Setelah menerima jumlah simpul, program kemudian meminta pengguna untuk memasukkan nama-nama dari setiap simpul tersebut. Nama-nama ini disimpan dalam sebuah vektor. Kemudian nama-nama  pada simpul dimasukkan, selanjutnya  progam meminta pengguna untuk memasukkan bobot antar simpul, yang mewakili hubungan atau busur (edges) di antara simpul-simpul tersebut. Bobot-bobot ini disimpan dalam sebuah matriks dua dimensi yang dikenal sebagai matriks ketetanggaan, di mana setiap elemen dari matriks menunjukkan bobot antara pasangan simpul tertentu. Setelah semua data yang diperlukan dimasukkan, program kemudian menggunakan dua fungsi bantu, `printHeader` dan `printRows`, untuk menampilkan matriks ketetanggaan tersebut. Fungsi `printHeader` bertugas mencetak header dari matriks, yaitu baris pertama yang berisi nama-nama simpul. Fungsi `printRows` bertugas mencetak setiap baris dari matriks ketetanggaan, di mana setiap baris diawali dengan nama simpul dan diikuti dengan bobot hubungan ke simpul-simpul lainnya. Seluruh proses menampilkan matriks ketetanggaan ini dikendalikan oleh fungsi `tampilGraph`, yang memanggil `printHeader` dan `printRows` secara berurutan untuk menampilkan matriks secara lengkap dan terstruktur. Dengan cara ini, pengguna dapat dengan mudah melihat representasi graf dalam bentuk matriks ketetanggaan, yang memvisualisasikan bobot antar simpul dengan jelas dan rapi.

### 2. [Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!]

```C++
#include <iostream>
#include <queue>
using namespace std;

// Struktur Node Tree
struct Pohon
{
    // Data dari node
    char data_2311102135;
    // Pointer ke child kiri
    Pohon *left_2311102135;
    // Pointer ke child kanan
    Pohon *right_2311102135;
    // Pointer ke parent node
    Pohon *parent_2311102135;
};
// Pointer ke root node
Pohon *root_2311102135;

// Fungsi untuk mengecek apakah tree kosong
bool isEmpty()
{
    return root_2311102135 == NULL;
}

// Fungsi untuk inisialisasi root
void init()
{
    root_2311102135 = nullptr;
}

// Fungsi untuk membuat root node
void buatNode(char data)
{
    if (root_2311102135 == nullptr)
    {
        root_2311102135 = new Pohon();
        root_2311102135->data_2311102135 = data;
        root_2311102135->left_2311102135 = nullptr;
        root_2311102135->right_2311102135 = nullptr;
        cout << "Node " << data << " berhasil dibuat sebagai root." << endl;
    }
    else
    {
        cout << "Root sudah ada!" << endl;
    }
}

// Fungsi untuk menambahkan node di sebelah kiri sebuah node tertentu
Pohon *insertLeft(char data, Pohon *parent)
{
    if (parent == nullptr)
    {
        cout << "Node parent tidak ditemukan!" << endl;
        return nullptr;
    }

    if (parent->left_2311102135 == nullptr)
    {
        Pohon *newNode = new Pohon();
        newNode->data_2311102135 = data;
        newNode->left_2311102135 = nullptr;
        newNode->right_2311102135 = nullptr;
        parent->left_2311102135 = newNode;
        cout << "Node " << data << " berhasil ditambahkan ke child kiri " << parent->data_2311102135 << endl;
        return newNode;
    }
    else
    {
        cout << "Node kiri dari " << parent->data_2311102135 << " sudah terisi!" << endl;
        return nullptr;
    }
}

// Fungsi untuk menambahkan node di sebelah kanan sebuah node tertentu
Pohon *insertRight(char data, Pohon *parent)
{
    if (parent == nullptr)
    {
        cout << "Node parent tidak ditemukan!" << endl;
        return nullptr;
    }

    if (parent->right_2311102135 == nullptr)
    {
        Pohon *newNode = new Pohon();
        newNode->data_2311102135 = data;
        newNode->left_2311102135 = nullptr;
        newNode->right_2311102135 = nullptr;
        parent->right_2311102135 = newNode;
        cout << "Node " << data << " berhasil ditambahkan ke child kanan " << parent->data_2311102135 << endl;
        return newNode;
    }
    else
    {
        cout << "Node kanan dari " << parent->data_2311102135 << " sudah terisi!" << endl;
        return nullptr;
    }
}

// Fungsi untuk mengubah data sebuah node
void update(char oldData, Pohon *node)
{
    if (node == nullptr)
    {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }

    if (node->data_2311102135 == oldData)
    {
        cout << "Masukkan data baru: ";
        char newData;
        cin >> newData;
        node->data_2311102135 = newData;
        cout << "Data node: " << newData << endl;
        return;
    }

    if (node->left_2311102135 != nullptr)
    {
        update(oldData, node->left_2311102135);
    }
    if (node->right_2311102135 != nullptr)
    {
        update(oldData, node->right_2311102135);
    }
}

// Fungsi untuk mencari node berdasarkan data
Pohon *find(char data)
{
    queue<Pohon *> q;
    if (root_2311102135 != nullptr)
        q.push(root_2311102135);

    while (!q.empty())
    {
        Pohon *temp = q.front();
        q.pop();

        if (temp->data_2311102135 == data)
        {
            return temp;
        }

        if (temp->left_2311102135 != nullptr)
        {
            q.push(temp->left_2311102135);
        }
        if (temp->right_2311102135 != nullptr)
        {
            q.push(temp->right_2311102135);
        }
    }
    return nullptr;
}

// Fungsi untuk menampilkan descendant (anak-anak) dari sebuah node
void tampilkanDescendant(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->left_2311102135 != nullptr)
    {
        cout << node->left_2311102135->data_2311102135 << " ";
        tampilkanDescendant(node->left_2311102135);
    }
    if (node->right_2311102135 != nullptr)
    {
        cout << node->right_2311102135->data_2311102135 << " ";
        tampilkanDescendant(node->right_2311102135);
    }
}

// Fungsi untuk menampilkan data secara ascending (in-order traversal)
void tampilkanAscending(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    tampilkanAscending(node->left_2311102135);
    cout << node->data_2311102135 << " ";
    tampilkanAscending(node->right_2311102135);
}

// Fungsi untuk melakukan pre-order traversal
void PreOrder(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->data_2311102135 << " ";
    PreOrder(node->left_2311102135);
    PreOrder(node->right_2311102135);
}

// Fungsi untuk melakukan in-order traversal
void InOrder(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    InOrder(node->left_2311102135);
    cout << node->data_2311102135 << " ";
    InOrder(node->right_2311102135);
}

// Fungsi untuk melakukan post-order traversal
void PostOrder(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    PostOrder(node->left_2311102135);
    PostOrder(node->right_2311102135);
    cout << node->data_2311102135 << " ";
}

// Fungsi untuk menampilkan sibling dari sebuah node
void sibling(Pohon *node)
{
    if (root_2311102135 == nullptr || root_2311102135 == node)
    {
        cout << "Root node tidak memiliki sibling." << endl;
        return;
    }

    Pohon *parent = nullptr;
    Pohon *current = root_2311102135;

    queue<Pohon *> q;
    q.push(current);

    while (!q.empty())
    {
        current = q.front();
        q.pop();

        if (current->left_2311102135 == node || current->right_2311102135 == node)
        {
            parent = current;
            break;
        }

        if (current->left_2311102135 != nullptr)
        {
            q.push(current->left_2311102135);
        }
        if (current->right_2311102135 != nullptr)
        {
            q.push(current->right_2311102135);
        }
    }

    if (parent == nullptr)
    {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    if (parent->left_2311102135 != nullptr && parent->left_2311102135 != node)
    {
        cout << "Sibling: " << parent->left_2311102135->data_2311102135 << endl;
    }
    else if (parent->right_2311102135 != nullptr && parent->right_2311102135 != node)
    {
        cout << "Sibling: " << parent->right_2311102135->data_2311102135 << endl;
    }
    else
    {
        cout << "Node tidak memiliki sibling." << endl;
    }
}

// Fungsi untuk melakukan traversal (preorder, inorder, postorder) dan menampilkan sibling
void traversalAndSibling(Pohon *node)
{
    cout << "PreOrder: ";
    if (node == nullptr)
    {
        cout << "Tree kosong" << endl;
    }
    else
    {
        PreOrder(node);
    }
    cout << endl;

    cout << "InOrder: ";
    if (node == nullptr)
    {
        cout << "Tree kosong" << endl;
    }
    else
    {
        InOrder(node);
    }
    cout << endl;

    cout << "PostOrder: ";
    if (node == nullptr)
    {
        cout << "Tree kosong" << endl;
    }
    else
    {
        PostOrder(node);
    }
    cout << endl;

    sibling(node);
}

// Fungsi untuk menghapus seluruh subtree dari sebuah node
void deleteSubtree(Pohon *&node)
{
    if (node == nullptr)
    {
        return;
    }
    // Hapus seluruh subtree dari anak kiri dan anak kanan secara rekursif
    deleteSubtree(node->left_2311102135);
    deleteSubtree(node->right_2311102135);
    // Setiap node dihapus dari memori
    delete node;
    node = nullptr;
}
void retrieve(Pohon *node)
{
    if (node != nullptr)
    {
        cout << "Data node: " << node->data_2311102135 << endl;
    }
    else
    {
        cout << "Node tidak ditemukan!" << endl;
    }
}
// Fungsi untuk menghapus sebuah node
void deleteNode(char data, Pohon *&node)
{
    if (node == nullptr)
    {
        return;
        // Jika data node sesuai dengan yang dicari
        if (node->data_2311102135 == data)
        {
            // Jika node tidak memiliki anak
            if (node->left_2311102135 == nullptr && node->right_2311102135 == nullptr)
            {
                delete node;
                node = nullptr;
                cout << "Node " << data << " berhasil dihapus." << endl;
            }
            else
            {
                // Jika node memiliki anak, panggil fungsi deleteSubtree untuk menghapus subtree
                deleteSubtree(node);
                node = nullptr;
                cout << "Node " << data << " beserta subtree berhasil dihapus." << endl;
            }
            return;
        }

        // Pencarian dilanjutkan ke anak kiri dan anak kanan
        deleteNode(data, node->left_2311102135);
        deleteNode(data, node->right_2311102135);
    }
}
// Fungsi untuk menampilkan detail sebuah node dan parent, sibling, dan child-nya
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node : " << node->data_2311102135 << endl;

            // Mencari parent
            Pohon *parent = nullptr;
            Pohon *current = root_2311102135;
            queue<Pohon *> q;
            q.push(current);

            while (!q.empty())
            {
                current = q.front();
                q.pop();

                if (current->left_2311102135 == node || current->right_2311102135 == node)
                {
                    parent = current;
                    break;
                }

                if (current->left_2311102135 != nullptr)
                {
                    q.push(current->left_2311102135);
                }
                if (current->right_2311102135 != nullptr)
                {
                    q.push(current->right_2311102135);
                }
            }

            // Menampilkan parent
            if (parent != nullptr)
            {
                cout << " Parent : " << parent->data_2311102135 << endl;
            }
            else
            {
                cout << " Parent : (tidak punya parent)" << endl;
            }

            // Menampilkan sibling
            if (parent != nullptr)
            {
                if (parent->left_2311102135 == node)
                {
                    if (parent->right_2311102135 != nullptr)
                        cout << " Sibling : " << parent->right_2311102135->data_2311102135 << endl;
                    else
                        cout << " Sibling : (tidak punya sibling)" << endl;
                }
                else if (parent->right_2311102135 == node)
                {
                    if (parent->left_2311102135 != nullptr)
                        cout << " Sibling : " << parent->left_2311102135->data_2311102135 << endl;
                    else
                        cout << " Sibling : (tidak punya sibling)" << endl;
                }
            }
            else
            {
                cout << " Sibling : (tidak punya sibling)" << endl;
            }

            // Menampilkan child kiri
            if (!node->left_2311102135)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left_2311102135->data_2311102135 << endl;

            // Menampilkan child kanan
            if (!node->right_2311102135)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right_2311102135->data_2311102135 << endl;
        }
    }
}

// Fungsi untuk mencari level dari sebuah node dalam tree
void findLevel(Pohon *node, char data, int level)
{
    if (node == nullptr)
    {
        return;
    }

    // Jika data node ditemukan, tampilkan levelnya
    if (node->data_2311102135 == data)
    {
        cout << "Level node: " << level << endl;
        return;
    }

    // Pencarian dilanjutkan ke anak kiri dan anak kanan dengan meningkatkan level
    findLevel(node->left_2311102135, data, level + 1);
    findLevel(node->right_2311102135, data, level + 1);
}

// Fungsi untuk menghitung jumlah node dalam tree (size)
int size(Pohon *node = root_2311102135)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            // Jumlah node dihitung dengan rekursif pada anak kiri dan anak kanan
            return 1 + size(node->left_2311102135) + size(node->right_2311102135);
        }
    }
}

// Fungsi untuk menghitung tinggi (height) dari tree
int height(Pohon *node = root_2311102135)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            // Tinggi tree dihitung dengan mencari tinggi maksimum dari anak kiri dan anak kanan
            int heightKiri = height(node->left_2311102135);
            int heightKanan = height(node->right_2311102135);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Fungsi untuk menampilkan karakteristik dari tree (size, height, rata-rata node per level)
void characteristic()
{
    cout << "Size Tree : " << size() << endl;
    cout << "Height Tree : " << height() << endl;
    cout << "Average Node of Tree : " << size() / height() << endl;
}

// Fungsi utama
int main()
{
    // variable pilihan data parent data parent node dan selected node
    int pilihan;
    char data, parentData;
    Pohon *parentNode;
    Pohon *selectedNode;
    // Inisialisasi tree
    init();

    do
    {
        // menu
        cout << "\nMenu:\n";
        cout << "1. Buat Root\n";
        cout << "2. Insert Left\n";
        cout << "3. Insert Right\n";
        cout << "4. Update\n";
        cout << "5. Retrieve\n";
        cout << "6. Tampilkan Descendant\n";
        cout << "7. Tampilkan Ascending\n";
        cout << "8. Traversal (preorder, inorder, postorder, sibling)\n";
        cout << "9. Delete Node\n";
        cout << "10. Find Level\n";
        cout << "11. Karateristik\n";
        cout << "12. Detail tree\n";
        cout << "13. Exit\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)

        {
        case 1:
            // Membuat root node
            cout << "Masukkan data root: ";
            cin >> data;
            buatNode(data);
            break;

        case 2:
            // Mencari parent node
            cout << "Masukkan data parent: ";
            cin >> parentData;
            parentNode = find(parentData);
            if (parentNode == nullptr)
            {
                cout << "Node parent tidak ditemukan!" << endl;
                break;
            }
            // Menambahkan node sebagai anak kiri
            cout << "Masukkan data node: ";
            cin >> data;
            insertLeft(data, parentNode);
            break;

        case 3:
            // Mencari parent node
            cout << "Masukkan data parent: ";
            cin >> parentData;
            parentNode = find(parentData);
            if (parentNode == nullptr)
            {
                cout << "Node parent tidak ditemukan!" << endl;
                break;
            }
            // Menambahkan node sebagai anak kanan
            cout << "Masukkan data node: ";
            cin >> data;
            insertRight(data, parentNode);
            break;

        case 4:
            // Memperbarui data node
            cout << "Masukkan data node yang ingin diupdate: ";
            cin >> data;
            update(data, root_2311102135);
            break;

        case 5:
            // Mendapatkan data node
            cout << "Masukkan data node yang ingin diretrieve: ";
            cin >> data;
            retrieve(find(data));
            break;

        case 6:
            // Menampilkan descendant dari sebuah node
            cout << "Masukkan data node: ";
            cin >> data;
            tampilkanDescendant(find(data));
            cout << endl;
            break;

        case 7:
            // Menampilkan data secara ascending
            tampilkanAscending(root_2311102135);
            cout << endl;
            break;

        case 8:
            // Menampilkan traversal (preorder, inorder, postorder) dan sibling
            cout << "Masukkan data node yang ingin ditampilkan traversal dan siblingnya: ";
            cin >> data;
            selectedNode = find(data);
            if (selectedNode == nullptr)
            {
                cout << "Node tidak ditemukan." << endl;
            }
            else
            {
                cout << "Traversal dan Sibling dari node " << data << ":\n";
                traversalAndSibling(selectedNode);
            }
            break;

        case 9:
            // Menghapus sebuah node
            cout << "Masukkan data node yang ingin dihapus: ";
            cin >> data;
            deleteNode(data, root_2311102135);
            break;

        case 10:
            // Mencari level dari sebuah node
            cout << "Masukkan data node yang ingin dicari levelnya: ";
            cin >> data;
            findLevel(root_2311102135, data, 1);
            break;

        case 11:
            // Menampilkan karakteristik dari tree
            cout << "Detail Tree : " << endl;
            characteristic();
            break;

        case 12:
            // Menampilkan detail sebuah node beserta parent, sibling, dan child-nya
            cout << "Masukkan data node : ";
            cin >> data;
            cout << "Detail tree dari node " << data << " adalah : " << endl;
            find(find(data));
            break;

        case 13:
            cout << "Keluar dari program.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            break;
        }
    } while (pilihan != 13);

    return 0;
}
```
#### Output:

![Alt text](<screenshoot unguided 2.1.png>)

![Alt text](<screenshoot unguided 2.2.png>)

![Alt text](<screenshoot unguided 2.3.png>)

![Alt text](<screenshoot unguided 2.4.png>)

![Alt text](<screenshoot unguided 2.5.png>)

Program diatas merupakan implementasi pohon biner dalam bahasa pemrograman C++. Program ini menyediakan berbagai fungsi untuk memanipulasi pohon biner, termasuk membuat root, menambah node, menghapus node, memperbarui data pada node, mencari node, dan menampilkan informasi terkait node serta pohon itu sendiri. Struktur data `Pohon` digunakan untuk merepresentasikan setiap node dalam pohon, yang menyimpan data karakter dan pointer ke anak kiri, anak kanan, dan parent node. Program dimulai dengan inisialisasi pohon melalui fungsi `init()` dan menyediakan pengecekan apakah pohon kosong melalui `isEmpty()`. Node baru dapat ditambahkan sebagai root menggunakan `buatNode()`, atau sebagai anak kiri atau kanan dari node tertentu menggunakan `insertLeft()` dan `insertRight()`. Fungsi `update()` memungkinkan perubahan data pada node tertentu, sedangkan `find()` digunakan untuk mencari node berdasarkan data. Program juga menyediakan berbagai jenis traversal pohon seperti pre-order, in-order, dan post-order melalui fungsi `PreOrder()`, `InOrder()`, dan `PostOrder()`. Fungsi `deleteSubtree()` dan `deleteNode()` digunakan untuk menghapus node dan subtree-nya, sedangkan `size()` dan `height()` menghitung jumlah node dan tinggi pohon. Program ini juga dapat menampilkan karakteristik pohon dan detail node tertentu termasuk parent, sibling, dan anak-anaknya. Fungsi utama (`main`) menyediakan antarmuka menu interaktif bagi pengguna untuk melakukan berbagai operasi pada pohon biner sesuai pilihan yang diberikan.

## Kesimpulan

Graf dan pohon adalah konsep fundamental dalam teori graf dan struktur data yang memiliki aplikasi luas dalam ilmu komputer. Graf adalah representasi grafis yang melibatkan sekumpulan objek yang dilambangkan dengan simpul (vertex) dan relasi antar objek yang dilambangkan dengan rusuk (edge). Berdasarkan keberadaan gelang atau sisi ganda, graf dibedakan menjadi graf sederhana yang tidak mengandung gelang maupun sisi ganda, dan graf tak sederhana yang dapat mengandung sisi ganda atau gelang. Selain itu, berdasarkan orientasi arah pada sisinya, graf dibagi menjadi graf tak berarah, di mana urutan pasangan simpul tidak diperhatikan, dan graf berarah, di mana urutan pasangan simpul diperhatikan dan diberikan orientasi arah.

Pohon (tree) adalah jenis khusus dari graf yang terhubung tanpa mengandung sirkuit, dan menggambarkan hubungan hierarkis antar elemen. Terdapat berbagai jenis pohon seperti full binary tree, di mana setiap nodenya memiliki satu root dan dua anak; complete binary tree, yang mirip dengan full binary tree tetapi memperbolehkan sub-tree dengan panjang path berbeda kecuali leaf; dan skewed binary tree, di mana semua nodenya kecuali daun hanya memiliki satu anak. Berbagai operasi dapat dilakukan pada pohon, termasuk membentuk, mengosongkan, memeriksa kekosongan, memasukkan node, mencari elemen, mengubah isi node, mengetahui isi node, menghapus subtree, mengetahui karakteristik pohon, dan mengunjungi seluruh node dengan metode traversal seperti Pre-Order, In-Order, dan Post-Order. Kedua struktur ini memainkan peran penting dalam pengelolaan dan manipulasi data di berbagai aplikasi komputasi.

## Referensi

[1] Edwin Leonardo, Tri Sutrisno, Dyah Erny Herwindiati. 2020. KLASIFIKASI EMPLOYABILITY MAHASISWA PENERIMA BEASISWA DI UNIVERSITAS TARUMANAGARA DENGAN GRAPH THEORY (MINIMUM SPANNING TREE). Universitas Tarunanegara : Jakarta.

[2]. Fitri Latifah. 2022. PENERAPAN ALGORITHMA POHON UNTUK OPERASI PENGOLAHAN DAN PENYIMPANAN DATA DALAM TEKNIK PEMROGRAMAN (KAJIAN ALGORITHMA POHON PADA TEKNIK PEMROGRAMAN). Jakarta.

[3] Susila Bahri, Ghazy Muhari Novrial, Narwen. 2023. PEMROGRAMAN PEWARNAAN GRAF PADA PENJADWALAN MATA KULIAH JURUSAN MATEMATIKA. Universitas Andalas.