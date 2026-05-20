#include "QuanLySinhVien.h"

// ================= CÀI ĐẶT LỚP SINH VIÊN (CHA) =================
SinhVien::SinhVien(int maSV, string HoTen, string diaChi, int tongTC, double dtb) {
    this->maSV = maSV;
    this->HoTen = HoTen;
    this->diaChi = diaChi;
    this->tongTC = tongTC;
    this->dtb = dtb;
}

SinhVien::~SinhVien() {}


// ================= CÀI ĐẶT LỚP SINH VIÊN CAO ĐẲNG =================
SinhVienCaoDang::SinhVienCaoDang(int maSV, string HoTen, string diaChi, int tongTC, double dtb, double diemTN) : 
    SinhVien(maSV, HoTen, diaChi, tongTC, dtb) {
    this->diemTN = diemTN;
}

void SinhVienCaoDang::in() {
    cout << "Ma so sinh vien: " << maSV << '\n';
    cout << "Ho ten: " << HoTen << '\n';
    cout << "Dia chi: " << diaChi << '\n';
    cout << "Tong so tin chi: " << tongTC << '\n';
    cout << "Diem trung binh: " << dtb << '\n';
    cout << "Diem tot nghiep: " << diemTN << '\n';
}

SinhVienCaoDang::~SinhVienCaoDang() {}


// ================= CÀI ĐẶT LỚP SINH VIÊN ĐẠI HỌC =================
SinhVienDaiHoc::SinhVienDaiHoc(int maSV, string HoTen, string diaChi, int tongTC, double dtb, string tenLuanVan, double diemLuanVan) : 
    SinhVien(maSV, HoTen, diaChi, tongTC, dtb) {
    this->tenLuanVan = tenLuanVan;
    this->diemLuanVan = diemLuanVan;
}

void SinhVienDaiHoc::in() {
    cout << "Ma so sinh vien: " << maSV << '\n';
    cout << "Ho ten: " << HoTen << '\n';
    cout << "Dia chi: " << diaChi << '\n';
    cout << "Tong so tin chi: " << tongTC << '\n';
    cout << "Diem trung binh: " << dtb << '\n';
    cout << "Ten luan van: " << tenLuanVan << '\n';
    cout << "Diem luan van: " << diemLuanVan << '\n';
}

SinhVienDaiHoc::~SinhVienDaiHoc() {}