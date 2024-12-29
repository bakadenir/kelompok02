#include <iostream>
#include "header.h"
#include "paket.h"
#include "barang.h"
#include "utils.h"
#include "pemesanan.h"
#include "pembayaran.h"

using namespace std;

void panelStaff() {
    int subPilihan;
    clearScreen();
    banner();
    
    do {
        cout << " \n";
        cout << "   +---STAFF------------------------------+\n";
        cout << "   |                                      |\n";
        cout << "   |      1. > Manajemen Pemesanan        |\n";
        cout << "   |      2. > Manajemen Pembayaran       |\n";
        cout << "   |      3. > Kembali ke Menu Utama      |\n";
        cout << "   |                                      |\n";
        cout << "   +--------------------------------------+\n";
        cout << " \n";
        cout << "   Masukkan pilihan Anda (1/2/3): ";

        std::cin >> subPilihan;

        if (!validateInput(subPilihan, 1, 3)) {
            clearScreen();
            banner();
            cout << "\n   ** Pilihan tidak valid. Silakan coba lagi yaa!";
            cout << "\n";
        } else {
            switch (subPilihan) {
                case 1:
                    clearScreen();
                    panelPemesanan();
                    break;
                case 2:
                    clearScreen();
                    prosesPembayaran(); 
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
