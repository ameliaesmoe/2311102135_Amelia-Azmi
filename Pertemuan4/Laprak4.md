# <h1 align="center">Laporan Praktikum Modul 4 Linked List Circular dan Non Circular</h1>
<p align="center">Amelia Azmi_2311102135</p>

## Dasar Teori

Linked List atau Single Linked List merupakan suatu bentuk struktur data yang berisi kumpulan data yang disebut sebagai node yang tersusun secara sekuensial, saling sambung menyambung, dinamis, dan terbatas Linked list sering juga disebut dengan sebagai sebutan senarai brantai. Cara untuk menghubungkan satu node dengan node lainnya maka Linked List menggunakan pointer sebagai penunjuk node selanjutnya atau bisa disebut next.
Node merupakan sebuah struct atau tipe data bentukkan yang menempati suatu lokasi memori secara dinamis yang terdiri dari beberapa field, minimal 2 buah field. Field tersebut adalah field untuk isi struct datanya sendiri dan 1 field arbitari bertipe pointer sebagai penunjuk node selanjutnya.

1. Linked List Non-Circular
Single Linked List Non Circular adalah Node terakhir menunjuk ke NULL yang akan digunakan sebagai kondisi berhenti pada saat pembacaan isi linked list. 

BENTUK NODE SINGLE LINKLED LIST NON CIRCULAR 
a). Single : field pointer-nya hanya satu arah, pada akhir not pointer-nya menunjuk NULL 
b). Linked List : Node - node tersebut saling terhubung satu sama lain setiap node pada linked list mempunyai field yang berisi pointer ke node berikutnya, dan juga memiliki field yang berisi data. Mode terakhir akan menunjuk NULL yang akan digunakan sebagai kondisi berhenti pada saat pembacaan isi linked list. 

1.  Deklarasi Simpul (Node)
```C++
struct node
{
    int data;
    node *next;
}
```

2. Membuat dan Menginisialisasi Pointer Head dan Tail
```C++
node *head, *tail;
void init()
{
    head = NULL;
    tail = NULL;
};
```

3. Pengecekan Kondisi Linked List
```C++
bool isEmpty()
{
    if (head == NULL && tail == NULL)
    {
        return true;
        }
        else
        {
            return false;
            }
}
```
4. Penambahan Simpul (Node)
```C++
void insertBelakang(string dataUser)
{
    if (isEmpty() == true)
    {
        node *baru = new node;
        baru->data = dataUser;
        head = baru;
        tail = baru;
        baru->next = NULL;
        }
        else
        {
            node *baru = new node;
            baru->data = dataUser;
            baru->next = NULL;
            tail->next = baru;
            tail = baru;
            }
};
```

5. Penghapusan Simpul (Node)
```C++
void hapusDepan()
{
    if (isEmpty() == true)
    {
        cout << "List kosong!" << endl;
        }
        else
        {
            node *helper;
            helper = head;
            if (head == tail)
            {
                head = NULL;
                tail = NULL;
                delete helper;
                }
                else
                head = head->next;
                helper->next = NULL;
                delete helper;
            }
        }
}
```

6.  Tampil Data Linked List
```C++
void tampil()
{
    if (isEmpty() == true)
    {
        cout << "List kosong!" << endl;
        }
        else
        {
            node *helper;
            helper = head;
            while (helper != NULL)
            {
                cout << helper->data << ends;
                helper = helper->next;
             }
        }
}
```


2. Linked list circular 

Circural linked list adalah suatu linked list yang tidak memiliki nilai nil / NULL untuk medan sambungannya. Circular Linked List dapat dilakukan terhadap Singly Linked List maupun Doubly Linked List. Dalam Circular Linked List tidak terdapat suatu simpul yang bernilai NULL. Hal ini terjadi karena simpul terakhir dihubungkan terhadap simpul pertama untuk Single Linked List dan simpul pertama dengan simpul terakhir saling terhubung untuk Double Linked List. 

1. Deklarasi Simpul (Node)
```C++
struct Node
{
    string data;
    Node *next;
};
```

