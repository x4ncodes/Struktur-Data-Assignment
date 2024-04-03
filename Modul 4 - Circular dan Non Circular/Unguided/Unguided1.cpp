/*
Axandio Biyanatul Lizan - 2311102179
*/

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;

void insertDepan(string nama, string nim) {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = head;
    head = newNode;
    cout << "Yeyyy, Data " << nama << " dengan NIM " << nim << " berhasil ditambahkan!" << endl;
}

void insertTengah(string nama, string nim, int posisi) {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nim = nim;
    Mahasiswa* temp = head;
    for (int i = 1; i < posisi - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Yeyyy, Data " << nama << " dengan NIM " << nim << " berhasil ditambahkan pada posisi " << posisi << "!" << endl;
}

void insertAkhir(string nama, string nim) {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        cout << "Yeayyy, Data " << nama << " dengan NIM " << nim << " berhasil ditambahkan!" << endl;
        return;
    }
    Mahasiswa* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    cout << "Yeayyy, Data " << nama << " dengan NIM " << nim << " berhasil ditambahkan!" << endl;
}

void changeDepan(string nama, string nim) {
    if (head == NULL) {
        cout << "Linked List kosong!" << endl;
        return;
    }
    cout << "Data dengan nama " << head->nama << " nim " << head->nim << " berhasil diperbarui menjadi " << nama << " " << nim << ", Yeayyy!" << endl;
    head->nama = nama;
    head->nim = nim;
}

void changeTengah(string nama, string nim, int posisi) {
    if (head == NULL) {
        cout << "Linked List kosong!" << endl;
        return;
    }
    Mahasiswa* temp = head;
    for (int i = 1; i < posisi; i++) {
        temp = temp->next;
    }
    cout << "Data dengan nama " << temp->nama << " nim " << temp->nim << " pada posisi " << posisi << " berhasil diperbarui menjadi " << nama << " " << nim << ", Yeayyy!" << endl;
    temp->nama = nama;
    temp->nim = nim;
}

void changeAkhir(string nama, string nim) {
    if (head == NULL) {
        cout << "Linked List kosong!" << endl;
        return;
    }
    Mahasiswa* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    cout << "Data dengan nama " << temp->nama << " nim " << temp->nim << " berhasil diperbarui menjadi " << nama << " " << nim << ", Yeayyy!" << endl;
    temp->nama = nama;
    temp->nim = nim;
}

void deleteDepan() {
    if (head == NULL) {
        cout << "Linked List kosong!" << endl;
        return;
    }
    Mahasiswa* temp = head;
    head = head->next;
    delete temp;
    cout << "Yessss! Data " << temp->nama << " dengan NIM " << temp->nim << " berhasil dihapus!" << endl;
}

void deleteAkhir() {
    if (head == NULL) {
        cout << "Linked List kosong!" << endl;
        return;
    }
    Mahasiswa* temp = head;
    Mahasiswa* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        head = NULL;
    }
    cout << "Yessss! Data " << temp->nama << " dengan NIM " << temp->nim << " berhasil dihapus!" << endl;
    delete temp;
}

void deleteTengah(int posisi) {
    if (head == NULL) {
        cout << "Linked List kosong!" << endl;
        return;
    }
    Mahasiswa* temp = head;
    Mahasiswa* prev = NULL;
    
    if (posisi == 1) {
        head = head->next;
        cout << "Yes! Data " << temp->nama << " dengan NIM " << temp->nim << " pada posisi " << posisi << " berhasil dihapus!" << endl;
        delete temp;
        return;
    }

    for (int i = 1; i < posisi; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == NULL) {
            cout << "Posisi " << posisi << " tidak valid!" << endl;
            return;
        }
    }
    
    prev->next = temp->next;
    cout << "Yes! Data " << temp->nama << " dengan NIM " << temp->nim << " pada posisi " << posisi << " berhasil dihapus!" << endl;
    delete temp;
}

