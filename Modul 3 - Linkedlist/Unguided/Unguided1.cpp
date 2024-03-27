/*
By Axandio Biyanatul Lizan - 2311102179
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node {
    string nama;
    int usia;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertDepan(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    void insertBelakang(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertTengah(string nama, int usia, string namaSebelum) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        Node* current = head;
        while (current != nullptr && current->nama != namaSebelum) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Data " << namaSebelum << " tidak ditemukan." << endl;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void hapus(string nama) {
        if (head == nullptr) {
            cout << "List kosong!" << endl;
            return;
        }
        if (head->nama == nama) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->nama != nama) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "Data " << nama << " tidak ditemukan." << endl;
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    void update(string oldNama, string newNama) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama == oldNama) {
                current->nama = newNama;
                return;
            }
            current = current->next;
        }
        cout << "Data " << oldNama << " tidak ditemukan." << endl;
    }

    bool isEmpty() {
        return head == nullptr; // Check if head pointer is null (empty list)
    }

    void display() {
        Node* bantu = head;

        cout << left << setw(15) << "-Nama-" << right << setw(4) << "-Usia-" << endl; // Supaya rapi

        if (!isEmpty()) { // Use isEmpty function
            while (bantu != NULL) {
            cout << left << setw(15) << bantu->nama << right << setw(4) << bantu->usia << endl; // Supaya lurus di output
            bantu = bantu->next;
            }
            cout << endl;
        } else {
            cout << "ITS EMPTY!" << endl;
        }
    }

};

int main() {
    LinkedList list;

    // a. Insert data
    cout << "\n=-=-=-=-= Linked List Axan =-=-=-=-=-=" << endl;
    list.insertDepan("Karin", 19);
    list.insertDepan("Hoshino", 18);
    list.insertDepan("Akechi", 20);
    list.insertDepan("Yusuke", 19);
    list.insertDepan("Michael", 18);
    list.insertDepan("Jane", 20);
    list.insertDepan("John", 19);
    list.insertDepan("Axan", 19);
    list.display();

    // b. Hapus data Akechi
    cout << "=-=-=-=-= Hapus Data Akechi =-=-=-=-=" << endl;
    list.hapus("Akechi");
    list.display();

    // c. Tambahkan data Futaba 18 di antara John dan Jane
    cout << "=-=-=-=-= Tambah data Futaba 18 diantara John dan Jane =-=-=-=-=" << endl;
    list.insertTengah("Futaba", 18, "John");
    list.display();

    // d. Tambahkan data Igor 20 di awal
    cout << "=-=-=-=-= Tambahkan data Igor 20 di Awal =-=-=-=-=" << endl;
    list.insertDepan("Igor", 20);
    list.display();

    // e. Ubah data Michael menjadi Reyn 18
    cout << "=-=-=-=-= Ubah Data Michael Menjadi Reyn 18 =-=-=-=-=" << endl;
    list.update("Michael", "Reyn");
    list.display();

    // f. Tampilkan seluruh data (Hasil Akhir)
    cout << "=-=-=-=-= Hasil Akhir =-=-=-=-=-=" << endl;
    list.display();

    return 0;
}
