#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

// Node untuk Linked List
struct NodeMataUang {
    string namaMataUang;
    double nilaiTukar;
    NodeMataUang* berikutnya;
};

class DaftarMataUang {
private:
    NodeMataUang* kepala;

public:
    DaftarMataUang() : kepala(nullptr) {}

    void tambahMataUang(string nama, double nilai) {
        NodeMataUang* nodeBaru = new NodeMataUang{nama, nilai, nullptr};
        if (!kepala) {
            kepala = nodeBaru;
        } else {
            NodeMataUang* sementara = kepala;
            while (sementara->berikutnya) {
                sementara = sementara->berikutnya;
            }
            sementara->berikutnya = nodeBaru;
        }
    }

    double dapatkanNilaiTukar(string nama) {
        NodeMataUang* sementara = kepala;
        while (sementara) {
            if (sementara->namaMataUang == nama) {
                return sementara->nilaiTukar;
            }
            sementara = sementara->berikutnya;
        }
        return -1; // Jika tidak ditemukan
    }

    void tampilkanMataUang() {
        NodeMataUang* sementara = kepala;
        while (sementara) {
            cout << "Mata Uang: " << sementara->namaMataUang << ", Nilai Tukar: " << sementara->nilaiTukar << endl;
            sementara = sementara->berikutnya;
        }
    }
};

int main() {
    DaftarMataUang daftarMataUang;
    stack<string> riwayatKonversi;
    queue<string> antrianKonversi;

    // Menambahkan beberapa mata uang ke linked list
    daftarMataUang.tambahMataUang("USD", 1.0);
    daftarMataUang.tambahMataUang("EUR", 0.85);
    daftarMataUang.tambahMataUang("JPY", 110.0);

    int pilihan;
    string dariMataUang, keMataUang;
    double jumlah, nilaiDari, nilaiKe, jumlahTerkonversi;

    do {
        cout << "Menu Konverter Mata Uang:\n";
        cout << "1. Tambah Mata Uang\n";
        cout << "2. Tampilkan Mata Uang\n";
        cout << "3. Konversi Mata Uang\n";
        cout << "4. Tampilkan Riwayat Konversi\n";
        cout << "5. Tambah ke Antrian Konversi\n";
        cout << "6. Proses Antrian Konversi\n";
        cout << "7. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama mata uang: ";
                cin >> dariMataUang;
                cout << "Masukkan nilai tukar: ";
                cin >> nilaiDari;
                daftarMataUang.tambahMataUang(dariMataUang, nilaiDari);
                break;

            case 2:
                daftarMataUang.tampilkanMataUang();
                break;

            case 3:
                cout << "Masukkan mata uang asal: ";
                cin >> dariMataUang;
                cout << "Masukkan mata uang tujuan: ";
                cin >> keMataUang;
                cout << "Masukkan jumlah: ";
                cin >> jumlah;
                nilaiDari = daftarMataUang.dapatkanNilaiTukar(dariMataUang);
                nilaiKe = daftarMataUang.dapatkanNilaiTukar(keMataUang);
                if (nilaiDari != -1 && nilaiKe != -1) {
                    jumlahTerkonversi = (jumlah / nilaiDari) * nilaiKe;
                    cout << "Jumlah Terkonversi: " << jumlahTerkonversi << " " << keMataUang << endl;
                    riwayatKonversi.push(dariMataUang + " ke " + keMataUang + ": " + to_string(jumlah) + " -> " + to_string(jumlahTerkonversi));
                } else {
                    cout << "Mata uang tidak valid!" << endl;
                }
                break;

            case 4:
                while (!riwayatKonversi.empty()) {
                    cout << riwayatKonversi.top() << endl;
                    riwayatKonversi.pop();
                }
                break;

            case 5:
                cout << "Masukkan mata uang asal: ";
                cin >> dariMataUang;
                cout << "Masukkan mata uang tujuan: ";
                cin >> keMataUang;
                cout << "Masukkan jumlah: ";
                cin >> jumlah;
                antrianKonversi.push(dariMataUang + " ke " + keMataUang + ": " + to_string(jumlah));
                break;

            case 6:
                while (!antrianKonversi.empty()) {
                    string konversi = antrianKonversi.front();
                    antrianKonversi.pop();
                    cout << "Memproses: " << konversi << endl;
                }
                break;

            case 7:
                cout << "Keluar..." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 7);

    return 0;
}