2.  Membuat dan Menginisialisasi Pointer Head dan Tail
```C++
Node *head, *tail, *baru, *bantu, *hapus;
void init()
{
    head = NULL;
    tail = head;
}
```

3.  Pengecekan Kondisi Linked List
```C++
int isEmpty()
{
    if (head == NULL)
    return 1; // true
    else
    return 0; // false
}
```

4.  Pembuatan Simpul (Node)
```C++
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}
```

5. Penambahan Simpul (Node)
```C++
// Tambah Depan
void insertDepan(string data)
{

// Buat Node baru
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
            }
            baru->next = head;
            head = baru;
            tail->next = head;
        }
}
```

6. Penghapusan Simpul (Node)
```C++
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
            }
            else
            {
                while (hapus->next != head)
                {
                    hapus = hapus->next;
                    }
                    while (tail->next != hapus)
                    {
                        tail = tail->next;
                        }
                        tail->next = head;
                        hapus->next = NULL;
                        delete hapus;
                        }
}
```

7.  Menampilkan Data Linked List
```C++
oid tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
            } while (tail != head);
            cout << endl;
            }
}
 ```
## Guided 

### 1. [Linked List Non-Circular]

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node{
    int data;
    Node *next;
    };
    Node *head;
    Node *tail;

// Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
    }

// Pengecekan
bool isEmpty(){
    if (head == NULL)
        return true;
    else
        return false;
    }

// Tambah Depan
void insertDepan(int nilai){
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }else {
        baru->next = head;
        head = baru;
        }
    }

// Tambah Belakang
void insertBelakang(int nilai){
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }else {
        tail->next = baru;
        tail = baru;
        }
    }
        
// Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Tengah
void insertTengah(int data, int posisi){
    if (posisi < 1 || posisi > hitungList()){
        cout << "Posisi diluar jangkauan" << endl;
        }
    else if (posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }else {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;

        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan(){
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
            head = tail = NULL;
        }else{
            cout << "List kosong!" << endl;
        }
    }
}
// Hapus Belakang
void hapusBelakang(){
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }else{
            head = tail = NULL;
        }
    }else{
        cout << "List kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi){
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList()){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }else{
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi){
            if (nomor == posisi - 1){
                sebelum = bantu;
            }
            if (nomor == posisi){
                hapus = bantu;
                }
                bantu = bantu->next;
                nomor++;
            }
            sebelum->next = bantu;
            delete hapus;
        }
    }

// Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == 0){
        head->data = data;
        }else{
            cout << "List masih kosong!" << endl;
        }
    }

// Ubah Tengah
void ubahTengah(int data, int posisi){
Node *bantu;
if (isEmpty() == 0){
    if (posisi < 1 || posisi > hitungList()){
        cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }else{
    cout << "List masih kosong!" << endl;
    }
}

// Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == 0){
        tail->data = data;
    }else{
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }else{
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
Program yang tersebut merupakan struktur data linked list non-circular dalam bahasa pemrograman C++. Pada program ini, memiliki fungsi utama yang digunakan untuk mengelola operasi-operasi dasar pada linked list, seperti penambahan, penghapusan, dan pengubahan nilai data pada simpul. Fungsi `init()` digunakan untuk menginisialisasi linked list, sementara `isEmpty()` memeriksa apakah linked list kosong. Penambahan elemen dilakukan dengan fungsi `insertDepan()` dan `insertBelakang()`, yang masing-masing menambahkan simpul baru di bagian depan dan belakang linked list. Selain itu, terdapat juga fungsi `insertTengah()` untuk menambahkan simpul baru pada posisi tertentu dalam linked list. Penghapusan elemen dilakukan dengan fungsi `hapusDepan()`, `hapusBelakang()`, dan `hapusTengah()`, untuk menghapus simpul pertama, terakhir, dan pada posisi tertentu dalam linked list. Kemudian untuk mengubah nilai data pada simpul, terdapat fungsi `ubahDepan()`, `ubahTengah()`, dan `ubahBelakang()`. Fungsi `hitungList()` digunakan untuk menghitung jumlah simpul dalam linked list, `clearList()` untuk menghapus semua simpul dari linked list. Fungsi `tampil()` digunakan untuk menampilkan isi dari linked list. Di dalam `main()`, program menunjukkan serangkaian operasi yang menggambarkan penggunaan fungsi-fungsi tersebut, seperti menambah, menghapus, dan mengubah nilai data simpul, serta menampilkan isi linked list setiap kali ada perubahan.  Program ini memberikan implementasi yang fleksibel dalam mengelola data dengan menggunakan konsep single linked list dalam pengolahan data yang dinamis. 

### 2. [Linked List Circular]

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node* next;
};

