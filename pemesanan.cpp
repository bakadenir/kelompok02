#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "pemesanan.h"
#include "utils.h"
#include "header.h"
#include "paket.h"

using namespace std;

string getNamaBulan(int bulan);

string idPemesanan[MAX_PEMESANAN];
string namaPelanggan[MAX_PEMESANAN];
string pilihanPaket[MAX_PEMESANAN];
int tanggalPemesanan[MAX_PEMESANAN];
int bulanPemesanan[MAX_PEMESANAN];
int tahunPemesanan[MAX_PEMESANAN]; // Tambahkan array untuk tahun
int jamPemesanan[MAX_PEMESANAN];
string statusPemesanan[MAX_PEMESANAN];
int jumlahPemesanan = 0;
int hargaPaket[MAX_PEMESANAN];

string getNamaBulan(int bulan) {
    switch (bulan) {
        case 1: return "Jan";
        case 2: return "Feb";
        case 3: return "Mar";
        case 4: return "Apr";
        case 5: return "May";
        case 6: return "Jun";
        case 7: return "Jul";
        case 8: return "Aug";
        case 9: return "Sep";
        case 10: return "Oct";
        case 11: return "Nov";
        case 12: return "Dec";
        default: return "";
    }
}

string getPaketNamaByID(const string& id) {
    for (int i = 0; i < jumlahPaket; i++) {
        if (paketID[i] == id && paketAktif[i]) {
            return paketNama[i];
        }
    }
    return "";
}

bool isValidDate(int tanggal, int bulan, int tahun) {
    // Cek jumlah hari dalam setiap bulan
    if (bulan < 1 || bulan > 12) return false; // Bulan tidak valid

    // Array jumlah hari dalam bulan (index 0 untuk bulan 1, index 1 untuk bulan 2, dst.)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Cek tahun kabisat untuk bulan Februari
    if (bulan == 2) {
        if ((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0)) {
            daysInMonth[2] = 29; // Tahun kabisat
        }
    }

    // Cek apakah tanggal valid
    return (tanggal > 0 && tanggal <= daysInMonth[bulan]);
}

void tampilkanPemesanan() {
    cout << "---------------------------------------------------------------------------\n";
    cout << setw(5) << left << "ID" 
         << setw(20) << left << "Nama Pelanggan" 
         << setw(10) << left << "Paket" 
         << setw(10) << left << "Tanggal" 
         << setw(10) << left << "Bulan" 
         << setw(10) << left << "Tahun" // Tampilkan kolom Tahun
         << setw(10) << left << "Jam" 
         << setw(10) << left << "Status" 
         << endl;
    cout << "---------------------------------------------------------------------------\n";

    if (jumlahPemesanan == 0) {
        cout << "   Pelanggan tidak tersedia, silahkan 'Tambah Pelanggan' terlebih dulu yaa \n";
    } else {
        for (int i = 0; i < jumlahPemesanan; i++) {
            cout << setw(5) << left << idPemesanan[i]
                 << setw(20) << left << namaPelanggan[i]
                 << setw(10) << left << pilihanPaket[i]
                 << setw(10) << left << "  " << tanggalPemesanan[i]
                 << setw(10) << left << getNamaBulan(bulanPemesanan[i])
                 << setw(10) << left << tahunPemesanan[i] // Tampilkan tahun
                 << setw(10) << left << jamPemesanan[i]
                 << setw(10) << left << statusPemesanan[i] << endl;
        }
    }
}

int getValidatedInput(const string& prompt, int min, int max) {
    int value;
    cout << "   > " << prompt;
    cin >> value;
    while (!validateInput(value) || value < min || value > max) {
        cout << "   > Masukkan nilai yang benar (" << min << "-" << max << "): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> value;
    }
    return value;
}

