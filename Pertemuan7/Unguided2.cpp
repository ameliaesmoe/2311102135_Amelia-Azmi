#include<iostream>

using namespace std;

//Deklarasi struct node
struct node{ //node berisi variabel NamaMahasiswa_151, NIM_151, dan pointer next
    string NamaMhs_135;
    string Nim_135;
    node *next;
};
    node *front; //Deklarasi node front
    node *back; //Deklarasi node back

//Prosedur inisialisasi node front dan back sebagai NULL
void Inisialisasi_135(){ 
    front = NULL;
    back = NULL;
}

//Fungsi untuk mengecek apakah queue kosong atau tidak
bool isEmpty_135(){
    if (front == 0){
        return true; //jika antrian pertama tidak ada, maka antrian kosong (kembalikan true)
    } else {
        return false; //jika antrian pertama ada, maka antrian tidak kosong (kembalikan false)
    }
}

//Prosedur untuk menambahkan data pada antrian
void TambahData_135(string Nama_135, string Nim_151){
    node *baru = new node; //tambah node baru
    baru->NamaMhs_135 = Nama_135; //node baru berisi nama mahasiswa dan NIM 
    baru->Nim_135 = Nama_135; 
    baru->next = NULL; //next dari node baru adalah NULL
    if(isEmpty_135() == true){ //jika antrian kosong, maka lanjutkan
        front = back = baru; //node baru sebagai front dan back
        back->next = NULL; //node selanjutnya dari node baru adalah NULL
    } else if(isEmpty_135() == false){ //jika antrian tidak kosong, maka lanjutkan
        back->next = baru; //node baru sebagai node selanjutnya dari antrian yang sudah ada
        back = baru; //node baru sebagai back
    }
}

//Prosedur untuk mengurangi antrian (lanjut ke antrian selanjutnya)
void KurangiAntrian_135(){
    node *hapus; //inisialisasi node hapus
    if(isEmpty_135() == false){ //jika antrian tidak kosong, maka lanjutkan
        if(front->next != NULL){ //jika node selanjutnya setelah antrian pertama bukan NULL, maka lanjutkan
            hapus = front; //node hapus sebagai front
            front = front->next; //pindahkan front ke node selanjutnya setelah node pertama
            delete hapus; //hapus node pertama
        } else { //jika tidak ada node selanjutnya setelah antrian pertama, maka lanjutkan
            front = back = NULL; //front dan back adalah NULL
        }
    }
}

//Fungsi untuk menghitung jumlah antrian
int HitungAntrian_135(){
    node *hitung; //inisialisasi node hitung
    hitung = front; //node hitung sebagai front
    int jumlah_135 = 0; //inisialisasi variabel jumlah_135
    while(hitung != NULL){ //jika node hitung bukan NULL, maka ulangi
        hitung = hitung->next; //node hitung berlanjut ke node selanjutnya
        jumlah_135++; //variabel jumlah_151 bertambah nilainya
    }
    return jumlah_135; //kembalikan nilai variabel jumlah_135
}

//Prosedur untuk menghapus seluruh antrian
void HapusAntrian_135(){
    node *hapus, *bantu; //inisialisasi node hapus dan node bantu
    bantu = front; //node bantu sebagai front
    while(bantu != NULL){ ///jika node bantu bukan NULL, maka ulangi
        hapus = bantu; //node hapus sama dengan node bantu
        bantu = bantu->next; //node selanjutnya dari posisi node bantu saat ini, juga merupakan node bantu
        delete hapus; //hapus seluruh node yang merupakan node bantu
    }
    front = back = NULL; //front dan back sebagai NULL
}

//Prosedur untuk menampilkan antrian
void LihatAntrian_135(){
    node *bantu; //inisialisasi node bantu
    bantu = front; //node bantu sebagai front
    if(isEmpty_135() == true){ //jika antrian kosong, maka tampilkan "Antrian kosong!" 
        cout << "Antrian kosong!" << endl; 
    } else if(isEmpty_135() == false){ //jika antrian tidak kosong, maka lanjutkan
        cout << "============ Antrian Saat Ini ============" << endl; 
        int NomorAntrian_135 = 1; //inisialisasi variabel NomorAntrian_135 dengan nilai 1
        while(bantu != NULL){ //jika node bantu bukan NULL, maka ulangi
            cout << NomorAntrian_135 << ". " << bantu->NamaMhs_135 << " - " << bantu->Nim_135 << endl; //tampilkan antrian dengan nomor urut, nama mahasiswa - NIM
            bantu = bantu->next; //node bantu berlanjut ke node selanjutnya
            NomorAntrian_135++; //nomor antrian bertambah
        }
    }
    cout << endl;
}

