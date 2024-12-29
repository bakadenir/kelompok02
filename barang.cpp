#include "barang.h"
#include <limits>
#include <iostream>
#include <iomanip> 
#include "header.h"
#include "utils.h" 

using namespace std;

string barangSKU = "001";
string barangNama = "Kertas Foto";
int barangJumlah = 10;

void tampilkanBarang() {
    cout << "---------------------------------------------------------------------------\n";
    cout << setw(10) << left << "SKU" 
         << setw(20) << left << "Nama Barang" 
         << setw(15) << left << "Jumlah Tersisa\n";
    cout << "---------------------------------------------------------------------------\n";
    cout << setw(10) << left << barangSKU 
         << setw(20) << left << barangNama 
         << setw(3) << left << barangJumlah << " Lembar";
    cout << "\n";
    cout << "\n";
}

void stockMasuk() {
    int tambahan;
    clearScreen();
    banner();
    cout << "\n";
    cout << "    TAMBAH STOCK KERTAS FOTO\n";
    cout << "\n";
    cout << "   > Masukkan jumlah stock yang akan ditambahkan: ";
    while (!(cin >> tambahan) || !validateInput(tambahan)) {
        clearScreen();
        banner();
        cout << "\n";
        cout << "   ** Gagal menambahkan stock, masukkan jumlah yang benar yaa! \n";
        cout << "\n";
        cout << "    TAMBAH STOCK MASUK KERTAS FOTO\n";
        cout << "\n";
        cout << "   > Masukkan jumlah stock yang akan ditambahkan: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    barangJumlah += tambahan;
    clearScreen();
    banner();
    cout << "\n";
    cout << "   ** Stock berhasil di tambahkan sebanyak " << tambahan << " lembar\n";
}

void stockTerpakai() {
    int terpakai;
    clearScreen();
    banner();
    cout << "\n";
    cout << "    STOCK KERTAS FOTO TERPAKAI\n";
    cout << "\n";
    cout << "   > Masukkan jumlah stock yang terpakai: ";
    while (!(cin >> terpakai) || !validateInput(terpakai)) {

        clearScreen();
        banner();
        cout << "\n";
        cout << "   ** Gagal mengurangi stock, masukkan jumlah yang benar yaa! \n";
        cout << "\n";
        cout << "    STOCK KERTAS FOTO YANG TERPAKAI\n";
        cout << "\n";
        cout << "   > Masukkan jumlah stock yang terpakai: ";
        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (terpakai <= barangJumlah) {
        barangJumlah -= terpakai;
        clearScreen();
        banner();
        cout << "\n";
        cout << "   ** Stock berhasil di kurangkan sebanyak " << terpakai << " lembar\n";
    } else {
        clearScreen();
        banner();
        cout << "\n";
        cout << "   ** Jumlah stock tidak cukup!\n";
    }
}

int getSubMenuChoice() {
    int subPilihan;
    while (true) {
        cout << "\n                              STOCK BARANG\n";
        tampilkanBarang();

        cout << "+-------------------------------------------------------------------------+\n";
        cout << "|    1. > Stock Masuk    |    2. > Stock Terpakai    |    3. > Kembali    |\n";
        cout << "+-------------------------------------------------------------------------+\n";
        cout << "\n";
        cout << "   Masukkan pilihan Anda (1/2/3): ";
        
        if (!(cin >> subPilihan) || !validateInput(subPilihan) || subPilihan < 1 || subPilihan > 3) {
            clearScreen();
            banner();
            cout <<"\n";
            cout << "   ** Pilihan tidak valid. Silakan coba lagi yaa!";
            cout <<"\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return subPilihan;
        }
    }
}

void menuStockBarang() {
    clearScreen();
    banner();
    int subPilihan;
    do {
        subPilihan = getSubMenuChoice();

        switch (subPilihan) {
            case 1:
                stockMasuk();
                break;
            case 2:
                stockTerpakai();
                break;
            case 3:
                clearScreen();
                banner();
                break;
            default:
                cout << "   ** Pilihan tidak valid!\n";
        }
    } while (subPilihan != 3);
}
