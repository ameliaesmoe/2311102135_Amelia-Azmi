#include <iostream>
using namespace std;

int main(){
    int arr_135[10]; // Mendeklarasikan array dengan 10 elemen
    int genap_135[5], ganjil_135[5]; // Mendeklarasikan array untuk menyimpan angka genap dan ganjil
    int genapIndex_135 = 0; // Indeks untuk array angka genap
    int ganjilIndex_135 = 0; // Indeks untuk array angka ganjil
    
    // Meminta pengguna untuk memasukkan data array
    cout << "Data Array: ";
    for (int a = 0; a < 10; a++){
        cin >> arr_135[a];
    }

    // Memisahkan angka genap dan ganjil dari array
    for (int a = 0; a < 10; a++){
        if(arr_135[a] % 2 == 0){
            genap_135[genapIndex_135] = arr_135[a]; // Menyimpan angka genap ke dalam array angka genap
            genapIndex_135++;
        } else {
            ganjil_135[ganjilIndex_135] = arr_135[a]; // Menyimpan angka ganjil ke dalam array angka ganjil
            ganjilIndex_135++;
        }
    }

    // Mencetak angka genap
    cout << "Angka Genap: ";
    for (int a = 0; a < genapIndex_135; a++){
        cout << genap_135[a] << " , ";
    }
   cout << endl;

    // Mencetak angka ganjil
    cout << "Angka Ganjil: ";
    for (int a = 0; a < ganjilIndex_135; a++){
        cout << ganjil_135[a] << " , ";
    }
    cout << endl;
    return 0;
}
