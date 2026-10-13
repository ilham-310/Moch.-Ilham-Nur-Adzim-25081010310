#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Mengecek apakah karakter termasuk huruf vokal
bool vokal(char c) {
    c = tolower(c);
    return c == 'a' || c == 'i' || c == 'u' ||
           c == 'e' || c == 'o';
}

// Mengecek apakah karakter termasuk huruf konsonan
bool konsonan(char c) {
    c = tolower(c);
    return c >= 'a' && c <= 'z' && !vokal(c);
}

int main() {
    string kalimat;
    int vokalBerurutan = 0;
    int konsonanBerurutan = 0;

    // Memasukkan kalimat dari pengguna
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    int i = 0;

    // Memeriksa setiap kelompok huruf dalam kalimat
    while (i < (int)kalimat.length()) {
        int j = i;

        if (vokal(kalimat[i])) {
            // Menghitung huruf vokal yang berurutan
            while (j < (int)kalimat.length() &&
                   vokal(kalimat[j])) {
                j++;
            }

            // Kelompok vokal dihitung jika minimal 2 huruf
            if (j - i >= 2) {
                vokalBerurutan++;
            }
        }
        else if (konsonan(kalimat[i])) {
            // Menghitung huruf konsonan yang berurutan
            while (j < (int)kalimat.length() &&
                   konsonan(kalimat[j])) {
                j++;
            }

            // Kelompok konsonan dihitung jika minimal 2 huruf
            if (j - i >= 2) {
                konsonanBerurutan++;
            }
        }

        // Melanjutkan pemeriksaan ke kelompok berikutnya
        if (j == i) {
            i++;
        } else {
            i = j;
        }
    }

    // Menampilkan hasil perhitungan
    cout << "Vokal berurutan: "
         << vokalBerurutan << endl;

    cout << "Konsonan berurutan: "
         << konsonanBerurutan << endl;

    return 0;
}