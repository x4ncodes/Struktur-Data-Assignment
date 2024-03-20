#include <iostream>
using namespace std;

int main (){
    int x,y,z;

    cout << "Masukan dimensi X (Array) : ";
    cin >> x;
    cout << "Masukan dimensi Y (Array) : ";
    cin >> y;
    cout << "Masukan dimensi Z (Array) : ";
    cin >> z;

    int array [x][y][z];

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                cout << "Masukan data Array [" << i << "][" << j << "][" << k << "]: ";
                cin >> array [i][j][k];
            }
        }
        cout << endl;
    }

    cout << "Data Array: " << endl;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int k = 0; k < z; k++){
                cout << array [i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}