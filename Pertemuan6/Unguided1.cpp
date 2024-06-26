//Edited by amelia azmi_2311102135
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Fungsi untuk memeriksa apakah sebuah kalimat adalah palindrom
bool isPalindrome_135(const string& kal) {
    string strippedSentence_135;

    // Menghapus spasi dan tanda baca dari kalimat, dan mengonversi huruf menjadi lowercase
    for (char r047 : kal) {
        if (isalpha(r047)) {
            strippedSentence_135 += tolower(r047); // Menambahkan karakter yang valid ke dalam kalimat tanpa tanda baca dan spasi
        }
    }

    string reversedSentence_135 = strippedSentence_135;
    reverse(reversedSentence_135.begin(), reversedSentence_135.end()); 
    // Membalikkan kalimat untuk memeriksa apakah sama dengan kalimat asli
    
    return strippedSentence_135 == reversedSentence_135; // Mengembalikan nilai true jika kalimat adalah palindrom, dan false jika tidak
}

int main() {
    string kal;
    cout << "Masukkan kalimat: ";
    getline(cin, kal);

    bool isPalindrom_135 = isPalindrome_135(kal); // Memanggil fungsi isPalindrome untuk memeriksa apakah kalimat adalah palindrom atau tidak

    cout << "Kalimat: " << kal << endl;

    // Menampilkan hasil apakah kalimat adalah palindrom atau tidak
    if (isPalindrom_135) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0; // Mengembalikan nilai 0, menandakan bahwa program berjalan dengan sukses
}