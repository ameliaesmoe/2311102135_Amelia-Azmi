# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Amelia Azmi_2311102135</p>

## Dasar Teori

### Pengertian Stack
Stack adalah suatu koleksi atau kumpulan item data yang terorgaisasi dalam bentuk urutan linear, yang operasi pemasukan dan penghapusan datanya dilakukan pada salah satu sisinya. Sedangkan pengertian stack pada struktur data adalah sebagai tumpukan dari benda, sekumpulan data
yang seolah-olah diletakkan di atas data yang lain, koleksi dari objek-objek homogen, atau suatu urutan elemen yang elemennya dapat diambil dan ditambah hanya pada posisi akhir (top) saja. Stack merupakan bentuk khusus dari suatu struktur data, dimana node yang ditambahkan
ke dalam list dan diambil dari list hanya pada kepalanya, atau dengan prinsip pengolahannya adalah last-in first-out (LIFO). Pada struktur ini hanya ada dua fungsi utama, yaitu push (memasukkan node ke dalam stack), dan pop (mengambil node dari stack).

![Alt text](<Ilustrasi Stack.png>)

Deklarasi Struktur Data Stack
```C++
const int maxsize = 100; // Mendefinisikan maks ukuran data dalam stack
struct stack {
    int top;            // Indeks TOP
    char items[maxsize];// Array
};
```

### Operasi Dasar Pada Stack
1. Create : merupakan operator yang berfungsi untuk membuat sebuah stack kosong.
```C++
struct STACK {
    int top;
    float data[5];
    };
    float dta;
    struct STACK stackbaru;
```C++

2. IsEmpty : merupakan operator yang berfungsi untuk menentukan apakah suatu stack merupakan stack kosong. Tanda bahwa sebuah stack kosong adalah Top bernilai kurang dari nol (-1).
```C++
bool isempty() {
    if (stackbaru.top==1) return true;
    else return false;
}
```

3. IsFull : merupakan operator yang digunakan untuk memeriksa apakah stack yang ada sudah penuh. Stack akan penuh jika puncak stack terletak tepat dibawah jumlah maksimum yang dapat ditampung stack (Top = MAX_STACK-1).
```C++
bool isfull() {
    if (stackbaru.top==maxstack) return
    true;
    else return false;
}
```

4. Push : merupakan operator yang berfungsi untuk menambahkan satu elemen ke dalam stack dan tidak dapat dilakukan jika stack dalam keadaan penuh.
```C++
void push(float dta) {
    if (isfull()==false) {
        puts("stack penuh");
        } else {
            stackbaru.top++;
            stackbaru.data[top]=dta;
            }
}
```

5. Pop : merupakan operator yang berfungsi untuk mengeluarkan satu elemen teratas dari dalam stack dengan syarat stack tidak dalam kondisi kosong.
```C++
void pop() {
    if (isempty()==false) {
        cout<<"data kosong";
        } else {
            cout<<"data yang terambil : "<<stackbaru.data[top]<<endl;
            stackbaru.top--;
            }
}
```

6. Clear : fungsi yang digunakan untuk mengosongkan stack dengan cara mengeset Top dengan -1. Jika Top bernilai kurang dari nol maka stack dianggap kosong.
```C++
void clear () {
    top=-1
}
```

7. Retrieve : fungsi yang digunakan untuk melihat nilai yang berada pada posisi tumpukan teratas
```C++
void print() {
    for (int i=0; i<=top; i++) {
        cout<<stackbaru.data[i]<<"";
        }
}
```

### 1. [Guided]

