/*
Axandio Biyanatul Lizan - 2311102179
*/

#include <iostream>
#include <algorithm>

using namespace std;

// Struktur untuk menyimpan karakter dan indeksnya
struct CharIndex {
    char karakter;
    int indeks;
};

// Fungsi untuk melakukan binary search
int binarySearch(CharIndex arr[], int size, char x) {
    int kiri = 0, kanan = size - 1;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (arr[tengah].karakter == x)
            return tengah;
        if (arr[tengah].karakter < x)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    return -1;
}

int main() {
    string kalimat, hurufDicari;

    cout << "=-=-=-= Input Sentence =-=-=-=" << endl;
    cout << "Masukan Kalimat: ";
    getline(cin, kalimat);

    cout << "\n=-=-=-= Find a Letter in The Index =-=-=-=" << endl;
    cout << "Kalimat: " << kalimat << endl;

    cout << "Huruf yang akan dicari: ";
    cin >> hurufDicari;

    char huruf = hurufDicari[0];
    int length = kalimat.length();

    // Membuat array untuk menyimpan karakter dan indeksnya
    CharIndex* charIndexArray = new CharIndex[length];
    for (int i = 0; i < length; i++) {
        charIndexArray[i].karakter = kalimat[i];
        charIndexArray[i].indeks = i;
    }

    // Mengurutkan array berdasarkan karakter
    sort(charIndexArray, charIndexArray + length, [](CharIndex a, CharIndex b) {
        return a.karakter < b.karakter;
    });

    // Mencari huruf yang dicari
    int index = binarySearch(charIndexArray, length, huruf);
    int* resultIndices = new int[length];
    int resultCount = 0;

    // Jika huruf ditemukan, kita cari semua indeks kemunculannya
    if (index != -1) {
        int tempIndex = index;
        // Cari ke kiri
        while (tempIndex >= 0 && charIndexArray[tempIndex].karakter == huruf) {
            resultIndices[resultCount++] = charIndexArray[tempIndex].indeks;
            tempIndex--;
        }
        // Cari ke kanan
        tempIndex = index + 1;
        while (tempIndex < length && charIndexArray[tempIndex].karakter == huruf) {
            resultIndices[resultCount++] = charIndexArray[tempIndex].indeks;
            tempIndex++;
        }
    }

    // Mengurutkan indeks yang ditemukan
    sort(resultIndices, resultIndices + resultCount);

    // Menampilkan hasil
    if (resultCount > 0) {
        cout << "Huruf '" << huruf << "' ditemukan pada indeks ke: ";
        for (int i = 0; i < resultCount; i++) {
            cout << resultIndices[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
    }

    // Membersihkan memori
    delete[] charIndexArray;
    delete[] resultIndices;

    return 0;
}
