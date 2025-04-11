#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int MAX_BARANG = 100;
int MAX_USER = 100;

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
    Barang barang[100];
    User users[100];
    int jumlahBarang = 6;
    int jumlahUser = 0;
};

void tampilkanMenuLogin();
void prosesLogin(VapeStore &store, bool &loginBerhasil, bool &isAdmin);
void prosesRegister(VapeStore &store);
void tampilkanMenuUser();
void tampilkanMenuAdmin();
void tampilkanBarang(VapeStore &store);
void tambahBarang(VapeStore &store);
void ubahBarang(VapeStore &store);
void hapusBarang(VapeStore &store);
void tampilkanHeaderTabel();
void tampilkanBarisBarang(Barang &barang, int index);
void tampilkanFooterTabel();
int hitungTotalBarang(VapeStore &store);
int hitungTotalBarang(VapeStore &store, string &jenis);
int faktorial(int n);
void tampilkanInfoTotalBarang(VapeStore &store);

// Fungsi utama
int main() {
    VapeStore store = {
        {{"Oxva xlim GO", "Device", 10}, {"Voopoo Drag X", "Device", 7}, {"TRML T99", "Device", 5}, 
         {"Makna V2 3mg", "Liquid", 15}, {"Bolu Lapis Talas V1 6mg", "Liquid", 12}, {"The Orama V1 3mg", "Liquid", 20}},
        {},
        6,
        0
    };

    while (true) {
        tampilkanMenuLogin();
        int menuLogin;
        cout << "Pilihan: ";
        cin >> menuLogin;

        switch (menuLogin) {
            case 1: {
                bool loginBerhasil = false;
                bool isAdmin = false;
                prosesLogin(store, loginBerhasil, isAdmin);
                
                if (loginBerhasil) {
                    if (isAdmin) {
                        // Menu Admin
                        while (true) {
                            tampilkanMenuAdmin();
                            int pilihan;
                            cout << "Pilihan: ";
                            cin >> pilihan;

                            switch (pilihan) {
                                case 1: tampilkanBarang(store); break;
                                case 2: tambahBarang(store); break;
                                case 3: ubahBarang(store); break;
                                case 4: hapusBarang(store); break;
                                case 5: tampilkanInfoTotalBarang(store); break;
                                case 6: 
                                    cout << "Logout berhasil.\n";
                                    goto logout;
                                default: 
                                    cout << "Pilihan tidak valid!\n";
                            }
                        }
                    } else {
                        // Menu User Biasa
                        while (true) {
                            tampilkanMenuUser();
                            int pilihan;
                            cout << "Pilihan: ";
                            cin >> pilihan;

                            switch (pilihan) {
                                case 1: tampilkanBarang(store); break;
                                case 2: 
                                    cout << "Logout berhasil.\n";
                                    goto logout;
                                default: 
                                    cout << "Pilihan tidak valid!\n";
                            }
                        }
                    }
                    logout:;
                }
                break;
            }
            case 2:
                prosesRegister(store);
                break;
            case 3:
                cout << "Keluar dari program.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}


void tampilkanMenuLogin() {
    cout << "\n=== Menu Login ===\n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "3. Keluar\n";
}

void prosesLogin(VapeStore &store, bool &loginBerhasil, bool &isAdmin) {
    string username, password;
    int attempts = 0;
    loginBerhasil = false;
    isAdmin = false;

    while (attempts < 3 && !loginBerhasil) {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        // Cek admin
        if (username == "reja" && password == "2409106107") {
            loginBerhasil = true;
            isAdmin = true;
            cout << "Login sebagai admin berhasil!\n";
            return;
        }

        // Cek user biasa
        for (int i = 0; i < store.jumlahUser; i++) {
            if (store.users[i].username == username && store.users[i].password == password) {
                loginBerhasil = true;
                cout << "Login berhasil!\n";
                return;
            }
        }

        cout << "Login gagal! Coba lagi.\n";
        attempts++;
    }

    if (attempts == 3) {
        cout << "Kesempatan login habis. Program berhenti.\n";
        exit(0);
    }
}

void prosesRegister(VapeStore &store) {
    if (store.jumlahUser >= MAX_USER) {
        cout << "Kapasitas user penuh!\n";
        return;
    }

    cout << "Username: ";
    cin >> store.users[store.jumlahUser].username;
    cout << "Password: ";
    cin >> store.users[store.jumlahUser].password;
    store.jumlahUser++;
    cout << "Registrasi berhasil!\n";
}

void tampilkanMenuUser() {
    cout << "\n=== Menu User ===\n";
    cout << "1. Tampilkan Barang\n";
    cout << "2. Logout\n";
}

void tampilkanMenuAdmin() {
    cout << "\n=== Menu Admin ===\n";
    cout << "1. Tampilkan Barang\n";
    cout << "2. Tambah Barang\n";
    cout << "3. Ubah Barang\n";
    cout << "4. Hapus Barang\n";
    cout << "5. Info Total Barang\n";
    cout << "6. Logout\n";
}

void tampilkanBarang(VapeStore &store) {
    if (store.jumlahBarang == 0) {
        cout << "Belum ada barang dalam daftar.\n";
        return;
    }

    tampilkanHeaderTabel();
    for (int i = 0; i < store.jumlahBarang; i++) {
        tampilkanBarisBarang(store.barang[i], i + 1);
    }
    tampilkanFooterTabel();
}

void tambahBarang(VapeStore &store) {
    if (store.jumlahBarang >= MAX_BARANG) {
        cout << "Kapasitas penyimpanan penuh!\n";
        return;
    }

    cout << "Nama barang: ";
    cin.ignore();
    getline(cin, store.barang[store.jumlahBarang].nama);
    cout << "Jenis (Device/Liquid): ";
    getline(cin, store.barang[store.jumlahBarang].jenis);
    cout << "Jumlah: ";
    cin >> store.barang[store.jumlahBarang].jumlah;
    store.jumlahBarang++;
    cout << "Barang berhasil ditambahkan!\n";
}

void ubahBarang(VapeStore &store) {
    if (store.jumlahBarang == 0) {
        cout << "Tidak ada barang untuk diubah.\n";
        return;
    }

    tampilkanBarang(store);
    int index;
    cout << "Pilih nomor barang yang ingin diubah: ";
    cin >> index;

    if (index < 1 || index > store.jumlahBarang) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    cin.ignore();
    cout << "Nama baru: ";
    getline(cin, store.barang[index - 1].nama);
    cout << "Jenis baru (Device/Liquid): ";
    getline(cin, store.barang[index - 1].jenis);
    cout << "Jumlah baru: ";
    cin >> store.barang[index - 1].jumlah;
    cout << "Barang berhasil diubah!\n";
}

void hapusBarang(VapeStore &store) {
    if (store.jumlahBarang == 0) {
        cout << "Tidak ada barang untuk dihapus.\n";
        return;
    }

    tampilkanBarang(store);
    int index;
    cout << "Pilih nomor barang yang akan dihapus: ";
    cin >> index;

    if (index < 1 || index > store.jumlahBarang) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    for (int i = index - 1; i < store.jumlahBarang - 1; i++) {
        store.barang[i] = store.barang[i + 1];
    }
    store.jumlahBarang--;
    cout << "Barang berhasil dihapus!\n";
}

void tampilkanHeaderTabel() {
    cout << "+-----+----------------------+------------+--------+\n";
    cout << "| No  | Nama Barang          | Jenis      | Jumlah |\n";
    cout << "+-----+----------------------+------------+--------+\n";
}

void tampilkanBarisBarang(Barang &barang, int index) {
    cout << "| " << setw(3) << index << " | " << setw(20) << barang.nama << " | " 
         << setw(10) << barang.jenis << " | " 
         << setw(6) << barang.jumlah << " |\n";
}

void tampilkanFooterTabel() {
    cout << "+-----+----------------------+------------+--------+\n";
}


int hitungTotalBarang(VapeStore &store) {
    int total = 0;
    for (int i = 0; i < store.jumlahBarang; i++) {
        total += store.barang[i].jumlah;
    }
    return total;
}

int hitungTotalBarang(VapeStore &store, string &jenis) {
    int total = 0;
    for (int i = 0; i < store.jumlahBarang; i++) {
        if (store.barang[i].jenis == jenis) {
            total += store.barang[i].jumlah;
        }
    }
    return total;
}

int faktorial(int n) {
    if (n <= 1) return 1;
    return n * faktorial(n - 1);
}


void tampilkanInfoTotalBarang(VapeStore &store) {
    cout << "\n=== Informasi Total Barang ===\n";
    cout << "Total semua barang: " << hitungTotalBarang(store) << endl;
    
    string jenis1 = "Device";
    string jenis2 = "Liquid";
    cout << "Total Device: " << hitungTotalBarang(store, jenis1) << endl;
    cout << "Total Liquid: " << hitungTotalBarang(store, jenis2) << endl;
    
    cout << "\nDemo Fungsi Rekursif (Faktorial):\n";
    for (int i = 1; i <= 5; i++) {
        cout << "Faktorial " << i << ": " << faktorial(i) << endl;
    }
}