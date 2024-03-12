#include <iostream>
using namespace std;

class Segitiga {
    private:
    int alas, tinggi;

    public:
    Segitiga(int a, int x){
        alas = a;
        tinggi = x;
    }

    int area(){
        return 0.5 * alas * tinggi;
    }
};

struct PersegiPanjang{
    int panjang, lebar;
};

int main(){

    //Class
    Segitiga s(6,8);

    cout << "Luas Segitiga : " << s.area() << endl;

    //Struct
    PersegiPanjang p;
    p.panjang = 8;
    p.lebar = 10;

    int area = p.panjang * p.lebar;
    cout << "Luas Persegi Panjang: " << area << endl;

    return 0;
}