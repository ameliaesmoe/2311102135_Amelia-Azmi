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