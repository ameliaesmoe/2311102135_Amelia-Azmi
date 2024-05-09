//Edited by amelia azmi_2311102135
#include<iostream>

using namespace std;

const int Max_135 = 100;
string ArrayKalimat_135 [Max_135 ]; //deklarasi array bernama ArrayKalimat sebagai stack
int Top_135  = 0;

//fungsi isEmpty untuk mengecek apakah stack kosong atau tidak
bool isEmpty(){
    return (Top_135  == 0);
}

//prosedur PushKata_135  untuk menambahkan kata pada stack
void PushKata_135 (string InputKata_135 ){
    if(!InputKata_135 .empty()){  // Periksa apakah input kata tidak kosong
        ArrayKalimat_135 [Top_135 ] = InputKata_135 ;
        Top_135 ++;
    }
}

//prosedur PopKata_135  untuk mengeluarkan elemen pertama pada stack
void PopKata_135 (){
    if(Top_135  > 0){
        ArrayKalimat_135 [Top_135  - 1] = "";
        Top_135 --;
    }
}

//fungsi HitungKata_135  untuk menghitung jumlah kata yang diinputkan user
int HitungKata_135 (const char* InputKata_135 ){
    int JumlahKata_135  = 0;
    int i = 0;
    while (InputKata_135 [i] != '\0') {
        // Jika karakter saat ini bukan spasi dan karakter selanjutnya adalah spasi atau null terminator,
        // itu menandakan bahwa kata baru dimulai.
        if (InputKata_135 [i] != ' ' && (InputKata_135 [i + 1] == ' ' || InputKata_135 [i + 1] == '\0')) {
            JumlahKata_135 ++;
        }
        i++;
    }
    return JumlahKata_135 ;
}

//Fungsi BalikKatav untuk membalikkan urutan huruf pada kata di kalimat yang diinputkan user
string BalikKata_135 (const char* InputKata_135 ){
    string KalimatTerbalik_135 ; //variabel untuk menampung kata yang sudah terbalik secara keseluruhan
    string KataBelumTerbalik_135 ;  // variabel untuk menampung kata sementara yang belum dibalik
    string KataSudahTerbalik_135 ; //variabel untuk menampung kata sementara yang sudah dibalik
    int i = 0;
    //perulangan while
    while (InputKata_135 [i] != '\0') { //jika setiap elemen pada InputKata_135  bukan spasi, maka lanjutkan
        char Huruf_135  = InputKata_135 [i]; //masukkan setiap elemen pada InputKata_135  pada variabel Huruf_135 
        //percabangan if-else
        if (Huruf_135  != ' ') { //jika karakter yang sedang diproses bukan spasi, maka lanjutkan
            KataBelumTerbalik_135  += Huruf_135 ; //tambahkan karakter bukan spasi ke dalam KataBelumTerbalik_135 
        } else { //jika karakter yang sedang diproses adalah spasi, maka lanjutkan
            int PanjangKata_135 = KataBelumTerbalik_135 .length(); //Hitung panjang kata pada KataBelumTerbalik_135 
            for (int j = PanjangKata_135  - 1; j >= 0; --j) {
                KataSudahTerbalik_135  += KataBelumTerbalik_135 [j]; //balikkan kata pada KataBelumTerbalik_135  dan masukkan kedalam KataSudahTerbalik_135 
            }
            //Tambahkan kata yang sudah terbalik ke dalam stack menggunakan PushKata_135 
            if (!KataSudahTerbalik_135 .empty()) {
                PushKata_135 (KataSudahTerbalik_135 );
            }
            KataBelumTerbalik_135 = "";  // Kosongkan KataBelumTerbalik_135  untuk menampung kata baru
            KataSudahTerbalik_135  = "";  // Kosongkan KataBelumTerbalik_135  untuk menampung kata baru
        }
        ++i;
    }
    // Balik kata terakhir jika setelah kata tersebut tidak diikuti oleh spasi
    if(!KataBelumTerbalik_135 .empty()) {
        int PanjangKata_135  = KataBelumTerbalik_135 .length(); //Hitung panjang kata 
        for (int j = PanjangKata_135  - 1; j >= 0; --j) {
            KataSudahTerbalik_135 += KataBelumTerbalik_135 [j]; //balikkan kata dan masukkan kedalam KataSudahTerbalik_135 
        }
        if (!KataSudahTerbalik_135.empty()) { //Tambahkan kata yang sudah terbalik ke dalam stack menggunakan PushKata_135 
            PushKata_135(KataSudahTerbalik_135);
        }
    }
    
    //keluarkan kata yang sudah dibalik dari stack
    while(!isEmpty()){
        KalimatTerbalik_135 += ArrayKalimat_135[Top_135 - 1]; //masukkan kata yang sudah dibalik kedalam KalimatTerbalik_135 
        PopKata_135(); //keluarkan KalimatTerbalik_151 menggunakan PopKata_135 
        if (!isEmpty()) { // Jika stack belum kosong, tambahkan spasi di antara kata yang sudah dibalik
            KalimatTerbalik_135 += " ";
        }
    }
    return KalimatTerbalik_135; //kembalikan nilai KalimatTerbalik_135 
}

int main(){
    char InputKata_135[Max_135];
    string KalimatTerbalik_135, hasil_135;
    cout << "================ PEMBALIK KALIMAT ================" << endl;
    cout << "Anda dapat memasukkan minimal 2 kata untuk dibalik" << endl;
    MasukkanKalimat:
    cout << "Masukkan kalimat (minimal 2 kata) = ";
    cin.getline(InputKata_135 , Max_135);  //Kalimat yang diinputkan user dimasukkan kedalam array InputKata_135 

    //Pengecekan apakah kata yang diinputkan user lebih dari 2 atau tidak
    if(HitungKata_135(InputKata_135) < 2){ //Jika kata yang dimasukkan user kurang dari 2 maka user harus memasukkan kalimat lagi 
        cout << "Jumlah kata = " << HitungKata_135(InputKata_135) << endl;
        cout << "Kata yang telah anda masukkan kurang dari 2, silahkan masukkan ulang kalimat anda" << endl;
        cout << endl;
        goto MasukkanKalimat;
    } else { //jika kata yang diinputkan user lebih dari sama dengan 2 maka tampilkan urutan huruf setiap kata pada kalimat secara terbalik
        cout << "Jumlah kata = " << HitungKata_135(InputKata_135) << endl;
        hasil_135 = BalikKata_135(InputKata_135);
        cout << "Kalimat yang dibalik menjadi " << hasil_135 << endl;
    }
    
    return 0;
}