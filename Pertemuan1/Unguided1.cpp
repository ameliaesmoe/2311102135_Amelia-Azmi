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
