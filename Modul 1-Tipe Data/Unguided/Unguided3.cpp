#include <iostream>
#include <map>
#include <string>

using namespace std;
// Code Axan find telepon numbers.

int main (){
    map<string, int> contacts;

    contacts["Xansan"] = 1211129;
    contacts["Axan"] = 192380;
    contacts["Lizan"] = 1938043;
    contacts["Abel"] = 394209;

    cout << "Daftar Nomor Telepon : " << endl;
    for(const auto& contact : contacts){
        cout << contact.first << ": " << contact.second << endl;
    }

    cout << endl;
    string searchNama = "Axan";
    if (contacts.find(searchNama) != contacts.end()){
        cout << "Nomor Telepon " << searchNama << ": " << contacts[searchNama] << endl;
    } else {
        cout << "Kontak tidak ditemukan untuk " << searchNama << endl;
    }

    return 0;
}