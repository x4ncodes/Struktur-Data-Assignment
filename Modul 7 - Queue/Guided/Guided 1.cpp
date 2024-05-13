/*
Axandio Biyanatul Lizan - 2311102179
*/

#include <iostream>
using namespace std;

const int MAX_QUEUE = 5; // Kapasitas maksimal antrian
int front = 0; // Indeks elemen terdepan dalam antrian
int back = 0; // Indeks elemen berikutnya yang tersedia dalam antrian
string queueTeller[MAX_QUEUE]; // Array untuk menyimpan nama pelanggan

// Fungsi untuk memeriksa apakah antrian penuh
bool isFull() {
    return back == MAX_QUEUE;
}

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty() {
    return back == 0;
}

// Fungsi untuk menambahkan pelanggan ke antrian
void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian penuh!" << endl;
        return; // Keluar dari fungsi jika antrian penuh
    }

    if (isEmpty()) { // Kondisi awal saat antrian kosong
        queueTeller[0] = data; // Tambahkan data ke elemen pertama
        front++;
        back++;
        return;
    }

    // Kondisi antrian tidak kosong
    queueTeller[back] = data; // Tambahkan data ke elemen berikutnya yang tersedia
    back++;
}

// Fungsi untuk mengeluarkan pelanggan dari antrian
void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
        return; // Keluar dari fungsi jika antrian kosong
    }

    // Geser semua elemen ke depan satu posisi
    for (int i = 0; i < back - 1; i++) {
        queueTeller[i] = queueTeller[i + 1];
    }

    back--; // Perbarui indeks elemen berikutnya yang tersedia
}

// Fungsi untuk menghitung jumlah pelanggan dalam antrian
int countQueue() {
    return back;
}

// Fungsi untuk menghapus semua pelanggan dari antrian
void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
        return; // Keluar dari fungsi jika antrian kosong
    }

    // Set semua elemen ke string kosong
    for (int i = 0; i < back; i++) {
        queueTeller[i] = "";
    }

    back = 0; // Reset indeks elemen berikutnya yang tersedia
    front = 0; // Reset indeks elemen terdepan
}

// Fungsi untuk menampilkan isi antrian
void viewQueue() {
    cout << "Data Antrian Teller:" << endl;

    for (int i = 0; i < MAX_QUEUE; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (Kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian: " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian: " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian: " << countQueue() << endl;

    return 0;
}