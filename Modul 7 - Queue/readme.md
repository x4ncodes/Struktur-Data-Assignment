# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Axandio Biyanatul Lizan - 2311102179</p>

## Dasar Teori
Queue (antrian) adalah sekumpulan data,penambahan elemen hanya dapat dilakukan pada salah satu ujung (disebut belakang atau rear) ENQUEUE, dan penghapusan atau pengambilan elemen dilakukan melalui ujung yang lain (disebut sisi depan atau front) DEQUEUE.[1] Queue disebut juga antrian dimana data masuk di satu sisi dan keluar di sisi yang lain. Karena itu, queue bersifat FIFO (First In First Out). Jadi, dalam antrian menggunakan prinsip “masuk pertama keluar pertama” atau disebut juga dengan prinsip FIFO (first in first out). [2] <br/>

Berikut ini operasi - operasi standar pada queue : [2]<br/>
1. <b>Inisialisasi<b>, merupakan prosedur untuk membuat queue pada kondisi awal, yaitu queue yang masih kosong (belum mempunyai elemen). <br/>
2. <b>InQueue<b>, Insert Queue merupakan prosedur untuk memasukkan sebuah elemen baru pada queue. Jumlah elemen Queue akan bertambah satu dan elemen tersebut merupakan elemen belakang. <br/>
3. <b>DeQueue<b>, Delete Queue merupakan prosedur untuk menghapus/mengambil sebuah elemen dari queue. Elemen yang diambil adalah elemen depan dan jumlah elemen queue akan berkurang satu. <br/> <br/>

Operasi-operasi yang berhubungan dengan jumlah elemen suatu queue adalah : <br/>
1. <b>Size<b>, yaitu operasi untuk mendapatkan banyaknya elemen queue. <br/>
2. <b>Empty<b>, yaitu prosedur untuk mengetahui apakah queue dalam keadaan kosong atau tidak. Dengan status ini maka dapat dicegah dilakukannya operasi Dequeue dari suatu queue yang kosong. <br/>
3. <b>Full<b>, merupakan prosedur untuk mengetahui apakah Queue penuh atau tidak. Prosedur ini hanya berlaku untuk queue yang jumlahnya terbatas. <br/><br/>

Antrian merupakan suatu kumpulan data, maka tipe data yang sesuai untuk menyajikan antrian adalah menggunakan array atau list (senarai berantai). <br/>
![Queue Teori](queue_array.png)
Gambar di atas menunjukkan contoh penyajian antrian menggunakan array. Antrian di atas berisi 6 elemen yaitu A, B, C, D, E dan F. Elemen A terletak di bagian depan antrian dan elemen F terletak di bagian belakang antrian. Jika ada elemen baru yang akan masuk, maka elemen tersebut akan diletakkan di sebelah kanan F. Dan jika ada elemen yang akan dihapus, maka A akan dihapus terlebih dahulu. [2] <br/>

## Guided 

### 1. [Guided 1]

