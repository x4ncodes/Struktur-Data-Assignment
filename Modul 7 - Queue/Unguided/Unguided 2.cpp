/*
Axandio Biyanatul Lizan - 2311102179
*/

#include <iostream>
using namespace std;

// Struktur Mahasiswa yang digunakan untuk menyimpan Nama dan NIM
struct Mahasiswa {
    string nama;
    long long int nim;
};

// Node untuk menyimpan data Mahasiswa dan pointer ke Node berikutnya
struct Node {
    Mahasiswa data;
    Node* next;
};

class Queue {
private:
    Node* front; // Pointer elemen terdepan dalam antrian
    Node* back;  // Pointer elemen terbelakang dalam antrian
public:
    Queue() {
        front = nullptr;
        back = nullptr;
    }

    // Fungsi untuk memeriksa apakah antrian kosong atau tidak
    bool isEmpty() {
        return front == nullptr;
    }

    // Fungsi untuk menambahkan Mahasiswa ke antrian
    void enqueueAntrian(string nama, long long int nim) {
        Node* newNode = new Node;
        newNode->data.nama = nama;
        newNode->data.nim = nim;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }

    // Fungsi untuk mengeluarkan Mahasiswa dari antrian
    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Fungsi untuk menghitung jumlah Mahasiswa dalam antrian
    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Fungsi untuk menghapus semua Mahasiswa dari antrian
    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    // Fungsi untuk menampilkan isi antrian
    void viewQueue() {
        cout << "Data Antrian Mahasiswa:" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". Nama: " << current->data.nama << ", NIM: " << current->data.nim << endl;
            current = current->next;
            index++;
        }
    }
};

int main() {
    Queue queue;
    cout << "\n=-=-=-=-= Antrian Mahasiswa Axan =-=-=-=-=\n" << endl;
    cout << "--- Tambah Antrian Mahasiswa ---" << endl;
    queue.enqueueAntrian("Axandio", 2311102179);
    queue.enqueueAntrian("Biyanatul", 3111021792);
    queue.enqueueAntrian("Lizan", 1110217923);
    queue.enqueueAntrian("Abel", 1102179231);
    queue.viewQueue();
    cout << "Jumlah antrian: " << queue.countQueue() << endl;
    cout << "\n--- Hapus Antrian Mahasiswa ---\n";
    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian: " << queue.countQueue() << endl;
    cout << "\n--- Hapus Semua Antrian --- \n";
    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian: " << queue.countQueue() << endl;
    cout << "\n";

    return 0;
}