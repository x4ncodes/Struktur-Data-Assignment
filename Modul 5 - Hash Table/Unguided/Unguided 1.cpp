/*
Axandio Biyanatul Lizan - 2311102179
*/
#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Struktur data untuk mahasiswa
struct Mahasiswa {
    string nim;
    int nilai;
    string nama;
};

// Hash table
class HashTable {
private:
    static const int tableSize = 10;
    list<Mahasiswa> table[tableSize];

    // Fungsi hash
    int hashFunction(string nim) {
        int sum = 0;
        for (char ch : nim) {
            sum += ch;
        }
        return sum % tableSize;
    }

public:
    // Menambah data mahasiswa
    void tambahData(string nim, int nilai, string nama) {
        int index = hashFunction(nim);
        Mahasiswa mahasiswa = {nim, nilai, nama};
        table[index].push_back(mahasiswa);
    }

    // Menghapus data mahasiswa berdasarkan NIM
    void hapusData(string nim) {
        int index = hashFunction(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->nim == nim) {
                table[index].erase(it);
                break;
            }
        }
    }

    // Mencari data mahasiswa berdasarkan NIM
    Mahasiswa* cariByNIM(string nim) {
        int index = hashFunction(nim);
        for (auto& mahasiswa : table[index]) {
            if (mahasiswa.nim == nim) {
                return &mahasiswa;
            }
        }
        return nullptr;
    }

    // Mencari data mahasiswa berdasarkan rentang nilai (80 - 90)
    vector<Mahasiswa> cariByRentangNilai(int min, int max) {
        vector<Mahasiswa> hasil;
        for (int i = 0; i < tableSize; ++i) {
            for (auto& mahasiswa : table[i]) {
                if (mahasiswa.nilai >= min && mahasiswa.nilai <= max) {
                    hasil.push_back(mahasiswa);
                }
            }
        }
        return hasil;
    }
};

int main() {
    HashTable hashTable;
    int pilihan;
    string nim;
    int nilai;
    string nama;

    do {
        cout << "\n=-=-=-= Selamat Datang di Program Hash Table Mahasiswa Axan!!! =-=-=-=\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cari Data Mahasiswa berdasarkan NIM\n";
        cout << "4. Cari Data Mahasiswa berdasarkan Rentang Nilai (80-90)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n--- Tambah Data Mahasiswa ---" << endl;
                cout << "Silahkan tambah data mahasiswa dengan mengisi format dibawah!\n";
                cout << "Masukan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukan NIM Mahasiswa: ";
                cin >> nim;
                cout << "Masukan Nilai Mahasiswa: ";
                cin >> nilai;
                hashTable.tambahData(nim, nilai, nama);
                cout << "Data baru telah ditambahkan dengan Nama " << nama << " [" << nim << "] dengan perolehan Nilai " << nilai << "!\n";
                break;
            case 2:
                cout << "\n--- Hapus Data Mahasiswa ---" << endl;
                cout << "Silahkan masukan NIM Mahasiswa yang akan dihapus datanya dibawah ini!\n";
                cout << "Masukan NIM Mahasiswa: ";
                cin >> nim;
                if (Mahasiswa* mahasiswa = hashTable.cariByNIM(nim)) {
                    cout << "Data dengan nama " << mahasiswa->nama << " [" << mahasiswa->nim << "] dengan perolehan Nilai " << mahasiswa->nilai << " telah dihapus!\n";
                    hashTable.hapusData(nim);
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            case 3:
                cout << "\n--- Cari Data Mahasiswa Berdasarkan NIM ---" << endl;
                cout << "Silahkan masukan NIM Mahasiswa untuk mencari data!\n";
                cout << "Masukan NIM Mahasiswa: ";
                cin >> nim;
                if (Mahasiswa* mahasiswa = hashTable.cariByNIM(nim)) {
                    cout << "Data dengan " << nim << " ditemukan atas nama " << mahasiswa->nama << " dengan nilai " << mahasiswa->nilai << endl;
                } else {
                    cout << "Data tidak ditemukan.\n";
                }
                break;
            case 4:
                cout << "\n--- Data Mahasiswa Range Nilai 80-90 ---" << endl;
                cout << "Mahasiswa dengan nilai antara 80 - 90:\n";
                {
                    vector<Mahasiswa> mahasiswas = hashTable.cariByRentangNilai(80, 90);
                    for (const auto& mahasiswa : mahasiswas) {
                        cout << "Nama: " << mahasiswa.nama << ", NIM: " << mahasiswa.nim << ", Nilai: " << mahasiswa.nilai << endl;
                    }
                }
                break;
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}
