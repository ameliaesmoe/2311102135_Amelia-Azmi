# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Amelia Azmi_2311102135</p>

## Dasar Teori

Array merupakan struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Semua elmen array bertipe sama dan tersusun secara sekuensial dalam memori komputer. 

1. Array Satu Dimensi  
Array satu dimensi merupakan salah satu tipe data yang paling banyak digunakan. Contohnya adalah digunakan untuk membuat daftar sejumlah orang sesuai dengan usianya, maka syarat yang harus dimasukkan dalam menentukan elemennya yaitu usia. Anda bisa memakai rumus kueri untuk menentukannya. 

2. Array Dua Dimensi  
Array dua dimensi adalah array yang penomoran index-nya menggunakan dua buah angka. Atau dengan kata lain array dua dimensi adalah array yang memiliki dua buah indeks array. Jika pada array satu dimensi hanya memiliki satu indeks saja, pada array dua dimensi ini memiliki dua indeks pada arraynya. 

3. Array Multidimensi 
Array multimensi merupakan sebuah variabel yang menyimpan sekumpulan data yang memiliki tipe sama danelemen yang akan diakses melalui banyak indeks atau subskrip. Array seperti ini biasa digunakanuntuk matik, array 2 dimensi juga termasuk kedalam array multidimensi. 

4. Array Empat Dimensi
Array empat dimensi merupakan kumpulan dari paket-paket kartu yang setiap paket mempunyai jumlah kartu yang sama, setiap kartu dengan jumlah baris yang sama, dan setiap baris mempunyai jumlah kolom yang sama.

5. Array Lima Dimensi
Array lima dimensi merupakan struktur data pemrograman atau elemen yang disimpan pada lima dimensi yang berbeda, dimana setiap elemen pada array memiliki lima indeks yang digunakan untu mengidentifikasi posisi disetiap dimensi 


## Guided 

### 1. [Program Input Array Tiga Dimensi]

```C++
#include <iostream>
using namespace std; 
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
            
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
        
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout <<endl;
}
}
```
Kode di atas Contoh implementasi input dan output array tiga dimensi untuk menginisialisasi array arr dengan ukuran 2x3x3. Kemudian Program meminta pengguna untuk memasukkan nilai pada setiap elemen melalui loop. Setelah pengguna memasukkan niklai-nilai program akan mencetak kembali nilai array ke layar.  

### 2. [Program Mencari Nilai Maksimal pada Array]
```C++
#include <iostream>
using namespace std;
int main ()
{
    int maks, a, i=1, lokasi;
    cout << "Masukkan panjang array : ";
    cin >> a;
    int array [a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-: " << (i) << ": ";
        cin >> array[i];
    }
    maks = array [0];
    for (i = 0; i < a; i++)
    {
        if (array[i] < maks)
        {
            maks =array [i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di array ke " << lokasi<<endl;
}
```
Kode di atas digunakan untuk meminta pengguna memasukkan panjang array, kemudian menginputkan angka sesuai panjang array. Kemudian program akan mencari nilai maksimum dan minimum dari array yang telah dimasukkan oleh pengguna dan mencetak nilai maksimum beserta posisinya didalam array.

## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]

```C++
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
```
#### Output:
![screenshoot unguided1.amelia]![Alt text](<screenshoot unguided1.amelia-2.png>)

Kode diatas digunakan untuk meminta pengguna memasukkan data ke dalam array dengan 10 elemen. Kemudian program akan memisahkan antra angka genap dan angka ganjil. Setelah itu program akan menyimpannya ke dalam dua array yang terpisah. Kemudian program akan menampilkan ke layar angka genap dan ganjil yang telah dipisahkan.

### 2. [Buatlah Program input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya di inputkan oleh user!]

```C++
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
```
#### Output:
![screenshoot unguided2.amelia]![Alt text](<screenshoot unguided2.amelia.png>)

Kode di atas digunakan untuk meminta pengguna memasukkan ukuran array tiga dimensi (x, y, z). Kemudian program tersebut membuat array tiga dimensi sesuai dengan ukuran yang telah dimasukkan oleh pengguna dan menampilkan isi array tersebut.  

### 3. [Buatlah program menu untuk mencri nilai maksimum, minimum dan nilai rata-rata dari suatu array dengan input yang dimasukan oleh user!]

```C++
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
```
#### Output:
![screenshoot unguided3.amelia]![Alt text](<screenshoot unguided3.amelia.png>)

Kode diatas digunakan untuk meminta pengguna memasukkan panjang array dan elem-elemennya. Kemudian program akan menampilkan menu yang meminta pengguna untuk memilih menunu tersebut. Kemudian program akan memproses pilihan dari pengguna dan menampilkan hasilnya ke layar.  

## Kesimpulan

Dalam mempelajari array kita dapat mengetahui bahwa array itu penting dalam pemrograman karena pengelolaan dan manipulasi data lebih efisien. Menggunakan array juga dapat mengoptimalkan penggunaan memori pada komputer serta bisa mengelola data dengan baik. 

## Referensi
[1]. M. Aldi Pratama. 2020. Struktur Data Array Dua Dimensi Pada Pemrograman C++. Lampung : Universitas Mitra Indonesia. 
[2]. Msyah. Apr 15, 2021. Pengertian Array Satu Dimensi.