```C++
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
```
Kode diatas adalah bentuk implementasi dari Stack atau yang biasa dikenal tumpukan, kode diatas juga memiliki beberapa deklarasi prosedur & function. Hal pertama kode diatas menggunakan array yang bertipe string dengan nama variabel arrayBuku yang memiliki panjang array 5. Lalu terdapat 2 variabel bertipe data int, maksimal (berfungsi sebagai wadah/tempat/media) yang memiliki kapasitas 6 (0-5), kemudian ada inisiasi variabel top yang dimulai dari 0. Kemudian juga ada pengencekan apakah data stack udh penuh / kosong. Berikut adalah rincian penjelasan kode diatas : <br/>
- Bool IsEmpty <br/>
Function tersebut digunakan untuk mengecek apakah data stack kosong dengan cara mencocokan apakah nilai top sama dengan 0. <br/>
- Bool IsFull <br/>
Function tersebut digunakan untuk mengecek apakah data stack penuh dengan cara mencocokan apakah nilai top sama dengan maksimal.<br/>
- void pushArrayBuku <br/>
Deklarasi tersebut menjelaskan cara menambahkan data buku baru. Hal pertama adalah pengecekan menggunakan IsFull, jika bernilai true berarti data stack penuh. jika bernilai false maka top akan di increment/tambah 1 dengan menambahkan data. <br/>
- void popArrayBuku() <br/>
Deklarasi tersebut menjelaskan cara menghapus buku. Hal pertama adalah pengecekan menggunakan IsEmpty, jika bernilai true maka data stack kosong dan tidak dapat menghapus. Jika bernilai false maka tumpukan (top) akan di kurang 1, kemudian data yang paling atas akan dihapus.<br/>
- void peekArrayBuku(int posisi) <br/>
Deklarasi tersebut adalah melihat elemen stack pada posisi tertentu. Hal pertama adalah pengecekan IsEmpty, jika bernilai true maka tidak ada data yang bisa dilihat. Jika bernilai false maka mencetak posisi dan elemen array pada posisi yang dimaksud. parameter posisi adalah indeks yang ingin diakses, arrayBuku[index]  <br/>
- int countStack() <br/>
Function tersebut digunakan untuk menghitung jumlah stack, dengan cara mengembalikan nilai top.<br/>
- void changeArrayBuku(int posisi, string data) <br/>
Deklarasi tersebut digunakan untuk mengganti data pada posisi tertentu. Pertama adalah pengecekan apakah posisi yang dimasukan melebihi top, jika iya maka akan mencetak posisi melebihi data yang ada, jika tidak maka terjadi iterasi untuk mencari posisi yang diinginkan, kemudian memperbarui arrayBuku dengan data yang baru. <br/>
- void destroyBuku () <br/>
Deklarasi tersebut digunakan untuk menghapus semua data buku dengan menggunakan iterasi perulangan for.<br/>
- void cetakArrayBuku() <br/>
Deklarasi tersebut digunakan untuk mencetak data buku. Pertama kode menggunakan perkondisian pengecekan jika IsEmpty bernilai true maka tidak ada data yang dicetak, jika bernilai false maka akan mencetak arrayBuku[i] sesuai iterasi perulangan.<br/>
<br/>
Pada int main() ada pendeklarasian data seperti menambahkan kalkulus, struktur data, matematika diskrit, dasar multimedia, dan Inggris. Karena stack bersifat Last In First Out maka data kalkulus berada diurutan paling bawah dan data inggris berada diurutan paling atas. selain menambahkan data, ada juga pengecekan data, penghapusan data paling atas, pengecekan data stack penuh atau kosong, pengecekan banyak data menggunakan countStack, mengubah data pada posisi ke 2, kemudian menghapus seluruh data, dan mencetak hasil akhir data. <br/>

## Unguided 

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list <br/>
```C++
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
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
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
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Fungsi untuk menghitung jumlah pelanggan dalam antrian
    int countQueue() {
        int count = 0;
        Node* current = front;
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
```
#### Output Unguided 1:
![Output Unguided 1](unguided1.png)