void deleteList() {
    if (head == NULL) {
        cout << "Linked List kosong!" << endl;
        return;
    }
    while (head != NULL) {
        Mahasiswa* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Linked List berhasil dihapus!" << endl;
}

void showList() {
    if (head == NULL) {
        cout << "Linked List kosong!" << endl;
        return;
    }
    cout << "Data Mahasiswa & NIM" << endl;
    cout << "\nNama Mahasiswa\t\tNIM" << endl;
    Mahasiswa* temp = head;
    while (temp != NULL) {
        cout << temp->nama << "\t\t\t" << temp->nim << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    string nama, nim;
    int posisi;
    do {
        cout << "\n=-=-=-= SELAMAT DATANG DI AXAN NODE GUYS =-=-=-=" << endl;
        cout << "1. Insert Depan" << endl;
        cout << "2. Insert Tengah" << endl;
        cout << "3. Insert Akhir" << endl;
        cout << "4. Change Depan" << endl;
        cout << "5. Change Tengah" << endl;
        cout << "6. Change Akhir" << endl;
        cout << "7. Delete Depan" << endl;
        cout << "8. Delete Akhir" << endl;
        cout << "9. Delete Tengah" << endl;
        cout << "10. Delete List" << endl;
        cout << "11. Show List" << endl;
        cout << "0. Exit/Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                cout << "=-=-=-= Insert Depan =-=-=-=" << endl;
                cout << "Masukan Nama: ";
                cin >> nama;
                cout << "Masukan NIM: ";
                cin >> nim;
                insertDepan(nama, nim);
                break;
            case 2:
                cout << "=-=-=-= Insert Tengah =-=-=-=" << endl;
                cout << "Masukan Nama: ";
                cin >> nama;
                cout << "Masukan NIM: ";
                cin >> nim;
                cout << "Masukan Posisi: ";
                cin >> posisi;
                insertTengah(nama, nim, posisi);
                break;
            case 3:
                cout << "=-=-=-= Insert Akhir =-=-=-=" << endl;
                cout << "Masukan Nama: ";
                cin >> nama;
                cout << "Masukan NIM: ";
                cin >> nim;
                insertAkhir(nama, nim);
                break;
            case 4:
                cout << "=-=-=-= Change Depan =-=-=-=" << endl;
                cout << "Masukan New Nama: ";
                cin >> nama;
                cout << "Masukan New NIM: ";
                cin >> nim;
                changeDepan(nama, nim);
                break;
            case 5:
                cout << "=-=-=-= Change Tengah =-=-=-=" << endl;
                cout << "Masukan New Nama: ";
                cin >> nama;
                cout << "Masukan New NIM: ";
                cin >> nim;
                cout << "Masukan Posisi: ";
                cin >> posisi;
                changeTengah(nama, nim, posisi);
                break;
            case 6:
                cout << "=-=-=-= Change Akhir =-=-=-=" << endl;
                cout << "Masukan New Nama: ";
                cin >> nama;
                cout << "Masukan New NIM: ";
                cin >> nim;
                changeAkhir(nama, nim);
                break;
            case 7:
                cout << "=-=-=-= Delete Depan =-=-=-=" << endl;
                deleteDepan();
                break;
            case 8:
                cout << "=-=-=-= Delete Akhir =-=-=-=" << endl;
                deleteAkhir();
                break;
            case 9:
                cout << "=-=-=-= Delete Tengah =-=-=-=" << endl;
                cout << "Masukan Posisi: ";
                cin >> posisi;
                deleteTengah(posisi);
                break;
            case 10:
                cout << "=-=-=-= Delete List =-=-=-=" << endl;
                deleteList();
                break;
            case 11:
                cout << "=-=-=-= Show List =-=-=-=" << endl;
                showList();
                break;
            case 0:
                cout << "Yeyyyyy kamu berhasil! Jika puas dengan program ini jangan lupa mampir lagi yak!" << endl;
                break;
            default:
                cout << "Input Error/Invalid!" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