```C++
#include<iostream>

using namespace std;

//Deklarasi array bernama arrayBuku dengan ukuran 5
string arrayBuku[5];
int maksimal = 5, top = 0;

//Fungsi isFull untuk memeriksa apakah stack full atau tidak
bool isFull(){
    return (top == maksimal);
}

//Fungsi isEmpty untuk memeriksa apakah stack kosong atau tidak
bool isEmpty(){
    return (top == 0);
}

//Prosedur push untuk menambahkan elemen pada stack posisi paling atas
void pushArrayBuku(string data){
    if(isFull()){
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

//Prosedur pop untuk menghapus elemen pada stack posisi paling atas
void popArrayBuku(){
    if(isEmpty()){
        cout << "tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

//Prosedur peek untuk melihat elemen pada stack posisi tertentu 
void peekArrayBuku(int posisi){
    if(isEmpty()){
        cout << "tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for(int i = 1; i <= posisi; i++){
            index--;
        }
        cout << "Posisi ke-" << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

//Fungsi Count untuk menghitung jumlah elemen pada stack
int countStack(){
    return top;
}

//Prosedur change untuk mengubah elemen posisi tertentu pada stack
void changeArrayBuku(int posisi, string data){
    if(posisi > top){
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for(int i = 1; i <= posisi; i++){
            index--;
        }
        arrayBuku[index] = data;
    }
}

//Prosedur destroy atau clear untuk menghapus semua elemen pada stack
void destroyArrayBuku(){
    for(int i = top; i >= 0; i--){
        arrayBuku[i] = "";
    }
    top = 0;
}

//Prosedur cetak untuk menampilkan semua elemen pada stack
void cetakArrayBuku(){
    if(isEmpty()){
        cout << "tidak ada data yang bisa dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--){
            cout << arrayBuku[i] << endl;
        }
    }
}

int main(){
    //Menambahkan elemen pada stack menggunakan prosedur push
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    //mencetak semua elemen pada stack menggunakan prosedur cetak
    cetakArrayBuku();
    cout << "\n";

    //Memeriksa apakah stack penuh atau tidak menggunakan fungsi isFull
    cout << "Apakah data stack penuh? " << isFull() << endl;

    //Memeriksa apakah stack kosong atau tidak menggunakan fungsi isEmpty
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    cout << "\n";

    //Melihat elemen pada stack posisi ke 2 menggunakan prosedur peek
    peekArrayBuku(2);

    //Menghapus elemen stack posisi paling atas menggunakan prosedur pop
    popArrayBuku();
    cout << "\n";

    //Menghitung jumlah elemen pada stack menggunakan fungsi count
    cout << "Banyaknya data = " << countStack() << endl;

    //Mengubah elemen stack posisi ke 2 menjadi "Bahasa Jerman" menggunakan prosedur change
    changeArrayBuku(2, "Bahasa Jerman");

    //mencetak semua elemen pada stack menggunakan prosedur cetak
    cetakArrayBuku();
    cout << "\n";

    //Menghapus semua elemen pada stack menggunakan prosedur destroy atau clear
    destroyArrayBuku();

    //Menghitung jumlah elemen pada stack menggunakan fungsi count
    cout << "Jumlah data setelah dihapus = " << countStack() << endl;

    //mencetak semua elemen pada stack menggunakan prosedur cetak
    cetakArrayBuku();

    return 0;
}
```
Kode diatas merupakan sebuah implementasi dari struktur data stack menggunakan array dalam bahasa pemrograman C++. Stack merupakan struktur data yang mengadopsi prinsip LIFO (Last In, First Out), di mana elemen yang terakhir dimasukkan akan menjadi yang pertama dikeluarkan. Dalam program ini, sebuah array bernama `arrayBuku` dengan ukuran 5 dideklarasikan untuk bertindak sebagai stack penyimpanan nama buku. Melalui serangkaian fungsi dan prosedur, program ini memungkinkan operasi dasar pada stack, seperti menambahkan elemen ke atas stack dengan fungsi `pushArrayBuku()`, menghapus elemen dari atas stack dengan `popArrayBuku()`, serta melihat, mengubah, menghitung jumlah, dan menghapus seluruh elemen pada stack. Program utama mengilustrasikan penggunaan fungsi-fungsi dan prosedur-prosedur tersebut dengan contoh penggunaan nyata, seperti menambahkan beberapa nama buku ke stack, mencetaknya, memeriksa apakah stack penuh atau kosong, dan melakukan operasi lainnya.

## Unguided 

### 1. [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.]

Contoh:
Kalimat : ini
Kalimat tersebut adalah polindrom
Kalimat : telkom
Kalimat tersebut adalah bukan polindrom

![Alt text](U1.png)

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. [Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?]

Contoh
Kalimat : Telkom Purwokerto
Hasil : otrekowruP mokleT

![Alt text](U2.png)

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi

[1] J Sihombing. Penerapan Stack dan Queue Pada Array dan Linked List Dalam Java. 2019
[2] Mochamad Fajar Wicaksono, S.Kom., M.Kom.. Percabangan, Stack, Subrutin dan Delay. 2020. Unikom : Bandung.