#include <iostream>
#include <iomanip>
#include <string>
#include "paket.h"
#include "pembayaran.h"
#include "pemesanan.h"
#include "utils.h"
#include "header.h"
#include <ctime>

using namespace std;

string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
}

void prosesPembayaran() {
    clearScreen();
    banner();
    cout << "\n   PROSES PEMBAYARAN\n";
    cout << "\n";
    string idPelanggan;
    cout << "   Masukkan ID Pelanggan: ";
    cin >> idPelanggan;

    bool found = false;
    for (int i = 0; i < jumlahPemesanan; i++) {
        if (idPemesanan[i] == idPelanggan) {
            found = true;
            cout << "   Nama Pelanggan: " << namaPelanggan[i] << endl;
            string idPaket = pilihanPaket[i];
            double harga = getHargaPaketByID(idPaket);
            cout << "   ID Paket: " << idPaket << endl;
            cout << "   Harga: " << harga << endl;

            cout << "\n   Pilih metode pembayaran:\n";
            cout << "\n";
            cout << "       1. > Uang Tunai\n";
            cout << "       2. > QRIS\n";
            cout << "\n   Masukkan pilihan Anda: ";
            int pilihan;
            cin >> pilihan;

            if (pilihan == 1) {
                cout << "   Pembayaran dengan Uang Tunai diproses.\n";
            } else if (pilihan == 2) {
                cout << "   Pembayaran dengan QRIS diproses.\n";
            } else {
                cout << "   Pilihan tidak valid.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "   ** ID Pelanggan tidak ditemukan\n";
    }
    cout << "   Tekan enter untuk kembali.";
    cin.ignore();
    cin.get();
    clearScreen();
    banner();
}

void cetakStruk(const string& idPelanggan) {
    clearScreen();
    banner();
    cout << "\n   CETAK STRUK\n";

    bool found = false;
    for (int i = 0; i < jumlahPemesanan; i++) {
        if (idPemesanan[i] == idPelanggan) {
            found = true;
            cout << "   MADUS FOTO\n";
            cout << "   Jl. Sawo II RR 005 / 02\n";
            cout << "---------------------------\n";
            cout << "   Tanggal: " << getCurrentDate() << endl;
            cout << "   Nama: " << namaPelanggan[i] << endl;
            cout << "   No. Pemesanan: " << idPelanggan << endl;
            cout << "----------------------------\n";
            cout << "   " << pilihanPaket[i] << " - " << hargaPaket[i] << endl;
            cout << "----------------------------\n";
            cout << "   Subtotal: " << hargaPaket[i] << endl;
            cout << "----------------------------\n";
            cout << "   Total: " << hargaPaket[i] << endl;
            cout << "   QRIS: " << hargaPaket[i] << endl;
            cout << "----------------------------\n";
            break;
        }
    }

    if (!found) {
        cout << "   ** ID Pelanggan tidak ditemukan\n";
    }
    cout << "   Tekan enter untuk kembali.";
    cin.ignore();
    cin.get();
}
