#include <iostream>
using namespace std;

int main() {
    const int n = 3;
    int matriks[n][n];
    int nilai = 1; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriks[i][j] = nilai++;
        }
    }

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    int jumlahDiagonalUtama = 0;
    int jumlahDiagonalSekunder = 0;

    for (int i = 0; i < n; i++) {
        jumlahDiagonalUtama += matriks[i][i];               
        jumlahDiagonalSekunder += matriks[i][n - i - 1];   
    }

    int total = jumlahDiagonalUtama + jumlahDiagonalSekunder;

    cout << "\nJumlah diagonal utama = " << jumlahDiagonalUtama << endl;
    cout << "Jumlah diagonal sekunder = " << jumlahDiagonalSekunder << endl;
    cout << "Total (utama + sekunder) = " << total << endl;

    return 0;
}
