#ifndef PEMESANAN_H
#define PEMESANAN_H

#include <string>

using namespace std;

const int MAX_PEMESANAN = 100;

extern int jumlahPemesanan;
extern string idPemesanan[MAX_PEMESANAN];
extern string namaPelanggan[MAX_PEMESANAN];
extern string pilihanPaket[MAX_PEMESANAN];
extern int hargaPaket[MAX_PEMESANAN];

void panelPemesanan();
void kelolaPemesanan();
void memeriksaJadwal();
void perbaruiStatus();

#endif 
