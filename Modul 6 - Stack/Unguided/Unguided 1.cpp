/*
Axandio Biyanatul Lizan - 2311102179
*/
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

string hapusNonAlpha(string str) {
    string result;
    for (char a : str) {
        if (isalpha(a)) {
            result += tolower(a); // konversi ke huruf kecil
        }
    }
    return result;
}

// pengecekan polindrome atau bukan polindrome
bool isPalindrome(string str) {
    stack<char> charStack;
    int length = str.length();

    for (int a = 0; a < length / 2; a++) {
        charStack.push(str[a]);
    }

    // pengecekan jika string ganjil, maka skip kata ditengah
    if (length % 2 != 0) {
        length++;
    }

    for (int a = length / 2; a < length; a++) {
        if (charStack.empty() || str[a] != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    string masukan;

    cout << "=-=-=-=-= Welcome to Pengecekan Polindrome Word Axan =-=-=-=-=" << endl;
    cout << "Masukkan Kata / Kalimat: ";
    getline(cin, masukan);

    // Menghapus karakter non-alfabet dan menkonversi huruf menjadi huruf kecil
    string cleanMasukan = hapusNonAlpha(masukan);

    // pengecekan apakah kata yang sudah di clean polindrome atau bukan polindrome
    if (isPalindrome(cleanMasukan)) {
        cout << "Kategori kata / kalimat tersebut: Palindrom" << endl;
    } else {
        cout << "Kategori kata / kalimat tersebut: Bukan Palindrom" << endl;
    }
    cout << "=-=-=-= See you!! =-=-=-=-=" << endl;
    cout << "\n";
    return 0;
}