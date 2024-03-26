#include <iostream>
#include <string>
using namespace std;

// deklarasi struct node
struct Node {
    string datanama_135;
    int usia_135;
    Node* next_135;
};

Node* head_135 = nullptr;
Node* tail_135 = nullptr;

// inisialisasi node
void init_135() {
    head_135 = nullptr;
    tail_135 = nullptr;
}

// pengecekan apakah list kosong
bool isEmpty_135() {
    return head_135 == nullptr;
}

// hitung jumlah node
int hitungList_135() {
    int jumlah_135 = 0;
    Node* hitung_135 = head_135;
    while (hitung_135 != nullptr) {
        jumlah_135++;
        hitung_135 = hitung_135->next_135;
    }
    return jumlah_135;
}

// tambah node di depan
void insertDepan_135(string datanama_135, int usia_135) {
    Node* baru_135 = new Node;
    baru_135->datanama_135 = datanama_135;
    baru_135->usia_135 = usia_135;
    baru_135->next_135 = nullptr;

    if (isEmpty_135()) {
        head_135 = tail_135 = baru_135;
    } else {
        baru_135->next_135 = head_135;
        head_135 = baru_135;
    }
}

// tambah node di belakang
void insertBelakang_135(string datanama_135, int usia_135) {
    Node* baru_135 = new Node;
    baru_135->datanama_135 = datanama_135;
    baru_135->usia_135 = usia_135;
    baru_135->next_135 = nullptr;

    if (isEmpty_135()) {
        head_135 = tail_135 = baru_135;
    } else {
        tail_135->next_135 = baru_135;
        tail_135 = baru_135;
    }
}

// tambah node di tengah
void insertTengah_135(string datanama_135, int usia_135, int letak_135) {
    if (letak_135 < 1) {
        cout << "Posisi diluar jangkauan" << endl;
        return;
    }

    if (letak_135 == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }

    if (letak_135 > 1 && letak_135 <= hitungList_135()) {
        Node* baru = new Node;
        baru->datanama_135 = datanama_135;
        baru->usia_135 = usia_135;

        Node* bantu_135 = head_135;
        int nomor_135 = 1;

        while (nomor_135 < letak_135 - 1) {
            bantu_135 = bantu_135->next_135;
            nomor_135++;
        }

        baru->next_135 = bantu_135->next_135;
        bantu_135->next_135 = baru;
    } else {
        cout << "Posisi diluar jangkauan" << endl;
    }
}

// hapus node di tengah
void hapusTengah_135(string datanama_135) {
    if (!isEmpty_135()) {
        Node* hapus_135;
        Node* bantu_135 = head_135;

        if (head_135->datanama_135 == datanama_135) {
            hapus_135 = head_135;
            head_135 = head_135->next_135;
            delete hapus_135;
            return;
        }

        while (bantu_135->next_135 != nullptr && bantu_135->next_135->datanama_135 != datanama_135) {
            bantu_135 = bantu_135->next_135;
        }

        if (bantu_135->next_135 == nullptr) {
            cout << "Data tidak ditemukan!" << endl;
        } else {
            hapus_135 = bantu_135->next_135;
            bantu_135->next_135 = bantu_135->next_135->next_135;
            delete hapus_135;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// ubah data node
void ubahData_135(string datanamaCari_135, string datanamaBaru_135, int usiaBaru_135) {
    Node* bantu_135 = head_135;
    while (bantu_135!= nullptr) {
        if (bantu_135->datanama_135 == datanamaCari_135) {
            bantu_135->datanama_135 = datanamaBaru_135;
            bantu_135->usia_135 = usiaBaru_135;
            return;
        }
        bantu_135 = bantu_135->next_135;
    }
    cout << "Data tidak ditemukan!" << endl;
}

// tampilkan seluruh node
void tampil_135() {
    Node* bantu_135 = head_135;
    if (!isEmpty_135()) {
        while (bantu_135 != nullptr) {
            cout << bantu_135->datanama_135 << " " << bantu_135->usia_135 << endl;
            bantu_135 = bantu_135->next_135;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init_135();

    // Masukkan data mahasiswa
    cout << "Masukkan data mahasiswa sesuai urutan berikut:" << endl;
    cout << "[Nama] [Usia]" << endl;
    string datanama_135;
    int usia_135;
    while (true) {
        cout << "Masukkan nama : ";
        cin >> datanama_135;
        if (datanama_135 == "stop") break; // jika menginputkan stop, maka perulangan berhenti
        cout << "Masukkan usia : ";
        cin >> usia_135;
        insertBelakang_135(datanama_135, usia_135);
    }

    // a. Hapus data
    cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
    cin >> datanama_135;
    hapusTengah_135(datanama_135);

    // b. Tambahkan data
    cout << "Masukkan nama mahasiswa yang ingin ditambahkan: ";
    cin >> datanama_135;
    cout << "Masukkan usia : ";
    cin >> usia_135;
    insertTengah_135(datanama_135, usia_135, 2);

    // c. Tambahkan data di awal
    cout << "Masukkan nama mahasiswa yang ingin ditambahkan di awal: ";
    cin >> datanama_135;
    cout << "Masukkan usia : ";
    cin >> usia_135;
    insertDepan_135(datanama_135, usia_135);

    // d. Ubah data
    string datanamaCari_135, datanamaBaru_135;
    int usiaBaru_135;
    cout << "Masukkan nama mahasiswa yang ingin diubah datanya: ";
    cin >> datanamaCari_135;
    cout << "Masukkan nama baru: ";
    cin >> datanamaBaru_135;
    cout << "Masukkan usia baru: ";
    cin >> usiaBaru_135;
    ubahData_135(datanamaCari_135, datanamaBaru_135, usiaBaru_135);

    // e. Tampilkan seluruh data
    cout << "Data Mahasiswa:" << endl;
    tampil_135();

    return 0;
}