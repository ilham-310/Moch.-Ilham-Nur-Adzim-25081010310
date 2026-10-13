#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Mengubah nama menjadi Proper Case
string properCase(string nama) {
    bool awalKata = true;

    for (int i = 0; i < (int)nama.length(); i++) {
        if (nama[i] == ' ') {
            awalKata = true;
        } else {
            if (awalKata) {
                nama[i] = toupper(nama[i]);
                awalKata = false;
            } else {
                nama[i] = tolower(nama[i]);
            }
        }
    }

    return nama;
}

int main() {
    string nama, npm, email;
    string domain = "@upnjatim.ac.id";

    // Membaca data mahasiswa
    cout << "Masukkan nama lengkap: ";
    getline(cin, nama);

    cout << "Masukkan NPM: ";
    getline(cin, npm);

    cout << "Masukkan email: ";
    getline(cin, email);

    // Mengubah nama menjadi Proper Case
    nama = properCase(nama);

    // Memeriksa akhiran email
    bool emailValid = false;

    if (email.length() >= domain.length()) {
        emailValid =
            email.substr(email.length() - domain.length()) == domain;
    }

    // Menampilkan data dan status validasi
    cout << "\nNama   : " << nama << endl;
    cout << "NPM    : " << npm << endl;
    cout << "Email  : " << email << endl;

    if (emailValid) {
        cout << "Status : Data Valid" << endl;
    } else {
        cout << "Status : Email tidak valid" << endl;
    }

    return 0;
}