#include "CongTy.h"

NhanVien::NhanVien() : tuoi(0), luongCoBan(0) {}
NhanVien::~NhanVien() {}

void NhanVien::nhap() {
    cin.ignore();
    cout << "Nhap ma nhan vien: "; getline(cin, maNV);
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap tuoi: "; cin >> tuoi;
    cin.ignore();
    cout << "Nhap so dien thoai: "; getline(cin, sdt);
    cout << "Nhap email: "; getline(cin, email);
    cout << "Nhap luong co ban: "; cin >> luongCoBan;
}

void NhanVien::xuat() const {
    cout << "Ma NV: " << maNV << " | Ho ten: " << hoTen
         << " | Tuoi: " << tuoi << " | SDT: " << sdt
         << " | Email: " << email << " | Luong CB: " << (long long)luongCoBan;
}

string NhanVien::getMaNV() const { return maNV; }
string NhanVien::getHoTen() const { return hoTen; }


void LapTrinhVien::nhap() {
    NhanVien::nhap();
    cout << "Nhap so gio overtime: "; cin >> soGioOvertime;
}

void LapTrinhVien::xuat() const {
    NhanVien::xuat();
    cout << " | So gio OT: " << soGioOvertime
         << " | TONG LUONG: " << (long long)tinhLuong() << " (LTV)" << endl;
}

double LapTrinhVien::tinhLuong() const {
    return luongCoBan + (soGioOvertime * 200000.0);
}

string LapTrinhVien::getLoai() const { return "LTV"; }


void KiemChungVien::nhap() {
    NhanVien::nhap();
    cout << "Nhap so loi phat hien: "; cin >> soLoiPhatHien;
}

void KiemChungVien::xuat() const {
    NhanVien::xuat();
    cout << " | So loi: " << soLoiPhatHien
         << " | TONG LUONG: " << (long long)tinhLuong() << " (KCV)" << endl;
}

double KiemChungVien::tinhLuong() const {
    return luongCoBan + (soLoiPhatHien * 50000.0);
}

string KiemChungVien::getLoai() const { return "KCV"; }



QuanLyCongTy::~QuanLyCongTy() {
    for (NhanVien* nv : danhSachNV) {
        delete nv;
    }
    danhSachNV.clear();
}

void QuanLyCongTy::nhapDanhSach() {
    int n, chon;
    cout << "Nhap so luong nhan vien can them: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\n--- Chon loai nhan vien thu " << i + 1 << " ---\n";
        cout << "1. Lap trinh vien\n2. Kiem chung vien\nLua chon: ";
        cin >> chon;

        NhanVien* nv = nullptr;
        if (chon == 1) nv = new LapTrinhVien();
        else nv = new KiemChungVien();

        nv->nhap();
        danhSachNV.push_back(nv);
    }
}

void QuanLyCongTy::xuatDanhSach() const {
    for (const auto& nv : danhSachNV) {
        nv->xuat();
    }
}

double QuanLyCongTy::tinhLuongTrungBinh() const {
    if (danhSachNV.empty()) return 0;
    double tong = 0;
    for (const auto& nv : danhSachNV) {
        tong += nv->tinhLuong();
    }
    return tong / danhSachNV.size();
}

void QuanLyCongTy::xuatNVLuongThapHonTrungBinh() const {
    double luongTB = tinhLuongTrungBinh();
    cout << "\n[Muc luong trung binh cong ty: " << (long long)luongTB << "]\n";
    for (const auto& nv : danhSachNV) {
        if (nv->tinhLuong() < luongTB) {
            nv->xuat();
        }
    }
}

void QuanLyCongTy::xuatNVLuongCaoNhat() const {
    if (danhSachNV.empty()) return;
    double maxLuong = danhSachNV[0]->tinhLuong();
    for (const auto& nv : danhSachNV) {
        if (nv->tinhLuong() > maxLuong) maxLuong = nv->tinhLuong();
    }
    for (const auto& nv : danhSachNV) {
        if (nv->tinhLuong() == maxLuong) nv->xuat();
    }
}

void QuanLyCongTy::xuatNVLuongThapNhat() const {
    if (danhSachNV.empty()) return;
    double minLuong = danhSachNV[0]->tinhLuong();
    for (const auto& nv : danhSachNV) {
        if (nv->tinhLuong() < minLuong) minLuong = nv->tinhLuong();
    }
    for (const auto& nv : danhSachNV) {
        if (nv->tinhLuong() == minLuong) nv->xuat();
    }
}

void QuanLyCongTy::xuatLapTrinhVienLuongCaoNhat() const {
    double maxLuongLTV = -1;
    for (const auto& nv : danhSachNV) {
        if (nv->getLoai() == "LTV" && nv->tinhLuong() > maxLuongLTV) {
            maxLuongLTV = nv->tinhLuong();
        }
    }
    if (maxLuongLTV == -1) {
        cout << "Khong co lap trinh vien nao trong danh sach.\n";
        return;
    }
    for (const auto& nv : danhSachNV) {
        if (nv->getLoai() == "LTV" && nv->tinhLuong() == maxLuongLTV) {
            nv->xuat();
        }
    }
}
