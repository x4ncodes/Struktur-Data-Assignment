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