Program diatas merupakan kode bahasa c++ yang menjelaskan mengenai pengecekan apakah kata/kalimat yang dimasukan merupakan tipe polindrome atau tidak polindrome yang menggunakan fungsi Stack sebagai operasinya. Pada kode diatas, terdapat 1 Deklarasi function dan 1 Pengecekan. : <br/>
- string hapusNonAlpha(string str) <br/>
Fungsi diatas digunakan untuk menghapus karakter non-alfabet dari string. Fungsi ini menerima satu parameter berupa string str. Kemudian, dilakukan iterasi melalui setiap karakter dalam string tersebut menggunakan loop for (char a : str).Pada setiap iterasi, dilakukan pengecekan apakah karakter tersebut merupakan karakter alfabet atau bukan dengan menggunakan fungsi isalpha(a). Jika karakter tersebut adalah alfabet, maka karakter tersebut ditambahkan ke dalam string result. Selain itu juga ada fungsi tolower(a) yang digunakan untuk mengkonversi atau merubah menjadi huruf kecil.<br/>
- bool isPalindrome(string str) <br/>
Fungsi ini merupakan fungsi pengecekan apakah string merupakan sebuah polindrome atau tidak. stack<char> charStack;: Baris ini mendeklarasikan sebuah objek dari kelas stack dengan tipe data elemen char, yang dinamakan charStack. int length = str.length();: Baris ini menghitung panjang dari string str dengan menggunakan fungsi length(). Terdapat 2 fungsi iterasi perulangan for pada fungsi pengecekan ini. Iterasi pertama adalah memasukkan setengah pertama dari string ke dalam stack, dan Iterasi kedua adalah membandingkan setengah kedua dari string dengan karakter yang ada di stack. Ada 1 Perkondisian if yang berfungsi untuk jika panjang string ganjil, maka skip karakter di tengah. <br/>
<br/>
Pada int main() terdapat tipe data string dengan variabel 'masukan'. kemudian terdapat fungsi getline yang berguna untuk mengabaikan spasi dan dapat mengecek lebih dari 1 kata. Kemudian ada string cleanMasukan yang berfungsi untuk menghapus karakter non-alfabet dan mengubah huruf menjadi lowercase. Ada perkondisian IF-ELSE yang berguna untuk pengecekan apakah kata/kalimat yang diinputkan oleh user polindrome atau bukan polindrome. <br/>

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa <br/>
```C++
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
```
#### Output Unguided 2:
![Output Unguided 2](unguided2.png)

Program diatas merupakan kode bahasa c++ yang menjelaskan mengenai reverse word atau pembalikan kata menggunakan fungsi operasi Stack. Pada kode diatas, terdapat 2 Deklarasi function. : <br/>
- string reverseKata(string kata) <br/>
Fungsi ini menerima satu parameter berupa string kata. Selanjutnya, dilakukan iterasi mundur melalui setiap karakter dalam string kata menggunakan loop 'for' dengan inisialisasi 'int a = kata.length() - 1', yang berarti dimulai dari indeks karakter terakhir hingga indeks '0'. Pada setiap iterasi, karakter pada indeks ke-a dari string kata ditambahkan ke dalam string 'reversedKata'. Dengan cara ini, karakter-karakter dalam kata tersebut dipindahkan ke string baru dalam urutan terbalik. String 'reversedKata' yang berisi karakter-karakter dalam kata yang sudah terbalik urutannya, akan dikembalikan sebagai output dari fungsi 'reverseKata'<br/>
- string pembalikanKalimat(string kalimat) <br/>
Pada awalnya, dideklarasikan sebuah stack bernama kataStack yang bertipe stack<string> untuk menyimpan kata-kata dalam urutan terbalik. Selain itu, dideklarasikan juga dua string, yaitu kata untuk menyimpan kata sementara dan pembalikanKalimat untuk menyimpan kalimat terbalik. Kemudian dilakukan sebuah iterasi melalui setiap karakter dalam string kalimat menggunakan loop 'for' dengan deklarasi 'char x : kalimat'. Pada setiap iterasi, dilakukan pengecekan apakah karakter saat itu adalah spasi. Jika iya, maka kata sementara yang telah terbentuk ('kata') akan dimasukkan ke dalam stack kataStack setelah diubah urutan karakternya menggunakan fungsi reverseKata. Kemudian, variabel kata direset kembali menjadi string kosong untuk menampung kata berikutnya. Jika karakter saat itu bukan spasi, maka karakter tersebut ditambahkan ke dalam kata sementara. Kemudian setelah iterasi selesai, kata sementara terakhir (kata yang tidak diakhiri oleh spasi) juga dimasukkan ke dalam stack 'kataStack' setelah diubah urutan karakternya menggunakan fungsi 'reverseKata'. Proses pengambilan kata-kata dari stack 'kataStack' dan dimasukkan ke dalam string 'pembalikanKalimat' satu per satu dengan menambahkan spasi di antara setiap kata. Hal ini dilakukan sampai stack kataStack kosong. Kemudian, string 'pembalikanKalimat' yang berisi kalimat dengan urutan kata terbalik akan dikembalikan sebagai output dari fungsi 'pembalikanKalimat'.  <br/>
<br/>
Pada int main() terdapat tipe data string dengan variabel 'kalimat'. kemudian terdapat fungsi getline yang berguna untuk mengabaikan spasi dan dapat mengecek lebih dari 1 kata. Kemudian ada 'int kataCount = 0' yang menandakan bahwa belum ada kata sama sekali, Kemudian, dilakukan iterasi melalui setiap karakter dalam string kalimat menggunakan loop 'for' dengan deklarasi 'char a : kalimat'. Setiap kali karakter yang ditemui adalah spasi, nilai kataCount akan ditambah satu. Proses ini bertujuan untuk menghitung jumlah kata dalam kalimat. Kemudian ada pengecekan If apakah nilai 'kataCount' kurang dari 2. Jika iya, artinya kalimat yang dimasukkan tidak memiliki minimal tiga kata. Maka, program akan menampilkan pesan kesalahan "Kalimat harus memiliki minimal 3 kata!" dan menghentikan program dengan mengembalikan nilai 1 sebagai tanda kesalahan. Jika kalimat memiliki minimal tiga kata, maka fungsi 'pembalikanKalimat' dipanggil untuk melakukan pembalikan urutan kata, dan hasilnya disimpan dalam variabel 'hasil', kemudian program menampilkan sebuah informasi string "Hasil Data: " diikuti dengan nilai variabel 'hasil'.<br/>

