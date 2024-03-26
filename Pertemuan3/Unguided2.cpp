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