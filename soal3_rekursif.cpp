#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Fungsi rekursif untuk menghitung karakter
void hitung(string kalimat, int i, int &vokal,
            int &konsonan, int &spasi, int &kapital) {

    // Kondisi berhenti jika semua karakter sudah diperiksa
    if (i >= (int)kalimat.length()) {
        return;
    }

    char c = kalimat[i];
    char kecil = tolower(c);

    // Menghitung huruf vokal
    if (kecil == 'a' || kecil == 'i' || kecil == 'u' ||
        kecil == 'e' || kecil == 'o') {
        vokal++;
    }
    // Menghitung huruf konsonan
    else if (kecil >= 'a' && kecil <= 'z') {
        konsonan++;
    }

    // Menghitung jumlah spasi
    if (c == ' ') {
        spasi++;
    }

    // Menghitung jumlah huruf kapital
    if (isupper(c)) {
        kapital++;
    }

    // Memanggil fungsi untuk memeriksa karakter berikutnya
    hitung(kalimat, i + 1, vokal, konsonan, spasi, kapital);
}

int main() {
    string kalimat;
    int vokal = 0, konsonan = 0;
    int spasi = 0, kapital = 0;

    // Memasukkan kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // Memulai proses rekursif dari karakter pertama
    hitung(kalimat, 0, vokal, konsonan, spasi, kapital);

    // Menampilkan hasil perhitungan
    cout << "Vokal    : " << vokal << endl;
    cout << "Konsonan : " << konsonan << endl;
    cout << "Spasi    : " << spasi << endl;
    cout << "Kapital  : " << kapital << endl;

    return 0;
}