#include "NhanVien.h"


void NhanVien::Nhap() {
    cout << "Nhap ten: ";
    getline(cin >> ws, ten);
    cout << "Nhap ngay sinh: ";
    cin >> ngaysinh;
}

int NhanVien::getLuong() {
    return luong;
}

string NhanVien::getNgaySinh() {
    return ngaysinh;
}

void NhanVien::Xuat() {
    cout << "Ten: " << ten << '\n' << "Ngay sinh: " << ngaysinh << '\n' << "luong: " << luong << '\n';
}

NhanVien::~NhanVien() {}



void NhanVienVanPhong::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap so ngay lam viec: "; 
    cin >> soNgayLamViec;
}

void NhanVienVanPhong::TinhLuong() {
    luong = soNgayLamViec * 100000;
}



void NhanVienSanXuat::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap luong co ban: "; 
    cin >> luongCoBan;
    cout << "Nhap so san pham: "; 
    cin >> soSanPham;
}

void NhanVienSanXuat::TinhLuong() {
    luong = luongCoBan + soSanPham * 5000;
}



bool cmp(string x, string y) {
    auto toInt = [](int &i, int &size, string &s) {
        int k = 0;
        while (i < size && s[i] != '/') {
            k = k * 10 + (int)(s[i] - '0');
            i++;
        }
        return k;
    };
    int i = 0, n = x.size(), m = y.size();
    int dx = toInt(i, n, x); i++;
    int mx = toInt(i, n, x); i++;
    int yx = toInt(i, n, x); i++; i = 0;
    int dy = toInt(i, m, y); i++;
    int my = toInt(i, m, y); i++;
    int yy = toInt(i, m, y);
    if (yx != yy) {
        return yx < yy;
    } else if (mx != my) {
        return mx < my;
    } else {
        return dx < dy;
    }
}