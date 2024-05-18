/*
Axandio Biyanatul Lizan - 2311102179
*/

#include <iostream>

using namespace std;

struct SearchResult {
    int* indices; // Array dinamis untuk menyimpan indeks
    int count;    // Jumlah elemen yang ditemukan
};

// Fungsi sequential search untuk mencari angka 4 dan mengembalikan indeksnya
void sequentialSearch(const int data[], int size, int target, SearchResult& result) {
    result.indices = new int[size]; // Alokasikan memori untuk array dinamis
    result.count = 0; // Inisialisasi jumlah elemen yang ditemukan

    for (int i = 0; i < size; i++) {
        if (data[i] == target) {
            result.indices[result.count++] = i; // Simpan indeks dan tingkatkan jumlah
        }
    }
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 4;
    SearchResult result;

    // Panggil fungsi sequentialSearch untuk menemukan angka 4
    sequentialSearch(data, size, target, result);

    cout << "=-=-=-= Find Number Index =-=-=-=" << endl;
    cout << "Data = ";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "Angka " << target << " ditemukan pada indeks ke ";
    for (int i = 0; i < result.count; i++) {
        cout << result.indices[i];
        if (i != result.count - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    // Membersihkan memori yang dialokasikan
    delete[] result.indices;

    return 0;
}
