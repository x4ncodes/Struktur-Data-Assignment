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