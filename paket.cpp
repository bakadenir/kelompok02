#include <iostream>
#include <iomanip>
#include <limits>
#include "paket.h"
#include "header.h"
#include "utils.h"

using namespace std;

string paketID[MAX_PAKET];
string paketNama[MAX_PAKET];
double paketHarga[MAX_PAKET];
string paketDeskripsi[MAX_PAKET];
bool paketAktif[MAX_PAKET];
int jumlahPaket = 0;

void tampilkanPaket() {
    cout << "---------------------------------------------------------------------------\n";
    cout << setw(10) << "ID" << setw(20) << "Nama Paket" << setw(10) << "Harga" << setw(20) << "Deskripsi" << endl;
    cout << "---------------------------------------------------------------------------\n";
    
    if (jumlahPaket == 0) {
        cout << "   Paket tidak tersedia, silahkan 'Tambah Paket' terlebih dahulu yaa\n";
    } else {
        for (int i = 0; i < jumlahPaket; i++) {
            if (paketAktif[i]) {
                cout << setw(10) << left << paketID[i]
                     << setw(20) << left << paketNama[i]
                     << setw(10) << left << paketHarga[i]
                     << setw(20) << left << paketDeskripsi[i] << endl;
            }
        }
    }
    cout << "\n";
}

bool isIDUsed(const string& id) {
    for (int i = 0; i < jumlahPaket; i++) {
        if (paketID[i] == id) {
            return true;
        }
    }
    return false;
}

void tambahPaket() {
    clearScreen();
    banner();
    cout << "\n";
    cout << "   TAMBAH PAKET\n";
    cout << "\n";

    if (jumlahPaket < MAX_PAKET) {
        int id = jumlahPaket + 1;
        paketID[jumlahPaket] = std::to_string(id);
        paketID[jumlahPaket] = std::string(3 - paketID[jumlahPaket].length(), '0') + paketID[jumlahPaket];

        cout << "   > Nama Paket        : ";
        getline(cin, paketNama[jumlahPaket]);
        
        cout << "   > Harga Paket       : ";
        while (!(cin >> paketHarga[jumlahPaket]) || !validateInput(paketHarga[jumlahPaket])) {
            cout << "   > Masukkan harga yang benar: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "   > Deskripsi Paket   : ";
        cin.ignore();
        getline(cin, paketDeskripsi[jumlahPaket]);
        paketAktif[jumlahPaket] = true;
        jumlahPaket++;
        clearScreen();
        banner();
        cout << "\n   ** Berhasil menambahkan paket\n";
    } else {
        cout << "Jumlah paket sudah mencapai batas maksimum.\n";
    }
}

void showMenuUbah() {
    cout << "   UBAH PAKET\n";
    cout << "\n";
    cout << "       1. > Ubah Harga\n";
    cout << "       2. > Ubah Deskripsi\n";
    cout << "       3. > Nonaktifkan Paket\n";
    cout << "       4. > Kembali\n";
    cout << "\n";
}

int getUserChoiceUbah() {
    int choice;
    while (true) {
        cout << "   Masukkan pilihan Anda (1/2/3/4): ";
        if (cin >> choice && validateInput(choice, 1, 4)) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        } else {
            clearScreen();
            banner();
            cout << "\n   ** Pilihan tidak valid. Silakan coba lagi yaa!\n";
            cout << "\n";
            showMenuUbah();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void updatePaket() {
    clearScreen();
    banner();
    cout << "\n";
    showMenuUbah();

    int pilihan = getUserChoiceUbah();
    string id;
    switch (pilihan) {
        case 1: {
            clearScreen();
            banner();
            cout << "\n";
            cout << "                               UBAH HARGA\n";
            tampilkanPaket();
            cout << "   Masukkan ID Paket yang ingin diubah harganya: ";
            cin >> id;

            for (int i = 0; i < jumlahPaket; i++) {
                if (paketID[i] == id) {
                    cout << "   Harga baru paket '" << paketNama[i] << "': ";
                    while (!(cin >> paketHarga[i]) || !validateInput(paketHarga[i])) {
                        cout << "   Input tidak valid. Masukkan harga yang benar: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    clearScreen();
                    banner();
                    cout << "\n";
                    cout << "   Harga paket '" << paketNama[i] << "' berhasil diubah!\n";
                    return;
                }
            }
            clearScreen();
            banner();
            cout << "\n";
            cout << "   ** Gagal mengubah harga, ID paket tidak ditemukan.\n";
            break;
        }
        case 2: {
            clearScreen();
            banner();
            cout << "\n";
            cout << "                               UBAH DESKRIPSI\n";
            tampilkanPaket();
            cout << "   Masukkan ID Paket yang ingin diubah deskripsinya: ";
            cin >> id;

            for (int i = 0; i < jumlahPaket; i++) {
                if (paketID[i] == id) {
                    cout << "   Deskripsi baru paket '" << paketNama[i] << "': ";
                    cin.ignore();
                    getline(cin, paketDeskripsi[i]);
                    clearScreen();
                    banner();
                    cout << "\n";
                    cout << "   Deskripsi paket '" << paketNama[i] << "' berhasil diubah!\n";
                    return;
                }
            }
            clearScreen();
            banner();
            cout << "\n";
            cout << "   ** Gagal mengubah deskripsi, ID paket tidak ditemukan.\n";
            break;
        }
        case 3: {
            clearScreen();
            banner();
            cout << "\n";
            cout << "                             NONAKTIFKAN PAKET\n";
            tampilkanPaket();
            cout << "   Masukkan ID Paket yang ingin dinonaktifkan: ";
            cin >> id;

            for (int i = 0; i < jumlahPaket; i++) {
                if (paketID[i] == id) {
                    paketAktif[i] = false;
                    clearScreen();
                    banner();
                    cout << "\n";
                    cout << "   Paket '" << paketNama[i] << "' berhasil dinonaktifkan!\n";
                    return;
                }
            }
            clearScreen();
            banner();
            cout << "\n";
            cout << "   ** Gagal mengnonaktifkan paket, ID paket tidak ditemukan.\n";
            break;
        }
        case 4:
            clearScreen();
            banner();
            return;
        default:
            break;
    }
}

void panelPaket() {
    clearScreen();
    banner();
    int subPilihan;
    while (true) {
        cout << "\n                              DAFTAR PAKET\n";
        tampilkanPaket();
        
        cout << "+-------------------------------------------------------------------------+\n";
        cout << "|     1. > Tambah Paket    |     2. > Ubah Paket    |     3. > Kembali    |\n";
        cout << "+-------------------------------------------------------------------------+\n";
        cout << "\n";
        cout << "   Masukkan pilihan Anda (1/2/3): ";

        if (!(cin >> subPilihan) || !validateInput(subPilihan) || subPilihan < 1 || subPilihan > 3) {
            clearScreen();
            banner();
            cout << "\n";
            cout << "   ** Pilihan tidak valid. Silakan coba lagi yaa!";
            cout << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (subPilihan) {
                case 1:
                    tambahPaket();
                    break;
                case 2:
                    updatePaket();
                    break;
                case 3:
                    clearScreen();
                    banner();
                    return;
                default:
                    cout << "Pilihan tidak valid.\n";
            }
        }
    }
}

double getHargaPaketByID(const string& id) {
    for (int i = 0; i < jumlahPaket; i++) {
        if (paketID[i] == id && paketAktif[i]) {
            return paketHarga[i];
        }
    }
    return 0;
}
