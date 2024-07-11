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
    string currencyFromName;
    string currencyToName;
    double currencyExchangeValue;
    Currency *next;
};

// STRUCT KONVERSI
struct Konversi
{
    string currencyFrom;
    string currencyTo;
    double nominal;
    double resultConversion;
    string timeConversion;
};

// INIT LIBRARY STACK n QUEUE
stack<Konversi> history_konv;
queue<Konversi> queue_konv;

Currency *head = NULL, *tail = NULL, *cur = NULL, *del = NULL;

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
    string user[2] = {"user 1", "user 2"};
    int pass[2] = {12345, 12345};
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
    string currencyFromName, currencyToName;
    double currencyExchangeValue;

    cout << "↳ INPUT CURRENCY FROM NAME : ";
    cin >> currencyFromName;
    cout << "↳ INPUT CURRENCY TO NAME : ";
    cin >> currencyToName;
    cout << "↳ INPUT EXCHANGE VALUE : ";
    cin >> currencyExchangeValue;

    Currency *newCurrency = new Currency();
    newCurrency->currencyFromName = toUpperCase(currencyFromName);
    newCurrency->currencyToName = toUpperCase(currencyToName);
    newCurrency->currencyExchangeValue = currencyExchangeValue;
    newCurrency->next = NULL;

    if (head == NULL)
    {
        head = newCurrency;
        tail = newCurrency;
    }
    else
    {
        tail->next = newCurrency;
        tail = newCurrency;
    }

    cout << GREEN << "\n[ ✉ EXCHANGE RATE ADDED ! ]\n"
         << RESET << endl;
}

// SHOW KURS CURRENCY
void show_kurs()
{
    if (head == NULL)
    {
        cout << RED << "\n[ ✉  NO EXCHANGE RATE DATA ! ]\n"
             << RESET << endl;
    }
    else
    {
        Currency *cur = head; // Inisialisasi cur dengan head

        // Header tabel
        cout << CYAN << left << setw(20) << "[ CURRENCY FROM ] "
             << left << setw(20) << "[ CURRENCY TO ]"
             << left << setw(20) << "[ CURRENCY EXCHANGE VALUE ]" << RESET << endl;
        cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

        // Data tabel
        while (cur != NULL)
        {
            cout << CYAN << left << setw(22) << cur->currencyFromName
                 << left << setw(20) << cur->currencyToName
                 << left << setw(20) << cur->currencyExchangeValue << RESET << endl;
            cur = cur->next;
        }
    }
}

