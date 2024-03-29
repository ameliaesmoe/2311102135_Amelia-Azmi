# <h1 align="center">Laporan Praktikum Modul Single and Double Linked List</h1>
<p align="center">Amelia Azmi_2311102135</p>

## Dasar Teori

1. Single  Linked List	 

Single linked list terdiri dari elemen-elemen individu, dimana masing-masing dihubungkan dengan pointer tunggal. Masing-masing elemen terdiri dari dua bagian, yaitu sebuah data dan sebuah pointer yang disebut dengan pointer next. Dengan menggunakan struktur two-member seperti ini, linked list dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya 

2. Double Linked List 

Double linked list terdiri dari elemen-elemen individu, dimana masing-masing elemen dihubungkan dengan dua pointer. Setiap elemen terdiri dari tiga bagian, yaitu sebuah data dan sebuah pointer yang berisi alamat data berikutnya disebut dengan next dan pointer yang berisi alamat data sebelumnya disebut before. Dengan menggunakan struktur two-member seperti ini, linked list dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya. Pointer before pada elemen terakhir merupakan NULL, yang menunjukkan awal dari suatu list. Pointer next pada elemen terakhir merupakan NULL, yang menunjukkan akhir dari suatu list. 

## Guided 

### 1. [Single Linked List]

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
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
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
//Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
            cout << "List kosong!" << endl;
        }
    }
//Hapus Belakang
void hapusBelakang() {
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
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);tampil();
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
    insertTengah(7,2);
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
Program di atas merupakan implementasi dari struktur data single linked list dalam bahasa pemrograman C++. Linked list tersebut menyimpan data dalam simpul-simpul yang saling terhubung. Fungsi dari program ini untuk menambahkan, menghapus, mengubah, dan menampilkan data dalam linked list. Setiap simpul memiliki data dan pointer yang menunjuk ke simpul berikutnya. Program ini menggunakan operasi-operasi dasar pada linked list seperti tambah depan, tambah belakang, tambah tengah, hapus depan, hapus belakang, hapus tengah, ubah depan, ubah belakang, ubah tengah, dan tampilkan isi linked list. 

### 2. [Double Linked List]

```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Program tersebut merupakan sebuah program C++ yang mengimplementasikan double linked list. double linked list adalah struktur data berantai yang setiap nodenya memiliki dua pointer, yaitu pointer yang menunjuk ke node sebelumnya dan pointer yang menunjuk ke node selanjutnya. Program memiliki beberapa menu operasi seperti menambah data, menghapus data, mengubah data, membersihkan semua data, dan menampilkan data. Kemudian pengguna dapat memilih operasi yang ingin dilakukan melalui menu yang disediakan, dan program akan menjalankan operasi tersebut pada double linked list yang disimpan. Lalu program akan terus berjalan hingga pengguna memilih menu keluar. 

 
## Unguided 

### 1. [Soal Single Linked List]
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.
[Nama_anda] [Usia_anda]
John 19
Jane 20
Michael 18
Yusuke 19
Akechi 20
Hoshino 18
Karin 18
b. Hapus data Akechi
c. Tambahkan data berikut diantara John dan Jane : Futaba 18
d. Tambahkan data berikut diawal : Igor 20
e. Ubah data Michael menjadi : Reyn 18
f. Tampilkan seluruh data

```C++
#include <iostream>
#include <string>
using namespace std;

// deklarasi struct node
struct Node {
    string datanama_135;
    int usia_135;
    Node* next_135;
};

Node* head_135 = nullptr;
Node* tail_135 = nullptr;

// inisialisasi node
void init_135() {
    head_135 = nullptr;
    tail_135 = nullptr;
}

// pengecekan apakah list kosong
bool isEmpty_135() {
    return head_135 == nullptr;
}

// hitung jumlah node
int hitungList_135() {
    int jumlah_135 = 0;
    Node* hitung_135 = head_135;
    while (hitung_135 != nullptr) {
        jumlah_135++;
        hitung_135 = hitung_135->next_135;
    }
    return jumlah_135;
}

// tambah node di depan
void insertDepan_135(string datanama_135, int usia_135) {
    Node* baru_135 = new Node;
    baru_135->datanama_135 = datanama_135;
    baru_135->usia_135 = usia_135;
    baru_135->next_135 = nullptr;

    if (isEmpty_135()) {
        head_135 = tail_135 = baru_135;
    } else {
        baru_135->next_135 = head_135;
        head_135 = baru_135;
    }
}

// tambah node di belakang
void insertBelakang_135(string datanama_135, int usia_135) {
    Node* baru_135 = new Node;
    baru_135->datanama_135 = datanama_135;
    baru_135->usia_135 = usia_135;
    baru_135->next_135 = nullptr;

    if (isEmpty_135()) {
        head_135 = tail_135 = baru_135;
    } else {
        tail_135->next_135 = baru_135;
        tail_135 = baru_135;
    }
}

