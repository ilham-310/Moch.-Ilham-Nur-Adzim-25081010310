#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Fungsi rekursif untuk menghitung ekspresi prefix
long long evaluasi(stringstream &ss) {
    string token;
    ss >> token;

    // Jika token berupa operator
    if (token == "+" || token == "-" ||
        token == "*" || token == "/" ||
        token == ">" || token == "<" ||
        token == "=") {

        // Menghitung operand kiri dan kanan
        long long a = evaluasi(ss);
        long long b = evaluasi(ss);

        // Melakukan operasi sesuai operator
        if (token == "+") return a + b;
        if (token == "-") return a - b;
        if (token == "*") return a * b;

        if (token == "/") {
            if (b == 0) {
                throw runtime_error("Pembagian dengan nol");
            }
            return a / b;
        }

        if (token == ">") return a > b;
        if (token == "<") return a < b;
        if (token == "=") return a == b;
    }

    // Jika token berupa bilangan
    return stoll(token);
}

int main() {
    string ekspresi;

    // Membaca ekspresi prefix dari pengguna
    cout << "Masukkan ekspresi prefix: ";
    getline(cin, ekspresi);

    try {
        stringstream ss(ekspresi);

        // Menghitung hasil akhir ekspresi
        long long hasil = evaluasi(ss);

        cout << "Ekspresi: " << ekspresi << endl;
        cout << "Hasil: " << hasil << endl;
    }
    catch (const exception &e) {
        cout << "Ekspresi tidak valid atau terjadi kesalahan."
             << endl;
    }

    return 0;
}