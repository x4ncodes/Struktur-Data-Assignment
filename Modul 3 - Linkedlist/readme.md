# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Axandio Biyanatul Lizan - 2311102179</p>

## Dasar Teori
Linked List adalah struktur data yang setiap itemnya dihubungkan satu sama lain dengan menggunakan pointer[2]. Struktur data ini mempunyai bentuk dasar dengan sifat data disisipkan ke dalam senarai melalui salah satu ujungnya[1].<br/>
1. Single Linked List <br/>
Single linked list atau biasa disebut linked list terdiri dari elemen-elemen individu, dimana masing masing dihubungkan dengan pointer tunggal. Masing-masing elemen terdiri dari dua bagian, yaitu sebuah data dan sebuah pointer yang disebut dengan pointer next. Elemen pada awal suatu list disebut head, dan elemen terakhir dari suatu list disebut tail[1]. 
![Single Linked List](Single_Linked_List.png) <br/>
2. Double Linked List <br/>
Elemen-elemen dihubungkan dengan dua pointer dalam satu elemen. Struktur ini menyebabkan list melintas baik ke depan maupun ke belakang. Masing-masing elemen pada double linked list terdiri dari tiga bagian, disamping data dan pointer next, masing-masing elemen dilengkapi dengan pointer prev yang menunjuk ke elemen sebelumnya. Double linked list dibentuk dengan menyusun sejumlah elemen sehingga pointer next menunjuk ke elemen yang mengikutinya dan pointer prev menunjuk ke elemen yang mendahuluinya[1]. <br/>
![Double Linked List](Double_Linked_list.png)
## Guided 

### 1. [Latihan Single Linked List]

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty() {
    return head == NULL;
}

// Tambah Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah List
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    
    return jumlah;
}

// Tambah Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
        return;
    }

    if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }

    Node *baru = new Node();
    baru->data = data;
    
    Node *bantu = head;
    int nomor = 1;
    
    while (nomor < posisi - 1) {
        bantu = bantu->next;
        nomor++;
    }
    
    baru->next = bantu->next;
    bantu->next = baru;
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty()) {
        cout << "List kosong!" << endl;
        return;
    }

    Node *hapus = head;
    
    if (head->next != NULL) {
        head = head->next;
    } else {
        head = tail = NULL;
    }
    
    delete hapus;
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty()) {
        cout << "List kosong!" << endl;
        return;
    }

    Node *hapus = tail;
    Node *bantu = head;
    
    if (head != tail) {
        while (bantu->next != tail) {
            bantu = bantu->next;
        }
        tail = bantu;
        tail->next = NULL;
    } else {
        head = tail = NULL;
    }
    
    delete hapus;
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
        return;
    }

    if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }

    Node *hapus, *bantu, *bantu2;
    int nomor = 1;
    
    bantu = head;
    
    while (nomor <= posisi) {
        if (nomor == posisi - 1) {
            bantu2 = bantu;
        }
        if (nomor == posisi) {
            hapus = bantu;
        }
        bantu = bantu->next;
        nomor++;
    }
    
    bantu2->next = bantu;
    delete hapus;
}

// Ubah Depan
void ubahDepan(int data) {
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
        return;
    }
    
    head->data = data;
}

// Ubah Tengah
void ubahTengah(int data, int posisi) {
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
        return;
    }

    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
        return;
    }

    if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }

    Node *bantu = head;
    int nomor = 1;

    while (nomor < posisi) {
        bantu = bantu->next;
        nomor++;
    }
    
    bantu->data = data;
}

// Ubah Belakang
void ubahBelakang(int data) {
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
        return;
    }

    tail->data = data;
}

// Hapus List
void clearList() {
    Node *bantu, *hapus;
    bantu = head;
    
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
        return;
    }

    while (bantu != NULL) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    
    cout << endl;
}