// tambah node di tengah
void insertTengah_135(string datanama_135, int usia_135, int letak_135) {
    if (letak_135 < 1) {
        cout << "Posisi diluar jangkauan" << endl;
        return;
    }

    if (letak_135 == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }

    if (letak_135 > 1 && letak_135 <= hitungList_135()) {
        Node* baru = new Node;
        baru->datanama_135 = datanama_135;
        baru->usia_135 = usia_135;

        Node* bantu_135 = head_135;
        int nomor_135 = 1;

        while (nomor_135 < letak_135 - 1) {
            bantu_135 = bantu_135->next_135;
            nomor_135++;
        }

        baru->next_135 = bantu_135->next_135;
        bantu_135->next_135 = baru;
    } else {
        cout << "Posisi diluar jangkauan" << endl;
    }
}

// hapus node di tengah
void hapusTengah_135(string datanama_135) {
    if (!isEmpty_135()) {
        Node* hapus_135;
        Node* bantu_135 = head_135;

        if (head_135->datanama_135 == datanama_135) {
            hapus_135 = head_135;
            head_135 = head_135->next_135;
            delete hapus_135;
            return;
        }

        while (bantu_135->next_135 != nullptr && bantu_135->next_135->datanama_135 != datanama_135) {
            bantu_135 = bantu_135->next_135;
        }

        if (bantu_135->next_135 == nullptr) {
            cout << "Data tidak ditemukan!" << endl;
        } else {
            hapus_135 = bantu_135->next_135;
            bantu_135->next_135 = bantu_135->next_135->next_135;
            delete hapus_135;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// ubah data node
void ubahData_135(string datanamaCari_135, string datanamaBaru_135, int usiaBaru_135) {
    Node* bantu_135 = head_135;
    while (bantu_135!= nullptr) {
        if (bantu_135->datanama_135 == datanamaCari_135) {
            bantu_135->datanama_135 = datanamaBaru_135;
            bantu_135->usia_135 = usiaBaru_135;
            return;
        }
        bantu_135 = bantu_135->next_135;
    }
    cout << "Data tidak ditemukan!" << endl;
}

// tampilkan seluruh node
void tampil_135() {
    Node* bantu_135 = head_135;
    if (!isEmpty_135()) {
        while (bantu_135 != nullptr) {
            cout << bantu_135->datanama_135 << " " << bantu_135->usia_135 << endl;
            bantu_135 = bantu_135->next_135;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init_135();

    // Masukkan data mahasiswa
    cout << "Masukkan data mahasiswa sesuai urutan berikut:" << endl;
    cout << "[Nama] [Usia]" << endl;
    string datanama_135;
    int usia_135;
    while (true) {
        cout << "Masukkan nama : ";
        cin >> datanama_135;
        if (datanama_135 == "stop") break; // jika menginputkan stop, maka perulangan berhenti
        cout << "Masukkan usia : ";
        cin >> usia_135;
        insertBelakang_135(datanama_135, usia_135);
    }

    // a. Hapus data
    cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
    cin >> datanama_135;
    hapusTengah_135(datanama_135);

    // b. Tambahkan data
    cout << "Masukkan nama mahasiswa yang ingin ditambahkan: ";
    cin >> datanama_135;
    cout << "Masukkan usia : ";
    cin >> usia_135;
    insertTengah_135(datanama_135, usia_135, 2);

    // c. Tambahkan data di awal
    cout << "Masukkan nama mahasiswa yang ingin ditambahkan di awal: ";
    cin >> datanama_135;
    cout << "Masukkan usia : ";
    cin >> usia_135;
    insertDepan_135(datanama_135, usia_135);

    // d. Ubah data
    string datanamaCari_135, datanamaBaru_135;
    int usiaBaru_135;
    cout << "Masukkan nama mahasiswa yang ingin diubah datanya: ";
    cin >> datanamaCari_135;
    cout << "Masukkan nama baru: ";
    cin >> datanamaBaru_135;
    cout << "Masukkan usia baru: ";
    cin >> usiaBaru_135;
    ubahData_135(datanamaCari_135, datanamaBaru_135, usiaBaru_135);

    // e. Tampilkan seluruh data
    cout << "Data Mahasiswa:" << endl;
    tampil_135();

    return 0;
}

```
#### Output:
![Alt text](<Screenshoot Ouput Unguided1.png>)

Program tersebut merupakan implementasi dari single linked list untuk menyimpan informasi. Setiap simpul dalam linked list tersebut memiliki dua data, yaitu nama dan usia. Program ini memiliki fungsi untuk menambahkan, menghapus, mengubah, dan menampilkan data dalam linked list. Kemudian pengguna dapat memasukkan data mahasiswa, menghapus data, menambah data di awal, di tengah, mengubah data, dan menampilkan seluruh data yang telah tersimpan pada linked list. 

 
### 2. [Soal Double Linked List]
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
Nama Produk Harga
Originote 60.000
Somethinc 150.000
Skintific 100.000
Wardah 50.000
Hanasui 30.000
Case:

Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific.
Hapus produk wardah.
Update produk Hanasui menjadi Cleora dengan harga 55.000
Tampilkan menu seperti dibawah ini
Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit

Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :
Nama Produk Harga
Originote 60.000
Somethinc 150.000
Azarine 65.000
Skintific 100.000
Cleora 55.000


```C++
#include<iostream>
#include<iomanip>

using namespace std;

struct node{
    string barang_135;
    int harga_135;
    node *prev;
    node *next;
};
    node *head;
    node *tail;

//prosedur inisiaslisasi 
void Inisialisasi_135(){
    head = nullptr;
    tail = nullptr;
}

//prosedur tambah node
void TambahNode_135(string produk_135, int harga_135, int posisi_135){
    if(posisi_135 < 1 ){
        cout << "Node yang ingin ditambah diluar jangkauan" << endl;
    } else if(posisi_135 == 1){
        node *baru = new node;
        baru->barang_135 = produk_135;
        baru->harga_135 = harga_135;
        baru->next = head;
        baru->prev = nullptr;
        if(head != nullptr){
            head->prev = baru;
        } else {
            tail = baru;
        }
        head = baru;
    } else {
        node *current = head;
        node *baru = new node;
        baru->barang_135 = produk_135;
        baru->harga_135 = harga_135;
        baru->next = nullptr;
        baru->prev = nullptr;
        int hitung_135 = 1;
        while(hitung_135 < posisi_135 - 1){
            hitung_135++;
            current = current->next;
        }
        baru->next = current->next;
        baru->prev = current;
        if(current->next != nullptr){
            current->next->prev = baru;
        } else {
            tail = baru;
        }
        current->next = baru;
    }
}

//prosedur hapus node
void HapusNode_135(int posisi_135){
    if(posisi_135 < 1){
        cout << "Posisi node yang ingin dihapus diluar jangkauan" << endl;
    } else if(posisi_135 == 1){
        node *current = head;  // Simpan node pertama
        head = head->next;     // Geser head ke node berikutnya
        if(head != nullptr) {
            head->prev = nullptr;  // Tetapkan nullptr ke prev dari node baru pertama
        }
        delete current;  // Hapus node pertama
    } else {
        node *current = head;
        int hitung_135 = 1;
        while(hitung_135 < posisi_135){
            hitung_135++;
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
}

//fungsi update data
bool UpdateData_135(string ProdukLama_135, string ProdukBaru_135, int HargaBaru_135){
    node *current = head;
    while (current != nullptr){
        if(current->barang_135 == ProdukLama_135){
            current->barang_135 = ProdukBaru_135;
            current->harga_135 = HargaBaru_135;
            return true;
        }
        current = current->next;
    }
    return false;
}

//prosedur hapus semua data
void HapusSemua_135(){
    node *current = head;
    while(current != nullptr){
        node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

//prosedur tampilkan data
void TampilData_135(){
    node *current = head;
    if(head != nullptr){
        cout << left << setw(20) << "- Nama Produk -" << right << setw(5) << "- Harga -" << endl; 
        while(current != nullptr){
            cout << left << setw(20) << current->barang_135 << right << setw(7) << current->harga_135 << endl; 
            current = current->next;
        }
    }
    cout << endl;
}

int main(){
    int pilih_135, HargaBaru_135, PosisiProduk_135;
    string ProdukBaru_135, ProdukLama_135;
    char yakin_135;
    Inisialisasi_135();
    cout << "--- DAFTAR PRODUK SKINCARE ---" << endl;
    TambahNode_135("Hanasui", 30000, 1 );
    TambahNode_135("Wardah", 50000, 1);
    TambahNode_135("Skintific", 100000, 1);
    TambahNode_135("Somethinc", 150000, 1);
    TambahNode_135("Originote", 60000, 1);
    TampilData_135();

    MenuUtama:
    cout << "--- TOKO SKINCARE AMELIA PURWOKERTO  ---" << endl;
    cout << "1. Tambah data" << endl;
    cout << "2. Hapus data" << endl;
    cout << "3. Update data" << endl;
    cout << "4. Tambah data urutan tertentu" << endl;
    cout << "5. Hapus data urutan tertentu" << endl;
    cout << "6. Hapus seluruh data" << endl;
    cout << "7. Tampilkan data" << endl;
    cout << "8. exit" << endl;
    cout << "Pilihan anda = "; cin >> pilih_135;
    cout << endl;

    switch(pilih_135){
        case 1 :
            cout << "- Tambah Data Produk -" << endl;
            cout << "Masukkan nama produk yang ingin ditambahkan = "; 
            cin >> ProdukBaru_135;
            cout << "Masukkan harga produk = "; 
            cin >> HargaBaru_135;
            TambahNode_135(ProdukBaru_135, HargaBaru_135, 1);
            cout << "Produk telah ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2 :
            cout << "- Hapus Data Produk Pertama - " << endl;
            HapusNode_135(1);
            cout << "Data produk ke-1 telah dihapus" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 3 :
            cout << "- Update Data Produk -" << endl;
            cout << "Masukkan produk lama yang ingin diganti = ";
            cin >> ProdukLama_135;
            cout << "Masukkan nama produk baru = "; cin >> ProdukBaru_135;
            cout << "Masukkan harga produk baru = "; cin >> HargaBaru_135;
            UpdateData_135(ProdukLama_135, ProdukBaru_135, HargaBaru_135);
            cout << "Produk telah diupdate" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 4 :
            cout << "- Tambah Data Urutan Tertentu -" << endl;
            cout << "Masukkan nama produk yang ingin ditambahkan = "; cin >> ProdukBaru_135;
            cout << "Masukkan harga produk baru = "; cin >> HargaBaru_135;
            cout << "Masukkan posisi produk dalam database = "; cin >> PosisiProduk_135;
            TambahNode_135(ProdukBaru_135, HargaBaru_135, PosisiProduk_135);
            cout << "Produk telah ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 5 :
            cout << "- Hapus Data Urutan Tertentu -" << endl;
            cout << "Masukkan urutan produk yang ingin dihapus = "; cin >> PosisiProduk_135;
            HapusNode_135(PosisiProduk_135);
            cout << "Data produk urutan ke-" << PosisiProduk_135 << " telah dihapus" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 6 :
            cout << "- Hapus Seluruh Data -" << endl;
            cout << "Apakah anda yakin ingin menghapus semua produk? [y/n] = "; cin >> yakin_135;
            if(yakin_135 == 'y' || yakin_135 == 'Y'){
                HapusSemua_135();
                cout << "Semua data produk telah dihapus" << endl;
            } else if(yakin_135 == 'n' || yakin_135 == 'N'){
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 7 :
            cout << "- Tampilkan Data -" << endl;
            TampilData_135();
            cout << endl;
            goto MenuUtama;
            break;
        case 8 :
            cout << "Anda keluar dari program" << endl;
            return 0;
        default :
            cout << "Pilihan yang anda masukkan tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }    
}
```
#### Output:
![Alt text](<Screenshoot Output 2.1.png>)![Alt text](<Screenshoot Output 2.2.png>)![Alt text](<Screenshoot Output2.3.png>)

Program tersebut merupakan sebuah implementasi dari struktur data double linked dalam bahasa C++. Struktur data ini digunakan untuk menyimpan informasi tentang produk skincare, seperti nama produk dan harganya. Program ini menyediakan berbagai fungsi dasar untuk operasi-operasi pada linked list, termasuk penambahan data, penghapusan data, pembaruan data, dan penampilan data. 

## Kesimpulan
1. Linked List adalah sejumlah node yang berhubungan secara linier 
dengan bantuan pointer. 
2. Suatu senarai berkait(linked list) adalah simpul(node) yang dikaitkan 
dengan simpul yang lain dalam suatu urutan tertentu. 
3. Simpul harus mempunyai satu atau lebih elemen struktur atau class 
yang berisi data. 
4. Operasi-operasi linked list dapat diklasifikasikan sebagai 
berikut,insert,IsEmpty,FindFirst,FindNext,Retrieve,Update,D 
elete Now,Delete Head,dan Clear. 
5. Linked List dibedakan menjadi dua yaitu Single Linked List,dan 
double Linked List. 
6. Single linked list adalah apabila satu pointer menghubungkan satu 
node. Dimana single linked list terdapat dua jenis yaitu circular dan non 
circular. 
7. Double linked list adalah elemen-elemen yang dihubungkan dengan dua 
pointer dalam satu elemen dan list dapat melintas baik didepan ataupun 
dibelakang. Sama halnya Single linked list,double linked list juga 
terdapat dua jenis yaitu circular dan non circular. 

## Referensi
[1]. Ankit Kochar. 2023. Singly Linked List Program in C.  
[2]. Aria Sakti Nugraha. 2019. Artikel Double Linked List Circulate (DLLC). Universitas Mitra Indonesia : Bandar Lampung 