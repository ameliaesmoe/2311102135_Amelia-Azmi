# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Amelia Azmi_2311102135</p>

## Dasar Teori

Tipe data merupakan sebuah jenis data pada komputer untuk memenuhi kebutuhan dalam pemrograman komputer. Setiap variabel atau konstanta yang ada dalam kode program, harus bisa menentukan dengan pasti tipe datanya. Ketepatan pemilihan tipe data pada sebuah variabel atau konstanta   akan sangat menentukan pemakaian sumberdaya komputer (terutama memori komputer). 
1. Tipe  data  primitive
Tipe data primitive merupakan tipe data yang hanya mampu menyimpan satu nilai pada setiap satu variabel. Pada tipe data ini merupakan tipe data dasar yang sering digunakan program. Contoh data primitive seperti int, float, char, boolean
3. Tipe Data Abstrak
Tipe data abstrak merupakan sebuah data tertentu yang terlihat diluar dan menyembunyikan data lainnya dan proses detail data tersebut.
3. Tipe data koleksi 
Tipe data koleksi merupakan sebuah tipe yang digunakan untuk mrnyimpan beberapa nilai. Contoh tipe data koleksi seperti array, map, vector


## Guided 

### 1. [tipe data primitif]

```C++
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    char op;
    float num1, num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two operands: ";

    cin >> num1 >> num2;
    // Switch statement begins
    switch (op) {
    // If user enters +
        case '+':
            cout << "Result: " << num1 + num2;
            break;
    // If user enters -
        case '-':   
            cout << "Result: " << num1 - num2;
            break;
    // If user enters *
        case '*':
            cout << "Result: " << num1 * num2;
            break;
    // If user enters /
        case '/':
            if (num2 != 0) {
                cout << "Result: " << fixed << setprecision(2) << num1 / num2;
        } else {
            cout << "Error! Division by zero is not allowed.";
        }
    break;

    // If the operator is other than +, -, * or /,
    // error message will display
    default:
        cout << "Error! Operator is not correct";
    } // switch statement ends

    return 0;
}
```
Kode di atas digunakan untuk kalkulator sederhana dalam bentuk tambah, kurang, kali, bagi yang meminta pengguna untuk memasukkan operator dan dua operand. 

### 2. [tipe data abstrak]

```C++
#include <stdio.h>
#include <string.h>

//Struct
struct Mahasiswa{

    char name[50];
    char address[100];
    int age;
};

int main(){
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    strcpy(mhs1.name, "Dian");
    strcpy(mhs1.address, "Mataram");
    mhs1.age = 22;
    strcpy(mhs2.name, "Bambang");
    strcpy(mhs2.address, "Surabaya");
    mhs2.age = 23;
    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf ("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```

Kode di atas digunakan untuk memberikan sebuah informasi data mahasiswa dan mencetak informasi ke layar.

### 3. [tipe data koleksi]

```C++

#include <iostream>
#include <array>

using namespace std;
int main() {
    // Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    // Mencetak array dengan tab
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
return 0;
}
```

Kode di atas digunakan untuk memberikan sebuah informasi data mahasiswa dan mencetak informasi ke layar.

## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas.
Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari
materi tipe data primitif!]

```C++
#include <iostream>
using namespace std;

int penjumlahan_135(int num1_135, int num2_135) {
    return num1_135 + num2_135;
}

float LuasLingkaran_135(float Jarijari_135) {
    const float pi = 3.14; // Nilai pi
    return pi * Jarijari_135 * Jarijari_135; 
}

int main() {
  
    int num1_135 = 12, num2_135 = 10;
    float jarijari_135 = 14;
    
    cout << "Hasil penjumlahan: " << penjumlahan_135(num1_135, num2_135) << endl;
    cout << "Luas lingkaran adalah: " << LuasLingkaran_135(jarijari_135) << endl;

    return 0;
}
```

#### Output:
<<<<<<< HEAD
![Screenshot Output Unguided 1 ](<screenshoot output unguided1 .png>)
=======
![screenshoot unguided1 amelia](https://github.com/ameliaesmoe/2311102135_Amelia-Azmi/assets/162032965/fef3f913-51f2-4402-9cdf-9da7f5a4fe5c)
>>>>>>> 26a89edab525519a1b9b54cdc4463b89c3344055

Kode di atas digunakan untuk melakukan operasi matematika dasar seperti penjumlahan dan perhitungan luas lingkaran.

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya]

```C++
//1.contoh program menggunakan class

#include <iostream>
#include <string>

using namespace std;

class Student_135 {
private:
    string name_135;
    int age_135;
    string major_135;

public:
    // Constructor
    Student_135(string n_135, int a_135, string m_135) {
        name_135 = n_135;
        age_135 = a_135;
        major_135 = m_135;
    }

    // Member function to display student information
    void displayInfo() {
        cout << "Name: " << name_135 << endl;
        cout << "Age: " << age_135 << endl;
        cout << "Major: " << major_135 << endl;
    }
};

int main() {
    // Create an object of class Student
    Student_135 student1_135("Amelia Azmi", 19, "Teknik Informatika");

    // Display student information
    student1_135.displayInfo();

    return 0;
}
```

 //2.contoh program menggunakan struct

```C++
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
```

