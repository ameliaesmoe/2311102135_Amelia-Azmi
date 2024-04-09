# <h1 align="center">Laporan Praktikum Modul 5 Hash Table</h1>
<p align="center">Amelia Azmi_2311102135</p>

## Dasar Teori

1. Pengertian Hash table 

Struktur data Hash Table adalah struktur data yang digunakan untuk menyimpan dan mengelola data dengan cepat dan efisien. Ini beroperasi dengan prinsip kunci-nilai, di mana setiap elemen data memiliki kunci yang unik yang digunakan untuk mengakses atau memanipulasinya. 

Hash Table (Tabel Hash) adalah struktur data yang mengorganisir data ke dalam pasangan kunci-nilai. Ini menggunakan fungsi hash untuk mengonversi kunci menjadi indeks dalam array.

2. Struktur dan Fungsi pada Hash Table 
Hash table menggunakan struktur data array asosiatif yang mengasosiasikan record dengan sebuah field kunci unik berupa bilangan (hash) yang merupakan representasi dari record tersebut. Misalnya, terdapat data berupa string yang hendak disimpan dalam sebuah hash table. String tersebut direpresentasikan dalam sebuah field kunci k. Cara untuk mendapatkan field kunci ini sangatlah beragam, namun hasil akhirnya adalah sebuah bilangan hash yang digunakan untuk menentukan lokasi record.

Jenis fungsi hash yang dapat digunakan dalam struktur data tabel hash, antara lain:

1. Fungsi hash modulo, Fungsi ini menghasilkan indeks dengan menggunakan operasi modulo terhadap nilai hash dari kunci data dengan ukuran tabel hash.
2. Fungsi hash perkalian, Fungsi ini menghasilkan indeks dengan melakukan operasi perkalian antara nilai hash dari kunci data dengan sebuah konstanta dan kemudian mengambil sebagian bit dari hasil perkalian tersebut sebagai indeks.
3. Fungsi hash berbasis kunci, Fungsi ini menghasilkan nilai hash dengan melakukan operasi pada setiap karakter kunci data dan menggabungkan hasilnya.
4. Fungsi hash berdasarkan nilai acak, Fungsi ini menghasilkan nilai hash dengan menggunakan nilai acak sebagai input dan kemudian melakukan beberapa operasi matematika dan logika pada nilai tersebut.

Operasi Pada Hash Tabel :
1. Pencarian (Search): Digunakan untuk mencari elemen/data dalam Hash Table berdasarkan kunci atau indeksnya. Pencarian dilakukan dengan menggunakan fungsi hash untuk menghasilkan indeks elemen yang dicari.
2. Penyusunan (Insertion): Operasi ini digunakan untuk menyisipkan elemen/data baru ke dalam Hash Table. Elemen baru akan ditempatkan pada indeks yang dihasilkan oleh fungsi hash.
3. Penghapusan (Deletion): Digunakan untuk menghapus elemen/data dari Hash Table berdasarkan kunci atau indeksnya. Elemen yang dihapus akan dihapus dari indeks yang dihasilkan oleh fungsi hash.
4. Update: Operasi ini digunakan untuk mengubah nilai elemen/data yang sudah ada dalam Hash Table. Nilai elemen dapat diubah berdasarkan kunci atau indeksnya.
5. Collision Handling: Collision terjadi ketika dua atau lebih elemen memiliki indeks yang sama setelah melalui fungsi hash. Operasi ini digunakan untuk mengatasi tabrakan dan memastikan bahwa elemen-elemen dengan indeks yang sama dapat disimpan dan diakses dengan benar.
6. Resize: Operasi ini digunakan untuk mengubah ukuran Hash Table jika jumlah elemen/data yang disimpan melebihi kapasitas yang ditentukan. Resize dilakukan untuk menjaga efisiensi dan kinerja Hash Table.
7. Iterasi: Operasi yang digunakan untuk mengakses dan memproses semua elemen/data yang ada dalam Tabel Hash secara berurutan.

