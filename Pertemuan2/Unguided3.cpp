#include <iostream>
using namespace std;

int main() {
    int x_135, y_135, z_135;

    // Meminta pengguna untuk memasukkan ukuran array tiga dimensi
    cout << "Masukkan ukuran array tiga dimensi:" << endl;
    cout << "Jumlah elemen x: ";
    cin >> x_135;
    cout << "Jumlah elemen y: ";
    cin >> y_135;
    cout << "Jumlah elemen z: ";
    cin >> z_135;

    // Deklarasi array tiga dimensi dengan ukuran yang dimasukkan pengguna
    int array3D_135[x_135][y_135][z_135];

    // Mengisi array dengan nilai yang dimasukkan pengguna
    cout << "Masukkan elemen-elemen array:" << endl;
    for (int i = 0; i < x_135; ++i) {
        for (int j = 0; j < y_135; ++j) {
            for (int k = 0; k < z_135; ++k) {
                cout << "Elemen [" << i << "][" << j << "][" << k << "]: ";
                cin >> array3D_135[i][j][k];
            }
        }
    }

    // Menampilkan isi array tiga dimensi
    cout << "Array tiga dimensi yang dimasukkan:" << endl;
    for (int i = 0; i < x_135; ++i) {
        for (int j = 0; j < y_135; ++j) {
            for (int k = 0; k < z_135; ++k) {
                cout << array3D_135[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