## Kesimpulan
QUEUE merupakan struktur data dinamis, ketika program dijalankan, jumlah elemennya dapat berubah. Tumpukan dikenal dengan menggunakan prinsip LIFO (Last In First Out), maka pada antrian prinsip yang digunakan adalah FIFO (First In First Out). Queue menggunakan prinsip FIFO (First In First Out). Dari unguided dan guided bahwa queue juga dapat dipasangkan dengan array dan juga linkedlist. <br/>

Berikut ini operasi - operasi standar pada queue : <br/>
1. <b>Inisialisasi<b>, merupakan prosedur untuk membuat queue pada kondisi awal, yaitu queue yang masih kosong (belum mempunyai elemen). <br/>
2. <b>InQueue<b>, Insert Queue merupakan prosedur untuk memasukkan sebuah elemen baru pada queue. Jumlah elemen Queue akan bertambah satu dan elemen tersebut merupakan elemen belakang. <br/>
3. <b>DeQueue<b>, Delete Queue merupakan prosedur untuk menghapus/mengambil sebuah elemen dari queue. Elemen yang diambil adalah elemen depan dan jumlah elemen queue akan berkurang satu. <br/> <br/>

Operasi-operasi yang berhubungan dengan jumlah elemen suatu queue adalah : <br/>
1. <b>Size<b>, yaitu operasi untuk mendapatkan banyaknya elemen queue. <br/>
2. <b>Empty<b>, yaitu prosedur untuk mengetahui apakah queue dalam keadaan kosong atau tidak. Dengan status ini maka dapat dicegah dilakukannya operasi Dequeue dari suatu queue yang kosong. <br/>
3. <b>Full<b>, merupakan prosedur untuk mengetahui apakah Queue penuh atau tidak. Prosedur ini hanya berlaku untuk queue yang jumlahnya terbatas. <br/><br/>

## Referensi
[1] Bahit, M, ALGORITMA PEMROGRAMAN TERSTRUKTUR . Cetakan Pertama. Banjarmasin:Poliban Press,2024.<br/>
[2] Sindar, A, STRUKTUR DATA DAN ALGORITMADENGAN C++. Cetakan Pertama. Serang:CV.AA.RIZKY, 2018 <br/>