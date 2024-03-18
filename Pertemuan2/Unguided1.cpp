#include <iostream>
using namespace std;

int main(){
    int arr_135[10]; // Mendeklarasikan array dengan 10 elemen
    int gnp_135[5], gnjl_135[5]; // Mendeklarasikan array untuk menyimpan angka genap dan ganjil
    int gnpIndex_135 = 0; // Indeks untuk array angka genap
    int gnjlIndex_135 = 0; // Indeks untuk array angka ganjil
    
    // Meminta pengguna untuk memasukkan data array
    cout << "Data Array: ";
    for (int a = 0; a < 10; a++){
        cin >> arr_135[a];
    }

    // Untuk memisahkan angka genap dan ganjil dari array
    for (int a = 0; a < 10; a++){
        if(arr_135[a] % 2 == 0){
            gnp_135[gnpIndex_135] = arr_135[a]; // Untuk menyimpan angka genap ke dalam array angka genap
            gnpIndex_135++;
        } else {
            gnjl_135[gnjlIndex_135] = arr_135[a]; // Untuk menyimpan angka ganjil ke dalam array angka ganjil
            gnjlIndex_135++;
        }
    }

    // Mencetak angka genap
    cout << "Angka Genap: ";
    for (int a = 0; a < gnpIndex_135; a++){
        cout << gnp_135[a] << " , ";
    }
   cout << endl;

    // Mencetak angka ganjil
    cout << "Angka Ganjil: ";
    for (int a = 0; a < gnjlIndex_135; a++){
        cout << gnjl_135[a] << " , ";
    }
    cout << endl;
    return 0;
}