void kelolaPemesanan() {
    clearScreen();
    banner();
    cout << "\n   KELOLA PEMESANAN\n\n";

    if (jumlahPemesanan < MAX_PEMESANAN) {
        int id = jumlahPemesanan + 1;
        idPemesanan[jumlahPemesanan] = std::to_string(id);
        idPemesanan[jumlahPemesanan] = std::string(3 - idPemesanan[jumlahPemesanan].length(), '0') + idPemesanan[jumlahPemesanan];

        cout << "   > Nama Pelanggan: ";
        getline(cin, namaPelanggan[jumlahPemesanan]);

        cout << "   > Pilihan Paket (ID paket): ";
        string idPaket;
        getline(cin, idPaket);

        string namaPaket = getPaketNamaByID(idPaket);
        if (!namaPaket.empty()) {
            pilihanPaket[jumlahPemesanan] = namaPaket;
            cout << "   Paket yang dipilih: " << namaPaket << endl;
        } else {
            cout << "ID Paket tidak valid atau tidak aktif.\n";
            return;
        }

        tahunPemesanan[jumlahPemesanan] = getValidatedInput("Tahun (misal: 2025): ", 2020, 2100);
        bulanPemesanan[jumlahPemesanan] = getValidatedInput("Bulan (1-12): ", 1, 12);
        
        int tanggal;
        while (true) {
            tanggal = getValidatedInput("Tanggal (1-31): ", 1, 31);
            if (isValidDate(tanggal, bulanPemesanan[jumlahPemesanan], tahunPemesanan[jumlahPemesanan])) {
                tanggalPemesanan[jumlahPemesanan] = tanggal;
                break; // Keluar dari loop jika tanggal valid
            } else {
                cout << "   Tanggal tidak valid untuk bulan " << getNamaBulan(bulanPemesanan[jumlahPemesanan]) << " " << tahunPemesanan[jumlahPemesanan] << ". Silakan coba lagi.\n";
            }
        }

        jamPemesanan[jumlahPemesanan] = getValidatedInput("Jam (0-23): ", 0, 23);

        statusPemesanan[jumlahPemesanan] = "Diproses";
        jumlahPemesanan++;
        clearScreen();
        banner();
    } else {
        cout << "Jumlah pemesanan sudah mencapai batas maksimum.\n";
    }
}

void showMenu1() {
    cout << "\n";
    cout << "       1. > Bedasarkan Tanggal\n";
    cout << "       2. > Bedasarkan Jangka Waktu\n"; // Fitur baru
    cout << "       3. > Perbarui Status\n"; // Diubah urutan
    cout << "       4. > Kembali\n"; // Diubah urutan
    cout << "\n";
}

