/*
Axandio Biyanatul Lizan - 2311102179
*/
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    int data;
    Node *next;
};

Node *head; // Deklarasi head
Node *tail; // Deklarasi tail

// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty()
{
    return head == NULL;
}

// Tambah Depan
void insertDepan(int nilai)
{
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void insertBelakang(int nilai)
{
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah List
int hitungList()
{
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty())
    {
        cout << "List kosong!" << endl;
        return;
    }

    Node *hapus = head;
    if (head->next != NULL)
    {
        head = head->next;
    }
    else
    {
        head = tail = NULL;
    }
    delete hapus;
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty())
    {
        cout << "List kosong!" << endl;
        return;
    }

    Node *hapus = tail;
    if (head != tail)
    {
        Node *bantu = head;
        while (bantu->next != tail)
        {
            bantu = bantu->next;
        }
        tail = bantu;
        tail->next = NULL;
    }
    else
    {
        head = tail = NULL;
    }
    delete hapus;
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
        return;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }

    Node *bantu = head;
    Node *hapus = NULL;
    Node *sebelum = NULL;
    int nomor = 1;
    while (nomor <= posisi)
    {
        if (nomor == posisi - 1)
        {
            sebelum = bantu;
        }
        if (nomor == posisi)
        {
            hapus = bantu;
        }
        bantu = bantu->next;
        nomor++;
    }
    sebelum->next = bantu;
    delete hapus;
}

// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty())
    {
        cout << "List masih kosong!" << endl;
        return;
    }
    head->data = data;
}

// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    if (isEmpty())
    {
        cout << "List masih kosong!" << endl;
        return;
    }
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
        return;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }

    Node *bantu = head;
    int nomor = 1;
    while (nomor < posisi)
    {
        bantu = bantu->next;
        nomor++;
    }
    bantu->data = data;
}

// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty())
    {
        cout << "List masih kosong!" << endl;
        return;
    }
    tail->data = data;
}

// Hapus List
void clearList()
{
    Node *bantu = head;
    while (bantu != NULL)
    {
        Node *hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    Node *bantu = head;
    if (isEmpty())
    {
        cout << "List masih kosong!" << endl;
        return;
    }

    while (bantu != NULL)
    {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    return 0;
}
