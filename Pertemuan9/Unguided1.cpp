#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk mencetak header matriks
void printHeader(const vector<string> &simpul_2311102135, int n)
{
    cout << setw(15) << " ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << simpul_2311102135[i];
    }
    cout << endl;
}

// Fungsi untuk mencetak baris matriks ketetanggaan
void printRows(const vector<string> &simpul_2311102135, const vector<vector<int>> &busur_2311102135, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << simpul_2311102135[i];
        for (int j = 0; j < n; j++)
        {
            cout << setw(15) << busur_2311102135[i][j];
        }
        cout << endl;
    }
}

// Fungsi untuk menampilkan graf berdasarkan matriks ketetanggaan
void tampilGraph(const vector<string> &simpul_2311102135, const vector<vector<int>> &busur_2311102135, int n)
{
    printHeader(simpul_2311102135, n);
    printRows(simpul_2311102135, busur_2311102135, n);
}

int main()
{
    // Mendeklarasikan variabel untuk menyimpan jumlah simpul
    int n;

    // Mencetak prompt untuk meminta input jumlah simpul
    cout << "Silakan masukkan jumlah simpul: ";

    // Membaca input jumlah simpul dari pengguna
    cin >> n;

    // Deklarasi vektor untuk menyimpan nama simpul
    vector<string> simpul_2311102135(n);

    // Meminta input nama simpul dari pengguna
    for (int i = 0; i < n; i++)
    {
        cout << "Nama simpul " << i + 1 << " : ";
        cin >> simpul_2311102135[i];
    }

    // Deklarasi vektor dua dimensi untuk menyimpan bobot antar simpul matriks ini akan menyimpan bobot untuk setiap pasangan simpul
    vector<vector<int>> busur_2311102135(n, vector<int>(n, 0));

    // Mencetak prompt untuk meminta input bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;

    // Meminta input bobot antar simpul dari pengguna
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << simpul_2311102135[i] << "--> " << simpul_2311102135[j] << " = ";
            cin >> busur_2311102135[i][j];
        }
    }

    // Memanggil fungsi tampilGraph untuk menampilkan representasi matriks ketetanggaan dari graf yang telah diinput
    tampilGraph(simpul_2311102135, busur_2311102135, n);

    return 0;
}