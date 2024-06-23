#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <cctype>

#define RESET "\033[0m"
#define CYAN "\033[36m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"


using namespace std;

// STRUCT CURRENCY
struct Currency
{
    string nama_mata_uang_asal;
    string nama_mata_uang_tujuan;
    double nilai_tukar;
    Currency *next;
};

// STRUCT KONVERSI
struct Konversi
{
    string mata_uang_asal;
    string mata_uang_tujuan;
    double nominal;
    double hasil_konv;
    string waktu_konversi;
};

// INIT LIBRARY STACK n QUEUE
stack<Konversi> history_konv;
queue<Konversi> queue_konv;

Currency *head = nullptr, *tail = nullptr, *cur = nullptr, *del = nullptr;

string toUpperCase(string str)
{
    for (char &c : str)
    {
        c = toupper(c);
    }
    return str;
}

// AUTH
bool authenticate(string username, int password)
{
    string user[2] = {"Axan", "Muti"};
    int pass[2] = {123, 123};
    for (int i = 0; i < 2; i++)
    {
        if (toUpperCase(username) == user[i] && password == pass[i])
        {
            return true;
        }
    }
    return false;
}

// ADD CURRENCY
void add_currency()
{
    string nama_mata_uang_asal, nama_mata_uang_tujuan;
    double nilai_tukar;

    cout << "↳ INPUT NAMA MATA UANG ASAL : ";
    cin >> nama_mata_uang_asal;
    cout << "↳ INPUT NAMA MATA UANG TUJUAN : ";
    cin >> nama_mata_uang_tujuan;
    cout << "↳ NILAI TUKAR : ";
    cin >> nilai_tukar;

    Currency *newCurrency = new Currency();
    newCurrency->nama_mata_uang_asal = toUpperCase(nama_mata_uang_asal);
    newCurrency->nama_mata_uang_tujuan = toUpperCase(nama_mata_uang_tujuan);
    newCurrency->nilai_tukar = nilai_tukar;
    newCurrency->next = nullptr;

    if (head == nullptr)
    {
        head = newCurrency;
        tail = newCurrency;
    }
    else
    {
        tail->next = newCurrency;
        tail = newCurrency;
    }

    cout << GREEN << "\n[ ✉ KURS MATA UANG DITAMBAHKAN ! ]\n"
         << RESET << endl;
}

// SHOW KURS CURRENCY
void show_kurs()
{
    if (head == nullptr)
    {
        cout << RED << "\n[ ✉  TIDAK ADA DATA KURS ! ]\n"
             << RESET << endl;
    }
    else
    {
        Currency *cur = head; // Inisialisasi cur dengan head

        // Header tabel
        cout << CYAN << left << setw(20) << "[ MATA UANG ASAL ] "
             << left << setw(20) << "[ MATA UANG TUJUAN ]"
             << left << setw(20) << "[ NILAI TUKAR ]" << RESET << endl;
        cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

        // Data tabel
        while (cur != nullptr)
        {
            cout << CYAN << left << setw(22) << cur->nama_mata_uang_asal
                 << left << setw(20) << cur->nama_mata_uang_tujuan
                 << left << setw(20) << cur->nilai_tukar << RESET << endl;
            cur = cur->next;
        }
    }
}