int main() {
    init();
    
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();

    return 0;
}
```
Kode C++ diatas merepresentasikan cara kerja dari single linked list. Terdapat beberapa prosedur yang menjelaskan mengenai Insert (menambahkan), Hapus, Ubah data pada linked list, tampil, init, function hitungList. Sebagai gambaran saya jelaskan cara kerja 2 prosedur dan 1 fungsi yaitu function hitung list, insert depan, dan juga hapus depan:  <br/>
a. Fungsi HitungList <br/>
Pertama, sebuah pointer hitung diinisialisasi dengan head, yang merupakan pointer ke node pertama dari linked list. Kemudian, variabel jumlah diinisialisasi dengan nilai 0 untuk menyimpan jumlah elemen. Kemudian program melakukan looping while dengan kondisi hitung != NULL dan pada jumlah akan bertambah 1 dan pointer hitung akan maju ke node berikutnya. Looping ini akan berhenti jika pointer hitung mencapai NULL. <br/>
b. Prosedur insertDepan <br/>
Pertama void insertDepan menggunakan paramater int data, kemudian membuat node baru dengan nilai 'data'. Program mengecek apakah linked list kosong menggunakan fungsi if isEmpty(). Jika kosong maka 'head' 'tail' diarahkan ke baru. jika isi maka 'baru' dihubungkan ke head, dan head diperbarui menjadi baru. <br/>
c. Prosedur hapusDepan <br/>
Fungsi pertama kali adalah mengecek apakah linked list kosong atau tidak, jika linked list kosong maka akan memunculkan pesan "List Kosong!" dan fungsi if berhenti. Jika tidak, pointer 'hapus' akan menginisialisasi head, kemudian head dipindahkan ke node berikutnya. Selanjutnya node yang telah dihapus 'hapus' dialokasikan dari memori 'delete'.<br/>


### 2. [Latihan Double Linked List]
```C++
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    bool pop() {
        if (head == nullptr) {
            return false;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        return true;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }

    return 0;
}
```
Pertama terdapat class 'node' yang digunakan untuk merepresentasikan sebuah node DoublyLinkedList. data pada class node digunakan untuk menyimpan data dari node, prev bertipe pointer Node* digunakan untuk menunjukkan ke node sebelumnya pada linkedlist. sedangkan next bertipe pointer Node* digunakan untuk menunjukkan ke node selanjutnya pada linked List. <br/>

Class DoublyLinkedList() diinisialisasi dengan mengatur head dan tail ke nullptr, menandakan bahwa linked list awalnya kosong. Procedure push(int data) digunakan untuk menambahkan node baru di awal linked list. Jika linked list kosong, head dan tail diatur ke node baru tersebut. Jika tidak, node baru tersebut dihubungkan ke head dan head diperbarui. function bool pop() menghapus node dari awal linked list. Jika linked list kosong, metode ini mengembalikan false. Jika tidak, node pertama dihapus, head diperbarui, dan pointer prev dari node baru head diatur ke nullptr. Function bool updateupdate(int oldData, int newData) memperbarui nilai data dari node dengan nilai oldData menjadi newData. Jika node dengan nilai oldData ditemukan dan diperbarui, metode mengembalikan true. Jika tidak ditemukan, metode mengembalikan false. Procedure deleteAll() menghapus semua node dari linked list dan membebaskan memori yang dialokasikan untuk setiap node. Setelah itu, head dan tail diatur kembali ke nullptr. Procedure display() digunakan untuk menampilkan semua nilai data dalam linked list, mulai dari head sampai tail. <br/>

pada Int main terdapat switch case untuk menampilkan menu (add, delete, update, display, clear data) dan juga terdapat looping/perulangan while (true) sehingga program akan berjalan terus menerus kecuali user exit dari program. <br/>

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:<br/> a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data Pertama yang dimasukkan adalah nama dan usia anda. <br/> b. Hapus data Akechi <br/> c. Tambahkan data berikut diantara John dan Jane : Futaba 18 <br/> d. Tambahkan data berikut diawal : Igor 20 <br/> e. Ubah data Michael menjadi : Reyn 18 <br/> f. Tampilkan seluruh data <br/> Tampilan poin A : <br/> 
![Soal JPG](Data_nama.png)
```C++
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