// SEARCH Sequential KURS CURRENCY
Currency *search_kurs(string currencyFromName, string currencyToName)
{
    cur = head;
    while (cur != NULL)
    {
        if (cur->currencyFromName == toUpperCase(currencyFromName) && cur->currencyToName == toUpperCase(currencyToName))
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

// CONVERTER
void konv_currency()
{
    string sourceCurrency, targetCurrency;
    double nominal;

    cout << "↳ INPUT CURRENCY FROM : ";
    cin >> sourceCurrency;
    cout << "↳ INPUT CURRENCY TO : ";
    cin >> targetCurrency;
    cout << "↳ NOMINAL : ";
    cin >> nominal;

    Currency *sourceExchangeRate = search_kurs(sourceCurrency, targetCurrency);

    if (sourceExchangeRate == NULL)
    {
        cout << RED << "\n[ ✉ NO EXCHANGE RATE DATA ! ]" << RESET << endl;
        cout << RED << "[ ✉ ADD EXCHANGE RATE DATA FIRST ! ]\n"
             << RESET << endl;
        return;
    }

    double result = nominal / sourceExchangeRate->currencyExchangeValue;

    sourceCurrency = toUpperCase(sourceCurrency);
    targetCurrency = toUpperCase(targetCurrency);

    cout << GREEN << fixed << setprecision(2);
    cout << "\n[ ⇋ RESULT CONVERT : " << sourceCurrency << " → " << targetCurrency << " ] " << endl;
    cout << "[ ⇋ NOMINAL " << sourceCurrency << " : " << nominal << " | NOMINAL " << targetCurrency << " : " << result << " ]\n"
         << RESET << endl;

    // Mendapatkan waktu saat konversi dilakukan
    time_t now = time(0);
    char *dt = ctime(&now);
    string timeConversion(dt);

    history_konv.push({toUpperCase(sourceCurrency), toUpperCase(targetCurrency), nominal, result, timeConversion});
}

// ADD QUEUE
void add_queue_konv()
{
    string sourceCurrency, targetCurrency;
    double nominal;

    cout << "↳ INPUT CURRENCY FROM : ";
    cin >> sourceCurrency;
    cout << "↳ INPUT CURRENCY TO : ";
    cin >> targetCurrency;
    cout << "↳ NOMINAL : ";
    cin >> nominal;

    queue_konv.push({toUpperCase(sourceCurrency), toUpperCase(targetCurrency), nominal, 0, ""});

    cout << GREEN << "\n[ ✉ CONVERSION QUEUE ADDED ! ]\n"
         << RESET << endl;
}

// PROSES QUEUE
void proses_queue_konv()
{
    if (queue_konv.empty())
    {
        cout << RED << "\n[ ✉ NO CONVERSION QUEUE ! ]\n"
             << RESET << endl;
        return;
    }

    // Menampilkan semua antrian dalam tabel
    queue<Konversi> temp_queue = queue_konv;
    int queueTo = 1;

    cout << GREEN << "\n[ ✉ CLICK 'ENTER' TO PROCESS QUEUE !]\n"
         << RESET;
    cin.ignore(); // Ignore any leftover characters in the input buffer
    cin.get();    // Wait for the user to press enter

    cout << CYAN << left << setw(20) << "[ QUEUE ] "
         << left << setw(25) << "[ CURRENCY FROM ] "
         << left << setw(25) << "[ CURRENCY TO ]"
         << left << setw(20) << "[ NOMINAL ]"
         << left << setw(25) << "[ RESULT CONVERSION ]" << RESET << endl;
    cout << setfill('-') << setw(120) << "-" << setfill(' ') << endl;

    while (!temp_queue.empty())
    {
        Konversi konversi = temp_queue.front();
        temp_queue.pop();

        Currency *sourceExchangeRate = search_kurs(konversi.currencyFrom, konversi.currencyTo);

        if (sourceExchangeRate != NULL)
        {
            konversi.resultConversion = konversi.nominal / sourceExchangeRate->currencyExchangeValue;
        }

        cout << CYAN << left << setw(22) << queueTo
             << left << setw(25) << konversi.currencyFrom
             << left << setw(25) << konversi.currencyTo
             << left << setw(20) << konversi.nominal;

        if (sourceExchangeRate != NULL)
        {
            // Set presisi untuk nilai resultConversion
            cout << fixed << setprecision(2) << left << setw(25) << konversi.resultConversion << RESET;
        }
        else
        {
            cout << RED << left << setw(30) << " [ NO EXCHANGE RATE DATA ]";
        }

        cout << RESET << endl;

        queueTo++;
    }

    while (!queue_konv.empty())
    {
        Konversi konversi = queue_konv.front();
        queue_konv.pop();

        Currency *sourceExchangeRate = search_kurs(konversi.currencyFrom, konversi.currencyTo);

        if (sourceExchangeRate != NULL)
        {
            konversi.resultConversion = konversi.nominal / sourceExchangeRate->currencyExchangeValue;
            // Mendapatkan waktu saat konversi dilakukan
            time_t now = time(0);
            char *dt = ctime(&now);
            string timeConversion(dt);
            konversi.timeConversion = timeConversion;

            history_konv.push(konversi);
        }
    }

    cout << GREEN << "\n[ ✉ CONVERSION QUEUE SUCCESSFULLY PROCESSED! ]\n"
         << RESET << endl;
}

// HISTORY CONVERT (STACK)
void currency_history_konv()
{
    stack<Konversi> temp = history_konv;

    if (temp.empty())
    {
        cout << RED << "\n[ ✉ NO CONVERSION HISTORY ! ]\n"
             << RESET << endl;
        return;
    }

    // Header tabel
    cout << CYAN << left << setw(25) << "[ CURRENCY FROM ] "
         << left << setw(25) << "[ CURRENCY TO ]"
         << left << setw(20) << "[ NOMINAL ]"
         << left << setw(25) << "[ CONVERSION RESULT ]"
         << left << setw(25) << "[ CONVERSION TIME ]" << RESET << endl;
    cout << setfill('-') << setw(120) << "-" << setfill(' ') << endl;

    // Data tabel
    while (!temp.empty())
    {
        Konversi konversi = temp.top();
        temp.pop();

        cout << CYAN << left << setw(27) << konversi.currencyFrom
             << left << setw(25) << konversi.currencyTo
             << left << setw(20) << fixed << setprecision(2) << konversi.nominal
             << left << setw(25) << konversi.resultConversion
             << left << setw(25) << konversi.timeConversion << RESET << endl;
    }
}

// UPDATE CURRENCY
void update_currency()
{
    string currencyFromName, currencyToName;
    double currencyExchangeValue;

    cout << "↳ INPUT CURRENCY FROM : ";
    cin >> currencyFromName;
    cout << "↳ INPUT CURRENCY TO : ";
    cin >> currencyToName;

    Currency *kurs = search_kurs(currencyFromName, currencyToName);

    if (kurs == NULL)
    {
        cout << RED << "\n[ ✉ NO EXCHANGE RATE DATA ! ]" << RESET << endl;
        return;
    }

    cout << "↳ INPUT NEW EXCHANGE RATE : ";
    cin >> currencyExchangeValue;

    kurs->currencyExchangeValue = currencyExchangeValue;

    cout << GREEN << "\n[ ✉ THE CURRENCY EXCHANGE RATE HAS BEEN UPDATED ! ]\n"
         << RESET << endl;
}

// DELETE CURRENCY
void delete_currency()
{
    string currencyFromName, currencyToName;

    cout << "↳ INPUT CURRENCY FROM : ";
    cin >> currencyFromName;
    cout << "↳ INPUT CURRENCY TO : ";
    cin >> currencyToName;

    if (head == NULL)
    {
        cout << RED << "\n[ ✉ NO EXCHANGE RATE DATA ! ]\n"
             << RESET << endl;
        return;
    }

    Currency *prev = NULL;
    cur = head;

    while (cur != NULL)
    {
        if (cur->currencyFromName == toUpperCase(currencyFromName) && cur->currencyToName == toUpperCase(currencyToName))
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
            cout << GREEN << "\n[ ✉ EXCHANGE RATE HAS BEEN DELETED ! ]\n"
                 << RESET << endl;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    cout << RED << "\n[ ✉ NO EXCHANGE RATE DATA ! ]\n"
         << RESET << endl;
}

// INIT CURRENCIES
void init_currencies()
{
    Currency *currencies[] = {
        new Currency{"IDR", "AUD", 10890, NULL},
        new Currency{"IDR", "KRW", 11.91, NULL},
        new Currency{"IDR", "MYR", 3491, NULL},
        new Currency{"IDR", "SGD", 12165, NULL}};

    for (Currency *currency : currencies)
    {
        if (head == NULL)
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
        cout << RED << "[ ✉ LOGIN TO ACCESS THE PROGRAM ! ]" << RESET << endl;
        cout << "↳ USERNAME : " << RESET;
        cin >> username;
        cout << "↳ PASSWORD : " << RESET;
        cin >> password;

        if (authenticate(username, password))
        {
            cout << "\n[ ✉ INCORRECT USERNAME OR PASSWORD ! ]" << endl;
            break;
        }
        else
        {
            cout << GREEN << "\n[ ✉ LOGIN SUCCESS ! ]" << RESET << endl;
        }

        while (true)
        {
            cout << MAGENTA << left << setw(20) << "\n⥮ MENU AM! CONVERTER ⥮" << RESET << endl;
            cout << "[ 1 ] SHOW CURRENCY EXCHANGE RATES" << endl;
            cout << "[ 2 ] ADD CURRENCY EXCHANGE RATE" << endl;
            cout << "[ 3 ] UPDATE CURRENCY EXCHANGE RATE" << endl;
            cout << "[ 4 ] DELETE CURRENCY EXCHANGE RATE" << endl;
            cout << "[ 5 ] CONVERT CURRENCY" << endl;
            cout << "[ 6 ] ADD CONVERSION QUEUE" << endl;
            cout << "[ 7 ] PROCESS CONVERSION QUEUE" << endl;
            cout << "[ 8 ] HISTORY CONVERSION" << endl;
            cout << "[ 9 ] EXIT" << endl;
            cout << "↳ INPUT YOUR CHOICE : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << YELLOW << "\n⌜ EXCHANGE RATE TABLE ⌟\n" << RESET << endl;
                show_kurs();
                break;
            case 2:
                cout << YELLOW << "\n⌜ ADD CURRENCY EXCHANGE RATE ⌟\n" << RESET << endl;
                add_currency();
                break;
            case 3:
                cout << YELLOW << "\n⌜ UPDATE CURRENCY EXCHANGE RATE ⌟\n" << RESET << endl;
                update_currency();
                break;
            case 4:
                cout << YELLOW << "\n⌜ DELETE CURRENCY EXCHANGE RATE ⌟\n" << RESET << endl;
                delete_currency();
                break;
            case 5:
                cout << YELLOW << "\n⌜ CONVERT CURRENCY ⌟\n" << RESET << endl;
                konv_currency();
                break;
            case 6:
                cout << YELLOW << "\n⌜ ADD CONVERSION QUEUE ⌟\n" << RESET << endl;
                add_queue_konv();
                break;
            case 7:
                cout << YELLOW << "\n⌜ PROCESS CONVERSION QUEUE ⌟\n" << RESET << endl;
                proses_queue_konv();
                break;
            case 8:
                cout << YELLOW << "\n⌜ HISTORY CONVERSION ⌟\n" << RESET << endl;
                currency_history_konv();
                break;
            case 9:
                cout << RED << "\n[ ✉ EXIT ! ]\n" << RESET << endl;
                return 0;
            default:
                cout << RED << "\n[ ✉ INVALID CHOICE ! ]\n" << RESET << endl;
                break;
            }
        }
    }

    return 0;
}
