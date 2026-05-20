#include "CongTyXYZ.h"


KhachHang::KhachHang() : soLuongHang(0), donGiaHang(0.0) {}
KhachHang::~KhachHang() {}

void KhachHang::docFile(ifstream& in) {
    in.ignore();
    getline(in, tenKH);
    in >> soLuongHang >> donGiaHang;
}

void KhachHang::ghiFile(ofstream& out) const {
    out << tenKH << "\n" << (long long)tinhTienTra() << "\n";
}

string KhachHang::getTenKH() const { return tenKH; }



double KhachHangA::tinhTienTra() const {
    double tienHang = soLuongHang * donGiaHang;
    return tienHang + (tienHang * 0.10);
}



void KhachHangB::docFile(ifstream& in) {
    KhachHang::docFile(in);
    in >> soNamThanThiet;
}

double KhachHangB::tinhTienTra() const {
    double tienHang = soLuongHang * donGiaHang;

    double phanTramKM = max(soNamThanThiet * 0.05, 0.50);
    double tienSauKM = tienHang * (1.0 - phanTramKM);
    return tienSauKM + (tienSauKM * 0.10);
}


double KhachHangC::tinhTienTra() const {
    double tienHang = soLuongHang * donGiaHang;
    double tienSauKM = tienHang * 0.50;
    return tienSauKM + (tienSauKM * 0.10);
}


QuanLyMuaHang::~QuanLyMuaHang() {
    for (KhachHang* kh : danhSachKH) {
        delete kh;
    }
    danhSachKH.clear();
}

void QuanLyMuaHang::xuLyDuLieu(string fileIn, string fileOut) {
    ifstream in(fileIn);
    ofstream out(fileOut);

    if (!in.is_open() || !out.is_open()) {
        cout << "Loi mo file!" << endl;
        return;
    }

    int x, y, z;
    in >> x >> y >> z;


    out << x << " " << y << " " << z << "\n";


    for (int i = 0; i < x; i++) {
        KhachHang* kh = new KhachHangA();
        kh->docFile(in);
        danhSachKH.push_back(kh);
    }


    for (int i = 0; i < y; i++) {
        KhachHang* kh = new KhachHangB();
        kh->docFile(in);
        danhSachKH.push_back(kh);
    }


    for (int i = 0; i < z; i++) {
        KhachHang* kh = new KhachHangC();
        kh->docFile(in);
        danhSachKH.push_back(kh);
    }

    double tongDoanhThu = 0;
    for (const auto& kh : danhSachKH) {
        kh->ghiFile(out);
        tongDoanhThu += kh->tinhTienTra();
    }


    out << (long long)tongDoanhThu << "\n";

    in.close();
    out.close();
    cout << "Xu ly file hoàn tat thành cong!" << endl;
}