// SEARCH Sequential KURS CURRENCY
Currency *search_kurs(string nama_mata_uang_asal, string nama_mata_uang_tujuan)
{
    cur = head;
    while (cur != nullptr)
    {
        if (cur->nama_mata_uang_asal == toUpperCase(nama_mata_uang_asal) && cur->nama_mata_uang_tujuan == toUpperCase(nama_mata_uang_tujuan))
        {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

// CONVERTER
void konv_currency()
{
    string asal, tujuan;
    double nominal;

    cout << "↳ INPUT MATA UANG ASAL : ";
    cin >> asal;
    cout << "↳ INPUT MATA UANG TUJUAN : ";
    cin >> tujuan;
    cout << "↳ NOMINAL : ";
    cin >> nominal;

    Currency *kurs_asal = search_kurs(asal, tujuan);

    if (kurs_asal == nullptr)
    {
        cout << RED << "\n[ ✉ KURS TIDAK TERSEDIA ! ]" << RESET << endl;
        cout << RED << "[ ✉ TAMBAHKAN DATA KURS TERLEBIH DAHULU ! ]\n"
             << RESET << endl;
        return;
    }

    double hasil = nominal / kurs_asal->nilai_tukar;

    asal = toUpperCase(asal);
    tujuan = toUpperCase(tujuan);

    cout << GREEN << fixed << setprecision(2);
    cout << "\n[ ⇋ HASIL CONVERT : " << asal << " → " << tujuan << " ] " << endl;
    cout << "[ ⇋ NOMINAL " << asal << " : " << nominal << " | NOMINAL " << tujuan << " : " << hasil << " ]\n"
         << RESET << endl;

    // Mendapatkan waktu saat konversi dilakukan
    time_t now = time(0);
    char *dt = ctime(&now);
    string waktu_konversi(dt);

    history_konv.push({toUpperCase(asal), toUpperCase(tujuan), nominal, hasil, waktu_konversi});
}

// ADD QUEUE
void add_queue_konv()
{
    string asal, tujuan;
    double nominal;

    cout << "↳ INPUT MATA UANG ASAL : ";
    cin >> asal;
    cout << "↳ INPUT MATA UANG TUJUAN : ";
    cin >> tujuan;
    cout << "↳ NOMINAL : ";
    cin >> nominal;

    queue_konv.push({toUpperCase(asal), toUpperCase(tujuan), nominal, 0, ""});

    cout << GREEN << "\n[ ✉ ANTRIAN KONVERSI DITAMBAHKAN ! ]\n"
         << RESET << endl;
}

// PROSES QUEUE
void proses_queue_konv()
{
    if (queue_konv.empty())
    {
        cout << RED << "\n[ ✉ TIDAK ADA ANTRIAN KONVERSI ! ]\n"
             << RESET << endl;
        return;
    }

    // Menampilkan semua antrian dalam tabel
    queue<Konversi> temp_queue = queue_konv;
    int antrian_ke = 1;

    cout << GREEN << "\n[ ✉ KLIK 'ENTER' UNTUK MEMPROSES SELURUH ANTRIAN ]\n"
         << RESET;
    cin.ignore(); // Ignore any leftover characters in the input buffer
    cin.get();    // Wait for the user to press enter

    cout << CYAN << left << setw(20) << "[ ANTRIAN ] "
         << left << setw(25) << "[ MATA UANG ASAL ] "
         << left << setw(25) << "[ MATA UANG TUJUAN ]"
         << left << setw(20) << "[ NOMINAL ]"
         << left << setw(25) << "[ HASIL KONVERSI ]" << RESET << endl;
    cout << setfill('-') << setw(120) << "-" << setfill(' ') << endl;

    while (!temp_queue.empty())
    {
        Konversi konversi = temp_queue.front();
        temp_queue.pop();

        Currency *kurs_asal = search_kurs(konversi.mata_uang_asal, konversi.mata_uang_tujuan);

        if (kurs_asal != nullptr)
        {
            konversi.hasil_konv = konversi.nominal / kurs_asal->nilai_tukar;
        }

        cout << CYAN << left << setw(22) << antrian_ke
             << left << setw(25) << konversi.mata_uang_asal
             << left << setw(25) << konversi.mata_uang_tujuan
             << left << setw(20) << konversi.nominal;

        if (kurs_asal != nullptr)
        {
            // Set presisi untuk nilai hasil_konv
            cout << fixed << setprecision(2) << left << setw(25) << konversi.hasil_konv << RESET;
        }
        else
        {
            cout << RED << left << setw(30) << " [ KURS TIDAK TERSEDIA ]";
        }

        cout << RESET << endl;

        antrian_ke++;
    }

    while (!queue_konv.empty())
    {
        Konversi konversi = queue_konv.front();
        queue_konv.pop();

        Currency *kurs_asal = search_kurs(konversi.mata_uang_asal, konversi.mata_uang_tujuan);

        if (kurs_asal != nullptr)
        {
            konversi.hasil_konv = konversi.nominal / kurs_asal->nilai_tukar;
            // Mendapatkan waktu saat konversi dilakukan
            time_t now = time(0);
            char *dt = ctime(&now);
            string waktu_konversi(dt);
            konversi.waktu_konversi = waktu_konversi;

            history_konv.push(konversi);
        }
    }

    cout << GREEN << "\n[ ✉ ANTRIAN KONVERSI BERHASIL DIPROSES! ]\n"
         << RESET << endl;
}

// HISTORY CONVERT (STACK)
void currency_history_konv()
{
    stack<Konversi> temp = history_konv;

    if (temp.empty())
    {
        cout << RED << "\n[ ✉ TIDAK ADA RIWAYAT KONVERSI ! ]\n"
             << RESET << endl;
        return;
    }

    // Header tabel
    cout << CYAN << left << setw(25) << "[ MATA UANG ASAL ] "
         << left << setw(25) << "[ MATA UANG TUJUAN ]"
         << left << setw(20) << "[ NOMINAL ]"
         << left << setw(25) << "[ HASIL KONVERSI ]"
         << left << setw(25) << "[ WAKTU KONVERSI ]" << RESET << endl;
    cout << setfill('-') << setw(120) << "-" << setfill(' ') << endl;

    // Data tabel
    while (!temp.empty())
    {
        Konversi konversi = temp.top();
        temp.pop();

        cout << CYAN << left << setw(27) << konversi.mata_uang_asal
             << left << setw(25) << konversi.mata_uang_tujuan
             << left << setw(20) << fixed << setprecision(2) << konversi.nominal
             << left << setw(25) << konversi.hasil_konv
             << left << setw(25) << konversi.waktu_konversi << RESET << endl;
    }
}

// UPDATE CURRENCY
void update_currency()
{
    string nama_mata_uang_asal, nama_mata_uang_tujuan;
    double nilai_tukar;

    cout << "↳ INPUT NAMA MATA UANG ASAL : ";
    cin >> nama_mata_uang_asal;
    cout << "↳ INPUT NAMA MATA UANG TUJUAN : ";
    cin >> nama_mata_uang_tujuan;

    Currency *kurs = search_kurs(nama_mata_uang_asal, nama_mata_uang_tujuan);

    if (kurs == nullptr)
    {
        cout << RED << "\n[ ✉ KURS TIDAK DITEMUKAN ! ]" << RESET << endl;
        return;
    }

    cout << "↳ NILAI TUKAR BARU : ";
    cin >> nilai_tukar;

    kurs->nilai_tukar = nilai_tukar;

    cout << GREEN << "\n[ ✉ KURS MATA UANG DIPERBARUI ! ]\n"
         << RESET << endl;
}

// DELETE CURRENCY
void delete_currency()
{
    string nama_mata_uang_asal, nama_mata_uang_tujuan;

    cout << "↳ INPUT NAMA MATA UANG ASAL : ";
    cin >> nama_mata_uang_asal;
    cout << "↳ INPUT NAMA MATA UANG TUJUAN : ";
    cin >> nama_mata_uang_tujuan;

    if (head == nullptr)
    {
        cout << RED << "\n[ ✉ TIDAK ADA DATA KURS ! ]\n"
             << RESET << endl;
        return;
    }

    Currency *prev = nullptr;
    cur = head;

    while (cur != nullptr)
    {
        if (cur->nama_mata_uang_asal == toUpperCase(nama_mata_uang_asal) && cur->nama_mata_uang_tujuan == toUpperCase(nama_mata_uang_tujuan))
        {
            if (cur == head)
            {
                head = head->next;
            }
            else
            {
                prev->next = cur->next;
            }
            delete cur;
            cout << GREEN << "\n[ ✉ KURS MATA UANG DIHAPUS ! ]\n"
                 << RESET << endl;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    cout << RED << "\n[ ✉ KURS TIDAK DITEMUKAN ! ]\n"
         << RESET << endl;
}

// INIT CURRENCIES
void init_currencies()
{
    Currency *currencies[] = {
        new Currency{"IDR", "AUD", 10890, nullptr},
        new Currency{"IDR", "KRW", 11.91, nullptr},
        new Currency{"IDR", "MYR", 3491, nullptr},
        new Currency{"IDR", "SGD", 12165, nullptr}};

    for (Currency *currency : currencies)
    {
        if (head == nullptr)
        {
            head = currency;
            tail = currency;
        }
        else
        {
            tail->next = currency;
            tail = currency;
        }
    }
}

// MAIN PROGRAM
int main()
{
    string username;
    int password, choice;

    init_currencies();

    while (true)
    {
        cout << MAGENTA << "\n⌜ ⥮ PROGRAM AM! CONVERTER ⥮ ⌟" << RESET << endl;
        cout << RED << "[ ✉ LOGIN UNTUK MENGAKSES PROGRAM ! ]" << RESET << endl;
        cout << "↳ USERNAME : " << RESET;
        cin >> username;
        cout << "↳ PASSWORD : " << RESET;
        cin >> password;

        if (authenticate(username, password))
        {
            cout << "\n[ ✉ USERNAME ATAU PASSWORD SALAH ! ]" << endl;
            break;
        }
        else
        {
            cout << GREEN << "\n[ ✉ LOGIN SUKSES ! ]" << RESET << endl;
        }

        while (true)
        {
            cout << MAGENTA << left << setw(20) << "\n⥮ MENU AM! CONVERTER ⥮" << RESET << endl;
            cout << "[ 1 ] TAMPILKAN KURS MATA UANG" << endl;
            cout << "[ 2 ] TAMBAHKAN KURS MATA UANG" << endl;
            cout << "[ 3 ] UPDATE KURS MATA UANG" << endl;
            cout << "[ 4 ] HAPUS KURS MATA UANG" << endl;
            cout << "[ 5 ] KONVERSI MATA UANG" << endl;
            cout << "[ 6 ] TAMBAH ANTRIAN KONVERSI" << endl;
            cout << "[ 7 ] PROSES ANTRIAN KONVERSI" << endl;
            cout << "[ 8 ] RIWAYAT KONVERSI" << endl;
            cout << "[ 9 ] EXIT" << endl;
            cout << "↳ MASUKAN PILIHAN : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << YELLOW << "\n⌜ TABEL KURS MATA UANG ⌟\n" << RESET << endl;
                show_kurs();
                break;
            case 2:
                cout << YELLOW << "\n⌜ TAMBAH KURS MATA UANG ⌟\n" << RESET << endl;
                add_currency();
                break;
            case 3:
                cout << YELLOW << "\n⌜ PERBARUI KURS MATA UANG ⌟\n" << RESET << endl;
                update_currency();
                break;
            case 4:
                cout << YELLOW << "\n⌜ HAPUS KURS MATA UANG ⌟\n" << RESET << endl;
                delete_currency();
                break;
            case 5:
                cout << YELLOW << "\n⌜ KONVERSI MATA UANG ⌟\n" << RESET << endl;
                konv_currency();
                break;
            case 6:
                cout << YELLOW << "\n⌜ TAMBAH ANTRIAN KONVERSI ⌟\n" << RESET << endl;
                add_queue_konv();
                break;
            case 7:
                cout << YELLOW << "\n⌜ PROSES ANTRIAN KONVERSI ⌟\n" << RESET << endl;
                proses_queue_konv();
                break;
            case 8:
                cout << YELLOW << "\n⌜ RIWAYAT KONVERSI ⌟\n" << RESET << endl;
                currency_history_konv();
                break;
            case 9:
                cout << RED << "\n[ ✉ EXIT ! ]\n" << RESET << endl;
                return 0;
            default:
                cout << RED << "\n[ ✉ PILIHAN TIDAK VALID ! ]\n" << RESET << endl;
                break;
            }
        }
    }

    return 0;
}
