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