```
#### Output:
![Output JPG](Output_Unguided1.png)
![Output JPG](Output_Unguided1_2.png)

Kode diatas mendeklarasikan struct node dengan 3 tipe data yaitu string nama, int usia, dan pointer Node 'next'. kemudian terdapat class bernama linkedlist  dengan atribut public 'head' dengan definisi sebagai berikut : <br/>
- LinkedList() digunakan untuk menginisialisasi 'head' dengan 'nullptr', menandakan bahwa linked list awalnya kosong. <br/>
- void insertDepan(string nama, int usia) digunakan untuk menyisipkan data baru di awal linked list. Metode ini membuat node baru, mengisi data nama dan usia ke dalam node tersebut, dan kemudian mengatur 'next' node baru ke 'head'. 'head' kemudian diperbarui dengan node baru tersebut. <br/>
- insertBelakang(string nama, int usia) digunakan untuk menyisipkan data baru di akhir linked list. Metode ini melakukan iterasi melalui linked list hingga menemukan node terakhir, lalu menyisipkan node baru setelah node terakhir tersebut. <br/>
- insertTengah(string nama, int usia, string namaSebelum) digunakan untuk menyisipkan data baru setelah node dengan nama tertentu. Metode ini mencari node dengan nama yang diberikan, jika ditemukan, node baru akan disisipkan setelah node tersebut. <br/>
- hapus(string nama) digunakan untuk menghapus node dengan nama tertentu dari linked list. Metode ini mencari node dengan nama yang diberikan dan menghapusnya dari linked list. <br/>
- update(string oldNama, string newNama) digunakan untuk mengubah nama dari node dengan nama tertentu. Metode ini mencari node dengan nama yang diberikan dan menggantinya dengan nama baru. <br/>
- isEmpty() merupakan fungsi bantu yang mengembalikan 'true' jika linked list kosong (yaitu 'head' adalah 'nullptr') dan 'false' jika sebaliknya. <br/>
- display() digunakan untuk menampilkan seluruh data dalam linked list. Metode ini mencetak nama dan usia setiap node dalam format yang rapi ke layar. Jika linked list kosong, akan dicetak pesan "IS EMPTY!". <br/> <br/>
Kemudian pada int main, diawali dengan inisialisasi linked list dengan 'LinkedList List;'. Pertama program memasukan data kemudian menampilkan seluruh data, Kedua program menghapus data Akechi menggunakan 'list.hapus("Akechi");', Ketiga Program menambahkan data baru yaitu futaba diantara john dan jane dengan cara 'list.insertTengah("Futaba", 18, "John");' yang dapat diartikan sebagai menambahkan elemen baru dengan nama Futaba berusia 18 tahun setelah John, Keempat program menambahkan data baru igor 20 dengan cara 'list.insertDepan("Igor", 20);', Kelima Mengubah data michael menjadi reyn 18 dengan cara hanya mengubah nama michael menjadi ryan 'list.update("Michael", "Reyn");', Keenam program menampilkan seluruh hasil akhir.

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga. <br/> Case : <br/> 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific <br/> 2. Hapus produk Wardah <br/> 3. Update produk Hanasui menjadi Cleora dengan harga 55.000 <br> 4. Tampilan menu dan Tampilan Akhir seperti dibawah ini <br/>
![Tampilan menu](Tampilan_Menu.png) <br/>
![Tampilan akhir](Tampilan_Akhir.png)
```C++
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
```
#### Output
![Output PNG](Output1_Unguided2.png)
![Output PNG](Output2_Unguided2.png)
![Output PNG](Ouput3_Unguided2.png)

Kode di atas diawali dengan inisialisasi struct node dengan 2 variabel string namaProduk, int harga, pointer Node prev & next. Kemudian ada class DoubleLinkedList yang merepresentasikan sebuah doubly linked list (daftar berantai ganda) untuk menyimpan informasi tentang produk dengan nama dan harga. Detail penjelasan : <br/>
- DoubleLinkedList memiliki dua pointer head dan tail untuk mengidentifikasi awal dan akhir dari linked list. Konstruktor kelas ini menginisialisasi kedua pointer tersebut menjadi nullptr. <br/>
- insertDepan(string namaProduk, int harga) memasukkan sebuah node baru di awal linked list. Node baru dibuat dan diinisialisasi dengan data yang diberikan. Kemudian, node baru tersebut ditautkan ke head dan head diperbarui.<br/>
- insertBelakang(string namaProduk, int harga) memasukkan sebuah node baru di akhir linked list. Node baru dibuat dan diinisialisasi dengan data yang diberikan. Kemudian, node baru tersebut ditautkan ke tail dan tail diperbarui. <br/>
- insertTengah(string namaProduk, int harga, string namaSebelum) memasukkan sebuah node baru setelah node dengan nama produk tertentu. Metode ini mencari node dengan nama produk yang diberikan dan memasukkan node baru di antara node tersebut dan node berikutnya. <br/>
- hapus(string namaProduk) menghapus node dengan nama produk yang diberikan. Metode ini mencari node dengan nama produk yang diberikan dan menghapusnya dari linked list.<br/>
- update (string namaProdukLama, string namaProdukBaru, int hargaBaru) mengubah nama dan harga dari node dengan nama produk yang diberikan. Metode ini mencari node dengan nama produk yang diberikan dan mengubah data tersebut.<br/>
- hapusUrutanTertentu(int urutan) menghapus node pada posisi urutan yang diberikan. Metode ini mencari node pada posisi urutan yang diberikan dan menghapusnya dari linked list. <br/>
- hapusSeluruhData() menghapus semua node dari linked list dan mengosongkan linked list. <br/>
- insertUrutanTertentu(string namaProduk, int harga, int urutan) memasukkan sebuah node pada posisi urutan yang diberikan. Metode ini mencari posisi urutan yang diberikan dan memasukkan node baru di posisi tersebut.<br/>
- tampilkanData() menampilkan semua data produk yang ada di linked list dengan format yang ditentukan.<br/><br/>

Pada int main hal pertama yang dilakukan ada menginisialisasi DoubleLinkedList dengan tokoSkincare, terdapat percabangan switch case untuk menampilkan menu dan juga perulangan. perulangan akan berhenti apabila memilih menu 8 yaitu exit. <br/>

## Kesimpulan
Linked list, baik single linked list maupun double linked list, adalah struktur data yang penting dan sering digunakan dalam pemrograman. Keduanya memiliki kelebihan dan kekurangan masing-masing, dan pilihan antara keduanya tergantung pada kebutuhan dan kegunaan spesifik dari aplikasi yang sedang dikembangkan. <br/>
- Single Linked List <br/>
Cocok untuk situasi di mana akses cepat ke elemen terakhir jarang diperlukan dan kebutuhan memori adalah prioritas.<br/>
- Double Linked List <br/>
Lebih sesuai untuk aplikasi di mana akses cepat ke elemen terakhir dan kebutuhan untuk mengunjungi elemen sebelumnya adalah penting, meskipun dengan biaya memori yang lebih tinggi dan kompleksitas implementasi yang lebih rumit.<br/>

## Referensi
[1] Sindar, A, STRUKTUR DATA DAN ALGORITMA DENGAN C++. 1st Edisi. Serang:CV.AA.RIZKY,2018.<br/>
[2] Sanjaya, D, Asyiknya Belajar Struktur Data di Planet C++. 1st Edition. Jakarta:PT Gramedia, Jakarta,2005.