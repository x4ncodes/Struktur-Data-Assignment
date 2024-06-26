/*
Axandio Biyanatul Lizan - 2311102179
*/

#include <iostream>
using namespace std;

// Node untuk menyimpan data & pointer ke Node berikutnya
struct Node {
    string data;
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

    // Fungsi untuk menambahkan pelanggan ke antrian
    void enqueueAntrian(string data) {
        Node* newNode = new Node; // Membuat node baru
        newNode->data = data; // Mengisi node baru dengan data yang diberikan
        newNode->next = nullptr; // Menetapkan pointer next dari node baru ke nullptr, karena node ini menjadi node terakhir dalam antrian.
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }

    // Fungsi untuk mengeluarkan pelanggan dari antrian
    void dequeueAntrian() {
        if (isEmpty()) { // Mengecek apakah antrian kosong atau tidak
            cout << "Antrian kosong!" << endl;
            return;
        }
        Node* temp = front; // Menyimpan pointer dari node paling depan ke 'temp'
        front = front->next; // Menunjuk node berikutnya untuk menjadi front
        delete temp;
    }

    // Fungsi untuk menghitung jumlah pelanggan dalam antrian
    int countQueue() {
        int count = 0; // Inisialisasi nilai awal 0
        Node* current = front; // Menginisialisasi pointer current dengan front (elemen/node pertama).
        while (current != nullptr) { 
            count++;
            current = current->next;
        }
        return count;
    }

    // Fungsi untuk menghapus semua pelanggan dari antrian
    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    // Fungsi untuk menampilkan isi antrian
    void viewQueue() {
        cout << "Data Antrian Teller:" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". " << current->data << endl;
            current = current->next;
            index++;
        }
    }
};

int main() {
    Queue queue;
    cout << "=-=-=-=-= Antrian Teller Axan =-=-=-=-=\n" << endl;
    cout << "--- Add Queue Teller ---" << endl;
    queue.enqueueAntrian("Andi");
    queue.enqueueAntrian("Maya");
    queue.viewQueue();
    cout << "Jumlah antrian: " << queue.countQueue() << endl;
    cout << "\n--- Removal Queue Teller ---\n";
    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian: " << queue.countQueue() << endl;
    cout << "\n--- Remove All Queue --- \n";
    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian: " << queue.countQueue() << endl;
    cout << "\n";

    return 0;
}