#include <iostream>
using namespace std;

void balikArray(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    const int n = 7; 
    int arr[n];

    int prima[] = {2, 3, 5, 7, 11, 13, 17}; 
    int idxPrima = 0;
    int kelipatan = 3;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { 
            arr[i] = prima[idxPrima++];
        } else {          
            arr[i] = kelipatan;
            kelipatan += 3;
        }
    }

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    balikArray(arr, n);

    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