3. Kelebihan dan kekurangan dalam menggunakan Hash Table

~ Kelebihan Hash table meliputi efisiensi waktu operasi seperti insert, delete, dan search yang cepat dengan waktu rata-rata O(1). Selain itu, hash table ideal untuk data dengan frekuensi operasi yang tinggi dan menggunakan algoritma hashing untuk mempercepat pencarian data. Selain efisien dalam penggunaan memori dengan efisiensi tinggi, tabel hash juga memiliki teknik-teknik seperti hashing terbuka, rantai terpisah, dan hashing tertutup untuk mengurangi kemungkinan tabrakan dalam penyimpanan data.

![Alt text](<../Table Hash.png>)

~ Kekurangan menggunakan Hash table memiliki kekurangan seperti kemungkinan tabrakan yang memperlambat pencarian dan memakan lebih banyak memori, serta penggunaan memori yang lebih besar karena menggunakan array. Proses hashing dan pengelolaannya memakan lebih banyak prosesor, waktu, dan kompleksitas algoritma dibandingkan dengan data biasa, termasuk saat operasi penambahan, penghapusan, dan pengujian data.

## Guided 
### Guided 1 [Latihan Tabel Hash]

```C++
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value),
next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
                }
             }
             delete[] table;
        }

// Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
}
            current = current->next;
        }
        Node* node = new Node(key, value);
    node->next = table[index];
    table[index] = node;
}

// Searching
int get(int key) {
    int index = hash_func(key);
    Node* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
}
        current = current->next;
    }
return -1; }

// Deletion
void remove(int key) {
    int index = hash_func(key);
    Node* current = table[index];
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
return; }
        prev = current;
        current = current->next;
    }
}

// Traversal
void traverse() {
    for (int i = 0; i < MAX_SIZE; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            cout << current->key << ": " << current->value << endl;
            current = current->next;
            }
        }
    } 
};
int main (){
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 10);
    ht.insert(3, 10);

    //Searching
    cout << "Get key 1: "<< ht.get(1) << endl;
    cout << "Get key 4: "<< ht.get(4) << endl;
    
    // Delection
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;

}
```
Program diatas merupakan sebuah program data hash table dalam bahasa pemrograman C++. Program tersebut menggunakan konsep hash function sederhana untuk menentukan indeks di mana setiap pasangan kunci-nilai akan disimpan dalam hash table. Pertama-tama, program mendefinisikan beberapa konstanta dan library yang dibutuhkan. Konstanta MAX_SIZE digunakan untuk menentukan ukuran maksimum dari hash table, sedangkan library iostream digunakan untuk operasi input-output dalam program C++. Selanjutnya, program mendefinisikan struktur data Node yang akan digunakan dalam hash table. Setiap node dalam hash table memiliki dua atribut, yaitu key (kunci) dan value (nilai), serta sebuah pointer next yang menunjuk ke node berikutnya dalam kasus terjadinya tabrakan hash (collision). Dalam program ini, array dari pointer ke Node digunakan untuk menyimpan pasangan kunci-nilai. Konstruktor program tersebut menginisialisasi hash table dengan membuat array baru yang berukuran MAX_SIZE, kemudian destructor bertugas untuk menghapus semua node yang dialokasikan secara dinamis dalam hash table. 

Metode-metode dalam program HashTable mencakup operasi-operasi dasar pada hash table, yaitu insertion, searching, deletion, dan traversal. Metode insert() digunakan untuk memasukkan pasangan kunci-nilai baru ke dalam hash table. Jika kunci sudah ada dalam tabel, nilai yang terkait akan diperbarui. Metode get() berfungsi untuk mencari nilai yang terkait dengan kunci yang diberikan, dan mengembalikan nilai -1 jika kunci tidak ditemukan. Metode remove() menghapus pasangan kunci-nilai yang terkait dengan kunci yang diberikan dari hash table. Sedangkan metode traverse() digunakan untuk melakukan penelusuran seluruh hash table dan mencetak semua pasangan kunci-nilai yang ada. Pada fungsi main(), sebuah objek HashTable dibuat untuk menguji fungsionalitas dari hash table yang telah diimplementasikan. Beberapa operasi dasar seperti insertion, searching, dan deletion dijalankan untuk memverifikasi koreksi dari implementasi hash table. Setelah itu, dilakukan penelusuran seluruh hash table dengan menggunakan metode traverse() untuk mencetak semua pasangan kunci-nilai yang tersimpan di dalamnya. 

