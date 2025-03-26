#include <iostream>
#include <cmath>
using namespace std;

// Kelas Kalkulator dengan Abstraction & Encapsulation
class Kalkulator {
public:
    double tambah(double a, double b) { return operasi(a, b, '+'); }
    double kurang(double a, double b) { return operasi(a, b, '-'); }
    double kali(double a, double b) { return operasi(a, b, '*'); }
    double bagi(double a, double b) { return operasi(a, b, '/'); }
private:
    double operasi(double a, double b, char op) {
        if (op == '/' && b == 0) {
            cout << "Waduh! Bagi nol tuh dilarang!" << endl;
            return 0;
        }
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0;
        }
    }
};

// Kelas Mahasiswa dengan Encapsulation
class Mahasiswa {
private:
    string nama;
    int ID;
    char nilai;
public:
    void setData(string n, int id, char nl) {
        nama = n;
        ID = id;
        nilai = nl;
    }
    void tampilkanInfo() {
        cout << "Nama: " << nama << ", ID: " << ID << ", Nilai: " << nilai << endl;
    }
};

// Kelas PersegiPanjang dengan Encapsulation
class PersegiPanjang {
private:
    double panjang, lebar;
public:
    void setData(double p, double l) {
        panjang = p;
        lebar = l;
    }
    double hitungLuas() { return panjang * lebar; }
};

// Kelas Penghitung dengan Encapsulation
class Penghitung {
private:
    int hitungan;
public:
    Penghitung() : hitungan(0) {}
    void tambah() { hitungan++; }
    int nilaiSekarang() { return hitungan; }
};

// Kelas Titik dengan Abstraction
class Titik {
private:
    double x, y;
public:
    void setData(double xVal, double yVal) {
        x = xVal;
        y = yVal;
    }
    double jarakDariNol() { return sqrt(kuadrat(x) + kuadrat(y)); }
private:
    double kuadrat(double nilai) { return nilai * nilai; }
};

int main() {
    Kalkulator k;
    double a, b;
    cout << "Masukkan dua angka untuk operasi kalkulator: ";
    cin >> a >> b;
    cout << "Hasil tambah: " << k.tambah(a, b) << endl;
    cout << "Hasil kurang: " << k.kurang(a, b) << endl;
    cout << "Hasil kali: " << k.kali(a, b) << endl;
    cout << "Hasil bagi: " << k.bagi(a, b) << endl;
    
    Mahasiswa m;
    string nama;
    int id;
    char nilai;
    cout << "Masukkan nama, ID, dan nilai mahasiswa: ";
    cin >> nama >> id >> nilai;
    m.setData(nama, id, nilai);
    m.tampilkanInfo();
    
    PersegiPanjang pp;
    double p, l;
    cout << "Masukkan panjang dan lebar persegi panjang: ";
    cin >> p >> l;
    pp.setData(p, l);
    cout << "Luas persegi panjang: " << pp.hitungLuas() << endl;
    
    Penghitung peng;
    int hitung;
    cout << "Masukkan jumlah kenaikan penghitung: ";
    cin >> hitung;
    for (int i = 0; i < hitung; i++) {
        peng.tambah();
    }
    cout << "Nilai penghitung: " << peng.nilaiSekarang() << endl;
    
    Titik t;
    double x, y;
    cout << "Masukkan koordinat titik (x y): ";
    cin >> x >> y;
    t.setData(x, y);
    cout << "Jarak titik dari (0,0): " << t.jarakDariNol() << endl;
    
    return 0;
}
