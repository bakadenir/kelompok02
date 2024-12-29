#include "header.h"
#include "paket.h"
#include "admin.h"
#include "utils.h"
#include "staff.h"

using namespace std;

void showMenu() {
    cout << "\n";
    cout << "       1. > Admin\n";
    cout << "       2. > Staff\n";
    cout << "       3. > Keluar Program\n";
    cout << "\n";
}

int getUserChoice() {
    int choice;
    while (true) {
        showMenu();
        cout << "   Masukkan pilihan Anda (1/2/3): ";
        cin >> choice;

        if (!validateInput(choice, 1, 3)) {
            clearScreen();
            banner();
            cout << "\n   ** Pilihan tidak valid. Silakan coba lagi yaa!\n";
        } else {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}

int main() {
    clearScreen();
    banner();
    int choice;
    do {
        choice = getUserChoice();

        switch (choice) {
            case 1:
                clearScreen();
                panelAdmin();
                break;
            case 2:
                clearScreen();
                panelStaff();
                break;
            case 3:
                clearScreen();
                cout << "Terima kasih! Program akan keluar.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
