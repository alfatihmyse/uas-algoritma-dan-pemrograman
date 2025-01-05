#include <iostream>
using namespace std;

// Fungsi Linear Search
int linear_search(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;  // Mengembalikan indeks jika ditemukan
        }
    }
    return -1;  // Mengembalikan -1 jika elemen tidak ditemukan
}

int main() {
    // Menampilkan Nama dan NIM
    cout << "Nama: MUHAMAD ALFATIH" << endl; 
    cout << "NIM: 201011402109" << endl; 

    int arr[] = {15, 3, 9, 7, 13, 5, 1};  // Dataset tidak terurut
    int size = sizeof(arr) / sizeof(arr[0]);  // Ukuran array
    int x = 7;  // Elemen yang dicari

    int result = linear_search(arr, size, x);

    if (result != -1) {
        cout << "Elemen ditemukan di indeks " << result << endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }

    return 0;
}

