#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_BARANG = 100;
const int MAX_USER = 100;

struct Barang {
    string nama;
    string jenis;
    int jumlah;
};

struct User {
    string username;
    string password;
};

struct VapeStore {
    Barang barang[MAX_BARANG];
    User users[MAX_USER];
    int jumlahBarang = 6; // Jumlah data awal
    int jumlahUser = 0;   // Jumlah user terdaftar
};

int main() {
    VapeStore store = {
        {{"Oxva xlim GO", "Device", 10}, {"Voopoo Drag X", "Device", 7}, {"TRML T99", "Device", 5}, {"Makna V2 3mg", "Liquid", 15}, {"Bolu Lapis Talas V1 6mg", "Liquid", 12}, {"The Orama V1 3mg", "Liquid", 20}},
        {},
        6,
        0
    };

    while (true) {
        int menuLogin;
        cout << "\nMenu Login:\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> menuLogin;

        if (menuLogin == 3) {
            cout << "Keluar dari program.\n";
            break;
        }

        if (menuLogin == 2) {
            // Registrasi user baru
            if (store.jumlahUser >= MAX_USER) {
                cout << "Kapasitas user penuh!\n";
                continue;
            }

            cout << "Masukkan Username: ";
            cin >> store.users[store.jumlahUser].username;
            cout << "Masukkan Password: ";
            cin >> store.users[store.jumlahUser].password;
            store.jumlahUser++;
            cout << "Registrasi berhasil!\n";
            continue;
        }

        if (menuLogin != 1) {
            cout << "Pilihan tidak valid!\n";
            continue;
        }

        // Proses login
        string username, password;
        int attempts = 0;
        bool loginBerhasil = false;
        bool Admin = false;

        while (attempts < 3) {
            cout << "Masukkan Username: ";
            cin >> username;
            cout << "Masukkan Password: ";
            cin >> password;

            // Cek apakah admin
            if (username == "reja" && password == "2409106107") {
                loginBerhasil = true;
                Admin = true;
                break;
            }

            // Cek apakah user terdaftar
            for (int i = 0; i < store.jumlahUser; i++) {
                if (store.users[i].username == username && store.users[i].password == password) {
                    loginBerhasil = true;
                    break;
                }
            }
            if (loginBerhasil) {
                break;
            } else {
                cout << "Login gagal! Coba lagi.\n";
                attempts++;
            }
        }

        if (attempts == 3) {
            cout << "Kesempatan login habis. Program berhenti.\n";
            break;
        }

        
        while (true) {
            int pilihan;
            cout << "\nMenu Vape Store:\n";
            cout << "1. Tampilkan Barang\n";
            if (Admin) {
                cout << "2. Tambah Barang\n";
                cout << "3. Ubah Barang\n";
                cout << "4. Hapus Barang\n";
            }
            cout << "5. Logout\n";
            cout << "Pilihan: ";
            cin >> pilihan;

            if (pilihan == 1) {
                if (store.jumlahBarang == 0) {
                    cout << "Belum ada barang dalam daftar.\n";
                } else {
                    cout << "+-----+----------------------+------------+--------+\n";
                    cout << "| No  | Nama Barang          | Jenis      | Jumlah |\n";
                    cout << "+-----+----------------------+------------+--------+\n";
                    for (int i = 0; i < store.jumlahBarang; i++) {
                        cout << "| " << setw(3) << i + 1 << " | " << setw(20) << store.barang[i].nama << " | " 
                             << setw(10) << store.barang[i].jenis << " | " 
                             << setw(6) << store.barang[i].jumlah << " |\n";
                    }
                    cout << "+-----+----------------------+------------+--------+\n";
                }
            } else if (pilihan == 2 && Admin) {
                if (store.jumlahBarang >= MAX_BARANG) {
                    cout << "Kapasitas penyimpanan penuh!\n";
                } else {
                    cout << "Masukkan nama barang: ";
                    cin.ignore();
                    getline(cin, store.barang[store.jumlahBarang].nama);
                    cout << "Masukkan jenis (Device/Liquid): ";
                    getline(cin, store.barang[store.jumlahBarang].jenis);
                    cout << "Masukkan jumlah barang: ";
                    cin >> store.barang[store.jumlahBarang].jumlah;
                    store.jumlahBarang++;
                    cout << "Barang berhasil ditambahkan!\n";
                }
            } else if (pilihan == 3 && Admin) {
                if (store.jumlahBarang == 0) {
                    cout << "Tidak ada barang untuk diubah.\n";
                } else {
                    int index;
                    cout << "Pilih nomor barang yang ingin diubah: ";
                    cin >> index;

                    if (index < 1 || index > store.jumlahBarang) {
                        cout << "Nomor tidak valid!\n";
                    } else {
                        cin.ignore();
                        cout << "Masukkan nama baru: ";
                        getline(cin, store.barang[index - 1].nama);
                        cout << "Masukkan jenis baru (Device/Liquid): ";
                        getline(cin, store.barang[index - 1].jenis);
                        cout << "Masukkan jumlah baru: ";
                        cin >> store.barang[index - 1].jumlah;
                        cout << "Barang berhasil diubah!\n";
                    }
                }
            } else if (pilihan == 4 && Admin) {
                if (store.jumlahBarang == 0) {
                    cout << "Tidak ada barang untuk dihapus.\n";
                } else {
                    int index;
                    cout << "Masukkan nomor barang yang akan dihapus: ";
                    cin >> index;

                    if (index < 1 || index > store.jumlahBarang) {
                        cout << "Nomor tidak valid!\n";
                    } else {
                        for (int i = index - 1; i < store.jumlahBarang - 1; i++) {
                            store.barang[i] = store.barang[i + 1];
                        }
                        store.jumlahBarang--;
                        cout << "Barang berhasil dihapus!\n";
                    }
                }
            } else if (pilihan == 5) {
                cout << "Logout berhasil. Kembali ke menu login.\n";
                break;
            } else {
                cout << "Pilihan tidak valid!\n";
            }
        }
    }

    return 0;
}