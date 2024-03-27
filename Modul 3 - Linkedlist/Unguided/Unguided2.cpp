#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Node {
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
public:
    Node* head;
    Node* tail;

    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertDepan(string namaProduk, int harga) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        else
            tail = newNode;
        head = newNode;
    }

    void insertBelakang(string namaProduk, int harga) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->next = nullptr;
        newNode->prev = tail;
        if (tail != nullptr)
            tail->next = newNode;
        else
            head = newNode;
        tail = newNode;
    }

    void insertTengah(string namaProduk, int harga, string namaSebelum) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        Node* current = head;
        while (current != nullptr && current->namaProduk != namaSebelum) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Produk " << namaSebelum << " tidak ditemukan." << endl;
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr)
            current->next->prev = newNode;
        else
            tail = newNode;
        current->next = newNode;
    }

    void hapus(string namaProduk) {
        Node* current = head;
        while (current != nullptr && current->namaProduk != namaProduk) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Produk " << namaProduk << " tidak ditemukan." << endl;
            return;
        }
        if (current == head) {
            head = current->next;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;
        } else if (current == tail) {
            tail = current->prev;
            tail->next = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        cout << "Produk " << namaProduk << " berhasil dihapus." << endl;
    }

    void update(string namaProdukLama, string namaProdukBaru, int hargaBaru) {
        Node* current = head;
        while (current != nullptr && current->namaProduk != namaProdukLama) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Produk " << namaProdukLama << " tidak ditemukan." << endl;
            return;
        }
        current->namaProduk = namaProdukBaru;
        current->harga = hargaBaru;
        cout << "Produk " << namaProdukLama << " berhasil diupdate menjadi " << namaProdukBaru << " dengan harga " << hargaBaru << endl;
    }

    void hapusUrutanTertentu(int urutan) {
        if (head == nullptr) {
            cout << "List kosong!" << endl;
            return;
        }

        Node* current = head;
        for (int i = 1; current != nullptr && i < urutan; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Urutan " << urutan << " tidak ditemukan." << endl;
            return;
        }

        if (current == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
        } else if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        cout << "Produk pada urutan " << urutan << " berhasil dihapus." << endl;
    }

    void hapusSeluruhData() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "Seluruh data berhasil dihapus." << endl;
    }

    void insertUrutanTertentu(string namaProduk, int harga, int urutan) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;

        if (urutan == 1) {
            insertDepan(namaProduk, harga);
            return;
        }

        Node* current = head;
        for (int i = 1; current != nullptr && i < urutan - 1; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Urutan " << urutan << " tidak ditemukan." << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr)
            current->next->prev = newNode;
        else
            tail = newNode;
        current->next = newNode;
    }

    void tampilkanData() {
        Node* current = head;
        while (current != nullptr) {
            cout << setw(20) << left << current->namaProduk << setw(10) << left << current->harga << endl;
            current = current->next;
        }
    }
};

int main() {
    DoubleLinkedList tokoSkincare;

    // Menambahkan data awal
    tokoSkincare.insertBelakang("Originote", 60000);
    tokoSkincare.insertBelakang("Somethinc", 150000);
    tokoSkincare.insertBelakang("Skintific", 100000);
    tokoSkincare.insertBelakang("Wardah", 50000);
    tokoSkincare.insertBelakang("Hanasui", 30000);

    while (true) {
        cout << "=-=-=-=-= Daftar Skincare Axan =-=-=-=-=" << endl;
        cout << setw(20) << left << "Nama Produk" << setw(10) << left << "Harga" << endl;
        tokoSkincare.tampilkanData();
        cout << endl;
        cout << "Toko Skincare Purwokerto Axan" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        int pilihan;
        cout << "\nPilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string namaProduk;
                int harga;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga produk: ";
                cin >> harga;
                cout << "Masukan urutan untuk data baru: ";
                int urutan;
                cin >> urutan;
                tokoSkincare.insertUrutanTertentu(namaProduk, harga, urutan);
                break;
            }
            case 2: {
                string namaProduk;
                cout << "Masukkan nama produk yang akan dihapus: ";
                cin >> namaProduk;
                tokoSkincare.hapus(namaProduk);
                break;
            }
            case 3: {
                string namaProdukLama, namaProdukBaru;
                int hargaBaru;
                cout << "Masukkan nama produk yang akan diupdate: ";
                cin >> namaProdukLama;
                cout << "Masukkan nama produk baru: ";
                cin >> namaProdukBaru;
                cout << "Masukkan harga baru: ";
                cin >> hargaBaru;
                tokoSkincare.update(namaProdukLama, namaProdukBaru, hargaBaru);
                break;
            }
            case 4: {
                string namaProduk, namaSebelum;
                int harga;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga produk: ";
                cin >> harga;
                cout << "Masukkan nama produk sebelumnya: ";
                cin >> namaSebelum;
                tokoSkincare.insertTengah(namaProduk, harga, namaSebelum);
                break;
            }
            case 5: {
                int urutan;
                cout << "Masukkan urutan produk yang akan dihapus: ";
                cin >> urutan;
                tokoSkincare.hapusUrutanTertentu(urutan);
                break;
            }
            case 6: {
                tokoSkincare.hapusSeluruhData();
                break;
            }
            case 7: {
                cout << "=-=-=-=-= Daftar Skincare Axan =-=-=-=-=" << endl;
                cout << setw(20) << left << "Nama Produk" << setw(10) << left << "Harga" << endl;
                tokoSkincare.tampilkanData();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
            }
        }
    }

    return 0;
}

