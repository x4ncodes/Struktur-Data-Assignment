/*
Axandio Biyanatul Lizan - 2311102179
*/

#include <iostream>
#include <set>
#include <cctype>

using namespace std;

struct VocalData {
    int* indices; // Array dinamis untuk menyimpan indeks huruf vokal
    int count;    // Jumlah huruf vokal yang ditemukan
};

// Fungsi untuk memeriksa apakah sebuah karakter adalah huruf vokal
bool isVocal(char ch) {
    ch = tolower(ch); // Mengubah huruf menjadi huruf kecil untuk mempermudah pengecekan
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

// Fungsi sequential search untuk menemukan huruf vokal dan mengisi data dalam VowelData
void sequentialSearchVocals(const string& kalimat, set<char>& vocalsFound, VocalData& vocalData) {
    int length = kalimat.length();
    vocalData.indices = new int[length]; // Alokasikan memori untuk array dinamis
    vocalData.count = 0; // Inisialisasi jumlah huruf vokal

    for (int i = 0; i < length; i++) {
        if (isVocal(kalimat[i])) {
            vocalsFound.insert(kalimat[i]);
            vocalData.indices[vocalData.count++] = i; // Simpan indeks dan tingkatkan jumlah
        }
    }
}

int main() {
    string kalimat;
    cout << "=-=-=-= Input Sentence =-=-=-=" << endl;
    cout << "Masukan Kalimat: ";
    getline(cin, kalimat);

    cout << "\n=-=-=-= Find Letter's Vocal =-=-=-=" << endl;
    cout << "Kalimat: " << kalimat << endl;

    set<char> vocalsFound; // Set untuk menyimpan huruf vokal unik yang ditemukan
    VocalData vocalData;   // Struct untuk menyimpan data huruf vokal

    // Panggil fungsi sequentialSearchVowels untuk menemukan huruf vokal
    sequentialSearchVocals(kalimat, vocalsFound, vocalData);

    cout << "Pada kalimat di atas memiliki " << vocalData.count << " huruf vokal yaitu: ";
    for (auto it = vocalsFound.begin(); it != vocalsFound.end(); ++it) {
        if (it != vocalsFound.begin()) {
            cout << ", ";
        }
        cout << *it;
    }
    cout << endl;

    cout << "Huruf vokal terdapat pada indeks ke: ";
    for (int i = 0; i < vocalData.count; i++) {
        cout << vocalData.indices[i];
        if (i != vocalData.count - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    // Membersihkan memori yang dialokasikan
    delete[] vocalData.indices;

    return 0;
}
