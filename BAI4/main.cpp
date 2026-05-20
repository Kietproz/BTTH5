#include "CongTy.h"

int main() {
    QuanLyCongTy congTy;

    cout << "a. NHAP DANH SACH NHAN VIEN \n";
    congTy.nhapDanhSach();

    cout << "\n b. XUAT DANH SACH NHAN VIEN \n";
    congTy.xuatDanhSach();

    cout << "\nc. NHAN VIEN CO LUONG THAP HON MUC TRUNG BINH \n";
    congTy.xuatNVLuongThapHonTrungBinh();

    cout << "\n d. NHAN VIEN CO LUONG CAO NHAT \n";
    congTy.xuatNVLuongCaoNhat();

    cout << "\ne. NHAN VIEN CO LUONG THAP NHAT \n";
    congTy.xuatNVLuongThapNhat();

    cout << "\n f. LAP TRINH VIEN CO LUONG CAO NHAT \n";
    congTy.xuatLapTrinhVienLuongCaoNhat();

    return 0;
}
