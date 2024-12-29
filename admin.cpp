#include <iostream>
#include "header.h"
#include "paket.h"
#include "barang.h"
#include "utils.h"

using namespace std;

void panelBarang() {
    menuStockBarang();
}

void panelAdmin() {
    int subPilihan;
    clearScreen();
    banner();
    
    do {
        cout << " \n";
        cout << "   +---ADMIN------------------------------+\n";
        cout << "   |                                      |\n";
        cout << "   |      1. > Manajemen Paket            |\n";
        cout << "   |      2. > Manajemen Barang           |\n"; 
        cout << "   |      3. > Kembali ke Menu Utama      |\n";
        cout << "   |                                      |\n";
        cout << "   +--------------------------------------+\n";
        cout << " \n";
        cout << "   Masukkan pilihan Anda (1/2/3): ";

        cin >> subPilihan;

        if (!validateInput(subPilihan, 1, 3)) {
            clearScreen();
            banner();
            cout << "\n   ** Pilihan tidak valid. Silakan coba lagi yaa!";
            cout << "\n";
        } else {
            switch (subPilihan) {
                case 1:
                    clearScreen();
                    panelPaket(); 
                    break;
                case 2:
                    clearScreen();
                    panelBarang(); 
                    break;
                case 3:
                    clearScreen();
                    banner();
                    return; 
                default:
                    clearScreen();
                    banner();
                    cout << "   ** Pilihan tidak valid. Silakan coba lagi!\n";
            }
        }
    } while (true); 
}
