#include <iostream>
using namespace std;

struct Student_135 {
    string nama_135;
    int umur_135;
    float nilai_135;
};

int main() {
    Student_135 Telkom_135;
    Telkom_135.nama_135 = "Amelia Azmi";
    Telkom_135.umur_135 = 19;
    Telkom_135.nilai_135 = 3.8;

    cout << "Nama mahasiswa : " << Telkom_135.nama_135 << endl;
    cout << "Umur : " << Telkom_135.umur_135 << endl;
    cout << "Nilai : " <<  Telkom_135.nilai_135 << endl;

    return 0;
}

