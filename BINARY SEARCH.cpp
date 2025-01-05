#include <iostream>
using namespace std;

// Fungsi Binary Search
int binary_search(int arr[], int size, int x) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Jika elemen ditemukan
        if (arr[mid] == x) {
            return mid;
        }
        // Jika elemen lebih kecil dari nilai tengah
        else if (arr[mid] > x) {
            high = mid - 1;
        }
        // Jika elemen lebih besar dari nilai tengah
        else {
            low = mid + 1;
        }
    }

    return -1; // Jika elemen tidak ditemukan
}

int main() {
    // Menampilkan Nama dan NIM
    cout << "Nama: MUHAMAD ALFATIH" << endl;  
    cout << "NIM: 201011402109" << endl; 

    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};  // Dataset terurut
    int size = sizeof(arr) / sizeof(arr[0]);  // Ukuran array
    int x = 7;  // Elemen yang dicari

    int result = binary_search(arr, size, x);

    if (result != -1) {
        cout << "Elemen ditemukan di indeks " << result << endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }

    return 0;
}

