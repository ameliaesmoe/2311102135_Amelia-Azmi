#include<iostream>

using namespace std;

//Deklarasi struct node
struct node{ //node berisi variabel nama_135 dan pointer next
    string nama_135;
    node *next;
};
    node *front; //deklarasi node front 
    node *back; //deklarasi node back

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
void TambahData_135(string name_135){
    node *baru = new node; //tambah node baru
    baru->nama_135 = name_135; //node baru berisi variabel name_135
    baru->next = NULL; //next dari node baru adalah NULL
    if(isEmpty_151() == true){ //jika antrian kosong, maka lanjutkan
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
    if(isEmpty_135() == true){ //jika antrian kosong, maka tampilkan "Antrian masih kosong!"
        cout << "Antrian masih kosong!" << endl;
    } else if(isEmpty_135() == false){ //jika antrian tidak kosong, maka lanjutkan
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
int HitungAntrian_151(){
    node *hitung; //inisialisasi node hitung
    hitung = front; //node hitung sebagai front
    int jumlah_135 = 0; //inisialisasi variabel jumlah_135
    while(hitung != NULL){ //jika node hitung bukan NULL, maka ulangi
        hitung = hitung->next; //node hitung berlanjut ke node selanjutnya
        jumlah_135++; //variabel jumlah_135 bertambah nilainya
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
    } else if(isEmpty_151() == false){ //jika antrian tidak kosong, maka lanjutkan
        cout << "======== Antrian saat ini ========" << endl;  
        int NomorAntrian_135 = 1; //inisialisasi variabel NomorAntrian_135 dengan nilai 1
        while(bantu != NULL){ //jika node bantu bukan NULL, maka ulangi
            cout << NomorAntrian_135 << ". " << bantu->nama_135 << endl; //tampilkan antrian dengan nomor urutnya
            bantu = bantu->next; //node bantu berlanjut ke node selanjutnya
            NomorAntrian_135++; //nomor antrian bertambah
        }
    }
    cout << endl;
}

int main(){
    //Menambah 3 data nama kedalam antrian
    TambahData_151("Amelia");
    TambahData_151("Indi");
    TambahData_151("Ayu");

    //Menampilkan data yang sudah ditambahkan
    LihatAntrian_135();

    //Mengurangi data
    KurangiAntrian_135();

    //menampilkan data setelah dikurangi
    LihatAntrian_135();

    //Menghapus seluruh antrian
    HapusAntrian_135();

    //menampilkan data setelah dihapus
    LihatAntrian_135();
    
    return 0;
}