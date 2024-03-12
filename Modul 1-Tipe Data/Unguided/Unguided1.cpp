#include <iostream>
using namespace std;

int HitungLuasLingkaran(int jari){
    return 3.14 * jari * jari;
}

int kelilingLingkaran(int jari){
    return 2 * 3.14 * jari;
}

int main(){
    int jari;
    cout << "\nKalkulator Lingkaran" << endl;
    cout << "Masukan Jari-Jari Lingkaran : ";
    cin >> jari;
    cout << endl;

    int luas = HitungLuasLingkaran(jari);
    int keliling = kelilingLingkaran(jari);

    cout << "Hasil Luas Lingkaran: " << luas << endl;
    cout << "Hasil Keliling Lingkaran: " << keliling << endl;

    return 0;
}