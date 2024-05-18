/*
Axandio Biyanatul Lizan - 2311102179
*/
#include <iostream>

using namespace std;

int main() {
  // Jumlah data
  int n = 10;

  // Data yang akan dicari
  int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
  int cari = 10;
  int i;
  // Variabel untuk menandakan apakah data ditemukan
  bool ditemukan = false;

  // Algoritma Sequential Search
  for (i = 0; i < n; i++) {
    if (data[i] == cari) {
      ditemukan = true;
      break;
    }
  }

  // Menampilkan hasil pencarian
  cout << "\t Program Sequential Search Sederhana\n" << endl;
  cout << "Data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

  if (ditemukan) {
    cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
  } else {
    cout << cari << " tidak dapat ditemukan pada data." << endl;
  }

  return 0;
}