#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_BARANG = 100;
string namaBarang[MAX_BARANG] = {"Oxva xlim GO", "Voopoo Drag X", "TRML T99", "Makna V2 3mg", "Bolu Lapis Talas V1 6mg", "The Orama V1 3mg"};
string jenisBarang[MAX_BARANG] = {"Device", "Device", "Device", "Liquid", "Liquid", "Liquid"};
int jumlahBarangArr[MAX_BARANG] = {10, 7, 5, 15, 12, 20};
int jumlahBarang = 6; // Sesuai dengan jumlah data awal

int main() {
    string nama, nim;
    int menuLogin;
    while (true) {
        do {
            cout << "\nMenu Login:\n";
            cout << "1. Login\n";
            cout << "2. Keluar\n";
            cout << "Pilihan: ";
            cin >> menuLogin;

            if (menuLogin == 2) {
                cout << "Keluar dari program.\n";
                return 0;
            } else if (menuLogin != 1) {
                cout << "Pilihan tidak valid!\n";
            }
        } while (menuLogin != 1);

        int attempts = 0;
        while (attempts < 3) {
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            
            if (nama == "Reja" && nim == "2409106107") {
                break;
            } else {
                cout << "Login gagal! Coba lagi.\n";
                attempts++;
            }
            if (attempts == 3) {
                cout << "Kesempatan login habis. Program berhenti.\n";
                return 0;
            }
        }

        int pilihan;
        do {
            cout << "\nMenu Vape Store:\n";
            cout << "1. Tampilkan Barang\n";
            cout << "2. Tambah Barang\n";
            cout << "3. Ubah Barang\n";
            cout << "4. Hapus Barang\n";
            cout << "5. Logout\n";
            cout << "Pilihan: ";
            cin >> pilihan;

            if (pilihan == 1) {
                if (jumlahBarang == 0) {
                    cout << "Belum ada barang dalam daftar.\n";
                } else {
                    cout << "+-----+----------------------+------------+--------+\n";
                    cout << "| No  | Nama Barang          | Jenis      | Jumlah |\n";
                    cout << "+-----+----------------------+------------+--------+\n";
                    for (int i = 0; i < jumlahBarang; i++) {
                        cout << "| " << setw(3) << i + 1 << " | " << setw(20) << namaBarang[i] << " | " 
                             << setw(10) << jenisBarang[i] << " | " 
                             << setw(6) << jumlahBarangArr[i] << " |\n";
                    }
                    cout << "+-----+----------------------+------------+--------+\n";
                }
            } else if (pilihan == 2) {
                if (jumlahBarang >= MAX_BARANG) {
                    cout << "Kapasitas penyimpanan penuh!\n";
                } else {
                    cout << "Masukkan nama barang: ";
                    cin.ignore();
                    getline(cin, namaBarang[jumlahBarang]);
                    cout << "Masukkan jenis (Device/Liquid): ";
                    getline(cin, jenisBarang[jumlahBarang]);
                    cout << "Masukkan jumlah barang: ";
                    cin >> jumlahBarangArr[jumlahBarang];
                    jumlahBarang++;
                    cout << "Barang berhasil ditambahkan!\n";
                }
            } else if (pilihan == 3) {
                if (jumlahBarang == 0) {
                    cout << "Tidak ada barang untuk diubah.\n";
                } else {
                    int index;
                    cout << "Pilih nomor barang yang ingin diubah: ";
                    cin >> index;
                    if (index < 1 || index > jumlahBarang) {
                        cout << "Nomor tidak valid!\n";
                    } else {
                        cin.ignore();
                        cout << "Masukkan nama baru: ";
                        getline(cin, namaBarang[index - 1]);
                        cout << "Masukkan jenis baru (Device/Liquid): ";
                        getline(cin, jenisBarang[index - 1]);
                        cout << "Masukkan jumlah baru: ";
                        cin >> jumlahBarangArr[index - 1];
                        cout << "Barang berhasil diubah!\n";
                    }
                }
            } else if (pilihan == 4) {
                if (jumlahBarang == 0) {
                    cout << "Tidak ada barang untuk dihapus.\n";
                } else {
                    int index;
                    cout << "Masukkan nomor barang yang akan dihapus: ";
                    cin >> index;
                    if (index < 1 || index > jumlahBarang) {
                        cout << "Nomor tidak valid!\n";
                    } else {
                        for (int i = index - 1; i < jumlahBarang - 1; i++) {
                            namaBarang[i] = namaBarang[i + 1];
                            jenisBarang[i] = jenisBarang[i + 1];
                            jumlahBarangArr[i] = jumlahBarangArr[i + 1];
                        }
                        jumlahBarang--;
                        cout << "Barang berhasil dihapus!\n";
                    }
                }
            } else if (pilihan == 5) {
                cout << "Logout berhasil. Kembali ke menu login.\n";
                break;
            } else {
                cout << "Pilihan tidak valid!\n";
            }
        } while (true);
    }
    return 0;
}