#### Output:
<<<<<<< HEAD
![Screenshot Output Unguided 2.1 Class](<screenshoot ouput unguided2class.png>)
![Screenshot Output Unguided 2.2 Struct](<screenshoot ouput unguided 2.png>)
=======
![screenshoot unguided2 class amelia](https://github.com/ameliaesmoe/2311102135_Amelia-Azmi/assets/162032965/b2cf10b4-7844-4e92-8832-9787ebc64fcf)
![screenshoot unguided2 struct](https://github.com/ameliaesmoe/2311102135_Amelia-Azmi/assets/162032965/163ac374-58c3-4ba5-9fbb-2f55d5a9b058)


>>>>>>> 26a89edab525519a1b9b54cdc4463b89c3344055

Kode Class di atas digunakan untuk mengorganisir data dan fungsi terkait identitas mahasiswa. Pada kode class ini bersifat privat, namun dapat diakses melalui metode publik.

Kode Struct di atas menggunakan sebuah struct bernama Student_135 untuk merepresentasikan data seorang mahasiswa. Struktur tersebut memiliki tiga anggota data: nama_135 untuk menyimpan nama mahasiswa, umur_135 untuk menyimpan usia mahasiswa, dan nilai_135 untuk menyimpan nilai mahasiswa.

## Fungsi Class
1. Class dapat menyatukan data (variabel) dan fungsi (metode) yang berhubungan dalam satu kesatuan.
2. Class dapat menyembunyikan detail implementasi dari pengguna.
3. memiliki metode dengan nama yang sama tetapi perilaku yang berbeda, tergantung pada implementasi di kelas turunan.

## Fungsi Struct
1. memiliki kumpulan dari data (variabel) dan fungsi (metode), tetapi secara default semua anggotanya bersifat publik.
2. digunakan untuk merepresentasikan data sederhana yang tidak memerlukan fungsionalitas kompleks seperti enkapsulasi, inheritance, atau polymorphism.

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.]

```C++
#include <iostream>
#include <map>
#include <string>

using namespace std;
int main() {

  // Membuat map untuk menyimpan nomor tiket dengan nama penumpang
  map<int, string> tiketBus_135;
  // Menambahkan data ke dalam map
  tiketBus_135[1] = "Aditya_135";
  tiketBus_135[2] = "Wisnu_135";
  tiketBus_135[3] = "Amelia_135";
  tiketBus_135[4] = "Azmi_135";
  tiketBus_135[5] = "Boby_135";
  // Menampilkan nomor tiket bus beserta nama penumpang
  cout << "Nomor Tiket Bus dan Nama Penumpang:" << endl;
  for (const auto& pair : tiketBus_135) {
      cout << "Nomor Tiket: " << pair.first << ", Nama Penumpang: " << pair.second << endl;
  }
  // Mengakses nama penumpang dengan nomor tiket tertentu
  int nomorTiket = 1;
  cout << "Nama Penumpang dengan Nomor Tiket " << nomorTiket << ": " << tiketBus_135[nomorTiket] << endl;
  
  return 0;
}
```

#### Output:
<<<<<<< HEAD
![Screenshot Output Unguided 3 ] (<screenshoot output unguided3.png>)
=======
![screenshoot unguided3 amelia](https://github.com/ameliaesmoe/2311102135_Amelia-Azmi/assets/162032965/88194cd5-bc88-475d-aad1-2404829b3ca6)

>>>>>>> 26a89edab525519a1b9b54cdc4463b89c3344055
Kode di atas digunakan untuk menyimpan dan mengakses informasi mengenai penumpang bus berdasarkan nomor tiket mereka. Dengan menggunakan struktur data map, program dapat dengan mudah menangani pasangan kunci-nilai ini tanpa perlu memikirkan indeks seperti dalam array atau vektor.

## Perbedaan Array dengan Map:
1. Penyimpanan data : array merupakan kumpulan elemen data yang disimpan secara berurutan dalam memori, diakses menggunakan indeks numerik, sedangkan map merupakan struktur data yang menggunakan pasangan kunci-nilai untuk menyimpan dan mengakses data.
2. Indeks: array menggunakan indeks numerik untuk mengakses elemen-elemennya. Indeks dimulai dari 0 dan berurutan, sedangkan map menggunakan kunci (biasanya tipe data yang dapat diurutkan seperti int, string, dll.) untuk mengakses nilainya. Setiap kunci bersifat unik dan dapat diakses secara langsung untuk mendapatkan nilai yang terkait.
3. Penggunaan: array digunakan ketika kita memiliki kumpulan data dengan ukuran yang tetap dan kita ingin mengakses elemen-elemennya dengan cepat menggunakan indeks numerik, sedangkan map digunakan ketika kita memiliki data dengan kunci yang terkait dengan nilai tertentu. 

## Kesimpulan
Dari pembelajaran tentang tipe data dalam bahasa C++, seperti tipe data primitif, abstrak, dan koleksi. Dapat disimpulkan bahwa tipe data itu sangat penting, Dengan pemahaman yang baik tentang tipe data dalam bahasa C++, kita dapat merancang dan mengembangkan sebuah program yang lebih efisien, kuat, dan mudah dipahami.

## Referensi
[1] Muharajul Zani (2019). Penjelasan Struktur Data Majemuk. Lampung : Universitas Mitra Indonesia.
[2] Yogga Pratama Wijaya. Jenis-jenis Tipe Data. Lampung : Universitas Mitra Indonesia.
