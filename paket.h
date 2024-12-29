#ifndef PAKET_H
#define PAKET_H

#include <string>
#include "utils.h"

using namespace std;

const int MAX_PAKET = 100;

void tampilkanPaket();
bool isIDUsed(const string& id);
void tambahPaket();
void updatePaket();
void panelPaket();
double getHargaPaketByID(const string& id);

extern string paketID[MAX_PAKET];
extern string paketNama[MAX_PAKET];
extern double paketHarga[MAX_PAKET];
extern string paketDeskripsi[MAX_PAKET];
extern bool paketAktif[MAX_PAKET];
extern int jumlahPaket;

#endif 
