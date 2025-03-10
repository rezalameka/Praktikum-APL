#include <iostream> 

using namespace std;

// Fungsi untuk memeriksa apakah bilangan adalah bilangan prima
bool bujurprima(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool cekPalindrome(int angka) {
    int bujur = angka, kebalik = 0, digit;
    while (angka > 0) {
        digit = angka % 10;
        kebalik = kebalik * 10 + digit;
        angka /= 10;
    }
    return bujur == kebalik;
}

bool login() {
    string username, usernameBujur = "Reza";
    string pw, pwbujur = "2409106107";

    cin.ignore();
    while (true) {
        cout << "\nLOGIN \n";
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, pw);

        if (username == usernameBujur && pw == pwbujur) {
            cout << "Login berhasil!\n";
            return true;
        } else {
            cout << "Login gagal! Silakan coba lagi.\n";
        }
    }
}

int main() {
    while (true) {
        int opsi;
        cout << "SELAMAT DATANG \n";
        cout << "1. Login\n";
        cout << "2. Keluar\n";
        cout << "Pilih opsi wal: ";
        
        while (!(cin >> opsi)) {
            cout << "Input tidak valid! Masukkan angka.\nPilih opsi: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (opsi == 2) {
            cout << "Terima kasih Boskuhh.\n";
            return 0;
        } else if (opsi != 1) {
            cout << "Opsi tidak valid! Silakan pilih kembali boskuh.\n";
            continue;
        }

        if (!login()) {
            continue;
        }

        while (true) {
            int kode_sandi;

            cout << "Masukkan kode sandi rahasia (angka bulat positif): ";
            cin >> kode_sandi;

            if (kode_sandi <= 100 || kode_sandi > 99999) {
                cout << "Kode sandi harus lebih dari 100 dan tidak lebih dari 99999." << endl;
                continue;
            }

            // Menu Pilihan
            cout << "\nMenu:" << endl;
            cout << "1. Cek apakah kode sandi sebagai bilangan prima" << endl;
            cout << "2. Cek apakah kode sandi habis dibagi 2 dan 3 tetapi tidak habis dibagi 5" << endl;
            cout << "3. Cek apakah kode sandi adalah bilangan palindrome\n";
            cout << "4. Logout dari akun" << endl;
            cout << "Pilih opsi (1/2/3/4): ";
            int pilihan;
            cin >> pilihan;

            if (pilihan == 1) {
                if (bujurprima(kode_sandi)) {
                    cout << kode_sandi << " adalah bilangan prima." << endl;
                } else {
                    cout << kode_sandi << " bukan bilangan prima." << endl;
                }
            } else if (pilihan == 2) {
                if (kode_sandi % 2 == 0 && kode_sandi % 3 == 0 && kode_sandi % 5 != 0) {
                    cout << kode_sandi << " habis dibagi 2 dan 3 tetapi tidak habis dibagi 5." << endl;
                } else {
                    cout << kode_sandi << " tidak memenuhi syarat." << endl;
                }
            }  else if (pilihan == 3) {
                cout << (cekPalindrome(kode_sandi) ? "Kode sandi adalah bilangan palindrome.\n" : "Kode sandi bukan bilangan palindrome.\n");
      
            }  else if (pilihan == 4) {
                cout << "Logout berhasil!\n";
                break; 
            } else {
                cout << "Pilihan tidak valid! Silakan pilih opsi yang benar." << endl;
            }
        }
    }

    return 0;
}