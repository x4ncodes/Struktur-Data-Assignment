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

### 1. [Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:<br/> a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data Pertama yang dimasukkan adalah nama dan usia anda. <br/> b. Hapus data Akechi <br/> c. Tambahkan data berikut diantara John dan Jane : Futaba 18 <br/> d. Tambahkan data berikut diawal : Igor 20 <br/> e. Ubah data Michael menjadi : Reyn 18 <br/> f. Tampilkan seluruh data <br/> Tampilan poin A : <br/> ]
![Soal JPG](Soal_Unguided1.png)
```C++
#include <iostream>

using namespace std;

int main(){
    const int max_size = 10;
    int data [max_size];

    int jumlahElemen;
    cout << "Masukan jumlah elemen array(maksimal 10): ";
    cin >> jumlahElemen;

    if (jumlahElemen > max_size){
        cout << "Error: Jumlah elemen diluar kapasitas (maks 10)" << endl;
        return 1;
    }

    cout << "Masukan data array (dipisahkan dengan space/spasi): ";
    for (int i = 0; i < jumlahElemen; i++){
        cin >> data[i];
    }

    cout << "Data array : ";
    for (int i = 0; i < jumlahElemen; i++){
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "Nomor Genap : ";
    for (int i = 0; i < jumlahElemen; i++){
        if (data[i]%2 == 0){
            cout << data[i] << " ";
        }
    }
    cout << endl;

    cout << "Nomor Ganjil : ";
    for (int i = 0; i < jumlahElemen; i++){
        if (data[i]%2 == 1){
            cout << data[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
```
#### Output:
![Output JPG](Output_Unguided1.png)

Kode diatas menggunakan maximal panjang array 10, jika lebih dari itu maka akan memuncul kan error yaitu "Error : jumlah elemen diluar kapasitas(maks 10)". Kemudian memasukan data array sesuai panjang array (bisa kurang dari panjang array). kemudian program akan mencetak data array menggunakan perulangan for, untuk mencari nilai genap program menggunakan permisalakn data pada i dibagi 2 nilainya 0 maka nilai tersebut adalah nomor genap, begitupun juga dengan ganjil data i dibagi dengan 2 menghasilkan sisa bagi 1 itu adalah nomor ganjil. Terakhir program maksimal panjang array, data array, nomor genap, dan nomor ganjil.


### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]
```C++
#include <iostream>
using namespace std;

int main (){
    int x,y,z;

    cout << "Masukan dimensi X (Array) : ";
    cin >> x;
    cout << "Masukan dimensi Y (Array) : ";
    cin >> y;
    cout << "Masukan dimensi Z (Array) : ";
    cin >> z;

    int array [x][y][z];

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                cout << "Masukan data Array [" << i << "][" << j << "][" << k << "]: ";
                cin >> array [i][j][k];
            }
        }
        cout << endl;
    }

    cout << "Data Array: " << endl;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                cout << array [i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```

#### Output
![Output PNG](Output_Unguided2.png)

Kode di atas merupakan modifikasi dari guided 1 dimana untuk dimensi x, y, z diinputkan secara manual oleh user. untuk menginputkan nilai dari masing masing variable array x, y, z menggunakan perulangan for sehingga data tersebut akan disimpan pada 'array [i][j][k]'. kemudian program akan mencetak dengan memanggil "array [i][j][k]"


### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]

```C++
#include <iostream>

using namespace std;

int main (){
    int pilihan;
    int data[10];

    int jumlahElemen;
    cout << "Masukan jumlah elemen array (max 10): ";
    cin >> jumlahElemen;

    if (jumlahElemen > 10){
        cout << "Jumlah elemen diluar batas kemampuan" << endl;
        return 1;
    }

    cout << "Masukkan data array (pisahkan dengan space) : " ;
    for (int i = 0; i < jumlahElemen; i++){
        cin >> data[i];
    }

    do {
        cout << endl << "Axan Program Array : " << endl;
        cout << "1. Find Maximum Value of Array" << endl;
        cout << "2. Find Minimum Value of Array" << endl;
        cout << "3. Find Average Value of Array" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih (1-4)! : ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: {
                int max = data[0];
                for (int i = 1; i < jumlahElemen; i++){
                    if (data[i] > max){
                        max = data[i];
                    }
                }

                cout << "Nilai Maksimum : " << max << endl;
                break;
            }
            case 2 : {
                int min = data[0];
                for (int i = 1; i < jumlahElemen; i++){
                    if (data[i] < min){
                        min = data[i];
                    }
                }
                cout << "Nilai Minimum : " << min << endl;
                break;
            }

            case 3 : {
                int sum = 0;
                for (int i = 0; i < jumlahElemen; i++) {
                sum += data[i];
                }
                double average = (double)sum / jumlahElemen;
                cout << "Nilai Rata-rata: " << average << endl;
                break;
            }

            case 4 : {
                cout << "Terima kasih" << endl;
                break;
            }

            default : {
                cout << "Pilihan tidak valid!" << endl;
            }
            }
        } while (pilihan != 4);

        return 0;
    }

```
#### Output:
![Output JPG](Output-Unguided3.png)

Kode di atas mendeklarasikan int data dengan panjang maksimal 10, alur kerja jumlah elemen seperti dengan unguided 1.  kemudian data array akan disimpan pada data[i].
1. Find Maximum Value of Array <br/>
Program mendeklarasikan data dengan indeks array ke 0 (awal), kemudian menggunakan perulangan for untuk mencari nilai maksimum, jika data[i] lebih besar dari nilai maksimum sebelumnya maka program akan memperbarui nilai dalam maks.
2. Find Minimum Value of Array <br/>
Program mendeklarasikan data dengan indeks array ke 0 (awal), kemudian menggunakan perulangan for untuk mencari nilai minimum, jika data[i] lebih kecil dari nilai minimum sebelumnya maka program akan memperbarui nilai dalam min. <br/>
3. Find Average Value of Array <br/>
Kode ini menggunakan loop for untuk menghitung total nilai elemen array dan kemudian membaginya dengan jumlah elemen untuk mendapatkan nilai rata-rata. Nilai rata-rata kemudian dicetak. <br/>


## Kesimpulan
Pada dasarnya, array adalah struktur data yang digunakan untuk menyimpan sejumlah data dalam satu tempat dan memiliki indeks untuk setiap data, sehingga mudah diproses. Selain itu, array membantu pengguna menyimpan dan mengorganisir data, dan memberikan akses mudah ke data melalui indeksnya. Array dibagi menjadi 3 jenis : <br/>
1. Array 1 dimensi, biasanya berbentuk []
2. Array 2 dimensi, memiliki 2 baris, biasanya berbentuk [][]
3. Array Multidimensi, memiliki lebih dari 2 dimensi, biasanya berbentuk [][][]

## Referensi
[1] Sindar, A, STRUKTUR DATA DAN ALGORITMA DENGAN C++. 1st Edisi. Serang:CV.AA.RIZKY,2018.<br/>
[2] Sanjaya, D, Asyiknya Belajar Struktur Data di Planet C++. 1st Edition. Jakarta:PT Gramedia, Jakarta,2005.