int main(){
    string NamaMhs_135, Nim_135; 
    int Pilih_135; 
    char Yakin_135;
    MenuUtama:
    cout << "|================= ANTRIAN MAHASISWA ==================|" << endl; //Tampilan menu antrian mahasiswa
    cout << "|1. Tambah antrian                                     |" << endl;
    cout << "|2. Kurangi antrian                                    |" << endl;
    cout << "|3. Hitung jumlah antrian                              |" << endl;
    cout << "|4. Hapus antrian                                      |" << endl;
    cout << "|5. Lihat antrian                                      |" << endl;
    cout << "|6. Keluar                                             |" << endl;
    cout << "|======================================================|" << endl;
    cout << "Masukkan angka (1-6) = ";
    cin >> Pilih_135;
    cout << endl;
    switch(Pilih_135){ //switch case berdasarkan pilihan user
        case 1: //jika user memilih 1, maka tampilkan menu tambah antrian
            cout << "==================== Tambah Antrian ====================" << endl;
            cout << "Masukkan Nama Mahasiswa : ";
            cin >> NamaMhs_135;
            cout << "Masukkan Nim Mahasiswa : ";
            cin >> Nim_135;
            TambahData_135 (NamaMhs_135, Nim_135); //pemanggilan prosedur TambahData_135 dengan parameter nama mahasiswa dan NIM
            cout << "Data mahasiswa telah tersimpan!" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2: //jika user memilih 2, maka tampilkan menu kurangi antrian
            cout << "==================== Kurangi Antrian ====================" << endl;
            if(isEmpty_135() == true){ //Jika antrian kosong, maka tampilkan "Antrian masih kosong!"
                cout << "Antrian masih kosong!" << endl;
            } else { //jika antrian tidak kosong, maka lanjutkan
                cout << "Apakah anda ingin mengurangi antrian (menghapus antrian pertama)? [y/n] = "; //validasi keyakinan user untuk mengurangi antrian
                cin >> Yakin_135;
                if(Yakin_135 == 'y' || Yakin_135 == 'Y'){ //jika user menginputkan y atau Y, maka lanjutkan
                    KurangiAntrian_135(); //pemanggilan prosedur KurangiAntrian_135()
                    cout << "Antrian telah dikurangi" << endl;
                } else if(Yakin_135 == 'n' || Yakin_135 == 'Y'){ //jika user menginputkan n atau N, maka tampilkan "Aksi dibatalkan"
                    cout << "Aksi dibatalkan" << endl;
                }
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 3: //jika user memilih 3, maka tampilkan menu Hitung Jumlah Antrian
            cout << "==================== Hitung Jumlah Antrian ====================" << endl;
            cout << "Anrian yang tersimpan saat ini sebanyak " << HitungAntrian_135() << endl; //Pemanggilan fungsi HitungAntrian_135()
            cout << endl;
            goto MenuUtama;
            break;
        case 4: //jika user memilih 4, maka tampilkan menu hapus antrian
            cout << "==================== Hapus Antrian ====================" << endl;
            cout << "Apakah Anda yakin untuk menghapus seluruh antrian? [y/n] = "; //validasi keyakinan user untuk menghapus seluruh antrian
            cin >> Yakin_135;
            if(Yakin_135 == 'y' || Yakin_135 == 'Y'){ //jika user menginputkan y atau Y, maka lanjutkan
                HapusAntrian_135(); //pemanggilan prosedur HapusAntrian_135()
                cout << "Antrian telah dihapus" << endl;
            } else if(Yakin_135 == 'n' || Yakin_135 == 'N'){ //jika user menginputkan n atau N, maka tampilkan "Aksi dibatalkan"
                cout << "Aksi dibatalkan" << endl;
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 5: //jika user memilih 5, maka tampilkan antrian
            LihatAntrian_135(); //pemanggilan prosedur LihatAntrian_135()
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "Anda keluar dari program" << endl;
            cout << endl;
            return 0;
            break;
        default: //jika user memilih selain 1-5, maka tampilkan "Pilihan yang anda masukkan salah!"
            cout << "Pilihan yang anda masukkan salah!" << endl;
            cout << endl;
            goto MenuUtama;
            break;
    }
}