Dengan demikian, program ini memberikan dasar pemahaman tentang bagaimana hash table dapat diimplementasikan dalam bahasa pemrograman C++ untuk penyimpanan dan pengaksesan data dengan efisien menggunakan konsep hash function. 

### Guided 2 [ Latihan Tabel Hash Dengan Node]

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode{
    public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number){
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap{
    private:
    vector<HashNode*> table[TABLE_SIZE];
    public:
    int hashFunc(string key){
        int hash_val = 0;
        for(char c : key){
            hash_val += c;
        }
    return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number){
        int hash_val = hashFunc(name);

        for(auto node : table[hash_val]){
            if(node->name == name){
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name){
        int hash_val = hashFunc(name);

        for(auto it = table[hash_val].begin(); it != table[hash_val].end(); it++){
            if((*it)->name == name){
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name){
        int hash_val = hashFunc(name);
        for(auto node : table[hash_val]){
            if(node->name == name){
                return node->phone_number;
            }
        }
        return "";
    }

    void print(){
        for(int i = 0; i < TABLE_SIZE; i++){
            cout << i << ": ";
            for(auto pair : table[i]){
                if(pair != nullptr){
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main(){
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomor HP Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Nomor HP Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomor HP Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    employee_map.print();

    return 0;
}
```
Program di atas merupakan implementasi sederhana dari struktur data HashMap menggunakan tabel hash dengan bahasa pemrograman C++. Program ini memiliki beberapa kelas dan fungsi yang mengatur operasi-operasi dasar seperti penambahan, penghapusan, dan pencarian data dalam struktur hash. Kelas `HashNode` merepresentasikan node dalam tabel hash yang berisi nama dan nomor telepon. Kelas `HashMap` mengelola tabel hash yang terdiri dari vektor node-node hash. Fungsi hash digunakan untuk menghitung indeks dalam tabel hash berdasarkan nama. Program tersebut memiliki fungsi-fungsi seperti `insert` untuk menambahkan entri baru, `remove` untuk menghapus entri berdasarkan nama, `searchByName` untuk mencari nomor telepon berdasarkan nama, dan `print` untuk mencetak seluruh tabel hash. Di dalam fungsi `main`, penggunaan program ini ditunjukkan dengan menambahkan beberapa entri ke dalam tabel hash, mencari nomor telepon berdasarkan nama, dan menghapus salah satu entri. Hasil akhirnya dicetak untuk ditampilkan kepada pengguna. 

## Unguided 

### [1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
a. Setiap mahasiswa memiliki NIM dan nilai.
b. Program memiliki tampilan pilihan menu berisi poin C.
c. Implementasikan fungsi untuk menambahkan data baru, menghapus data,
mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).]

```C++
#include<iostream>
#include<vector> 
#include<iomanip>

using namespace std;

//Deklarasi isi tabel sebanyak 100
const int TableSize_135 = 100;

//Deklarasi class HashNode
class HashNode_135{
    public:
    string nama_135;
    string NIM_135;
    int nilai_135;

    //deklarasi konstruktor HashNode yang digunakan untuk membuat objek HashNode dengan parameter nama, nim, dan nilai
    HashNode_135(string name_135, string NIM_135, int grade_135){
        this->nama_135 = name_135;
        this->NIM_135 = NIM_135;
        this->nilai_135 = grade_135;
    }
};

//Deklarasi class HashMap
class HashMap_135{
    private:
    //array table yang berisi vektor dari pointer ke HashNode, 
    //yang digunakan sebagai wadah untuk menyimpan data secara terorganisir berdasarkan hasil hashing dari kunci (key).
    vector<HashNode_135*> table[TableSize_135];

    public:
    //menghitung nilai hash dari sebuah string key
    int hashFunc_135(string key_135){
        int hashValue_135 = 0;
        for(char c : key_135){
            hashValue_135 += c;
        }
        return hashValue_135 % TableSize_135;
    }

    //prosedur Tambah untuk menambah data baru kedalam tabel
    void Tambah_135(string name_135, string NIM_135, int grade_135){
        int hashValue_135 = hashFunc_135(name_135); //inisialisasi nilai hash

        //perulangan for-each yang memeriksa setiap node atau isi tabel
        for(auto node : table[hashValue_135]){
            if(node->nama_135 == name_135){ //jika nama dari node saat ini sama dengan inputan name, maka
                node->NIM_135 = NIM_135; //ubah nim node saat ini dengan inputan nim baru
                node->nilai_135 = grade_135; //ubah nilai saat ini dengan inputan nilai baru
                return;
            }
        }
        //jika tidak terdapat node dengan nama yang sama, maka buat node baru
        table[hashValue_135].push_back(new HashNode_135(name_135, NIM_135, grade_135));
    }

    //fungsi CekData untuk mengecek data tertentu dalam tabel apakah ada atau tidak
    bool CekData_135(string name_135){
        int hashValue_135 = hashFunc_135(name_135); //inisialisasi nilai hash

        //perulangan for-each yang memeriksa setiap node atau isi tabel
        for(auto node = table[hashValue_135].begin(); node != table[hashValue_135].end(); node++){
            if((*node)->nama_135 == name_135){  //jika nama dari node saat ini sama dengan inputan name, maka
                return true; //kembalikan true
            } 
        }
        return false; //kembalikan false jika nama dari node saat ini tidak sama dengan inputan name
    }

    //fungsi IsEmpty untuk mengecek apakah tabel kosong atau tidak 
    bool IsEmpty_135() {
        for (int i = 0; i < TableSize_135; i++) {
            if (!table[i].empty()) {
                return false; // Jika ditemukan tabel tidak kosong, kembalikan false
            }
        }
        return true; // Jika tabel kosong, kembalikan true
    }

    //prosedur Hapus untuk menghapus data tertentu yang ada didalam tabel
    void Hapus_135(string name_135){
        int hashValue_135 = hashFunc_135(name_135); //inisialisasi nilai hash

        //perulangan for-each yang memeriksa setiap node atau isi tabel
        for(auto node = table[hashValue_135].begin(); node != table[hashValue_135].end(); node++){
            if((*node)->nama_135 == name_135){ //jika nama dari node saat ini sama dengan inputan name, maka
                table[hashValue_135].erase(node); //hapus node saat ini
                return;
            } else { //jika nama dari node saat ini tidak sama dengan inputan name, maka tampilkan output
                cout << "Data mahasiswa " << name_135 << " tidak ditemukan" << endl;
            }
        }
    }

    //prosedur SearchByNIM untuk mencari data tertentu berdasarkan NIM
    void SearchByNIM_135(string NIM_135){
        bool ketemu = false; //deklarasi variable bool ketemu sebagai false
        cout << "-------------- HASIL PENCARIAN --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "---------------------------------------------" << endl;
        for(int i=0; i < TableSize_135; i++){
            //perulangan for-each yang memeriksa setiap node atau isi tabel
            for(auto node : table[i]){
                if(node->NIM_135 == NIM_135){ //jika nim dari node saat ini sama dengan inputan NIM, maka tampilkan data
                    cout << "|" << left << setw(14) << node->nama_135 << "|" << left << setw(14) << node->NIM_135 << "|" << left << setw(13) << node->nilai_135 << "|" << endl;
                    ketemu = true; //ubah bool ketemu menjadi true
                }
            }
        }
        if(!ketemu){ //jika nim dari node saat ini tidak sama dengan inputan NIM, maka tampilkan output
            cout << "Data mahasiswa dengan NIM " << NIM_135 << " tidak ditemukan" << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    //prosedur SearchByGrade untuk mencari data tertentu berdasarkan rentang nilai
    void SearchByGrade_135(int min_135, int max_135){
        bool ketemu = false; //deklarasi variable bool ketemu sebagai false
        cout << "-------------- HASIL PENCARIAN --------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "---------------------------------------------" << endl;
        for (int i=0; i < TableSize_135; i++){
            //perulangan for-each yang memeriksa setiap node atau isi tabel
            for(auto node : table[i]){
                if(node->nilai_135 >= min_135 && node->nilai_135 <= max_135){ //jika nilai dari node saat ini lebih dari sama dengan inputan min dan kurang dari sama degan max, maka tampilkan data  
                    cout << "|" << left << setw(14) << node->nama_135 << "|" << left << setw(14) << node->NIM_135 << "|" << left << setw(13) << node->nilai_135 << "|" << endl;
                    ketemu = true; //ubah bool ketemu menjadi true
                }
            }
        }
        if(!ketemu){ //jika nilai dari node saat ini tidak lebih dari sama dengan inputan min dan tidak kurang dari sama degan max, maka tampilkan output
            cout << "Data mahasiswa dengan rentang nilai " << min_135 << " - " << max_135 << " tidak ditemukan" << endl;
        }
        cout << "---------------------------------------------" << endl;
    }

    //prosedur TampilData untuk menampilkan tabel
    void TampilData_135(){
        for(int i=0; i < TableSize_135; i++){
            //perulangan for-each yang memeriksa setiap node atau isi tabel
            for(auto node : table[i]){ //tampilkan data setiap node 
            cout << "|" << left << setw(14) << node->nama_135 << "|" << left << setw(14) << node->NIM_135 << "|" << left << setw(13) << node->nilai_135 << "|" << endl;
            }
        }
        cout << "---------------------------------------------" << endl;
    }
};

int main(){
    //menggunakan class
    HashMap_135 StudentMap;
    //deklarasi variablel yang diperlukan
    int choose_135, grade_135, GradeMin_135, GradeMax_135;
    string name_135, NIM_135;
    char yakin_135;
    
    cout << "|===========================================|" << endl;
    cout << "|            Nama : Amelia Azmi             |" << endl;
    cout << "|            Nim  : 2311102135              |" << endl;
    cout << "|===========================================|\n"<< endl;
     
    //tag Menu Utama
    MenuUtama:
    cout << "|===========================================|" << endl;
    cout << "|          DATA MAHASISWA ◝(ᵔᵕᵔ)◜           |" << endl;
    cout << "|===========================================|" << endl;
    cout << "| 1. Tambah Data                            |" << endl;
    cout << "| 2. Hapus Data                             |" << endl;
    cout << "| 3. Cari Data Berdasarkan NIM              |" << endl;
    cout << "| 4. Cari Data Berdasarkan Nilai            |" << endl;
    cout << "| 5. Tampilkan Data                         |" << endl;
    cout << "| 6. Keluar                                 |" << endl;
    cout << "|===========================================|" << endl;
    cout << "Masukkan pilihan anda = ";
    cin >> choose_135;
    cout << endl;

    switch(choose_135){ //percabangan switchcase berdasarkan inputan variabel choose
        case 1: //jika memilih 1, maka tambah data
            cout << "---------------- TAMBAH DATA ----------------" << endl;
            cout << "Masukkan nama mahasiswa = "; cin >> name_135;
            cout << "Masukkan NIM = "; cin >> NIM_135;
            cout << "Masukkan nilai mahasiswa = "; cin >> grade_135;
            StudentMap.Tambah_135(name_135, NIM_135, grade_135); //pemanggilan metode Tambah pada objek StudentMap dari kelas HashMap
            cout << "Data mahasiswa " << name_135 << " berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 2: //jika memilih 2, maka hapus data
            cout << "----------------- HAPUS DATA ----------------" << endl;
            if(StudentMap.IsEmpty_135() == false){ //jika metode IsEmpty pada objek StudentMap dari kelas HashMap bernilai false, maka lanjutkan
                cout << "Masukkan nama mahasiswa yang ingin dihapus = "; cin >> name_135;
                StudentMap.CekData_135(name_135); //pemanggilan metode CekData pada objek StudentMap dari kelas HashMap
                if(StudentMap.CekData_135(name_135) == true){ //jika metode CekData bernilai true, maka lanjutkan
                    cout << "Apakah anda yakin unuk menghapus data mahasiswa " << name_135 << "? [y/n] = "; cin >> yakin_135;
                    if(yakin_135 == 'y' || yakin_135 == 'Y'){
                        StudentMap.Hapus_135(name_135); //pemanggilan metode Hapus pada objek StudentMap dari kelas HashMap
                        cout << "Data mahasiswa " << name_135 << " berhasil dihapus" << endl;
                    } else if(yakin_135 == 'n' || yakin_135 == 'N'){
                        cout << "Aksi dibatalkan" << endl;
                    }
                } else { //jika data name tidak ditemukan pada tabel, maka tampilkan output
                    cout << "Data mahasiswa " << name_135 << " tidak ditemukan" << endl;
                }
            } else { //jika metode IsEmpty bernilai true, maka tabel masih kosong
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 3: //jika memilih 3, maka cari data berdasarkan NIM
            cout << "--------- CARI DATA BERDASARKAN NIM ---------" << endl;
            if(StudentMap.IsEmpty_135() == false){ //jika metode IsEmpty pada objek StudentMap dari kelas HashMap bernilai false, maka lanjutkan
                cout << "Masukkan NIM = "; cin >> NIM_135;
                cout << endl;
                StudentMap.SearchByNIM_135(NIM_135); //pemanggilan metode SearchByNIM pada objek StudentMap dari kelas HashMap
            } else { //jika metode IsEmpty bernilai true, maka tabel masih kosong
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 4: //jika memilih 4, maka cari data berdasarkan nilai
            cout << "-------- CARI DATA BERDASARKAN NILAI --------" << endl;
            if(StudentMap.IsEmpty_135() == false){ //jika metode IsEmpty pada objek StudentMap dari kelas HashMap bernilai false, maka lanjutkan
                cout << "Masukkan rentang nilai minimum = "; cin >> GradeMin_135;
                cout << "Masukkan rentang nilai maksimum = "; cin >> GradeMax_135;
                cout << endl;
                StudentMap.SearchByGrade_135(GradeMin_135,GradeMax_135); //pemanggilan metode SearchByGrade pada objek StudentMap dari kelas HashMap
            } else { //jika metode IsEmpty bernilai true, maka tabel masih kosong
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 5: //jika memilih 5, maka tampilkan data
            cout << "---------------- TAMPIL DATA ----------------" << endl;
            if(StudentMap.IsEmpty_135() == false){ //jika metode IsEmpty pada objek StudentMap dari kelas HashMap bernilai false, maka lanjutkan
                cout << "---------------------------------------------" << endl;
                cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
                cout << "---------------------------------------------" << endl;
                StudentMap.TampilData_135(); //pemanggilan metode TampilData pada objek StudentMap dari kelas HashMap
            } else { //jika metode IsEmpty bernilai true, maka tabel masih kosong
                cout << "Tabel masih kosong!" << endl;
            }
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
        case 6: //jika memilih 6, maka keluar dari program
            cout << "Anda keluar dari program" << endl;
            return 0;
        default: //opsi jika inputan pilihan tidak tersedia
            cout << "Pilihan anda tidak tersedia" << endl;
            cout << endl;
            goto MenuUtama; //kembali ke Menu Utama
            break;
    }
```
#### Output:

Menambahkan Data Mahasiswa

![Alt text](<../Screenshoot 1.1.png>)

![Alt text](<../Screenshoot 1.2.png>)

![Alt text](<../Screenshoot 1.3.png>)

![Alt text](<../Screenshoot 1.4.png>)

Mencari Data NIM Mahaiswa

![Alt text](<../Screenshoot mencari nim.png>)

Mencari Data Rentang Nilai Mahasiswa

![Alt text](<../Screenshoot rentan nilai.png>)

Menghapus Data Mahasiswa

![Alt text](<../Screenshoot hapus data.png>)


Program tersebut merupakan sebuah aplikasi sederhana untuk mengelola data mahasiswa menggunakan struktur data HashMap dalam bahasa pemrograman C++. 

Penjelasan program di atas sebagai berikut :

1. HashNode : Kelas ini merepresentasikan node individu dalam tabel hash. Setiap node memiliki atribut nama, NIM, dan nilai.
2. HashMap : Kelas ini mengelola tabel hash dan menyediakan operasi-operasi seperti penambahan data, pencarian data berdasarkan NIM atau nilai, penghapusan data, dan tampilan data.
3. Fungsi Hashing : Program menggunakan fungsi hash untuk mengonversi nama menjadi indeks dalam tabel hash. Fungsi hash ini menggunakan jumlah nilai ASCII dari karakter-karakter nama sebagai basis untuk menghasilkan nilai hash.
4. Operasi Utama:
   - Tambah Data : Pengguna dapat menambahkan data mahasiswa ke dalam tabel hash.
   - Hapus Data : Pengguna dapat menghapus data mahasiswa berdasarkan nama.
   - Cari Data Berdasarkan NIM : Pengguna dapat mencari data mahasiswa berdasarkan NIM.
   - Cari Data Berdasarkan Nilai : Pengguna dapat mencari data mahasiswa berdasarkan rentang nilai.
   - Tampilkan Data : Pengguna dapat melihat seluruh data mahasiswa yang tersimpan dalam tabel hash.
   - Keluar : Pengguna dapat keluar dari program.

Program tersebut menyediakan menu utama yang interaktif untuk memudahkan pengguna dalam mengelola data mahasiswa. Setiap operasi diimplementasikan dengan menggunakan metode yang sesuai dari kelas HashMap. Semua operasi dan tampilan disesuaikan dengan input pengguna, sehingga pengguna dapat dengan mudah berinteraksi dengan program untuk melakukan tugas-tugas yang diinginkan terkait pengelolaan data mahasiswa.

## Kesimpulan
Hash Table adalah struktur data yang mengorganisir data dalam pasangan kunci-nilai dan menggunakan fungsi hash untuk mengonversi kunci menjadi indeks dalam array. Terdapat berbagai jenis fungsi hash yang dapat digunakan, termasuk fungsi modulo, fungsi perkalian, fungsi berbasis kunci, dan fungsi berdasarkan nilai acak. Operasi yang dapat dilakukan pada Hash Table meliputi pencarian, penyisipan, penghapusan, pembaruan, penanganan tabrakan, penyesuaian ukuran, dan iterasi. Kelebihan Hash Table meliputi efisiensi waktu operasi yang cepat dengan rata-rata O(1), efisiensi penggunaan memori yang tinggi, dan teknik-teknik untuk mengurangi kemungkinan tabrakan data. Kekurangan Hash Table termasuk kemungkinan tabrakan yang dapat memperlambat pencarian dan meningkatkan konsumsi memori, serta kompleksitas algoritma yang lebih tinggi dalam pengelolaan dan pemrosesan data.

## Referensi
[1]. Desra Rizki Riyandi, Elvia Budianita, Zulkarnain. 2022. Penerapan Algoritma Hash Based Untuk Analisis Pola Pemilihan Mata Kuliah Pilihan Jurusan Teknik Informatika UIN Sultan Syarif Kasim Riau. Riau.
[2] Tian Qi Zheng, Orcid, Zhibin Zhang 1DanXueqi Cheng. 2020. Tabel Hash Adaptif String untuk Database Analitik. Tiongkok. 
[3] Nugraha, Muhammad. 2021. Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform.