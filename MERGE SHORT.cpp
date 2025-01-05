#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

// Struktur data untuk menyimpan informasi pesanan
struct Pesanan {
    string id_pesanan;
    string lokasi_pengambilan;
    string lokasi_tujuan;
    string waktu_pemesanan;

    // Fungsi untuk mengonversi waktu pemesanan ke time_t agar bisa diurutkan
    time_t waktu_to_time_t() const {
        struct tm tm = {0};  // Inisialisasi struktur tm menjadi nol
        stringstream ss(waktu_pemesanan);
        char separator;

        // Parsing tanggal (YYYY-MM-DD)
        ss >> tm.tm_year >> separator >> tm.tm_mon >> separator >> tm.tm_mday;

        tm.tm_year -= 1900;  // Tahun dimulai dari 1900, kurangi dengan 1900
        tm.tm_mon -= 1;      // Bulan dimulai dari 0 (Januari), kurangi dengan 1

        // Parsing waktu (HH:MM:SS)
        ss >> separator >> tm.tm_hour >> separator >> tm.tm_min >> separator >> tm.tm_sec;

        // Mengonversi tm ke time_t untuk perbandingan
        return mktime(&tm);
    }
};

// Fungsi merge untuk menggabungkan dua bagian yang sudah terurut
void merge(vector<Pesanan>& pesanan, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Membuat vector sementara untuk menyimpan bagian kiri dan kanan
    vector<Pesanan> left(n1), right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = pesanan[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = pesanan[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i].waktu_to_time_t() <= right[j].waktu_to_time_t()) {
            pesanan[k++] = left[i++];
        } else {
            pesanan[k++] = right[j++];
        }
    }

    // Menyalin sisa elemen dari left
    while (i < n1) {
        pesanan[k++] = left[i++];
    }

    // Menyalin sisa elemen dari right
    while (j < n2) {
        pesanan[k++] = right[j++];
    }
}

// Fungsi untuk menerapkan merge sort
void mergeSort(vector<Pesanan>& pesanan, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Mengurutkan bagian kiri dan kanan secara rekursif
        mergeSort(pesanan, low, mid);
        mergeSort(pesanan, mid + 1, high);

        // Menggabungkan dua bagian yang sudah terurut
        merge(pesanan, low, mid, high);
    }
}

// Fungsi untuk menampilkan data pesanan
void tampilkanPesanan(const vector<Pesanan>& pesanan) {
    for (size_t i = 0; i < pesanan.size(); i++) {
        const Pesanan& p = pesanan[i]; 
        cout << "ID Pesanan: " << p.id_pesanan << ", "
             << "Lokasi Pengambilan: " << p.lokasi_pengambilan << ", "
             << "Lokasi Tujuan: " << p.lokasi_tujuan << ", "
             << "Waktu Pemesanan: " << p.waktu_pemesanan << endl;
    }
}

int main() {
    // Menampilkan Nama dan NIM
    cout << "Nama: Muhamad Alfatih\n";
    cout << "NIM: 201011402109\n\n";

    // Data pesanan yang akan diurutkan
    vector<Pesanan> pesanan = {
        {"001", "Jakarta", "Bandung", "2025-01-05 14:30:00"},
        {"002", "Surabaya", "Malang", "2025-01-05 13:00:00"},
        {"003", "Medan", "Padang", "2025-01-05 15:00:00"},
        {"004", "Yogyakarta", "Solo", "2025-01-05 12:00:00"}
    };

    cout << "Data pesanan sebelum diurutkan:\n";
    tampilkanPesanan(pesanan);

    // Mengurutkan pesanan berdasarkan waktu pemesanan menggunakan Merge Sort
    mergeSort(pesanan, 0, pesanan.size() - 1);

    cout << "\nData pesanan setelah diurutkan berdasarkan waktu pemesanan:\n";
    tampilkanPesanan(pesanan);

    return 0;
}

