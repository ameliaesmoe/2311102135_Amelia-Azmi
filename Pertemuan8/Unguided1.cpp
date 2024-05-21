#include <iostream>
#include <string>

using namespace std;
// Fungsi untuk mengurutkan karakter dalam string menggunakan Bubble Sort
void bubble_sort(string &kalimat_135)
{
    int n = kalimat_135.size();
    // Perulangan untuk setiap elemen dalam string
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (kalimat_135[j] > kalimat_135[j + 1])
            {
                swap(kalimat_135[j], kalimat_135[j + 1]);
            }
        }
    }
}
// Fungsi untuk mencari karakter dalam string yang sudah diurutkan
void binary_search(const string &kalimat_135, char cari_135)
{
    bool ditemukan = false;
    cout << "Kata setelah diurutkan: " << kalimat_135 << endl;
    cout << "Huruf '" << cari_135 << "' ditemukan pada indeks ke: ";
    // Perulangan untuk mencari huruf dalam string
    for (size_t i = 0; i < kalimat_135.size(); ++i)
    {
        if (kalimat_135[i] == cari_135)
        {
            ditemukan = true;
            cout << i << " ";
        }
    }
    cout << endl;
    // percabangan jika tidak menemukan huruf pada kata
    if (!ditemukan)
    {
        cout << "Huruf '" << cari_135 << "' tidak ditemukan dalam kalimat." << endl;
    }
}

int main()
{
    string kalimat_135;
    char cari_135;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat_135);

    // Urutkan kalimat menggunakan bubble sort
    bubble_sort(kalimat_135);
    cout << "Kalimat setelah diurutkan: " << kalimat_135 << endl;

    cout << "Masukkan huruf yang ingin Anda cari: ";
    cin >> cari_135;

    // Cari huruf dalam kalimat menggunakan binary search
    binary_search(kalimat_135, cari_135);

    return 0;
}