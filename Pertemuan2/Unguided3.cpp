#include <iostream>
#include <iomanip>

using namespace std;

// Fungsi untuk mencari nilai maksimum dari array
int cariMaksimum_135(int arr_135[], int size_135) {
    int maksimum_135 = arr_135[0];
    for (int i = 1; i < size_135; ++i) {
        if (arr_135[i] > maksimum_135) {
            maksimum_135 = arr_135[i];
        }
    }
    return maksimum_135;
}

// Fungsi untuk mencari nilai minimum dari array
int cariMinimum_135(int arr_135[], int size_135) {
    int minimum_135 = arr_135[0];
    for (int i = 1; i < size_135; ++i) {
        if (arr_135[i] < minimum_135) {
            minimum_135 = arr_135[i];
        }
    }
    return minimum_135;
}

// Fungsi untuk mencari nilai rata-rata dari array
double cariRataRata_135(int arr_135[], int size_135) {
    double total_135 = 0.0;
    for (int i = 0; i < size_135; ++i) {
        total_135 += arr_135[i];
    }
    return total_135 / size_135;
}

int main() {
    int size_135;
    cout << "Masukkan panjang array: ";
    cin >> size_135;

    int arr_135[size_135];
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < size_135; ++i) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr_135[i];
    }

    int pilihan_135;
    do {
        cout << "\nMenu:\n";
        cout << "1. Cari nilai maksimum\n";
        cout << "2. Cari nilai minimum\n";
        cout << "3. Cari nilai rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan_135;

        switch (pilihan_135) {
            case 1:
                cout << "Nilai maksimum: " << cariMaksimum_135(arr_135, size_135) << endl;
                break;
            case 2:
                cout << "Nilai minimum: " << cariMinimum_135(arr_135, size_135) << endl;
                break;
            case 3:
                cout << fixed << setprecision(2);
                cout << "Nilai rata-rata: " << cariRataRata_135(arr_135, size_135) << endl;
                break;
            case 4:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali.\n";
                break;
        }
    } while (pilihan_135 != 4);

    return 0;
}