Node* head, * tail, * baru, * bantu, * hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Program ini merupakan implementasi dari sebuah struktur data circular linked list dalam bahasa pemrograman C++. Circular linked list adalah struktur data berantai di mana setiap node memiliki pointer yang menunjuk ke node berikutnya, dan node terakhir menunjuk kembali ke node pertama, membentuk lingkaran. Pada program di atas memiliki beberapa fungsi. 

Main() pada program tersebut memiliki serangkaian operasi yang menunjukkan penggunaan fungsi-fungsi tersebut, seperti menambah dan menghapus simpul, serta menampilkan isi linked list setiap kali terjadi perubahan. Program tersebut juga menggunakan konsep linked list untuk menyimpan dan mengelola data dalam bentuk circular, pada simpul terakhir mengarah kembali ke simpul pertama hal tersebut untuk menciptakan struktur data yang fleksibel dan efisien. 

## Unguided 

### 1. [Linked List Non Circular]

Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.
1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:
Tampilan Menu:
PROGRAM SINGLE LINKED LIST NON-CIRCULAR
1. Tambah Depan
2. Tambah Belakang
3. Tambah Tengah
4. Ubah Depan
5. Ubah Belakang
6. Ubah Tengah
7. Hapus Depan
8. Hapus Belakang
9. Hapus Tengah
10. Hapus List
11. TAMPILKAN
0. KELUAR
Pilih Operasi :

• Tampilan Operasi Tambah:
-Tambah Depan-
Masukkan Nama :
Masukkan NIM :
Data telah ditambahkan
-Tambah Tengah-
Masukkan Nama :
Masukkan NIM :
Masukkan Posisi :
Data telah ditambahkan

• Tampilan Operasi Hapus:
-Hapus Belakang-
Data (nama mahasiswa yang dihapus) berhasil dihapus
-Hapus Tengah-
Masukkan posisi :
Data (nama mahasiswa yang dihapus) berhasil dihapus

• Tampilan Operasi Ubah:
-Ubah Belakang-
Masukkan nama :
Masukkan NIM :
Data (nama lama) telah diganti dengan data (nama baru)
-Ubah Belakang-
Masukkan nama :
Masukkan NIM :
Masukkan posisi :
Data (nama lama) telah diganti dengan data (nama baru)

• Tampilan Operasi Tampil Data:
DATA MAHASISWA
NAMA NIM
Nama1 NIM1
Nama2 NIM2
*Buat tampilan output sebagus dan secantik mungkin sesuai kreatifitas anda
masing-masing, jangan terpaku pada contoh output yang diberikan

