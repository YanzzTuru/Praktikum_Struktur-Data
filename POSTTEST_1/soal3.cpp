#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int jumlah = 5; 
    Mahasiswa mhs[jumlah];

    cout << "=== Input Data Mahasiswa ===" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin >> ws; 
        getline(cin, mhs[i].nama);
        cout << "NIM   : ";
        cin >> mhs[i].nim;
        cout << "IPK   : ";
        cin >> mhs[i].ipk;
    }

    int idxMax = 0;
    for (int i = 1; i < jumlah; i++) {
        if (mhs[i].ipk > mhs[idxMax].ipk) {
            idxMax = i;
        }
    }

    cout << "\n=== Mahasiswa dengan IPK Tertinggi ===" << endl;
    cout << "Nama : " << mhs[idxMax].nama << endl;
    cout << "NIM  : " << mhs[idxMax].nim << endl;
    cout << "IPK  : " << mhs[idxMax].ipk << endl;

    return 0;
}
