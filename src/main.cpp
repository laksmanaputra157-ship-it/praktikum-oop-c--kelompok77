
#include <iostream>
#include <vector>
#include <iomanip>
#include "AlatLaboratorium.hpp"

using namespace std;

int main() {

    vector<AlatLaboratorium> daftarAlat = {
        AlatLaboratorium("Mikroskop", "Optik", 10),
        AlatLaboratorium("Tabung Reaksi", "Gelas", 50),
        AlatLaboratorium("Multimeter", "Elektronik", 8),
        AlatLaboratorium("Gelas Ukur", "Gelas", 20),
        AlatLaboratorium("Termometer", "Pengukur", 15)
    };

    int pilihan;
    int indeks;
    int jumlah;

    do {
        cout << "Sistem Manajemen Alat Laboratium" << endl;
        cout << "1. Tampilkan Daftar Alat" << endl;
        cout << "2. Tambah Jumlah Alat" << endl;
        cout << "3. Kurangi Jumlah Alat" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << endl << "Daftar alat Laboratium" << endl;
                cout << left << setw(24) << "Nama Alat"
                     << setw(20) << "Kategori"
                     << setw(10) << "Jumlah" << endl;

                cout << "----------------------------------------------\n";

                for (int i = 0; i < daftarAlat.size(); i++) {
                    daftarAlat[i].tampilkanInfo();
                }

                cout << "----------------------------------------------\n";
                break;

            case 2:
                cout << endl << "Tambah jumlah alat" << endl;

                for (int i = 0; i < daftarAlat.size(); i++) {
                    cout << i + 1 << ". ";
                    daftarAlat[i].tampilkanInfo();
                }

                cout << "\nMasukkan nomor alat yang ingin ditambah: ";
                cin >> indeks;

                if (indeks >= 1 && indeks <= daftarAlat.size()) {
                    cout << "Masukkan jumlah penambahan: ";
                    cin >> jumlah;

                    daftarAlat[indeks - 1].tambahJumlah(jumlah);
                } else {
                    cout << "Nomor alat tidak ditemukan!\n";
                }
                break;

            // 4. Mengurangi jumlah alat
            case 3:
                cout << endl << "Mengurangi jumlah alat" << endl;

                for (int i = 0; i < daftarAlat.size(); i++) {
                    cout << i + 1 << ". ";
                    daftarAlat[i].tampilkanInfo();
                }

                cout << "\nMasukkan nomor alat yang ingin dikurangi: ";
                cin >> indeks;

                if (indeks >= 1 && indeks <= daftarAlat.size()) {
                    cout << "Masukkan jumlah pengurangan: ";
                    cin >> jumlah;

                    daftarAlat[indeks - 1].kurangiJumlah(jumlah);
                } else {
                    cout << "Nomor alat tidak ditemukan!\n";
                }
                break;

            case 4:
                cout << "\nTerima kasih telah menggunakan sistem!\n";
                break;

            default:
                cout << "\nPilihan tidak valid! Silakan coba lagi.\n";
        }

    } while (pilihan != 4);

    return 0;
}