```C++
// Edited by Amelia Azmi_2311102135
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

class LinkedList_Mahasiswa {
private:
    Mahasiswa* head;

public:
    LinkedList_Mahasiswa() {
        head = NULL;
    }

    void tambah_depan(string nama, string nim) {
        Mahasiswa* new_mahasiswa = new Mahasiswa;
        new_mahasiswa->nama = nama;
        new_mahasiswa->nim = nim;
        new_mahasiswa->next = head;
        head = new_mahasiswa;
    }

    void tambah_belakang(string nama, string nim) {
        Mahasiswa* new_mahasiswa = new Mahasiswa;
        new_mahasiswa->nama = nama;
        new_mahasiswa->nim = nim;
        new_mahasiswa->next = NULL;

        if (head == NULL) {
            head = new_mahasiswa;
            return;
        }

        Mahasiswa* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_mahasiswa;
    }

    void tambah_tengah(int posisi, string nama, string nim) {
        if (posisi <= 1) {
            tambah_depan(nama, nim);
            return;
        }

        Mahasiswa* new_mahasiswa = new Mahasiswa;
        new_mahasiswa->nama = nama;
        new_mahasiswa->nim = nim;

        Mahasiswa* current = head;
        for (int i = 1; i < posisi - 1 && current != NULL; i++) {
            current = current->next;
        }

        if (current != NULL) {
            new_mahasiswa->next = current->next;
            current->next = new_mahasiswa;
        } else {
            cout << "Posisi tidak valid." << endl;
        }
    }

    void hapus_belakang() {
        if (head == NULL) {
            cout << "Linked list kosong." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Mahasiswa* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }

        delete current->next;
        current->next = NULL;
    }

    void hapus_tengah(int posisi) {
        if (posisi <= 1) {
            Mahasiswa* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Mahasiswa* current = head;
        for (int i = 1; i < posisi - 1 && current != NULL; i++) {
            current = current->next;
        }

        if (current != NULL && current->next != NULL) {
            Mahasiswa* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            cout << "Posisi tidak valid." << endl;
        }
    }

    void tampilkan() {
        Mahasiswa* current = head;
        cout << "==============================================================" << endl;
        cout << setw(5) << left << "NO." << setw(20) << left << "NAMA" << "NIM" << endl;
        int i = 1;
        while (current != NULL) {
            cout << setw(5) << left << i << setw(20) << left << current->nama << current->nim << endl;
            current = current->next;
            i++;
        }
        cout << "==============================================================" << endl;
    }

  void ubah_depan(string nama_baru, string nim_baru) {
    if (head == NULL) {
        cout << "Linked list kosong." << endl;
        return;
    }

    string nama_lama = head->nama; 
    head->nama = nama_baru;
    head->nim = nim_baru;
    cout << "Data " << nama_lama << " telah diganti dengan data " << nama_baru << endl;
}


    void ubah_belakang(string nama_baru, string nim_baru) {
    if (head == NULL) {
        cout << "Linked list kosong." << endl;
        return;
    }

    Mahasiswa* current = head;
    Mahasiswa* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    
    string nama_lama = current->nama;
    current->nama = nama_baru;
    current->nim = nim_baru;
    cout << "Data " << nama_lama << " telah diganti dengan data " << nama_baru << endl;
}


    void ubah_tengah(int posisi, string nama_baru, string nim_baru) {
    if (posisi <= 1) {
        ubah_depan(nama_baru, nim_baru);
    } else {
        Mahasiswa* current = head;
        for (int i = 1; i < posisi && current != NULL; i++) {
            current = current->next;
        }
        if (current != NULL) {
            string nama_lama = current->nama;
            current->nama = nama_baru;
            current->nim = nim_baru;
            cout << "Data " << nama_lama << " telah diganti dengan data " << nama_baru << endl;
        } else {
            cout << "Posisi tidak valid." << endl;
        }
    }
}

    void hapus_list() {
        while (head != NULL) {
            hapus_depan();
        }
        cout << "Seluruh data mahasiswa telah dihapus." << endl;
    }

    void hapus_depan() {
        if (head != NULL) {
            Mahasiswa* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList_Mahasiswa linked_list;
    int pilihan;
    string nama, nim;
    int posisi;

do {
    cout << "|===========================================|" << endl;
    cout << "|            Nama : Amelia Azmi             |" << endl;
    cout << "|            Nim  : 2311102135              |" << endl;
    cout << "|===========================================|\n"<< endl;
     
    cout << "|===============================================|" << endl;
    cout << "|PROGRAM SINGLE LINKED LIST NON-CIRCULAR ◝(ᵔᵕᵔ)◜|" << endl;
    cout << "|===============================================|" << endl;
    cout << "|1.Tambah Depan                                 |" << endl;
    cout << "|2.Tambah Belakang                              |" << endl;
    cout << "|3.Tambah Tengah                                |" << endl;
    cout << "|4.Ubah Depan                                   |" << endl;
    cout << "|5.Ubah Belakang                                |" << endl;
    cout << "|6.Ubah Tengah                                  |" << endl;
    cout << "|7.hapus depan                                  |" << endl;
    cout << "|8.hapus belakang                               |" << endl;
    cout << "|9.hapus Tengah                                 |" << endl;
    cout << "|10.hapus list                                  |" << endl;
    cout << "|11.Tampilkan                                   |" << endl;
    cout << "|0.Exit                                         |" << endl;
    cout << "|===============================================|" << endl;
    cout << "\nPilih Operasi : ";
    cin >> pilihan;
    
    switch (pilihan) {
            case 1:
                cout << "Tambah Depan" << endl;
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                linked_list.tambah_depan(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 2:
                cout << "Tambah Belakang" << endl;
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                linked_list.tambah_belakang(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 3:
                cout << "Tambah Tengah" << endl;
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                linked_list.tambah_tengah(posisi, nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 4:
                cout << "Ubah Depan" << endl;
                cout << "Masukkan Nama Baru: ";
                cin >> nama;
                cout << "Masukkan NIM Baru: ";
                cin >> nim;
                linked_list.ubah_depan(nama, nim);
                cout << "Data telah diubah" << endl;
                break;
            case 5:
                cout << "Ubah Belakang" << endl;
                cout << "Masukkan Nama Baru: ";
                cin >> nama;
                cout << "Masukkan NIM Baru: ";
                cin >> nim;
                linked_list.ubah_belakang(nama, nim);
                break;
            case 6:
                cout << "Ubah Tengah" << endl;
                cout << "Masukkan Nama Baru: ";
                cin >> nama;
                cout << "Masukkan NIM Baru: ";
                cin >> nim;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                linked_list.ubah_tengah(posisi, nama, nim);
                break;
            case 7:
                cout << "Hapus Depan" << endl;
                linked_list.hapus_depan();
                cout << "Data depan berhasil dihapus." << endl;
                break;
            case 8:
                cout << "Hapus Belakang" << endl;
                linked_list.hapus_belakang();
                cout << "Data belakang berhasil dihapus." << endl;
                break;
            case 9:
                cout << "Hapus Tengah" << endl;
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                linked_list.hapus_tengah(posisi);
                cout << "Data pada posisi " << posisi << " berhasil dihapus." << endl;
                break;
            case 10:
                cout << "Hapus List" << endl;
                linked_list.hapus_list();
                break;
            case 11:
                cout << "Tampilkan" << endl;
                linked_list.tampilkan();
                break;
            case 0:
                cout << "Keluar" << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }

    } while (pilihan != 0);
 return 0;
}
```
#### Output:
Tampilan Menu
![Alt text](<../Screenshoot 1.1.png>)

