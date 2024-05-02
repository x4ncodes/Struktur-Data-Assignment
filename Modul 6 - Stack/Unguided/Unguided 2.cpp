/*
Axandio Biyanatul Lizan - 2311102179
*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Pembalikan karakter dalam kata
string reverseKata(string kata) {
    string reversedKata = "";
    for (int a = kata.length() - 1; a >= 0; a--) {
        reversedKata += kata[a];
    }
    return reversedKata;
}

// Pembalikan kalimat menggunakan stack
string pembalikanKalimat(string kalimat) {
    stack<string> kataStack;
    string kata = "";
    string pembalikanKalimat = "";

    // Memisahkan kata-kata dari kalimat dan memasukkan ke dalam stack
    for (char x : kalimat) {
        if (x == ' ') {
            kataStack.push(reverseKata(kata));
            kata = "";
        } else {
            kata += x;
        }
    }

    // Menambahkan kata terakhir kedalam stack
    kataStack.push(reverseKata(kata));

    // Membentuk kalimat terbalik
    while (!kataStack.empty()) {
        pembalikanKalimat += kataStack.top() + " ";
        kataStack.pop();
    }

    return pembalikanKalimat;
}

int main() {
    string kalimat;
    cout << "\n=-=-=-=-= Welcome to Reverse Word Axan =-=-=-=-=-=" << endl;
    cout << "Masukan Kalimat (minimal 3 kata): ";
    getline(cin, kalimat);

    // Memeriksa apakah kalimat memiliki minimal 3 kata
    int kataCount = 0;
    for (char a : kalimat) {
        if (a == ' ') {
            kataCount++;
        }
    }
    if (kataCount < 2) {
        cout << "Kalimat harus memiliki minimal 3 kata!" << endl;
        return 1;
    }

    // Memanggil fungsi pembalikan kalimat
    string hasil = pembalikanKalimat(kalimat);

    // Mencetak Hasil
    cout << "Hasil Data: " << hasil << endl;
    cout << "=-=-=-=-= Thank You =-=-=-=-=-=" << endl;
    return 0;
}
