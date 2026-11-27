#include "AlatLaboratorium.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

AlatLaboratorium::AlatLaboratorium(string nama, string kategori, int jumlah) {
    this->nama = nama;
    this->kategori = kategori;
    this->jumlah = (jumlah >= 0) ? jumlah : 0;
}

string AlatLaboratorium::getNama() const {
    return nama;
}

string AlatLaboratorium::getKategori() const {
    return kategori;
}

int AlatLaboratorium::getJumlah() const {
    return jumlah;
}

void AlatLaboratorium::tampilkanInfo() const {
    cout << left << setw(24) << nama
         << setw(20) << kategori
         << setw(10) << jumlah << endl;
}

void AlatLaboratorium::tambahJumlah(int n) {
    if (n > 0) {
        jumlah += n;
        cout << "[BERHASIL] Stok '" << nama << "' bertambah " << n
             << ". Total stok sekarang: " << jumlah << endl;
    } else {
        cout << "PERINGATAN! Jumlah penambahan harus lebih dari 0!" << endl;
    }
}

void AlatLaboratorium::kurangiJumlah(int n) {
    if (n <= 0) {
        cout << "PERINGATAN! Jumlah pengurangan harus lebih dari 0!" << endl;
    } else if (n > jumlah) {
        cout << "GAGAL! Stok '" << nama << "' tidak mencukupi (Tersedia: "
             << jumlah << ")." << endl;
    } else {
        jumlah -= n;
        cout << "[BERHASIL] Stok '" << nama << "' berkurang " << n
             << ". Sisa stok sekarang: " << jumlah << endl;
    }
}