Tampilan Operasi Tambah
![Alt text](<../Screenshoot 1.2.png>)

![Alt text](<../Screenshoot 1.3.png>)

Tampilan Operasi Hapus
![Alt text](<../Screenshoot 1.4.png>)

![Alt text](<../Screenshoot 1.5.png>)

Tampilan Operasi Ubah
![Alt text](<../Screenshoot 1.6.png>)

![Alt text](<../Screenshoot 1.7.png>)

Tampilkan Operasi Tampilan
![Alt text](<../Screenshoot 1.8.png>)

Program tersebut merupakan implementasi dari struktur data linked list non circular yang digunakan untuk menyimpan informasi mahasiswa. Program ini memiliki fungsi-fungsi dasar yang memungkinkan pengguna untuk menambah, mengubah, dan menghapus data mahasiswa dalam linked list. Dalam program ini mendefinisikan struktur data `Mahasiswa` yang memiliki atribut nama dan NIM. Kemudian, terdapat `LinkedList_Mahasiswa` yang merupakan representasi dari linked list itu sendiri. `LinkedList_Mahasiswa` memiliki berbagai fungsi, mulai dari menambah data mahasiswa di bagian depan, belakang, ataupun di tengah linked list, hingga menghapus data depan, belakang, ataupun di posisi tertentu dalam linked list. Selain itu, program ini juga mempunyai fungsi untuk menampilkan seluruh data mahasiswa dalam linked list seperti fungsi untuk mengubah data mahasiswa pada bagian depan, belakang, ataupun di posisi tengah linked list. Program tersebut juga terdapat fungsi untuk menghapus seluruh data dalam linked list. Fungsi utama (`main`) dari program yang memiliki sebuah loop `do-while` yang akan terus berjalan sampai pengguna memilih opsi keluar (0). Setiap opsi memiliki penjelasan yang jelas untuk pengguna bisa dengan mudah berinteraksi dengan program dan mengelola data mahasiswa sesuai kebutuhan. 

 
2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu
tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau
tengah)
![Alt text](<../Screenshoot 2.1.png>)