int getUserChoice1() {
    int choice;
    while (true) {
        showMenu1();
        cout << "   Masukkan pilihan Anda (1/2/3/4): "; // Diubah urutan
        cin >> choice;

        if (!validateInput(choice, 1, 4)) { // Diubah urutan
            clearScreen();
            banner();
            cout << "\n   ** Pilihan tidak valid. Silakan coba lagi yaa!\n";
            cout << "\n   MEMERIKSA JADWAL\n";
        } else {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}

void cariPemesananBerdasarkanTanggal(int tanggal) {
    clearScreen();
    banner();
    cout << "\n                     DAFTAR PELANGGAN DI TANGGAL " << tanggal << "\n";

    cout << "---------------------------------------------------------------------------\n";
    cout << setw(5) << left << "ID" 
         << setw(20) << left << "Nama Pelanggan" 
         << setw(10) << left << "Paket" 
         << setw(10) << left << "Tanggal" 
         << setw(10) << left << "Bulan" 
         << setw(10) << left << "Tahun" 
         << setw(10) << left << "Jam" 
         << setw(10) << left << "Status" 
         << endl;
    cout << "---------------------------------------------------------------------------\n";

    bool found = false; 
    for (int i = 0; i < jumlahPemesanan; i++) {
        if (tanggalPemesanan[i] == tanggal) {
            cout << setw(5) << idPemesanan[i]
                 << setw(20) << namaPelanggan[i]
                 << setw(10) << pilihanPaket[i]
                 << setw(10) << "  " << tanggalPemesanan[i]
                 << setw(10) << getNamaBulan(bulanPemesanan[i])
                 << setw(10) << tahunPemesanan[i] // Tampilkan tahun
                 << setw(10) << jamPemesanan[i]
                 << setw(10) << statusPemesanan[i] << endl;
            found = true; // Set flag jika ada pemesanan yang ditemukan
        }
    }

    if (!found) {
        cout << "   Tidak ada pemesanan untuk tanggal " << tanggal << ".\n";
    }

    cout << "\n   Tekan enter untuk kembali";
    cin.ignore();
    cin.get();
}

void cariPemesananBerdasarkanJangkaWaktu(int tanggalAwal, int tanggalAkhir) {
    clearScreen();
    banner();
    cout << "\n                     DAFTAR PELANGGAN ANTARA TANGGAL " << tanggalAwal << " SAMPAI " << tanggalAkhir << "\n";

    cout << "---------------------------------------------------------------------------\n";
    cout << setw(5) << left << "ID" 
         << setw(20) << left << "Nama Pelanggan" 
         << setw(10) << left << "Paket" 
         << setw(10) << left << "Tanggal" 
         << setw(10) << left << "Bulan" 
         << setw(10) << left << "Tahun" 
         << setw(10) << left << "Jam" 
         << setw(10) << left << "Status" 
         << endl;
    cout << "---------------------------------------------------------------------------\n";

    bool found = false; 
    for (int i = 0; i < jumlahPemesanan; i++) {
        if (tanggalPemesanan[i] >= tanggalAwal && tanggalPemesanan[i] <= tanggalAkhir) {
            cout << setw(5) << idPemesanan[i]
                 << setw(20) << namaPelanggan[i]
                 << setw(10) << pilihanPaket[i]
                 << setw(10) << "  " << tanggalPemesanan[i]
                 << setw(10) << getNamaBulan(bulanPemesanan[i])
                 << setw(10) << tahunPemesanan[i] // Tampilkan tahun
                 << setw(10) << jamPemesanan[i]
                 << setw(10) << statusPemesanan[i] << endl;
            found = true; // Set flag jika ada pemesanan yang ditemukan
        }
    }

    if (!found) {
        cout << "   Tidak ada pemesanan antara tanggal " << tanggalAwal << " dan " << tanggalAkhir << ".\n";
    }

    cout << "\n   Tekan enter untuk kembali";
    cin.ignore();
    cin.get();
}

void memeriksaJadwal() {
    clearScreen();
    banner();
    cout << "\n   MEMERIKSA JADWAL\n";
    int pilihan = getUserChoice1();

    switch (pilihan) {
        case 1: {
            int tanggal;
            clearScreen();
            banner();
            cout << "\n   CARI BEDASARKAN TANGGAL\n";
            cout << "\n";
            cout << "   Masukkan tanggal yang ingin diperiksa (1-31): ";
            cin >> tanggal;

            cariPemesananBerdasarkanTanggal(tanggal);
            clearScreen();
            banner();
            break;
        }
        case 2: {
            int tanggalAwal, tanggalAkhir;
            clearScreen();
            banner();
            cout << "\n   CARI BEDASARKAN JANGKA WAKTU\n";
            cout << "\n";
            cout << "   Masukkan tanggal awal (1-31): ";
            cin >> tanggalAwal;
            cout << "   Masukkan tanggal akhir (1-31): ";
            cin >> tanggalAkhir;

            cariPemesananBerdasarkanJangkaWaktu(tanggalAwal, tanggalAkhir);
            clearScreen();
            banner();
            break;
        }
        case 3:
            perbaruiStatus();
            break;
        case 4:
            clearScreen();
            banner();
            cout << "Kembali ke menu sebelumnya..." << endl;
            break;
        default:
            break;
    }
}

void perbaruiStatus() {
    clearScreen();
    banner();
    cout << "\n   PERBARUI STATUS PEMESANAN\n\n";
    tampilkanPemesanan();

    int pilihan;
    cout << "\n";
    cout << "+-------------------------------------------------------------------------+\n";
    cout << "|      1. > Selesai     |      2. > Dibatalkan     |     3. > Kembali     |\n";
    cout << "+-------------------------------------------------------------------------+\n";
    cout << "\n";
    cout << "   Masukkan pilihan Anda (1/3): ";
    
    while (!(cin >> pilihan) || !validateInput(pilihan, 1, 3)) {
        cout << "   Input tidak valid. Masukkan pilihan yang benar: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (pilihan == 1 || pilihan == 2) {
        string id;
        cout << "   Masukkan ID Pemesanan yang ingin diubah statusnya: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < jumlahPemesanan; i++) {
            if (idPemesanan[i] == id) {
                statusPemesanan[i] = (pilihan == 1) ? "Selesai" : "Dibatalkan";
                clearScreen();
                banner();
                cout << "\n";
                cout << "   Status pemesanan '" << namaPelanggan[i] << "' berhasil diubah menjadi " << statusPemesanan[i] << "!\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "   Pemesanan dengan ID tersebut tidak ditemukan.\n";
        }
    }
}

void panelPemesanan() {
    clearScreen();
    banner();
    int subPilihan;
    while (true) {
        cout << "\n                              DAFTAR PELANGGAN\n";
        tampilkanPemesanan();
        cout << "\n";
        cout << "+-------------------------------------------------------------------------+\n";
        cout << "|    1. > Tambah Pelanggan   |   2. > Periksa Jadwal   |   3. > Kembali   |\n";
        cout << "+-------------------------------------------------------------------------+\n";
        cout << "\n";
        cout << "   Masukkan pilihan Anda (1/2/3): ";

        if (!(cin >> subPilihan) || !validateInput(subPilihan, 1, 3)) {
            clearScreen();
            banner();
            cout << "\n   ** Pilihan tidak valid. Silakan coba lagi yaa!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (subPilihan) {
                case 1:
                    kelolaPemesanan();
                    break;
                case 2:
                    memeriksaJadwal();
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