3. Lakukan perintah berikut :
a). Tambahkan data diantara  Farrel dan Denis : Wati 2330004
![Alt text](<../Screenshoot 3.1.png>)

b). Hapus data Denis
![Alt text](<../Screenshoot 3.2.png>)

c). Tambahkan data berikut diawal : Owi 2330000
![Alt text](<../Screenshoot 3.3.png>)

d). Tambahkan data berikut di akhir : David 23300100
![Alt text](<../Screenshoot 3.4.png>)

e). Ubah data Udin menjadi data berikut : idin 23300045
![Alt text](<../Screenshoot 3.5.png>)

f). Ubah data terakhir menjadi berikut : Lucy 23300101
![Alt text](<../Screenshoot 3.6.png>)

g). Hapus data awal
![Alt text](<../Screenshoot 3.7.png>)

h). Ubah data awal menjadi beriku : Bagas 2330002
![Alt text](<../Screenshoot 3.8.png>)

i). Hapus data akhir
![Alt text](<../Screenshoot 3.9.png>)

j). Tampilkan seluruh data
![Alt text](<../Screenshoot 3.10.png>)


## Kesimpulan

1. Linked List Non-Circular:
   - Merupakan struktur data dinamis yang terdiri dari node-node yang saling terhubung satu sama lain secara sekuensial.
   - Setiap node memiliki minimal dua field: satu untuk menyimpan data dan yang lainnya untuk menunjukkan ke node berikutnya (disebut pointer next).
   - Node terakhir dalam linked list non-circular menunjuk ke NULL sebagai kondisi berhenti pada pembacaan isi linked list.
   - Dalam operasinya, dapat dilakukan penambahan simpul di belakang, penghapusan simpul dari depan, dan tampilan data linked list.

2. Linked List Circular:
   - Mirip dengan non-circular, namun dalam circular linked list tidak ada simpul yang menunjuk ke NULL.
   - Simpul terakhir terhubung kembali dengan simpul pertama untuk single linked list dan simpul pertama dengan simpul terakhir untuk double linked list.
   - Operasinya mencakup penambahan simpul di depan, penghapusan simpul dari belakang, dan tampilan data linked list.
   
Kedua jenis linked list ini menyediakan fleksibilitas dalam penyimpanan dan manipulasi data, meskipun penggunaannya mungkin lebih efisien dalam kasus-kasus tertentu dibandingkan dengan array. Setiap jenis memiliki keunggulan dan kelemahan yang perlu dipertimbangkan sesuai dengan kebutuhan aplikasi yang spesifik.

Kesimpulan pada praktikum kali ini, linked list adalah bentuk struktur data yang berisi kumpulan data node yang tersusun secara sequensial, saling sambung, dinamis, dan terbatas. Linked list berbeda dengan array,dimana dapat dilihat dari sifat datanya, kefleksibelan data dimana linked list dapat menambah, mengubah dan menghapus data secara tak terbatas, dan akses terhadap memori. Dari tugas yang tersedia kita diminta untuk membuat program menu Single Linked List Non-Circular untuk menyimpan Nama dan NIMmahasiswa, dengan menggunakan inputan dari user

## Referensi
[1]. Irene, Irma, Irmayanti, Irwandi, Jumarni, Kurniati. 2022. Single Linked List, Double-Ended List, Doubly Linked List, Circular Linked List, dan Iterator. Universitas Tomakaka Mamuju : Mamuju, Sulaweesi Barat.
[2]. Triase, ST, M. Kom. 2020. Struktur Data. Universitas Negeri Sumatera Utara : Sumatera Utara.
[3]. Praktikum Modul 4. Circular dan Non Circular. Institute Technology Telkom Purwokerto : Purwokerto.